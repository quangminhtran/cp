#include <stdio.h>
#include <stdlib.h>

/* Generate all subsets of n elements by binary counting, i.e. counting from 0 to 2^n - 1*/
int generate_subsets(int n) {
	int i, j;
	int count = 0;
	for (i = 0; i <= (1 << n) - 1; i++) {
		j = 1;
		printf("{");
		while (j <= n) {
			if (i & (1 << (j-1))) printf(" %d", j);	/* Is j-th bit on? */
			j++;
		}
		count++;
		printf(" }\n");
	}
	printf("There are %d subsets of %d elements\n", count, n);
	printf("\n");
	return count;
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		 generate_subsets(n);
	}
	return 0;
}
