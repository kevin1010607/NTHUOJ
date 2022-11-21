#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;
int **s;
bool **used;
int cnt = INF;
void solve(int x, int y, int m, int n, int sum) {
	if (s[x][y] == -1 || sum > cnt) return;
	bool end = true;
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
	used[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n || used[nx][ny] || s[nx][ny] == 0) continue;
		end = false;
		solve(nx, ny, m, n, sum + s[nx][ny]);
	}
	used[x][y] = false;
	if (end) cnt = sum;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n, startX, startY;
	cin >> m >> n;
	s = new int*[m];
	used = new bool*[m];
	for (int i = 0; i < m; i++) {
		s[i] = new int[n];
		used[i] = new bool[n]();
	}
	cin >> startY >> startX;
	for (int i = 0; i < m; i++)
		for (int j = 0, tmp; j < n; j++)
			cin >> s[i][j];
	solve(startX, startY, m, n, s[startX][startY]);
	cout << cnt << '\n';
	for (int i = 0; i < m; i++) {
		delete[]s[i];
		delete[]used[i];
	}
	delete[]s;
	delete[]used;
	return 0;
}