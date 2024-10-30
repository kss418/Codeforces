#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 2010;
constexpr ll MOD = 998244353;
ll a[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; 
        for(int i = 1;i <= n;i++) cin >> a[i];
        if(n == 1) {
            cout << 1 << "\n"; continue;
        }

        ll result = 1e18 + 1;
        if(n % 2){
            for(int i = 1;i <= n;i+=2){
                vector <ll> cur;
                for(int j = 1;j <= n;j++){
                    if(i == j) continue;
                    cur.push_back(a[j]);
                }
                
                ll mx = 0;
                for(int j = 0;j < n - 1;j+=2){
                    mx = max(mx, cur[j + 1] - cur[j]);
                }

                result = min(mx, result);
            }
        }
        else{
            ll mx = 0;
            for(int i = 1;i <= n;i+=2) mx = max(mx, a[i + 1] - a[i]);
            result = min(mx, result);
        }

        cout << result << "\n";
    }

    return 0;
}