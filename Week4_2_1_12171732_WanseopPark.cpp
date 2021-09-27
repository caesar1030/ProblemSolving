#include <iostream>
#include <algorithm>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1 > 0) {
        return 1;
    }
    else if (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1 < 0) {
        return -1;
    }
    else {
        return 0;
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
        pair<int, int> a; // 선분1의 점1
        pair<int, int> b; // 선분1의 점2

        pair<int, int> c; // 선분2의 점1
        pair<int, int> d; // 선분2의 점2

        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        a.first = x1; 
        a.second = y1;
        b.first = x2;
        b.second = y2;
       
        c.first = x3;
        c.second = y3;
        d.first = x4;
        d.second = y4;

        if (a > b) {
            swap(a, b);
        }
        if (c > d) {
            swap(c, d);
        }
        if (a > c || (a==c &&  b < d)) {
            swap(a, c);
            swap(b, d);
        }

        int abc = ccw(a.first, a.second, b.first, b.second, c.first, c.second);
        int abd = ccw(a.first, a.second, b.first, b.second, d.first, d.second);
        int cda = ccw(c.first, c.second, d.first, d.second, a.first, a.second);
        int cdb = ccw(c.first, c.second, d.first, d.second, b.first, b.second);

        
        if (abc * abd == 0 && cda * cdb == 0) { // 두 선이 한 직선안에 포함
            if (b < c) {
                cout << 1 << "\n";
            }
            else if (b == c) {
                cout << 2 << "\n";
            }
            else if (c<b && d>b) {
                cout << 3 << "\n";
            }
            else if (c < b && d <= b) {
                cout << 4 << "\n";
            }
        }
        else {
            if (abc * abd > 0 || cda * cdb > 0) { // 한 선분을 포함하는 직선에 대해 두 점이 모두 같은 방향에 있으므로 접점x
                cout << 1 << "\n";
            }
            else { // <=0 && <=0
                cout << 2 << "\n";
            }
        }

    }
    
}
