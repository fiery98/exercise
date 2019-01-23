#include <stdio.h>
#include <string.h>

int input(char line[]);

int rank(char v[], int n);

int binsearch(int x, char v[], int n);

int main() {
	int n, x, a;
	char v[2000] = { " " };
	while ((n = input(v)) > 0) {
		rank(v, n);
		x = getchar();
		a = binsearch(x, v, n);
		printf("%d", a);
		memset(v, '\0', sizeof(v));
	}
	return 0;
}

int input(char line[]) {
	int a, i;
	for (i = 0; (a = getchar()) != EOF && a != '\n'&&i < 999; i++)
		line[i] = a;
	if (a == '\n') {
		line[i] = a;
		i++;
	}
	return i;
}

int rank(char v[], int n) {
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n - 1; j++) {
			if (v[j] > v[j + 1]) {
				k = v[j];
				v[j] = v[j + 1];
				v[j + 1] = k;
			}
		}
	return 0;
}

int binsearch(int x, char v[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && v[mid] != x) {
		if (x < v[mid])
			high = mid + 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (v[mid] == x)
		return mid;
	else
		return -1;
}