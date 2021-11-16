#include <iostream>
#include <queue>
using namespace std;


queue<int> q;
bool check[10000];
int dist[10000];
int a, b;
int temp[4];

void transform(int x) {
    temp[0] = x / 1000;
    temp[1] = (x % 1000) / 100;
    temp[2] = (x % 100) / 10;
    temp[3] = x % 10;
   
}


int reverse(int x) {
    transform(x);
    int tmp;
    tmp = temp[0];
    temp[0] = temp[3];
    temp[3] = tmp;
    tmp = temp[1];
    temp[1] = temp[2];
    temp[2] = tmp;
    
    return temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 10000; i++) {
            check[i] = false;
            dist[i] = 0;
        }
        for (int i = 0; i < 4; i++) {
            temp[i] = false;
        }
        

        cin >> a >> b;

        q.push(a);
        check[a] = true;
        dist[a] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (now == b) break;

            if (now < 9999) {
                if (check[now + 1] == false) {
                    q.push(now + 1);
                    check[now + 1] = true;
                    dist[now + 1] = dist[now] + 1;
                }
            }

            if (now > 0) {
                if (check[now - 1] == false) {
                    q.push(now - 1);
                    check[now - 1] = true;
                    dist[now - 1] = dist[now] + 1;
                }
            }

            int ra = reverse(now);

            if (check[ra] == false) {
                q.push(ra);
                check[ra] = true;
                dist[ra] = dist[now] + 1;
            }
        }

        while (!q.empty()) {
            q.pop();
        }

        cout << dist[b]<<"\n";
    }
}
