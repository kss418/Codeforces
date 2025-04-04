#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll a[MAX];
ll sum[MAX];


int main() {
    fastio;


    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= m;i++) sum[i] = 0;
        for(int i = 1;i <= m;i++) {
            cin >> a[i].x >> a[i].y;
            sum[a[i].x] += a[i].y;
        }

        sort(sum + 1, sum + m + 1);
        ll result = 0;
        for(int i = m;i >= m - n + 1 && i >= 1;i--) result += sum[i];

        cout << result << "\n";
    }



    return 0;
}

