#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int L, R, C;
int dir[6][3] = { {0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1} };
char board[35][35][35];
int dist[35][35][35];
int cnt = 0;
struct Pos {
	int l, r, c;
};
queue<Pos> q;
Pos st = { 0,0,0 };
Pos e = { 0,0,0 };
void bfs() {
	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		if (cur.l == e.l && cur.r == e.r && cur.c == e.c) {
			cout << "Escaped in " << dist[e.l][e.r][e.c] << " minute(s)."<<endl;
			return;
		}
		for (int i = 0; i < 6; i++) {
			int newL = cur.l + dir[i][0];
			int newR = cur.r + dir[i][1];
			int newC = cur.c + dir[i][2];
			if (newL < 0 || newL >= L || newR < 0 || newR >= R || newC < 0 || newC >= C || board[newL][newR][newC] == '#') continue;
			if ((board[newL][newR][newC] == '.' && dist[newL][newR][newC] == 0) || (board[newL][newR][newC] == 'E'&&dist[newL][newR][newC] == 0)) {
				q.push({ newL,newR,newC });
				//board[newL][newR][newC] = board[cur.l][cur.r][cur.c] + 1;
				dist[newL][newR][newC] = dist[cur.l][cur.r][cur.c] + 1;
			}

		}
	}
	cout << "Trapped!" << endl;
}

int main() {
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) return 0;
		while (!q.empty()) q.pop();
		memset(board, 0, sizeof(board));
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					char n; cin >> n;
					board[i][j][k] = n;
					if (n == 'S') {
						st = { i,j,k };
						q.push(st);
						dist[i][j][k] = 0;
					}
					else if (n == 'E') {
						e = { i,j,k };
					}
				}
			}
		}
		bfs();
	}
}