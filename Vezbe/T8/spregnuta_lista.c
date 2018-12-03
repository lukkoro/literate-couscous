#include <stdio.h>
#include <stdlib.h>


typedef struct list_st {
    char ch;
    struct list_st *pnext;
} LIST;

void init_list(struct list_st **);
LIST *create_new_item(char);
void add_to_list(LIST *, LIST **);
void read_char(LIST **);
void print_list(LIST *);
void sort_list(LIST **);
void replace_char(LIST **, char, char);
int find_char(LIST *, char);

int main() {
    struct list_st *head;

    init_list(&head);
    for(int i = 0; i < 10; i++) {
        read_char(&head);
    }

    print_list(head);
    printf("\n");
    sort_list(&head);
    print_list(head);
    printf("\n");
    replace_char(&head, 'a', 'b');
    print_list(head);
    printf("\n");
    int idx = find_char(head, 'b');
    if(idx >= 0) {
        printf("Index of the element searched for is %d.\n", idx);
    }
}

void init_list(struct list_st **head) {
    *head = NULL;
}

LIST *create_new_item(char ch) {
    LIST *new = malloc(sizeof(struct list_st));
    if(new == NULL) {
        printf("Not enough RAM!\n");
        exit(-4);
    }

    new->ch = ch;
    new->pnext = NULL;

    return new;
}

void add_to_list(LIST *new, LIST **head) {
    if(*head == NULL) {
        *head = new;
    }
    else {
        LIST *temp;
        temp = *head;

        while((*head)->pnext != NULL) {
            *head = (*head)->pnext;
        }

        (*head)->pnext = new;
        *head = temp;
    }
}

void read_char(LIST **head) {
    printf("Enter a character: ");

    char ch;
    do {
        scanf("%c", &ch);
    } while(!(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'));

    LIST *new;
    new = create_new_item(ch);
    add_to_list(new, head);
}

void print_list(LIST *head) {
    
    if(head == NULL) {
        return;
    }

    printf("%c ", head->ch);

    print_list(head->pnext);
}

void sort_list(LIST **head) {
    LIST *i, *j;
    char temp;

    for(i = *head; i->pnext != NULL; i = i->pnext) {
        for(j = i->pnext; j != NULL; j = j->pnext) {
            if(i->ch > j->ch) {
                temp = i->ch;
                i->ch = j->ch;
                j->ch = temp;
            }
        }
    }
}

void replace_char(LIST **head, char orig, char ch) {
    LIST *curr;
    curr = *head;
    while(curr != NULL) {
        if(curr->ch == orig) {
            curr->ch = ch;
        }
        curr = curr->pnext;
    }
}

int find_char(LIST *head, char ch) {
    LIST *curr = head;
    int i = 0;
    while(curr != NULL) {
        if(curr->ch == ch) {
            return i;
        }
        i++;
        curr = curr->pnext;
    }

    return -1;
}