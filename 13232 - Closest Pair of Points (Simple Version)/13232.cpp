#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
void swap(int *a, int *b) { int tmp = *a; *a = *b; *b = tmp; }
void QuickSort(int arr[], int l, int r) {
	if (l >= r) return;
	int i = l, j = r;
	int pivot = arr[l];
	while (i != j) {
		while (arr[j] > pivot && i < j) j--;
		while (arr[i] <= pivot && i < j) i++;
		if (i < j) swap(&arr[i], &arr[j]);
	}
	swap(&arr[l], &arr[i]);
	QuickSort(arr, l, i - 1);
	QuickSort(arr, i + 1, r);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, *x, *y, tmpX, tmpY, idx1 = 0, idx2 = 0;
		cin >> n;
		x = new int[n];
		y = new int[n];
		for (int i = 0; i < 2 * n; i++) {
			cin >> tmpX >> tmpY;
			if (tmpX == 0) y[idx2++] = tmpY > 0 ? tmpY : -tmpY;
			if (tmpY == 0) x[idx1++] = tmpX > 0 ? tmpX : -tmpX;
		}
		QuickSort(x, 0, n - 1);
		QuickSort(y, 0, n - 1);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sqrt((long long)x[i] * x[i] + (long long)y[i] * y[i]);
		}
		cout << fixed << setprecision(8) << ans << '\n';
		delete[]x;
		delete[]y;
	}
	return 0;
}