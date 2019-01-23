#include <stdio.h>
#include <string.h>

int input(char line[]);

int escape(char s[], char t[], int n);

int main() {
	int n;
	char t[2000] = { " " }, s[2000] = { " " };
	while ((n = input(t)) > 0) {
		escape(s, t, n);
		printf("%s", s);
		memset(t, '\0', sizeof(t));
		memset(s, '\0', sizeof(s));
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

int escape(char s[], char t[], int n) {
	int i, j;
	for (i = 0, j = 0; i < n; i++) {
		switch (t[i]) {
		case '\n':
			s[j] = '\\';
			s[j + 1] = 'n';
			j = j + 2;
			break;
		case'\t':
			s[j] = '\\';
			s[j + 1] = 't';
			j = j + 2;
			break;
		default:
			s[j] = t[i];
			j = j + 1;
			break;
		}
	}
	return 0;
}