#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;

		int g = abs(a - b);
		int cost = (g - (b % g)) * x;

		if (min(a, b) > g) {
			cost = min(cost, (b % g) * y);
		}

		cout << g << " " << cost << "\n";
	}

}
