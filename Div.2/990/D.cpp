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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

int main() {
    fastio;

    cin >> t; 
    while(t--){
        cin >> n; vector <ll> result, now;
        for(int i = 1;i <= n;i++) cin >> a[i], now.push_back(a[i]);
        
        priority_queue <ll, vector<ll>, greater<ll>> pq;
        ll cnt = 2;
        while(result.size() != n){
            for(auto& i : now){
                while(!result.empty() && result.back() > i){
                    pq.push(result.back() + 1); result.pop_back();
                }
                result.push_back(i);
            }

            while(!result.empty() && !pq.empty() && pq.top() < result.back()){
                pq.push(result.back() + 1); result.pop_back();
            }

            now.clear();
            while(!pq.empty()) now.push_back(pq.top()), pq.pop();
        }

        for(auto& i : result) cout << i << " ";
        cout << "\n";
    }
  
     
    return 0;
}