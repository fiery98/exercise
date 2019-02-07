#include <stdio.h>
#include <string.h>

#define LENGTHE 100

int getline(char[]);

void reverse(char[]);

int main() {
	int n;
	char s[LENGTHE] = " ";
	while ((n = getline(s)) > 0) {
		reverse(s);
		putchar('\n');
	}
	return 0;
}

int getline(char s[]) {
	int a, i;
	for (i = 0; (a = getchar()) != 'EOF' && a != '\n'&&i < 1999; i++)
		s[i] = a;
	if (a == '\n') {
		s[i] = a;
		i++;
	}
	return i;
}

void reverse(char s[]) {
	int c, i, lengthe;
	if ((c = s[0]) != '\0'&&c != '\n') {
		lengthe = strlen(s);
		for (i = 0; i < lengthe; i++)
			s[i] = s[i + 1];
		reverse(s);
		putchar(c);
	}
}