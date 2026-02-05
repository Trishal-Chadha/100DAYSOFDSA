#include <stdio.h>

int main() {
    int p, q;
    int A[100], B[100];
    int i = 0, j = 0;

    // Input size and elements of first array
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    // Input size and elements of second array
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    i = 0;
    j = 0;

    // Merge both arrays
    while (i < p && j < q) {
        if (A[i] < B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

    // Remaining elements of A
    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }

    // Remaining elements of B
    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}
