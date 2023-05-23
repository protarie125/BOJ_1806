#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

ll n, s;
vl vals;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> s;
	vals = vl(n);
	for (auto&& x : vals) {
		cin >> x;
	}

	auto left = vals.begin();
	auto right = vals.begin();
	auto sum = vals[0];
	auto len = n + 1;
	while (left <= right && right < vals.end()) {
		if (sum < s) {
			++right;
			if (right < vals.end()) {
				sum += *right;
			}
		}
		else {
			len = min(len, static_cast<ll>(distance(left, right) + 1));
			sum -= *left;
			++left;
		}
	}

	if (n + 1 == len) {
		cout << 0;
		return 0;
	}

	cout << len;

	return 0;
}