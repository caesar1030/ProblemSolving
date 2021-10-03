#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];

int n,m;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int left = 1;
    int right = arr[n];

   
    while (left <= right)
    {
        int count = 1;
        int mid = (left + right) / 2;
        int latest = 1;


        for (int i = 2; i <= n; i++) {
            if (arr[i] - arr[latest] >= mid) {
                ++count;
                latest = i;
            }
        }

        if (count >= m) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
  
    cout << ans;
}
