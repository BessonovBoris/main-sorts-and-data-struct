#include <stdio.h>

void insertionS(int *a, int n){
    int key;
    int i;
    for(int j = 1; j<n; j++){
        key = a[j];
        i = j - 1;
        while(i>=0 && key<a[i]){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main() {
    int n;
    int a[] = {5, 7, 6, 1, 3, 2, 4};
    n = sizeof(a)/sizeof(a[0]);

    insertionS(a, n);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
