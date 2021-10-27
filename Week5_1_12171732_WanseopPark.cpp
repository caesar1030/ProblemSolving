#include <iostream>
using namespace std;


int arr[5001];
int table[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 5001; i++) {
			arr[i] = 0;
			table[i] = 0;
		}

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int j = 0;
		for (int i = 1; i < n; i++) {
			while (j > 0 && arr[j] != arr[i]) {
				j = table[j - 1];
			}

			if (arr[i] == arr[j]) {
				table[i] = ++j;;
			}
		}


		for (int i = 0; i < n - table[n - 1]; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}
