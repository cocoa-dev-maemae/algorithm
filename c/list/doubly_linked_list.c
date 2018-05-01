#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct cell_t {
    struct cell_t *next;
    struct cell_t *prev;
    int data;
} cell_t;

static cell_t *create_cell(int data);
static void insert(cell_t *header, int data);
static void delete(cell_t *header);
static void print_list(cell_t *header);
static void print_list_reverse(cell_t *header);

cell_t *create_cell(int data)
{
    cell_t *new = NULL;
    new = (cell_t *)malloc(sizeof(cell_t));
    if (new == NULL) {
        fprintf(stderr, "ERROR: create_cell(): %s\n", strerror(errno)); 
        return NULL;
    }
    new->next = NULL;
    new->prev = NULL;
    new->data = data;
    return new;
}

void insert(cell_t *header, int data)
{
    cell_t *next = NULL;
    cell_t *prev = header;

    //create cell
    next = create_cell(data);

    // cell to end
    while (prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = next;
    prev->prev = prev;
}

void delete(cell_t *header)
{

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

void print_list_reverse(cell_t *header)
{
    cell_t *p = header;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main(void)
{
    int cnt = 0;
    cell_t *header = create_cell(0);
    if (header == NULL) {
        return 1;
    }
    for (cnt = 1; cnt < 10; cnt++) {
        insert(header, cnt);
    }
    print_list(header);
    print_list_reverse(header);
    delete(header);

    return 0;
}
