#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
    int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		stack<int> minStack;
		stack<int> maxStack;
		while (n--)
		{
			int cmd;
			cin >> cmd;
			if (cmd == 1) {
				int block;
				cin >> block;
				if (minStack.empty()) {
					minStack.push(block);
					maxStack.push(block);
				}
				else {
					minStack.push(min(block, minStack.top()));
					maxStack.push(max(block, maxStack.top()));
				}
				cout << minStack.top() << " " << maxStack.top() << '\n';
			}
			else {
				if (minStack.empty()) continue;
				minStack.pop();
				maxStack.pop();
			}
		}
	}
    
}
