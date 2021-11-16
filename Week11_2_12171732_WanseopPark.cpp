#include <iostream>
#include <vector>
using namespace std;

const int RED = 0;
const int BLUE = 1;


int arr[1026][1026];
int numRed, sumRed, numBlue, sumBlue;

void recursion(int row, int col, int size) {

	bool ok = true;
	int c = arr[row][col];
	for (int i = 0; i < size; i++) {
		for (int j =0 ; j < size; j++) {
			if (arr[row+i][col+j] != c) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			break;
		}
	}

	if (!ok) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				recursion(row + (i * (size / 2)), col + (j * (size / 2)), size / 2);
			}
		}
	}
	else {
		if (arr[row][col] == RED) {
			numRed++;
			sumRed += size * size;
		}
		else {
			numBlue++;
			sumBlue += size * size;
		}
		return;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1026; i++) {
			for (int j = 0; j < 1026; j++) {
				arr[i][j] = 0;
			}
		}
		numRed = 0; sumRed = 0; numBlue = 0; sumBlue = 0;

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				string c;
				cin >> c;
				if (c == "R") {
					arr[i][j] = RED;
				}
				else {
					arr[i][j] = BLUE;
				}
			}
		}

		recursion(1, 1,n);

		cout << numRed <<" " << sumRed<< " " << numBlue<< " " << sumBlue << "\n";

	}
}
