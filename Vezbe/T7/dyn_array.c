#include <stdio.h>
#include <stdlib.h>

struct dynamic_array_st {
	int *parray;
	int filled;
	int capacity;
};

void init_array(struct dynamic_array_st *);
void resize_array(struct dynamic_array_st *);
void add(struct dynamic_array_st *, int );
void print_array(struct dynamic_array_st );
int size(struct dynamic_array_st);
void destroy_array(struct dynamic_array_st *);
void remove(struct dynamic_array_st *, int);

int main() {
	struct dynamic_array_st d;
	
	init_array(&d);

	add(&d, 1);
	add(&d, 2);
	add(&d, 3);

    print_array(d);
    printf("Array size: %d\n", size(d));

    add(&d, 6);
    print_array(d);
    printf("Array size: %d\n", size(d));

    add(&d, 5);
    print_array(d);
    printf("Array size: %d\n", size(d));

    add(&d, 5);
    print_array(d);
    printf("Array size: %d\n", size(d));

    destroy_array(&d);
    print_array(d);
    printf("Array size %d\n", size(d));

    getchar();
	return 0;
}

void init_array(struct dynamic_array_st *pd) {
	pd->parray = NULL;
	pd->capacity = 0;
	pd->filled = 0;
}

void resize_array(struct dynamic_array_st *pd) {
	if (pd->parray == NULL) {
		pd->capacity = 1;
	}
	else {
		pd->capacity *= 2;
	}

	pd->parray = realloc(pd->parray, pd->capacity * sizeof(int));
}

void add(struct dynamic_array_st *pd, int val) {
	if (pd->filled == pd->capacity) {
		resize_array(pd);
	}

	pd->parray[pd->filled] = val;
	pd->filled++;
}

void print_array(struct dynamic_array_st pd) {
    printf("[ ");
    for(int i = 0; i < pd.filled; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", pd.parray[i]);
    }
    printf(" ]\n");
}

int size(struct dynamic_array_st pd) {
    return pd.capacity;
}

void destroy_array(struct dynamic_array_st *d) {
    free(d->parray);
    init_array(d);
}