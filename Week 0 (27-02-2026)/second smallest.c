#include <stdio.h>

int main() {
    int n, i;
    int smallest, secondSmallest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    smallest = secondSmallest = arr[0];

    for(i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if(arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Second smallest element = %d", secondSmallest);
    return 0;
}
