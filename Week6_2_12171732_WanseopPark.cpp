#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
bool check[1001][1001];
int x[8] = { -1,-1,-1,0,1,1,1,0 };
int y[8] = { 1,0,-1,-1,-1,0,1,1 };
int n;

int main()
{
    int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}


		cin >> n;
		
		int a, b, c, d; // 인하 a,b 안전지역 c,d
		cin >> a >> b >> c >> d;
		
		int e, f, g, h; // 소총수 e,f 검사 g,h
		cin >> g >> h >> e >> f;
		

		check[e][f] = true;
		check[g][h] = true;

		int sof = f;
		int soe = e;


		
		for (int i = 0; i < 8; i++) {
			//소총수
			while ((soe >= 1 && soe <= n) && (sof >= 1 && sof <= n)) {
				sof += x[i];
				soe += y[i];

				if (arr[soe][sof]  == false) {
					check[soe][sof] = true;
				}
				else {
					break;
				}
			}
			sof = f;
			soe = e;
			
			// 검사
			if (g + y[i] >= 0 && g + y[i] <= n && h + x[i] >= 0 && h + x[i] <= n) {
				check[g + y[i]][h + x[i]] = true;
			}
		}

		queue<pair<int, int>> q;

		q.push({ a,b });
		check[a][b] = true;

		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nrow = row + y[i];
				int ncol = col + x[i];
				if (nrow >= 1 && nrow <= n && ncol >= 1 && ncol <= n) {
					if (check[nrow][ncol] == false) {
						q.push({ nrow,ncol });
						check[nrow][ncol] = true;
						arr[nrow][ncol] = arr[row][col] + 1;
					}
				}
			}
		}

		cout << arr[c][d] << "\n";

	}
}
