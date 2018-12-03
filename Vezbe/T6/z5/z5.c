#include <stdio.h>
#include <stdlib.h>
#define MAX_INDEX 10+1
#define MAX_IME 20+1
#define MAX_STUDENT 180

typedef struct student {
	char brIndex[MAX_INDEX];
	char ime[MAX_IME];
    char prezime[MAX_IME];
	int ocena;
} STUDENT;

FILE *safe_fopen(char filename[], char mode[], int n);
int readfile(FILE *, STUDENT *);
void makefile(STUDENT *, int);

int main(int argNum, char *arg[]) {
	if (argNum < 2) {
		printf("Program ima premalo argumenata. Pravilno koriscenje programa: ./z1 ulazna_datoteka.txt");
		exit(1);
	}
	else if (argNum > 2) {
		printf("Program ima previse argumenata. Pravilno koriscenje programa: ./z1 ulazna_datoteka.txt");
		exit(2);
	}

	char *finputName = arg[1];
	FILE *input = fopen(finputName, "r");
	STUDENT st[MAX_STUDENT];
	int brStudenata;
	brStudenata = readfile(input, st);
	makefile(st, brStudenata);


	return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code) {
	FILE *fp = fopen(filename, mode);

	if (fp == NULL) {
		printf("Can't open %s!", filename);
		exit(error_code);
	}

	return fp;
}

int readfile(FILE *input, STUDENT *st) {
	int lineCount = 0;
	char ch;
	while ((ch = getc(input)) != EOF) {
		if (ch == '\n') {
			lineCount++;
		}
	}
	fseek(input, 0, 0);

	int i;
	for (i = 0; i < lineCount; i++) {
		fscanf(input, "%s %s %s %d", st[i].brIndex, st[i].ime, st[i].prezime, &st[i].ocena);
	}

	return lineCount;
}

void makefile(STUDENT *st, int n) {
	int i;
	int high = st[0].ocena;
	int low = st[0].ocena;
	int maxIdx, minIdx;
	float sum = 0;
	for (i = 0; i < n; i++) {
		sum += st[i].ocena;
		if (st[i].ocena > high) {
			maxIdx = i;
			high = st[i].ocena;
		}
		else if (st[i].ocena < low) {
			minIdx = i;
			low = st[i].ocena;
		}
	}
	float avg = sum / n;
	printf("Prosecna ocena svih studenata je %f", avg);
	FILE *najvisi = fopen("najvisi.txt", "w");
	FILE *najnizi = fopen("najnizi.txt", "w");
	fprintf(najvisi, "%s %s %s %d", st[maxIdx].brIndex, st[maxIdx].ime, st[maxIdx].prezime, st[maxIdx].ocena);
	fprintf(najnizi, "%s %s %s %d", st[minIdx].brIndex, st[minIdx].ime, st[minIdx].prezime, st[minIdx].ocena);

	fclose(najvisi);
	fclose(najnizi);
}