#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_OF_ARR(arr) (sizeof(arr) / sizeof(arr[0]))

static void print_arr(const int *a, bool is_sorted);
static void merge_sort(int *a, int begin, int end, int *result);
static void merge(int *a, int begin, int end, int mid, int *result);

int main(int argc, char *argv)
{
    int a[] = {7, 2, 9, 6, 4, 3, 8, 1, 5, 10};

    int *result = malloc(sizeof(int) * SIZE_OF_ARR(a));

    print_arr(a, false);
    merge_sort(a, 0, SIZE_OF_ARR(a) - 1, result);
    print_arr(a, true);

    free(result);
    return 0;
}

void print_arr(const int *a, bool is_sorted)
{
    if (is_sorted == true) {
        printf("After sorted \n");
    } else {
        printf("Before sorted \n");
    }

    size_t i;
    for (i = 0; i < sizeof(a); ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge_sort(int *a, int begin, int end, int *result)
{
    int mid;

    // if array element is only one, exit
    if (begin >= end) {
        return;
    }

    /* Divide 2 rows, process recursively */
    mid = (begin + end) / 2;
    merge_sort(a, begin, mid, result);
    merge_sort(a, mid + 1, end, result);

    merge(a, begin, end, mid, result);
}

void merge(int* a, int begin, int end, int mid, int* result)
{
    int i, j, k;

    // put the first half array to result array
    for (i = begin; i <= mid; ++i) {
        result[i] = a[i];
    }

    // put the last half array to result array
    for (i = mid + 1, j = end; i <= end; ++i, --j) {
        result[i] = a[j];
    }

    /* 作業用配列の両端から取り出した要素をマージ */
    i = begin;
    j = end;
    for (k = begin; k <= end; ++k) {
        /* 昇順にソートするので、小さい方の要素を結果の配列へ移す。 */
        if (result[i] <= result[j]) { /* == の場合は先頭を優先すると安定なソートになる */
            a[k] = result[i];
            ++i;
        } else {
            a[k] = result[j];
            --j;
        }
    }
}
