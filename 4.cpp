#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int V, E;
vector<int> adjacentLst[20005];
bool visited[20005]; // 방문 여부
bool colorLst[20005]; // 색
bool dfs(int idx, int depth) {
	if (depth > V) return true;
	bool color = colorLst[idx];
	for (int i = 0;i < adjacentLst[idx].size();i++) {
		if (visited[adjacentLst[idx][i]]) {
			if (colorLst[adjacentLst[idx][i]] == color) return false;
			continue;
		}
		visited[adjacentLst[idx][i]] = true;
		colorLst[adjacentLst[idx][i]] = !color;
		//cout << adjacentLst[idx][i] << " color:" << colorLst[adjacentLst[idx][i]] << endl;
		if(!dfs(adjacentLst[idx][i], depth + 1)) return false;
	}
	return true;
}
int main() {
	int caseCnt; cin >> caseCnt;
	for (int i = 0;i < caseCnt;i++) {
		cin >> V >> E; // 정점, 간선의 개수 
		for (int i = 1;i <= V;i++) adjacentLst[i].clear();
		for (int i = 0;i < E;i++) {
			int u, v; cin >> u >> v;
			adjacentLst[u].push_back(v);
			adjacentLst[v].push_back(u);
		}
		bool result = true;
		memset(visited, false, sizeof(visited));
		memset(colorLst, false, sizeof(colorLst));
		for (int i = 1;i <= V;i++) {
			if (visited[i]) continue;
			visited[i] = true;
			if (dfs(i, 1)) continue;
			else {
				cout << "NO" << endl;
				result = false;
				break;
			}
		}
		if(result) {
			cout << "YES" << endl;
		}
	}
	return 0;
}

//1
//5 4
//1 2
//3 4
//3 5
//4 5