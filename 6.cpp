#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N, S;
	int list[100005];
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}

	int l = 0, r = 0;
	int sum = 0; int minLength = 100005;
	while (1) {
		sum += list[r];
		if (r == N) break;
		/*cout << "dudud";*/
		while (1) {
			if (l > r) break;
			if (sum < S) break;
			if (sum >= S) {
				if (minLength > (r - l + 1)) {
					minLength = r - l + 1;
				}
				sum -= list[l++];
			}
		}
		r++;
	}
	if (minLength == 100005) { 
		cout << "0"; return 0; 
	}
	cout << minLength;
}