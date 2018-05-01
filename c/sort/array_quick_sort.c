#include <stdlib.h>
#include <stdbool.h>

static void print_arr(int a[], int arr_num, bool is_sorted);
static void quick_sort(int a[], int begin, int end);
static int partition(int a[], int begin, int end);

/**
 * execute recursive quick sort algorithm
 */
int main(int argc, char *argv[])
{
    int arr_num = 10;
    int a[10] = {3, 4, 1, 10, 9, 5, 8, 7, 6, 2};

    print_arr(a, arr_num, false);
    quick_sort(a, 0, arr_num - 1);
    print_arr(a, arr_num, true);
}

static void print_arr(int a[], int arr_num, bool is_sorted)
{

    if (is_sorted == true) {
        printf("After sort \n");
    } else {
        printf("Before sort \n");
    }

    int i = 0;
    for (i; i < arr_num; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

static void quick_sort(int a[], int begin, int end)
{
    if (begin >= end) {
        return;
    }

    int part = partition(a, begin, end);
    quick_sort(a, begin, part - 1);
    quick_sort(a, part + 1, end);
}

static int partition(int a[], int begin, int end)
{
    int i = begin - 1;
    int j = end;

    // set the right element as pivot
    int pivot = a[end];
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
    a[i] = a[end];
    a[end] = t;

    // return partition location
    return i;
}
