#include <iostream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int N;
int row[20];
int cnt = 0;
bool canGo(int c, int r) {
	for (int i = 0; i < c; i++) {
		if (row[i] == r)return false;
		// 대각선에 있으면 (너비 차이 == 높이 차이 (부호는 상관없이))
		if (abs(row[i] - r) == c - i) return false;
	}
	return true;
}
void dfs(int rowNo) {
	if (rowNo == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!canGo(rowNo, i)) continue;
		row[rowNo] = i;
		dfs(rowNo + 1);
	}
}

int main() {
	cin >> N;
	dfs(0);
	cout << cnt<<endl;
	return 0;
}