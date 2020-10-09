#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n) {
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(arr[min_idx], arr[i]);
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
			selectionSort(arr, n);
			end = clock();
			double duration = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken for " << size[j] << " elements is : " << duration << "\n";
		}
	}
	return 0;
}
