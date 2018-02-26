#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_OF_ARR(arr) (sizeof(arr) / sizeof(arr[0]))

static void print_arr(const int* arr, size_t size, bool is_sorted);
static void merge_sort(int* arr, size_t size);
static void merge_sort_rec(int* arr, int begin, int end, int* work);
static void merge(int* arr, int begin, int end, int mid, int* work);

int main(int argc, char *argv)
{
    int arr[] = {7, 2, 9, 6, 4, 3, 8, 1, 5, 10};

    int* work;
    work = malloc(sizeof(int) * SIZE_OF_ARR(arr));
    
    print_arr(arr, SIZE_OF_ARR(arr), false);
    merge_sort_rec(arr, 0, SIZE_OF_ARR(arr) - 1, work);
    print_arr(arr, SIZE_OF_ARR(arr), true);

    free(work);
    return 0;
}

void print_arr(const int* arr, size_t size, bool is_sorted)
{
    if (is_sorted == true) {
        printf("After sorted \n");
    } else {
        printf("Before sorted \n");
    }

    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_sort_rec(int* arr, int begin, int end, int* work)
{
    int mid;

    // if array element is only one, exit
    if (begin >= end) {
        return;
    }

    /* Divide 2 rows, process recursively */
    mid = (begin + end) / 2;
    merge_sort_rec(arr, begin, mid, work);
    merge_sort_rec(arr, mid + 1, end, work);

    merge(arr, begin, end, mid, work);
}

void merge(int* arr, int begin, int end, int mid, int* work)
{
    int i, j, k;

    // put the first half array to result array
    for (i = begin; i <= mid; ++i) {
        work[i] = arr[i];
    }

    // put the last half array to result array
    for (i = mid + 1, j = end; i <= end; ++i, --j) {
        work[i] = arr[j];
    }

    /* 作業用配列の両端から取り出した要素をマージ */
    i = begin;
    j = end;
    for (k = begin; k <= end; ++k) {
        /* 昇順にソートするので、小さい方の要素を結果の配列へ移す。 */
        if (work[i] <= work[j]) { /* == の場合は先頭を優先すると安定なソートになる */
            arr[k] = work[i];
            ++i;
        } else {
            arr[k] = work[j];
            --j;
        }
    }
}
