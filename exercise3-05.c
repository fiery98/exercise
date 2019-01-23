#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);

void change(char s[]);

int main() {
	int n, b;
	char s[1000];
	scanf("%d%*c%d%*c", &n, &b);
	while (s[0] != '\0'&&b <= 36) {
		itob(n, s, b);
		printf("%s\n", s);
		scanf("%d%*c%d%*c", &n, &b);
	}
	return 0;
}

void itob(int n, char s[], int b) {
	int i, sign, number;
	unsigned int m;
	if ((sign = n) < 0)
		m = -n;
	else
		m = n;
	i = 0;
	do {
		number = m % b;
		if (number <= 9)
			s[i++] = number + '0';
		else if (number > 9 && number <= 36)
			s[i++] = number - 10 + 'a';
	} while ((m /= b) > 0);
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