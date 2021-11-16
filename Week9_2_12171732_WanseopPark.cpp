#include <iostream>
#include <stack>
using namespace std;

int arr[21][21]; // 0 빈곳 1 흑 2 백
int n, q;
int turn = 1;
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { 1,0,-1,-1,-1,0,1,1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {

        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                arr[i][j] = 0;
            }
        }


        cin >> n >> q;

        arr[n / 2][n / 2] = 1;
        arr[n / 2 + 1][n / 2 + 1] = 1;
        arr[n / 2][n / 2 + 1] = 2;
        arr[n / 2 + 1][n / 2] = 2;

      

        for (int i = 0; i < q; i++) {
            int r, c;
            cin >> r >> c;
            bool changed = false;
            for (int j = 0; j < 8; j++) {
                int nRow = r + dy[j];
                int nCol = c + dx[j];

                stack<pair<int, int>> st;

                if (nRow >= 1 && nRow <= n && nCol >= 1 && nCol <= n) {
                    if (arr[nRow][nCol] == turn) {
                        if (st.empty()) {

                        }
                        else {
                            while (!st.empty()) {
                                arr[st.top().first][st.top().second] = turn;
                            }
                            turn = 3 - turn;
                        }
                    }
                    else if (arr[nRow][nCol] == 0) {
                        continue;
                    }
                    else {
                        st.push({ nRow,nCol });
                    }
                }
                else { // 다음 칸이 벗어나면
                    continue;
                }

            }
        }






        int nBlack = 0;
        int nWhite = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 1) ++nBlack;
                if (arr[i][j] == 2) ++nWhite;
            }
        }

        if (nBlack > nWhite) {
            cout << 2 << "\n";
        }
        else if (nBlack < nWhite) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }

       
    }
}
