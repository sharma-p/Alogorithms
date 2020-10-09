#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
					arr[i] = rand() % n;
				else
					arr[i] = i;
			}
			clock_t start, end;
			start = clock();
			quickSort(arr, 0, n - 1);
			end = clock();
			double duration = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken for " << size[j] << " elements is : " << duration << "\n";
		}
	}
	return 0;
}
