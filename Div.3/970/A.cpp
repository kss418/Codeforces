#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n % 2 == 0 && m % 2 == 0) cout << "YES\n";
        else if (n && m % 2 && n % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
   

    return 0;
}