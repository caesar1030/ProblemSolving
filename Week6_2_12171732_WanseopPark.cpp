#include <iostream>
#include <queue>
using namespace std;



int dx[8] = { -1,-1,-1,0,1,1,1, 0 };
int dy[8] = { 1,0,-1,-1,-1,0,1,1 };

int arr[1001][1001];
int check[1001][1001];
int dist[1001][1001];

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
        int arow, acol, brow, bcol; // a인하 b 안전지역
        cin >> arow >> acol >> brow >> bcol;
        int crow, ccol, drow, dcol; // c 검사 d 소총수
        cin >> crow >> ccol >> drow >> dcol;



        check[crow][ccol] = 2;
        for (int i = 0; i < 8; i++) {
            if (crow + dy[i] >= 1 && crow + dy[i] <= n && ccol + dx[i] >= 1 && ccol + dx[i] <= n) {
                check[crow + dy[i]][ccol + dx[i]] = 1;
            }
        }

        check[drow][dcol] = 1;
        for (int i = 0; i < 8; i++) {
            int nrow = drow + dy[i];
            int ncol = dcol + dx[i];
            while (nrow >= 1 && nrow <= n && ncol >= 1 && ncol <= n) {
                if (check[nrow][ncol] == 2) break;
                check[nrow][ncol] = 1;

                nrow += dy[i];
                ncol += dx[i];
            }
        }

        queue<pair<int, int>> q;
        q.push({ arow,acol });
        check[arow][acol] = 1;
        dist[arow][acol] = 0;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nrow = row + dy[i];
                int ncol = col + dx[i];
                if (nrow >= 1 && nrow <= n && ncol >= 1 && ncol <= n) {
                    if (check[nrow][ncol] == 0) {
                        q.push({ nrow,ncol });
                        check[nrow][ncol] = 1;
                        dist[nrow][ncol] = dist[row][col] + 1;
                    }
                }
            }
        }

        cout << dist[brow][bcol] << "\n";


        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                arr[i][j] = 0;
                    check[i][j] = 0;
                    dist[i][j] = 0;
            }
        }
    }
}
