#include <stdio.h>
#include <string.h>

int input(char line[]);

int expand(char s[], char t[], int n);

int main() {
	int n;
	char t[2000] = { " " }, s[2000] = { " " }, empty[2000] = { " " };
	while ((n = input(t)) > 0) {
		expand(s, t, n);
		printf("%s", s);
		memset(s, '\0', sizeof(s));
		memset(t, '\0', sizeof(t));
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

int expand(char s[], char t[], int n) {
	int i, j;
	int a, b;
	for (i = 0, j = 0; i < n; i++) {
		if (t[i] == '-'&&i != 0 && i < n - 1) {
			a = t[i - 1], b = t[i + 1];
			if (a >= 48 && a <= 57 && b >= 48 && b <= 57) {
				if (a == b);
				else if ((a - b) == 1 || (a - b) == -1);
				else if ((a - b) > 1) {
					do {
						a--;
						s[j] = a;
						j++;
					} while ((a - b) > 1);
				}
				else if ((a - b) < -1) {
					do {
						a++;
						s[j] = a;
						j++;
					} while ((a - b) < -1);
				}
			}
			else if (a >= 65 && a <= 90 && b >= 65 && b <= 90) {
				if (a == b);
				else if ((a - b) == 1 || (a - b) == -1);
				else if ((a - b) > 1) {
					do {
						a--;
						s[j] = a;
						j++;
					} while ((a - b) > 1);
				}
				else if ((a - b) < -1) {
					do {
						a++;
						s[j] = a;
						j++;
					} while ((a - b) < -1);
				}
			}
			else if (a >= 97 && a <= 122 && b >= 97 && b <= 122) {
				if (a == b);
				else if ((a - b) == 1 || (a - b) == -1);
				else if ((a - b) > 1) {
					do {
						a--;
						s[j] = a;
						j++;
					} while ((a - b) > 1);
				}
				else if ((a - b) < -1) {
					do {
						a++;
						s[j] = a;
						j++;
					} while ((a - b) < -1);
				}
			}
			else {
				s[j] = '-';
				j++;
			}
		}
		else {
			s[j] = t[i];
			j++;
		}
	}
	return 0;
}