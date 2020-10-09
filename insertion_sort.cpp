#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
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
					arr[i] = n - i;
			}
			clock_t start, end;
			start = clock();
			insertionSort(arr, n);
			end = clock();
			double duration = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken for " << size[j] << " elements is : " << duration << "\n";
		}
	}
	return 0;
}
