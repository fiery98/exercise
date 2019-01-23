#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int b);

void change(char s[]);

void addspace(char s[], int b);

int main() {
	int n, b;
	char s[1000];
	scanf("%d%*c%d%*c", &n, &b);
	while (s[0] != '\0'&&b >= 0) {
		itoa(n, s, b);
		printf("%s\n", s);
		scanf("%d%*c%d%*c", &n, &b);
	}
	return 0;
}

void itoa(int n, char s[], int b) {
	int i, sign;
	unsigned int m;
	if ((sign = n) < 0)
		m = -n;
	else
		m = n;
	i = 0;
	do {
		s[i++] = m % 10 + '0';
	} while ((m /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	change(s);
	addspace(s, b);
}

void change(char s[]) {
	int a, n, i;
	n = strlen(s);
	for (i = 0; i < n / 2; i++) {
		a = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = a;
	}
}

void addspace(char s[], int b) {
	int a, n, i, j;
	n = strlen(s);
	if (n < b) {
		a = b - n;
		for (i = n; i >= 0; i--) {
			s[i + a] = s[i];
		}
		for (j = 0; j < a; j++) {
			s[j] = ' ';
		}
	}
}