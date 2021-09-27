#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	

	while (t--)
	{
		int a, b, x, y;
		cin >> a >> b >> x >> y;

		int min;
		int max;

		min = (a < b ? a : b);
		max = (a > b ? a : b);

		int gcd = max - min;
		int cost = 987654321;
		int cost2 = 987654321;
		int cost3 = 987654321;

		if ((max % gcd == 0) && (min % gcd == 0)) {
			cost = 0;
			cout << gcd << " " << cost << "\n";
			continue;
		}


		for (int i = 1; i < 1000000; i++) {
			if (((max+i) % gcd == 0) && ((min+i) % gcd == 0)) {
				cost2 = i * x;
				break;
			}
		}

		for (int i = 1; (min-i) >= gcd; i++) {
			if (((max-i) % gcd == 0) && ((min-i) % gcd == 0)) {
				cost3 = i * y;
				break;
			}
		}
		
		cost = cost2 < cost3 ? cost2 : cost3;

		cout << gcd << " " << cost << "\n";
	}
}