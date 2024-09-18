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
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		ll result = 0;
		sort(arr + 2, arr + n + 1);
		for (int i = 2; i <= n; i++) {
			if (arr[i] <= arr[1]) {
				continue;
			}

			arr[1] += (arr[i] - arr[1] + 1) / 2;
		}
		
		cout << arr[1] << "\n";
	}


	return 0;
}