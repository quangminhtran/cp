#include <stdio.h>

int main() {
	int TC;
	int n,m;
	int x, y;
	while (scanf("%d", &TC), TC) {
		scanf("%d %d", &n, &m);	
		while (TC--) {
			scanf("%d %d", &x, &y);
			if ((x == n) || (y == m)) {
				printf("divisa\n");
			} else {
				if (x >= n) {
					if (y >= m) {
						printf("NE\n");
					} else {
						printf("SE\n");
					}	
				} else {
					if (y >= m) {
						printf("NO\n");
					} else {
						printf("SO\n");
					}	
				}
			}
		}
	}
}
