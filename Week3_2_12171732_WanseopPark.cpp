#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 2001;

vector<pair<int, int>> tree[MAX]; 
int dist[MAX];
bool check[MAX];


void bfs(int node) {
    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));
    queue<int> q;
    q.push(node);
    check[node] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto x : tree[now]) {
            if (!check[x.first]) {
                dist[x.first] = dist[now] + x.second;
                q.push(x.first);
                check[x.first] = true;
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

        int n;
        cin >> n;

        for (int i = 1; i <= n - 1; i++) {
            int start, end, d;
            cin >> start >> end >> d;

            tree[start].push_back({ end,d });
            tree[end].push_back({ start,d });
        }

        bfs(1);
        int next = 1;
        for (int i = 1; i <= n; i++) {
            next = dist[i] > dist[next] ? i : next;
        }

       

        bfs(next);
        int max = 0;
        for (int i = 1; i <= n; i++) {
            max = dist[i] > max ? dist[i] : max;
        }

        cout << max << "\n";
    }
}