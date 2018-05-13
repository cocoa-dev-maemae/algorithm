#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX_NUM 10

struct {
    int key;
    char *value;
} table[MAX_NUM];

static void set_value();
static char *lsearch(int key);

int main(int argc, char *argv[])
{
    set_value();

    char *tmp_key = argv[1];
    if (tmp_key == NULL || tmp_key == '\0') {
        printf("Specify index of value \n");
        return 0;
    }

    int key = atoi(tmp_key);
    char *result = lsearch(key);
    if (result != NULL && result != '\0') {
        printf("result: %c \n", result);
    } else {
        printf("No result \n");
    }
    return 0;
}

void set_value()
{
    int8_t i = 0;
    char *value;
    for (i; i < MAX_NUM; i++) {
        table[i].key = i;
        value = (char *)('A' + i);
        table[i].value = value;
    }
}

/**
 * Simple linear search
 */
char *lsearch(int key)
{
    int i = 0;
    char *result = NULL;
    while (i < MAX_NUM) {
        if (key == table[i].key) {
            result = table[i].value;
        }
        i++;
    }
    return result;
}
