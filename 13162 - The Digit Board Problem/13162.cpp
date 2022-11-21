#include<iostream>
#include<sstream>
using namespace std;
int main(void) {
	stringstream ss;
	int T, L, R, id, num;
	cin >> T;
	while (T--) {
		cin >> L >> R;
		getchar();
		int *arr = new int[L]();
		while (R--) {
			string s;
			getline(cin, s);
			ss.str("");
			ss.clear();
			ss << s;
			ss >> id;
			while (ss >> num)
				arr[id] += num;
		}
		long long ans = 0;
		for (int i = 0; i < L; i++)
			ans = ans * 10 + arr[i];
		cout << ans << '\n';
		delete[]arr;
	}
	return 0;
}