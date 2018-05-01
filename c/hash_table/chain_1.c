#include <stdio.h>
#include <stdbool.h>

#define BUCKET_SIZE 50
#define MAX_INPUT_SIZE 10

typedef struct cell {
    char *key;
    char *value;
    struct cell *next;
} CELL;

CELL *hash_table[BUCKET_SIZE];

static int gen_hash(const char *s);
static char *find(const char *key);
static int insert(const char *key, const char *value);

int main(void)
{
    init();
    insert("A", "hogeA");
    insert("B", "hogeB");
    insert("C", "hogeC");
    insert("D", "hogeD");

    int i;
    char *input;
    for (i = 0; i < MAX_INPUT_SIZE; i++) {
        fgets(input, 2, stdin);
        if (input != NULL && *input != '\0') {
            if (find(input) != NULL) {
                printf("key %s is found. value: %s \n", input, find(input));
                break;
            } else {
                printf("key %s is not found \n", input); 
                continue;
            }
        }
    }
}

/**
 * initialize hash table
 */
void init()
{
    int i;
    for (i = 0; i < BUCKET_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

/**
 * Create a hash value
 */
int gen_hash(const char *s)
{
    int i = 0;
    while (*s) {
        i += *s++;
    }
    return i % 100;
}

char *find(const char *key)
{
    CELL *p;
    for (p = hash_table[gen_hash(key)]; p != NULL; p = p->next) {
        if (strcmp(key, p->key) == 0) {
            return p->value;
        }
    }
    return NULL;
}

int insert(const char *key, const char *value)
{
    CELL *p;
    int h;
    if (find(key) != NULL) {
        return 0;
    }
    if ((p = malloc(sizeof(CELL))) == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(2);
   }
    h = gen_hash(key);
    p->key = key;
    p->value = value;
    p->next = hash_table[h];
    hash_table[h] = p;
    p->next = NULL;
    return 1;
}
