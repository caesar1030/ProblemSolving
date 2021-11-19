#include <iostream>
using namespace std;

int arr[101][101];
int d[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                arr[i][j] = 0;
                d[i][j] = 0;
            }
        }



        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> arr[i][j];
            }
        }

        d[1][1] = arr[1][1];

        for (int i = 2; i <= n; i++) {
            d[i][1] = d[i - 1][1] + arr[i][1];
            for (int j = 2; j <= i - 1; j++) {
                d[i][j] = arr[i][j];
                d[i][j] += d[i - 1][j - 1] < d[i - 1][j] ? d[i - 1][j - 1] : d[i - 1][j];
            }
            d[i][i] = d[i - 1][i - 1] + arr[i][i];
        }

        int min = d[n][1];

        for (int i = 2; i <= n; i++) {
            if (min > d[n][i]) {
                min = d[n][i];
            }
        }
        cout << min << "\n";
    }
}
