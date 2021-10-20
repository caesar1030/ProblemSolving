#include <iostream>
#include <queue>
using namespace std;

class info {
public:
    
    pair<int, int> key;
    info(pair<int, int> _k) {
        key.first = _k.first;
        key.second = _k.second;
    }
};

struct cmp {
    bool operator() (info a, info b) {
        if (a.key.first * a.key.first + a.key.second * a.key.second == b.key.first * b.key.first + b.key.second * b.key.second) {
            return a.key < b.key;
        }
        return a.key.first * a.key.first + a.key.second * a.key.second < b.key.first * b.key.first + b.key.second * b.key.second;
    }
};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m; // 가게 수
        int n; // 날짜
        int k; // 가까운 순서 갈집

        cin >> m >> n >> k;

        priority_queue<info, vector<info>, cmp> pq;
        

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            pq.push(info({ x, y }));
        }

        while (pq.size() > k) {
            pq.pop();
        }

        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            pair<int, int> tmp = { x,y };

            if (pq.top().key.first * pq.top().key.first + pq.top().key.second * pq.top().key.second > tmp.first * tmp.first + tmp.second * tmp.second) {
                pq.pop();
                pq.push(tmp);
            }
            else if (pq.top().key.first * pq.top().key.first + pq.top().key.second * pq.top().key.second == tmp.first * tmp.first + tmp.second * tmp.second
                && tmp < pq.top().key) {
                pq.pop();
                pq.push(tmp);
            }
            

            cout << pq.top().key.first << " " << pq.top().key.second  << "\n";
        }
    }
}