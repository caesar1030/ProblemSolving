#include <iostream>
#include<vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50005;

vector<int> tree[MAX];
int len[MAX];
bool check[MAX];
int dist[MAX];
int n;



void bfs(int node) {
	queue<int> q;
	q.push(node);
	check[node] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (auto x : tree[now]) {
			if (!check[x]) {
				dist[x] = dist[now] + len[x] + 1;
				q.push(x);
				check[x] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	


    int t;
    cin >> t;
	while (t--)
	{
		for (int i = 0; i < MAX; i++) {
			tree[i].clear();
		}
		
		memset(len, 0, sizeof(len));
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		dist[1] = 4;
		

		cin >> n;

		

		for (int i = 1; i <= n-1; i++) {
			int parent, child;
			cin >> parent >> child;
			tree[parent].push_back(child);
		}
		
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			len[i] = str.length();
		}


		bfs(1);

		for (int i = 1; i <= n; i++) {
			cout << dist[i] << "\n";
		}
	}
}
