#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct cell {
    struct cell *next;
    int data;
} cell_t;

static cell_t *alloc_list(int data);
static void add(cell_t *header, int data);
static void delete(cell_t *header);

cell_t *alloc_list(int data)
{
    cell_t *new = NULL;
    new = (cell_t *)malloc(sizeof(cell_t));
    if (new == NULL) {
        fprintf(stderr, "ERROR: alloc_list(): %s\n", strerror(errno));
        return NULL;
    }
    new->next = NULL;
    new->data = data;
    return new;
}

void add(cell_t *header, int data)
{
    cell_t *next = NULL;
    cell_t *prev = header;

    //create cell
    next = alloc_list(data);

    // add cell to the end
    while (prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = next;
}

void delete(cell_t *header)
{
    cell_t *tmp = header;
    cell_t *swap = NULL;
    while (tmp != NULL) {
        swap = tmp->next;
        free(tmp);
        tmp = swap;
    }
}

void print_list(cell_t *header)
{
    cell_t *p = header;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char* argv)
{
    int cnt = 0;
    cell_t *header = alloc_list(0);
    if (header == NULL) {
        return 1;
    }
    for (cnt = 1; cnt < 10; cnt++) {
        add(header, cnt);
    }
    print_list(header);
    delete(header);
    return(0);
}
