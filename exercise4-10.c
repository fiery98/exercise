#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>

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
	int num;
	double op1, op2;
	char s[MAXOP], numb[MAXVAL];
	while ((lengthe = getline(s)) > 0) {
		for (i = 0; i < lengthe; i++) {
			if (s[i] == ' ' || s[i] == '\t')
				continue;
			else if (s[i] == '+')
				push(pop() + pop());
			else if (s[i] == '-') {
				op2 = pop();
				push(pop() - op2);
			}
			else if (s[i] == '*')
				push(pop() * pop());
			else if (s[i] == '/') {
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
			}
			else if (s[i] == '%') {
				op2 = pop();
				op1 = pop();
				num = op1 / op2;
				if (op2 != 0.0)
					push(op1 - num * op2);
				else
					printf("error: zero complementation\n");
			}
			else if (s[i] == '\n')
				printf("\t%.8g\n", pop());
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