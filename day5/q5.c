#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];

    scanf("%d", &p);
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0, k = 0;

    while(i < p && j < q) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while(i < p) {
        c[k++] = a[i++];
    }

    while(j < q) {
        c[k++] = b[j++];
    }

    for(int x = 0; x < k; x++) {
        printf("%d ", c[x]);
    }

    return 0;
}
