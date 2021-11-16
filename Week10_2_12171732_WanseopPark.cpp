#include <iostream>
using namespace std;

int arr[501];
int d[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 501; i++) {
            arr[i] = 0;
            d[i] = 0;
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            d[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] > ans) {
                ans = d[i];
            }
        }

        cout << ans << "\n";
    }
}
