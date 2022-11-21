#include<iostream>
#define INF 0x3f3f3f3f
#define min(a,b) a<b?a:b
using namespace std;
int D[105][105];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> D[i][j];
				if (D[i][j] == 0) D[i][j] = INF;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
		cout << "Testcase" << t << '\n';
		for (int i = 0; i < q; i++) {
			int a, b;
			cin >> a >> b;
			cout << "Cost(" << a << "," << b << "):";
			if (D[a][b] != INF) cout << D[a][b] << '\n';
			else cout << "No Service\n";
		}
	}
	return 0;
}