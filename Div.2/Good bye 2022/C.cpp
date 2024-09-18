#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 110;
ll arr[MAX], mod[1010][1010];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		memset(mod, 0, sizeof(mod));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			for (int j = 2; j <= 1000; j++) {
				mod[j][arr[i] % j]++;
			}
		}
		bool flag = 1;

		for (int j = 2; j <= 1000; j++) {
			if (!flag) {
				break;
			}

			for (int i = 0; i < j; i++) {
				if (mod[j][i] < 2) {
					break;
				}

				if (i == j - 1) {
					flag = 0;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (!flag) {
					break;
				}

				if (arr[i] == arr[j]) {
					flag = 0;
					break;
				}
			}
		}

		if (flag) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}

		cout << "\n";
	}

	return 0;
}
