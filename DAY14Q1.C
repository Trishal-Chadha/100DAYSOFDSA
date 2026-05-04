#include <stdio.h>
// This header file is used for input-output functions like printf

int main() {
    // Main function where execution of program starts

    int arr[] = {1, 3, 5, 7, 9};
    // This is a sorted array on which Binary Search is applied

    int n = 5;
    // Stores the total number of elements in the array

    int target = 5;
    // The element we want to search in the array

    int low = 0, high = n - 1, mid;
    // low = starting index, high = last index, mid = middle index

    while (low <= high) {
        // Loop runs until the search space is valid

        mid = (low + high) / 2;
        // Calculate the middle index of the current search space

        if (arr[mid] == target) {
            // Check if middle element is equal to target

            printf("Element found at index %d", mid);
            // Print the index where element is found

            return 0;
            // Exit the program after finding the element
        }

        else if (target < arr[mid]) {
            // If target is smaller than middle element

            high = mid - 1;
            // Move to the left half of the array
        }

        else {
            // If target is greater than middle element

            low = mid + 1;
            // Move to the right half of the array
        }
    }

    printf("Element not found");
    // This runs if element is not present in array

    return 0;
    // End of program
}
