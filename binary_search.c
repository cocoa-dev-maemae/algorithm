#include <stdio.h>
#include <stdlib.h>
#define MAX_IDX 9

struct {
    int key;
    char *data;
} table[10];

static void set_data();
static char *search(int key);

int main(int argc, char *argv[])
{
    set_data();

    char *tmp_key = argv[1];
    if (tmp_key == NULL || tmp_key == '\0') {
        printf("Specify index of data \n");
        return 0;
    }

    int key = atoi(tmp_key);
    char *result = search(key);
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
    for (i; i <= MAX_IDX; i++) {
        table[i].key = i;
        char *data = 'A' + i;
        table[i].data = data;
    }
}

/**
 * Simple binary search
 */
static char *search(int key)
{
    int low_idx, mid_idx, high_idx;
    low_idx = 0;
    high_idx = MAX_IDX;

    while (low_idx <= high_idx) {
        mid_idx = (low_idx + high_idx) / 2;
        if (table[mid_idx].key == key) {
            return table[mid_idx].data;
        } else if (table[mid_idx].key > key) {
            high_idx = mid_idx - 1;
        } else {
            low_idx = mid_idx + 1;
        }
    }
    return NULL;
}
