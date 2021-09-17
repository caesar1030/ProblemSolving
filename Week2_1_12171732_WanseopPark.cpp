#include <iostream>
#include <vector>
#include <queue>
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
		queue<string> gyosu;
		queue<string> v[21];
		int n; // 학생수
		int m; // 교수님 단어수
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			string s;
			cin >> s;
			gyosu.push(s);
		}

		

		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			for (int j = 0; j < temp; j++) {
				string s;
				cin >> s;
				v[i].push(s);
			}
		}
		
		bool ok = false;
		for(int j=0; j<m; j++) {
			if (j!=0 && !ok) break;
			ok = false;

			for (int i = 1; i <= n; i++) {
				if (v[i].empty()) continue;
				if (v[i].front() == gyosu.front()) {
					ok = true;
					v[i].pop();
					break;
				}
			}

			gyosu.pop();
		}

		cout << (ok ? "1" : "0") << '\n';
		
	}
}
