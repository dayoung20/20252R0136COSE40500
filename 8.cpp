#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int singer[1005];
vector<vector<int>> adjacentList;
queue<int> q;
vector<int> ans;
int inDegree[1005];
int main() {
	cin >> N >> M;
	adjacentList.resize(N + 1);
	memset(inDegree, 0, sizeof(inDegree));
	while (M--) {
		int p; cin >> p;
		for (int i = 1; i <= p; i++) cin>>singer[i];

		for (int i = 2; i <= p; i++) {
			adjacentList[singer[i - 1]].push_back(singer[i]);
			inDegree[singer[i]]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (inDegree[i]==0) q.push(i);
	}
	while (!q.empty()) {
		int val = q.front();
		q.pop();
		ans.push_back(val);
		for (int i = 0; i < adjacentList[val].size(); i++) {
			if (!--inDegree[adjacentList[val][i]]) q.push(adjacentList[val][i]);
		}
	}
	if (ans.size() != N) {
		cout << 0<<endl;
		return 0;
	} 
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}