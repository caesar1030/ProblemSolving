#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, n, m;
        cin >> x >> n >> m;

        long long ans = (x * ((long long)pow(x, n) - 1) / (x - 1));
        cout << ans % m;
    }
}
