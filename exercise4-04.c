#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>

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

void printp(void);

void copyp(void);

void changep(void);

void cleanp(void);

int getch(void);

void ungetch(int);

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
		case '\n':
			printp();
			printf(" ");
			changep();
			printp();
			printf(" ");
			printf("%g ", pop());
			printp();
			printf(" ");
			copyp();
			printf("%g ", pop());
			printf("%g ", pop());
			printf("%g ", pop());
			cleanp();
			printp();
			printf(" ");
			break;
		}
	}
	return 0;
}

int getop(char s[]) {
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
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

void printp(void) {
	if (sp > 0)
		printf("%g", val[sp - 1]);
	else
		printf("error: stack empty\n");
}

void copyp(void) {
	if (sp > 0) {
		val[sp] = val[sp - 1];
		sp++;
	}
	else
		printf("error: stack empty\n");
}

void changep(void) {
	int c;
	if (--sp > 0) {
		c = val[sp];
		val[sp] = val[sp - 1];
		val[sp - 1] = c;
		sp++;
	}
}

void cleanp(void) {
	while (sp > 0) {
		val[--sp] = '\0';
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