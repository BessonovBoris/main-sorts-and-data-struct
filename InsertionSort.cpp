#include <iostream>

using namespace std;

void insertionSort(int *a, int n){
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
    int len;

    int arr[] = {6, 2, 6, 3, 1, 0, 100, -5, 2};

    len = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, len);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
