#include <iostream>
using namespace std;

int arr[5005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		int len = 1;
		int i;
		bool flag = false;
		
		
		while (!flag)
		{
			for (i = len+1; i <= n; i++) {
				if (arr[i] != arr[i - len]) {
					break;
				}
			}

			if (i == n + 1) {
				flag = true;
				break;
			}

			++len;
		}

		for (int i = 1; i <= len; i++) {
			cout << arr[i] << " ";
		}

		cout << "\n";
	}
}
