#include <stdio.h>

int getline(char line[], int max);

int strindex(char s[], char t[]);

int main() {
	int n, b;
	char line[1000], s[100];
	while (getline(line, 1000) > 0)
		if (getline(s, 100) > 0)
			printf("%d\n", strindex(line, s));
	return 0;
}

int getline(char s[], int max) {
	int c, i;
	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[]) {
	int i, j, k, location;
	location = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0'&&t[k] != '\n'&&s[j] == t[k]; j++, k++)
			;
		if (k > 0 && (t[k] == '\0' || t[k] == '\n'))
			location = i + 1;
	}
	return location;
}