#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501;
constexpr ll MOD = 998244353;
ll a[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1 || n == 3) cout << -1 << "\n";
        else if(n % 2 == 0){
            for(int i = 1;i <= n - 2;i++) cout << 3;
            cout << 66 << "\n";
        }
        else{
            for(int i = 1;i <= n - 4;i++) cout << 3;
            cout << 6366 << "\n";
        }
    }
    
    
    return 0;
}
