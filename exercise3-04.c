#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);

void change(char s[]);

int main() {
	int n;
	char s[1000];
	scanf("%d%*c", &n);
	itoa(n, s);
	while (s[0] != '\0') {
		printf("%s\n", s);
		scanf("%d%*c", &n);
		itoa(n, s);
	}
	return 0;
}

void itoa(int n, char s[]) {
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