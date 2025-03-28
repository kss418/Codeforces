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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];

bool chk(){
    for(int i = 1;i <= n;i++){
        if(a[i - 1] > a[i]) return 0;
    }
    return 1;
}

void run(){
    cin >> n >> m; a[0] = MINF;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        ll now = a[i], use = b[1] - a[i];
        if(use >= a[i - 1] && now >= a[i - 1]) a[i] = min(use, now);
        else if(use >= a[i - 1]) a[i] = use;
    }

    cout << (chk() ? "YES" : "NO") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}
