#include <stdio.h>
#include <stdlib.h>

int cmpdesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], unique[n], count = 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Remove duplicates
    for (int i = 0; i < n; i++) {
        int exists = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == unique[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists)
            unique[count++] = arr[i];
    }

    if (count < 3) {
        printf("-1\n");
        return 0;
    }

    qsort(unique, count, sizeof(int), cmpdesc);
    printf("%d\n", unique[0] * unique[1] * unique[2]);
    return 0;
}
