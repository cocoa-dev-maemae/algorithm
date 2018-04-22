#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 40
#define MAX_KW_LEN 256
#define NUM_KW 23

struct list {
    char keyword[MAX_KW_LEN];
    struct list *next;
};
struct list *hashtable[HASH_TABLE_SIZE];

/*
typedef struct list {
    char keyword[MAX_KW_LEN];
    struct list *next; 
} *hashtable[HASH_TABLE_SIZE];
*/

/* keywords */
static char kw[NUM_KW][MAX_KW_LEN] = {
        "auto", "break", "double",
        "enum", "char", "continue", "extern", "float", "for", "int",
        "long", "register", "short", "signed", "static",
        "struct", "typedef", "union", "unsigned", "return",
        "void", "volatile", "while"
};

int hash(const char *key);           /* 0 から HASH_TABLE_SIZE のハッシュ値を返す */
void initHashTable(void);      /* キーワードをハッシュテーブルに登録 */
bool findKeyword(const char *key);    /* ハッシュテーブルに登録済みか調べる */
void freeKeyword(void);        /* malloc() で割り付けたメモリを解放 */
void main(void);

int hash(const char *key)
{
    int hashval = 0;
    while (*key != '\0') {
        hashval += *key++;
    }
    return (hashval % HASH_TABLE_SIZE);
}

void initHashTable(void)
{
    int i;
    struct list *p, *q;
    int hashval;
    for (i = 0; i < NUM_KW; i++) {
        if ((findKeyword(kw[i])) == false) {  /* 登録されていなかったら */
            if ((p = (struct list *)malloc(sizeof(struct list))) == NULL) {
                fprintf(stderr, "メモリ不足です。\n");
                exit(2);
            }
            strcpy((*p).keyword, kw[i]);
            hashval = hash(kw[i]);             /* ハッシュ値を求めて */
            if (hashtable[hashval] == NULL) {  /* 未登録なら */
                hashtable[hashval] = p;        /* p の指すアドレスを登録 */
                p->next = NULL;                /* リストの末尾に NULL を追加 */
            } else {                             /* 既に登録していたら */
                q = hashtable[hashval];
                while (q->next != NULL)        /* データがなくなるまで */
                    q = q->next;               /* リストをたどる */
                q->next = p;                   /* リストの末尾に p の指すアドレスを登録 */
                p->next = NULL;                /* その末尾に NULL を追加 */
            }
        }
    }
}

bool findKeyword(const char *key)
{
    struct list *p;
    for (p = hashtable[hash(key)]; p != NULL; p = p->next)
        if (!strcmp(key, (*p).keyword)) {
            return true;
        }
        return false;
}

/* malloc(  ) で割り付けたメモリを解放 */
void freeKeyword(void)
{
    int i;
    struct list *p, *q;
    for (i = 0; i < HASH_TABLE_SIZE; i++)
        for (p = hashtable[i]; p != NULL;) {   /* p が NULL でなければ */
            q = p->next;                        /* p->next を保存 */
            free(p);                            /* メモリを解放 */
            p = q;                              /* p->next を p に代入 */
        }
}


void main(void)
{
    char word[MAX_KW_LEN];
    int i;

    initHashTable();
    for (i = 0; i < 4; i++) {
        gets(word);

        if ((findKeyword(word)) == true)
            printf("%s は登録済みです。\n", word);
        else
            printf("%s は未登録です。\n", word);
    }
    freeKeyword();
}
