#include <stdio.h>
#include <ctype.h>

int getline(char line[], int max);

double atof(char s[]);

int main() {
	int n, b;
	char line[1000];
	while (getline(line, 1000) > 0)
		printf("%lf\n", atof(line));
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

double atof(char s[]) {
	double val, power, number;
	int sign, i;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-' ? -1 : 1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0*val + s[i] - '0';
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0*val + s[i] - '0';
		power *= 10;
	}
	if (s[i] == 'e')
		i++;
	if (s[i] == '-') {
		i++;
		for (number = 0.0; isdigit(s[i]); i++)
			number = 10.0*number + s[i] - '0';
		for (number; number > 0; number--)
			power *= 10;
	}
	else {
		for (number = 0.0; isdigit(s[i]); i++)
			number = 10.0*number + s[i] - '0';
		for (number; number > 0; number--)
			power /= 10;
	}
	return sign * val / power;
}