#include <stdlib.h>
#include <stdbool.h>

static void print_arr(int a[], bool is_sorted);
static void quick_sort(int a[], int begin, int end);
static int partition(int a[], int begin, int end);

/**
 * execute recursive quick sort algorithm
 */
int main(int argc, char *argv[])
{
    int a[] = {3, 4, 1, 10, 9, 5, 8, 7, 6, 2};
    print_arr(a, false);
    quick_sort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    print_arr(a, true);
}

void print_arr(int a[], bool is_sorted) {

    if (is_sorted == true) {
        printf("After sort \n");
    } else {
        printf("Before sort \n");
    }

    int i;
    for (i = 0; i < sizeof(a); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quick_sort(int a[], int begin, int end)
{
    if (begin >= end) {
        return;
    }

    int part = partition(a, begin, end);
    quick_sort(a, begin, part - 1);
    quick_sort(a, part + 1, end);
}

int partition(int a[], int begin, int end)
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
