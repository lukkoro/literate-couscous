#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFF_SIZE 30+1

typedef struct list_st {
    double value;
    struct list_st *next;
} LIST;

void init_list(LIST **);
void add_to_list(LIST *, LIST **);
void push(LIST **, double);
double pop(LIST **);
double calc(FILE *, LIST **);
FILE *safe_fopen(char *, char *, int);
LIST *create_new_item(double );

int main(int arg_num, char *args[]) {
    if(arg_num != 2) {
        printf("Too many or too few arguments! Right usage: %s inputfile.txt\n", args[0]);
        exit(-1);
    }

    LIST *head;
    init_list(&head);

    char *filename = args[1];
    FILE *input_file = safe_fopen(filename, "r", -2);

    printf("Result: %lf\n", calc(input_file, &head));

}

void init_list(LIST **head) {
    *head = NULL;
}

FILE *safe_fopen(char *filename, char *mode, int error_code) {
    FILE *fp = fopen(filename, mode);
    
    if(fp == NULL) {
        printf("Couldn't open the file, or it doesn't exist!");
        exit(error_code);
    }

    return fp;
}

LIST *create_new_item(double val) {
    LIST *new =(LIST *)malloc(sizeof(LIST));
    if(new == NULL) {
        printf("Not enough RAM!");
        exit(-3);
    }

    new->value = val;
    new->next = NULL;

    return new;
}

void add_to_list(LIST *new, LIST **head) {
    if(*head == NULL) {
        *head = new;
    }
    else {
        new->next = *head;
        *head = new;
    }
}

void push(LIST **head, double val) {
    LIST *new = create_new_item(val);
    add_to_list(new, head);
}

double pop(LIST **head) {
    if(*head == NULL) {
        printf("Tried to pop an empty stack!");
        exit(-4);
    }

    LIST *first = *head;
    double val = first->value;

    *head = first->next;
    free(first);

    return val;

}

double calc(FILE *input_file, LIST **head) {
    char ch;
    while((ch = getc(input_file)) != EOF && ch != '\n') {
        if(ch >= '0' && ch <= '9') {
            float val = ch - 48;
            push(head, val);
        }
        else if(ch != ' ') {
            char operator = ch;
            double op2 = pop(head);
            double op1 = pop(head);

            double result;
            switch(operator) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default: printf("Unknown operator '%c'\n!", ch); exit(-5);
            }
            push(head, result);
        }
    }

    return pop(head);
}