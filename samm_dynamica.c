#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *ptr;
    int min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for 'n' integers using malloc
    ptr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    // Assume the first element is the minimum
    min = *ptr;
    for (i = 1; i < n; i++) {
        // Compare each element with the current minimum
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }

    printf("The smallest element is: %d\n", min);

    // Free the allocated memory
    free(ptr);

    return 0;
}
