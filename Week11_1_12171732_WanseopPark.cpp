#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int arr[26];
int temp[26];
vector<pair<string, int>> v;
int ans = 0;

void recursion(int idx, int score) {
    if (idx >= v.size()) {
        bool ok = false;
        for (int i = 0; i < 26; i++) {
            if (temp[i] <= arr[i]) {
                ok = true;
            }
            else {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = max(ans, score);
        }
        return;
    }


    recursion(idx + 1, score);

    stack<int> st;
    string word = v[idx].first;
    for (char c : word) {
        temp[(int)c - 97] +=1 ;
        st.push((int)c - 97);
    }
    recursion(idx + 1, score + v[idx].second);
    while (!st.empty()) {
        temp[st.top()] -= 1;
        st.pop();
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 26; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string word;
        int score;

        cin >> word >> score;
        v.push_back({ word,score });
    }

    recursion(0, 0);

    cout << ans;
}
