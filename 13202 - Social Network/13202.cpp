#include<iostream>
#include<iomanip>
#define INF 0x3f3f3f3f
using namespace std;
int D[105][105], P[105][105];
double C[105];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			P[i][j] = j;
			cin >> D[i][j];
			if (D[i][j] == 0) D[i][j] = INF;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
				else if (D[i][k] + D[k][j] == D[i][j] && P[i][k] < P[i][j]) {
					P[i][j] = P[i][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (D[i][j] == INF) continue;
			cout << "Path(" << i << "," << j << "):" << i;
			int pos = P[i][j];
			while (pos != j) {
				cout << "->" << pos;
				pos = P[pos][j];
			}
			cout << "->" << j << '\n';
			cout << "Difficulty:" << D[i][j] << '\n';
			C[j] += 1.0 / D[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "Centrality(" << i << "):" << fixed << setprecision(3) << C[i] << '\n';
	}
	return 0;
}