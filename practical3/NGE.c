#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int nge[n];
    int stack[MAX];
    int top = -1;

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        nge[i] = -1;  // initialize
    }

    // Traverse from right → left
    for (int i = n - 1; i >= 0; i--) {

        // Pop all smaller or equal elements
        while (top != -1 && stack[top] <= arr[i]) {
            top--;
        }

        // If stack not empty → top is NGE
        if (top != -1) {
            nge[i] = stack[top];
        }

        // Push current element
        stack[++top] = arr[i];
    }

    // Print results in required format
    for (int i = 0; i < n; i++) {
        printf("NGE of %d is %d\n", arr[i], nge[i]);
    }

    return 0;
}
