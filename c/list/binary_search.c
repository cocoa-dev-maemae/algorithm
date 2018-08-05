#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10

struct {
    int key;
    char *value;
} table[MAX_NUM];

static void set_value();
static char *binsearch(int key);

int main(int argc, char *argv[])
{
    set_value();

    char *tmp_key = argv[1];
    if (tmp_key == NULL || *tmp_key == '\0') {
        printf("Specify index of value \n");
        return 0;
    }

    int key = atoi(tmp_key);
    char *result = binary_search(key);
    if (result != NULL && *result != '\0') {
        printf("result: %c \n", result);
    } else {
        printf("No result \n");
    }
    return 0;
}

static void set_value()
{
    int i = 0;
    for (i; i < MAX_NUM; i++) {
        table[i].key = i;
        char *value = 'A' + i;
        table[i].value = value;
    }
}

/**
 * Simple binary search
 */
char *binsearch(int key)
{
    int begin, mid, end;
    begin = 0;
    end = MAX_NUM - 1;

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (key == table[mid].key) {
            return table[mid].value;
        } else if (key < table[mid].key) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return NULL;
}
