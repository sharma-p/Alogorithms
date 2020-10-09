#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int main() {
	int size[] = {1000, 2000, 3000};
	string cases[] = {"Best", "Worst"};
	for (int u = 0; u < 2; u++) {
		cout << "For " << cases[u] << " Case\n";
		for (int j = 0; j < sizeof(size) / sizeof(int); j++) {
			int n = size[j];
			int arr[n];
			for (int i = 0; i < n; i++) {
				if (u == 0)
					arr[i] = i;
				else
					arr[i] = rand() % n;
			}
			clock_t start, end;
			start = clock();
			mergeSort(arr, 0, n - 1);
			end = clock();
			double duration = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken for " << size[j] << " elements is : " << duration << "\n";
		}
	}
	return 0;
}
