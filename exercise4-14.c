#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>

#define swap(t,x,y)	{t c;c=x;x=y;y=c;}

#define MAXOP 1000
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int getline(char[]);

void push(double);

double pop(void);

int main() {
	int lengthe;
	int i, j;
	int num1, num2;
	double op1, op2;
	char s[MAXOP], numb[MAXVAL];
	while ((lengthe = getline(s)) > 0) {
		for (i = 0; i < lengthe; i++) {
			if (s[i] == ' ' || s[i] == '\t')
				continue;
			else if (s[i] == '\n') {
				op2 = pop();
				op1 = pop();
				num1 = op1;
				num2 = op2;
				swap(int, num1, num2);
				swap(double, op1, op2);
				printf("%d		%d\n", num1, num2);
				printf("%.6lf	%.6lf\n", op1, op2);

			}
			else if (s[i] == '.') {
				j = 0;
				numb[j++] = '.';
				while (isdigit(s[++i]))
					numb[j++] = s[i];
				numb[j] = '\0';
				push(atof(numb));
				i--;
			}
			else if (isdigit(s[i])) {
				j = 0;
				numb[j++] = s[i];
				while (isdigit(s[++i]))
					numb[j++] = s[i];
				if (s[i] == '.') {
					numb[j++] = '.';
					while (isdigit(s[++i]))
						numb[j++] = s[i];
				}
				numb[j] = '\0';
				push(atof(numb));
				i--;
			}
			else
				printf("error: unknown command %s\n", s);
		}
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

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}