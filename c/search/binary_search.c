#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10

struct {
    int key;
    char *data;
} table[MAX_NUM];

static void set_data();
static char *binary_search(int key);

int main(int argc, char *argv[])
{
    set_data();

    char *tmp_key = argv[1];
    if (tmp_key == NULL || tmp_key == '\0') {
        printf("Specify index of data \n");
        return 0;
    }

    int key = atoi(tmp_key);
    char *result = binary_search(key);
    if (result != NULL && result != '\0') {
        printf("result: %c \n", result);
    } else {
        printf("No result \n");
    }
    return 0;
}

static void set_data()
{
    int i = 0;
    for (i; i < MAX_NUM; i++) {
        table[i].key = i;
        char *data = 'A' + i;
        table[i].data = data;
    }
}

/**
 * Simple binary search
 */
static char *binary_search(int key)
{
    int begin, mid, end;
    begin = 0;
    end = MAX_NUM - 1;

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (table[mid].key == key) {
            return table[mid].data;
        } else if (table[mid].key > key) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return NULL;
}
