#include"function.h"
#include<iostream>
template < class T > 
void swap(T *a, T *b) { T tmp = *a; *a = *b; *b = tmp;}
int *gem, *hand;

// TODO: Implement the sorting algorithm
template < class T >
void mysort(T arr[], int l, int r) {
	if (l >= r) return;
	int i = l, j = r;
	T pivot = arr[l];
	while (i != j) {
		while (arr[j] > pivot && i < j) j--;
		while (arr[i] <= pivot && i < j) i++;
		if (i < j) { swap(&arr[i], &arr[j]), swap(&hand[i], &hand[j]); }
	}
	swap(&arr[l], &arr[i]), swap(&hand[l], &hand[i]);
	mysort(arr, l, i - 1);
	mysort(arr, i + 1, r);
}

// TODO: Implement the funtion to read input, process data, and output answers.
void solve() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	// Sort glove by gem
	int n, l, r, c;
	std::cin >> n >> l >> r >> c;
	gem = new int[n];
	hand = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> gem[i];
		hand[i] = (i < l ? 0 : 1);
	}
	mysort(gem, 0, n - 1);
	// Remove pairs, negative means left, positive means right
	int id = 0, prev = gem[0];
	int *num = new int[n]();
	for (int i = 0; i < n; i++) {
		if (gem[i] != prev) { id++; prev = gem[i]; }
		num[id] += (hand[i] == 0 ? -1 : 1);
	}
	id++;
	delete[]gem;
	delete[]hand;
	// Separate L and R from num, glove[0] means L, glove[1] means R
	int idx[2] = { 0, 0 };
	int total[2] = { 0, 0 };
	int **glove = new int*[2];
	glove[0] = new int[id];
	glove[1] = new int[id];
	for (int i = 0; i < id; i++) {
		if (num[i] == 0) continue;
		int pos = (num[i] < 0 ? 0 : 1);
		int val = (num[i] < 0 ? -num[i] : num[i]);
		glove[pos][idx[pos]++] = val;
		total[pos] += val;
	}
	delete[]num;
	// Decide which one is more
	int M = 0, m = 1;
	long long ans = 0;
	if (total[m] > total[M]) swap(&M, &m);
	// First, make every more one gloves are even number
	for (int i = 0; i < idx[M]; i++) {
		if (total[m] == 0) break;
		if (glove[M][i] % 2 == 1) {
			total[m]--;
			glove[M][i]--;
			ans++;
		}
	}
	// Second, make less one are 0
	for (int i = idx[M] - 1; i >= 0; i--) {
		if (glove[M][i] < total[m]) {
			total[m] -= glove[M][i];
			ans += glove[M][i];
			glove[M][i] = 0;
		}
		else if (glove[M][i] == total[m]) {
			ans += total[m];
			total[m] = glove[M][i] = 0;
			idx[M] = i;
			break;
		}
		else {
			glove[M][i] -= total[m];
			ans += total[m];
			total[m] = 0;
			idx[M] = i + 1;
			break;
		}
	}
	// Third, solve the remaing gloves
	for (int i = 0; i < idx[M]; i++) {
		ans += (glove[M][i] / 2 + glove[M][i] % 2);
	}
	ans *= c;
	std::cout << ans << '\n';
	delete[]glove[0];
	delete[]glove[1];
	delete[]glove;
}