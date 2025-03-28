#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
ll arr[MAX], use[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> t;
	while (t--) {
		cin >> n;
		memset(use, 0, sizeof(use));
		ll result = 0;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = n; i >= 1; i--) {
			if (use[arr[i]]) {
				result = i;
				break;
			}
			else {
				use[arr[i]] = 1;
			}
		}

		cout << result << "\n";
	}
	
	return 0;
}
