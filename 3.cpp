#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool isNotP[4000005];
int primeList[400000];
int main() {
	fill(isNotP, isNotP + 4000005, false);
	int N; cin >> N;
	int sqrtN = sqrt(N);
	for (int i = 2; i <= sqrtN; i++) {
		if (isNotP[i]) continue;
		for (int j = i*i; j <= N; j+=i) {
			isNotP[j] = true;
		}
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (!isNotP[i]) {
			primeList[cnt] = i;
			cnt++;
		}
	}
	
	//투포인터
	int l = 0, r = 0, sum = 0;
	int ans = 0;
	while (1) {
		if (r == cnt)break;
		sum += primeList[r];
		while (1) {
			if (l >= r) break;
			if (sum <= N) break;
			sum -= primeList[l++]; // sum > N인 경우
		}
		if (sum == N) {
			ans++;
		}
		r++;
	}
	cout << ans;
}