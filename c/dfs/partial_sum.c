#include <stdlib.h>
#include <stdbool.h>

// num of array
int n = 4;
int a[4] = {1, 2, 4, 7};
// sum of array elements
int k = 13;

/**
 * Order to calculate of partial sum
 * 7
 * 4, 4 + 7
 * 2, 2 + 7, 2 + 4, 2 + 4 + 7(True here)
 *
 **/
bool dfs(int i, int s) {
    printf("i=%d, s=%d\n", i, s);
	if (i == n) return s == k;
	if (dfs(i + 1, s)) return true;
	if (dfs(i + 1, s + a[i])) return true;
	return false;
}

/**
 * If calculate k is enabled by using array elements, return Yes.
 *
 **/
int main(int argc, char *argv[]) {
	if (dfs(0, 0)) printf("Yes\n");
	else printf("No\n");
	return 0;
}

