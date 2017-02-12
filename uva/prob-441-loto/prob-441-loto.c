#include <stdio.h>
#include <stdlib.h>

int main() {
	int k, count = 1;
	while (scanf("%d", &k), k) {
		int i;
		int* S = malloc(sizeof(int) * k);
		for (i = 0; i < k; i++) {
			scanf("%d", &S[i]);
		}
		if (count > 1) {
			printf("\n");
		}

		int a, b, c, d, e, f;
		for (a = 0; a < k-5; a++) 
			for (b = a+1; b < k-4; b++) 
				for (c = b+1; c < k-3; c++) 
					for (d = c+1; d < k-2; d++) 
						for (e = d+1; e < k-1; e++)  
							for (f = e+1; f < k; f++) {
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
							}  
		count++;		
	}
	return 0;
}
