#include <stdio.h>

static void quick_sort(int a[], int array_num);
static void quick_sort_l(int a[], int left_idx, int right_idx);
static int partition(int a[], int left_idx, int right_idx);

/**
 * execute recursive quick sort algorithm
 */
int main(int argc, char *argv[])
{
    int array_num = 10;
    int a[10] = {3, 4, 1, 10, 9, 5, 8, 7, 6, 2};

    printf("Before sort \n");
    int i = 0;
    for (i; i < array_num; i++) {
        printf("%d \n", a[i]);
    }

    quick_sort(a, array_num);

    printf("After sort\n");
    int j = 0;
    for (j; j < array_num; j++) {
        printf("%d \n", a[j]);
    }
}

static void quick_sort(int a[], int array_num)
{
    int right_idx = array_num - 1;
    quick_sort_l(a, 0, right_idx);
}

static void quick_sort_l(int a[], int left_idx, int right_idx)
{
    int part_idx;
    if (left_idx >= right_idx) {
        return;
    }

    part_idx = partition(a, left_idx, right_idx);
    quick_sort_l(a, left_idx, part_idx - 1);
    quick_sort_l(a, part_idx + 1, right_idx);
}

static int partition(int a[], int left_idx, int right_idx)
{
    int i = left_idx - 1;
    int j = right_idx;

    // set the right element as pivot
    int pivot = a[right_idx];
    int t;
    for (;;) {
        // proceed pointer i to right
        while (a[++i] < pivot) {
            ;
        }

        // proceed pointer j to left
        while (i < --j && pivot < a[j]) {
            ;
        }

        if (i >= j) {
            break;
        }

        // exchange i element with j element
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    // exchange a[i] with pivot
    t = a[i];
    a[i] = a[right_idx];
    a[right_idx] = t;

    // return partition location
    return i;
}
