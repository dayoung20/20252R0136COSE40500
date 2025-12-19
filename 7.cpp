#include <iostream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int L, C;
char arr[16];
bool visit[16];
char ans[16];
void dfs(int depth, int first, int second, int preIdx) {
	if (depth == L) {
		if (first > 0 && second > 1) {
			for (int i = 0; i < L; i++) {
				cout << ans[i];
			}
			cout << endl;
		}
		first = 0; second = 0;
	}
	for (int i = preIdx; i < C; i++) {
		if (!visit[i]) {
			ans[depth] = arr[i];
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				first++;
			}
			else {
				second++;
			}
			visit[i] = true;
			dfs(depth + 1, first, second, i);
			visit[i] = false;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				first--;
			}
			else {
				second--;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		arr[i] = c;
	}
	//입력받은애 -> 사전식으로 정렬, dfs에 넣기 (현재 인덱스보다 큰 애부터 N+M(2)문제처럼)
	sort(arr, arr + C);
	dfs(0, 0, 0, 0);
	return 0;
}