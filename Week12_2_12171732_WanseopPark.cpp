#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> v;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a,b;
            cin >> a >> b;
            v.push_back({b,a});
        }

        sort(v.begin(), v.end()); // 거리,평점 으로 정렬

        int nowScore = v[0].second;
        int ans = 1;

        for (int i = 1; i < v.size(); i++) {
            if (v[i].second > nowScore) {
                ++ans;
                nowScore = v[i].second;
            }
        }

        cout << ans << "\n";

    }
}
