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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], num[1010101];
set <ll> cnt, use;

class _es { // flag (1 == prime / 2 == phi / 4 == mobius)
public:
    ll n; vector <ll> pv, pn, mov, phiv;
    vector <bool> v;
    _es(ll n, ll flag = 1) {
        this->n = n;

        if(flag & 1){
            pv.resize(n + 1, -1); pv[1] = 1;
            for (ll i = 2;i <= n;i++) {
                if(pv[i] != -1) continue; pv[i] = i;
                pn.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    if(pv[j] == -1) pv[j] = i;
                }
            }
        }

        if(flag & 2){
            phiv.resize(n + 1); iota(all(phiv), 0);
            v.resize(n + 1);
            for(ll i = 2;i <= n;i++){
                if(v[i]) continue;
                for(ll j = i;j <= n;j += i){
                    phiv[j] /= i; phiv[j] *= (i - 1); v[j] = 1;
                }
            }
        }

        if(flag & 4){
            mov.resize(n + 1, -2);
            mov[0] = 0; mov[1] = 1;
            for(ll i = 2;i <= n;i++){
                if(mov[i] != -2) continue; mov[i] = -1;
                for(ll j = 2 * i;j <= n;j += i) {
                    if(mov[j] == -2) mov[j] = 1;
                    mov[j] *= -1;
                }
                for(ll j = i * i;j <= n; j += i * i) mov[j] = 0;
            }
        }
    }

    ll mp(ll n) { return pv[n]; } // 최소 소인수 반환
    vector<ll> ret() { return pn; } // 소수 벡터 반환
    bool prime(ll n) { // 소수 판별
        if (n == 1) return 0;
        return pv[n] == n;
    }
    ll mobius(ll n){ return mov[n]; }
    ll phi(ll n){ return phiv[n]; }
};

int main() {
    fastio;

    cin >> n; _es es(1010101);
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll cur = a[1];
    while(cur != 1){
        ll div = es.mp(cur);
        cur /= div;

        cnt.insert(div);
    }
    
    vector <ll> arr;
    for(auto& i : cnt) arr.push_back(i);
    ll mx = arr.size();
    for(int i = 0;i < (1ll << mx);i++){
        ll cur = i, nxt = 1;

        for(int j = 0;j < mx;j++){
            if((1ll << j) & cur) nxt *= arr[j];
        }

        if(nxt == 1) continue;
        num[nxt]++;
    }


    for(int i = 2;i <= n;i++) {
        ll cur = a[i]; cnt.clear();

        while(cur != 1){
            ll div = es.mp(cur);
            cur /= div;

            cnt.insert(div);
        }

        vector <ll> arr;
        for(auto& i : cnt) arr.push_back(i);
        ll now = 0, mx = arr.size();

        for(int i = 0;i < (1ll << mx);i++){
            ll cur = i, nxt = 1, c = 0;
            for(int j = 0;j < mx;j++){
                if((1ll << j) & cur) {
                    nxt *= arr[j]; c++;
                }
            }

            if(nxt == 1) continue;
            if(c % 2) now += num[nxt];
            else now -= num[nxt];
            now %= MOD;
        }

        now = (now + MOD) % MOD;
        for(int i = 0;i < (1ll << mx);i++){
            ll cur = i, nxt = 1;

            for(int j = 0;j < mx;j++){
                if((1ll << j) & cur) nxt *= arr[j];
            }

            if(nxt == 1) continue;
            num[nxt] += now % MOD;
            num[nxt] %= MOD;
        }

        if(i == n) cout << now << " ";
    }


    return 0;
}
