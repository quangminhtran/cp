#include <stdio.h>
#include <stdlib.h>

void backtrack(int S[], int a[], int count, int i, int k, int n) {
	if (count == k) {
		int h;
		for (h = 1; h <= k; h++) {
			if (h == 1) 
				printf("%d", S[a[h]]);
			else
				printf(" %d", S[a[h]]);
		}
		printf("\n");
	} else {
		count++;
		int j;
		for (j = i+1; j < n-k+count; j++) {
			a[count] = j;
			backtrack(S, a, count, j, k, n);
		}
	}

}

int main() {
	int k, count = 1;
	while (scanf("%d", &k), k) {
		int i;
		int* S = malloc(sizeof(int) * k);
		int* a = malloc(sizeof(int) * k);
		for (i = 0; i < k; i++) {
			scanf("%d", &S[i]);
			a[i] = 0;
		}

		if (count > 1) {
			printf("\n");
		}

		backtrack(S, a, 0, -1, 6, k);
		count++;		
	}
	return 0;
}
