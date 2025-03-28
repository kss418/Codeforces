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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];
bool use[MAX];
map <ll, bool> v;

void init(){
    memset(use, 0, sizeof(use));
    v.clear();
}

void run(){
    cin >> n; init(); ll cnt = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(use[j]) continue;
            if(v.count(a[j] + b[i])) continue;
            use[j] = 1; v[a[j]+ b[i]] = 1;
            cnt++;
        }
    }

    cout << (cnt >= 3 ? "YES" : "NO") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}
