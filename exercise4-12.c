#include <stdio.h>
#include <string.h>

void itoa(int);

int main() {
	int n;
	char s[1000]=" ";
	scanf("%d%*c", &n);
	itoa(n);
	while (s[0] != '\0') {
		printf("%s\n", s);
		scanf("%d%*c", &n);
		itoa(n);
	}
	return 0;
}

void itoa(int n) {
	int i, sign;
	unsigned int m;
	if ((sign = n) < 0) {
		putchar('-');
		m = -n;
	}
	else
		m = n;
	i = 0;
	if (n / 10)
		itoa(n / 10);
	putchar(n % 10 + '0');
}