#include <iostream>
#include <cstring>
using namespace std;



char arr[100][1000];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        
        char str[1001] = { 0, };
        int k;

        int cnt = 0;

        cin >> str;
        cin >> k;
        
        for (int i = 0; i < k; i++) {
            memset(arr[i], 0, sizeof(arr[i]));
        }

        int j = 0;

        
        while (cnt < strlen(str) )
        {
            if (j % 2 == 0) {
                for (int i = 0; i < k; i++) {
                    arr[i][j] = str[cnt];
                }
                ++j;
            }
            else {
                for (int i = k-1; i >= 0; i--) {
                    arr[i][j] = str[cnt];
                }
                ++j;
            }
            cnt++;
        }


        for (int row = 0; row<k ; row++) {
            for (int col = 0; col < strlen(str) / k + 1; col++) {
                if (arr[row][col] == 0) break;
                cout << arr[row][col];
            }
        }

        cout << '\n';
        
    }
}
