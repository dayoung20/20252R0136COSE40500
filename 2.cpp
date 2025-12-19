//  최소힙, 최대힙
// 최대힙에 중간값 저장
// 가방에 담을 수 있는 보석을 우선순위 큐에 넣고 
// 가방을 순회하면서 가방에 담을 수 있는 애들을 순서대로 우선순위 큐에 넣기
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> valueP;
pair<int, int> types[300005]; // 무게, 가격
vector<int> bag;
int main() {
	long long sum = 0;
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		types[i] = { a,b };
	}
	for (int i = 0; i < K; i++) {
		int bagW; cin >> bagW;
		bag.push_back(bagW);
	}

	sort(bag.begin(), bag.end());
	sort(types, types + N);
	int j = 0;
	for (int i = 0; i < K; i++) { // 가방 돌면서
		for (; j < N; j++) { // 보석 돌면서 
			if (types[j].first <= bag[i]) {
				valueP.push(types[j].second);
			}
			else {
				break;
			}
		}
		if (!valueP.empty()) {
			sum += valueP.top();
			valueP.pop();
		}
	}
	cout << sum << endl;
}