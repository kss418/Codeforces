#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dp[MAX][MAX][2];

void init(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) dp[i][j][0] = dp[i][j][1] = 0;
    }
}

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(0){}
        node(ll v) : v(v) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        return{
            (l.v + r.v) % MOD
        };
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            seg[node] = val % MOD; 
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
    }

    void add(ll idx, ll val) { add(idx, val, 0, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};

void run(){
    cin >> n >> m >> k; init();
    _seg <ll> seg[2]; seg[0] = seg[1] = {m};
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < m;i++){
        if(st[n - 1][i] == '#') continue;
        seg[0].update(i, 1); dp[n - 1][i][0] = 1;
    }

    for(int i = 0;i < m;i++){
        if(st[n - 1][i] == '#') continue;
        dp[n - 1][i][1] = seg[0].query(max(i - k, 0ll), min(i + k, m - 1)) % MOD;
        dp[n - 1][i][1] = (dp[n - 1][i][1] + MOD - seg[0].query(i, i)) % MOD;
        dp[n - 1][i][1] %= MOD; seg[1].update(i, dp[n - 1][i][1]);
    }
    
    for(int i = n - 2;i >= 0;i--){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue;
            dp[i][j][0] = seg[0].query(max(j - k + 1, 0ll), min(j + k - 1, m - 1)) % MOD;
            dp[i][j][0] += seg[1].query(max(j - k + 1, 0ll), min(j + k - 1, m - 1)) % MOD;
            dp[i][j][0] %= MOD;
        }

        seg[0].clear();
        for(int j = 0;j < m;j++) seg[0].update(j, dp[i][j][0]);

        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue;
            dp[i][j][1] = seg[0].query(max(j - k, 0ll), min(j + k, m - 1)) % MOD;
            dp[i][j][1] = (dp[i][j][1] + MOD - seg[0].query(j, j)) % MOD;
            dp[i][j][1] %= MOD;
        }

        seg[1].clear();
        for(int j = 0;j < m;j++) seg[1].update(j, dp[i][j][1]);
    }

    cout << (seg[0].query(0, m - 1) + seg[1].query(0, m - 1)) % MOD << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

