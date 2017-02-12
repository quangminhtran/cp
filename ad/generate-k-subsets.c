#include <stdio.h>
#include <stdlib.h>

void backtrack(int a[], int count, int i, int k, int n) {
	if (count == k) {
		/* Found a solution*/
		int h;
		printf("{");
		for (h = 1; h <= k; h++) {
			 printf(" %d", a[h]);
		}	
		printf(" }\n");
	} else {
		count++;
		/* Construct next move */
		int j;
		for (j = i+1; j <= n-k+count; j++) {
			a[count] = j;
			backtrack(a, count, j, k, n);
		}				
	}
}

int main() {
	int k, n;
	while (scanf("%d %d", &k, &n), k && n) {
		int* a = malloc(sizeof(int)*(n+1));	
		int h;
		for (h = 0; h <= n; h++) {
			a[h] = 0;
		}
		backtrack(a, 0, 0, k, n);
		printf("\n");
	}
	return 0;
}
