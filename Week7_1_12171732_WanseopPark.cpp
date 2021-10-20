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
    while (t--) {
        vector<int> former[101];
        
        
        int ans[101] = { 0, };
        int n; // 공 개수
        int m; // 비교 횟수
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            former[b].push_back(a);
            
        }

        for (int i = 1; i <= n; i++ ) {
            bool check[101] = { 0, };
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int now = q.front(); q.pop();
                for (auto x : former[now]) {
                    if (!check[x]) {
                        ans[x] += 1;
                        q.push(x);
                        check[x] = true;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }

        cout << "\n";
    }
}
