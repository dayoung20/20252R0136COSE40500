#include <iostream>
using namespace std;
int N,M;
int r[1000001];
int grp(int k) {
	if (r[k]==k) return k;
	return r[k] = grp(r[k]);
}
void join(int a, int b) {
	int A = grp(a);
	int B = grp(b);
	r[B] = A;
}
int main() {
	int c, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++) r[i] = i;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &c, &a, &b);
		if (c) {
			if (grp(a) == grp(b)) puts("YES\n");
			else puts("NO\n");
		}
		else join(a, b);
	}
	return 0;
}