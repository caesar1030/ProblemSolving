#include <iostream>
#include <queue>
using namespace std;


class info {
public:
	int idx;
	int endTime;
	int price;

	info(int _i, int _t, int _p) {
		idx = _i;
		endTime = _t;
		price = _p;
	}
};

struct cmp {
	bool operator() (info a, info b){
		if (a.endTime == b.endTime) {
			return a.idx > b.idx;
		}
		return a.endTime > b.endTime;
	}
};


int n; // 계산대 수
int m; // 손님 수 
priority_queue<info, vector<info> , cmp> pq; // 계산대 인덱스
queue<pair<int, int>> q; // 대기 {시간, 가격} 
int now = 0;
int totalPrice[20001]; // 총계산시간

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		q.push({ a,b });
	}

	for (int i = 0; i < n; i++) {
		int nTime = q.front().first; 
		int nPrice = q.front().second; 
		q.pop();
		pq.push(info(i, nTime, nPrice));
	}

	while (!q.empty()) {
		int nIdx = pq.top().idx;
		totalPrice[nIdx] += pq.top().price;
		now = pq.top().endTime;
		pq.pop();
		int nTime = now + q.front().first;
		int nPrice = q.front().second;
		q.pop();
		pq.push(info(nIdx, nTime, nPrice));
	}

	while (!pq.empty()) {
		int nIdx = pq.top().idx;
		totalPrice[nIdx] += pq.top().price;
		now = pq.top().endTime;
		pq.pop();
	}

	cout << now << "\n";
	for (int i = 0; i < n; i++) {
		cout << totalPrice[i] << "\n";
	}

}
