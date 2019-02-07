#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100 
#define NUMBER '0'

int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFSIZE];

int getop(char[]);

void push(double);

double pop(void);

int getch(void);

void ungetch(int);

int math(char);

int main() {
	int type;
	int num;
	double op1, op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			op1 = pop();
			num = op1 / op2;
			if (op2 != 0.0)
				push(op1 - num * op2);
			else
				printf("error: zero complementation\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case 'sin':
			push(sin(pop()));
			break;
		case 'cos':
			push(cos(pop()));
			break;
		case 'tan':
			push(tan(pop()));
			break;
		case 'asin':
			op1 = pop();
			if (op1 >= -1 && op1 <= 1)
				push(asin(op1));
			else
				printf("error: domain error\n");
			break;
		case 'acos':
			op1 = pop();
			if (op1 >= -1 && op1 <= 1)
				push(acos(op1));
			else
				printf("error: domain error\n");
			break;
		case 'atan':
			push(atan(pop()));
			break;
		case 'sinh':
			push(sinh(pop()));
			break;
		case 'cosh':
			push(cosh(pop()));
			break;
		case 'tanh':
			push(tanh(pop()));
			break;
		case 'exp':
			push(exp(pop()));
			break;
		case 'log':
			push(log(pop()));
			break;
		case 'pow':
			op2 = pop();
			op1 = pop();
			if (op1 == 0 && op2 <= 0)
				printf("error: domain error\n");
			else if (op1 < 0) {
				if ((num = op2) == op2)
					push(pow(op1, num));
				else
					printf("error: domain error\n");
			}
			else
				push(pow(op1, op2));
			break;
		case 'sqrt':
			op1 = pop();
			if (op1 >= 0)
				push(sqrt(op1));
			else
				printf("error: domain error\n");
			break;
		case 'fabs':
			push(fabs(pop()));
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int getop(char s[]) {
	int i, c, m;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		if ((m = math(c)) == 0)
			return c;
		else
			return m;
	}
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
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

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int math(char s) {
	int a, b, c;
	if (s != '\n') {
		if ((a = getch()) != '\n') {
			if ((b = getch()) != '\n') {
				if (s == 's'&&a == 'i'&&b == 'n')
					return 'sin';
				else if (s == 'c'&&a == 'o'&&b == 's')
					return 'cos';
				else if (s == 't'&&a == 'a'&&b == 'n')
					return 'tan';
				else if (s == 'e'&&a == 'x'&&b == 'p')
					return 'exp';
				else if (s == 'p'&&a == 'o'&&b == 'w')
					return 'pow';
				else if (s == 'l'&&a == 'o'&&b == 'g')
					return 'log';
				else if ((c = getch()) != '\n') {
					if (s == 'a') {
						if (a == 's'&&b == 'i'&&c == 'n')
							return 'asin';
						else if (a == 'c'&&b == 'o'&&c == 's')
							return 'acos';
						else if (a == 't'&&b == 'a'&&c == 'n')
							return 'atan';
					}
					else if (s == 's'&&a == 'i'&&b == 'n'&&c == 'h')
						return 'sinh';
					else if (s == 'c'&&a == 'o'&&b == 's'&&c == 'h')
						return 'cosh';
					else if (s == 't'&&a == 'a'&&b == 'n'&&c == 'h')
						return 'tanh';
					else if (s == 's'&&a == 'q'&&b == 'r'&&c == 't')
						return 'sqrt';
					else if (s == 'f'&&a == 'a'&&b == 'b'&&c == 's')
						return 'fabs';
				}
				ungetch(c);
			}
			ungetch(b);
		}
		ungetch(a);
	}
	return 0;
}