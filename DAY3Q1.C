#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;
    int found = 0;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear Search
    for (i = 0; i < n; i++) {
        comparisons++;          // one comparison made
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    // If not found
    if (!found) {
        printf("Not Found\n");
    }

    // Print comparisons
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
