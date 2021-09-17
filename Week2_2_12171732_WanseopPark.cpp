#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> inha;
vector<int> beryong;
vector<pair<int, int>> sum;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

    int t;
    cin >> t;
	while (t--)
	{
		inha.clear();
		beryong.clear();
		sum.clear();
		int n; // 자원의 갯수
		cin >> n;
		for (int i = 0; i < n; i++) {
			int in, be;
			cin >> in >> be;
			inha.push_back(in);
			beryong.push_back(be);
			sum.push_back({ in + be,i });
		}

		int sumInha = 0;
		int sumBeryong = 0;

		sort(sum.begin(), sum.end());

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				sumInha += inha[sum.back().second];
				sum.pop_back();
			}
			else {
				sumBeryong += beryong[sum.back().second];
				sum.pop_back();
			}
		}
		
		cout << sumInha - sumBeryong << '\n';
	}
}

