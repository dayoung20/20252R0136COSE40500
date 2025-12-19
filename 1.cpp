#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
// #include <bits/stdc++.h>
using namespace std;
int N, K;
int cnt = 0;
int maxWords = 0;
bool arr[26];
int teachAlphabet[26]; // antic 를 제외하고 가르쳐야하는 알파벳의 인덱스
bool visited[26] = { false };
bool sel[26] = { false };
int ans[26]; // 가능한 조합 찾기 (0,1,2,3,...) teachAlphabet의 인덱스
string words[55];
int total() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 4; j < words[i].length() - 4; j++) {
			if (!sel[words[i][j] - 'a']) {
				sum++;
				break;
			}
		}
	}
	return N - sum;
}
void dfs(int preNo, int depth) {
	if (depth == K - 5) {
		/*for (int i = 0; i < depth; i++) {
			cout << ans[i] << " ";
		}*/ // 여기까지 알파벳 조합 선택 완료
		memset(sel, false, sizeof(sel));
		sel['a' - 'a'] = true;
		sel['t' - 'a'] = true;
		sel['i' - 'a'] = true;
		sel['c' - 'a'] = true;
		sel['n' - 'a'] = true;
		//여기서 가르치는 알파벳 개수
		for (int i = 0; i < depth; i++) {
			sel[teachAlphabet[ans[i]]] = true;
			//cout << teachAlphabet[ans[i]] << " ";
		}
		int temp = total();
		if (maxWords < temp) {
			maxWords = temp;
		}
		//cout << endl;
		return;
	}
	for (int i = preNo; i < cnt; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[depth] = i;
			dfs(i, depth + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		for (int j = 0; j < words[i].length(); j++) {
			arr[words[i][j] - 'a'] = true;
		}
	}
	/*for (int i = 0; i < 26; i++) {
		if (arr[i]) {
			cout << i << " ";
		}
	}
	cout << endl;*/
	arr['a' - 'a'] = false; //이거 할필요 없이 문자열의 앞뒤 4개는 for문에서 거르기
	arr['t' - 'a'] = false;
	arr['i' - 'a'] = false;
	arr['c' - 'a'] = false;
	arr['n' - 'a'] = false;
	cnt = 0; // 5개를 제외하고 가르쳐야하는 알파벳의 개수
	for (int i = 0; i < 26; i++) {
		if (arr[i]) {
			teachAlphabet[cnt] = i;
			cnt++;
		}
	}
	/*cout << "dfdfd";
	for (int i = 0; i < cnt; i++) {
		cout << teachAlphabet[i] << " "; // teachAlphabet에 5개의 알파벳을 제외한 나머지 알파벳
	}*/
	//cout << endl;
	if (K < 5) {
		cout << "0" << endl;
		return 0;
	}
	if (cnt + 5 < K) {
		cout << N;
		return 0;
	}
	dfs(0, 0);
	cout << maxWords;
}