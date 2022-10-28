#include <iostream>

using namespace std;

void merge(int *a, int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    int res[right-left];

    while((left + it1 < mid) && (mid + it2 < right)){
        if (a[left+it1] < a[mid+it2]){
            res[it1+it2] = a[left+it1];
            it1++;
        } else {
            res[it1+it2] = a[mid+it2];
            it2++;
        }
    }

    while (left + it1 < mid){
        res[it1+it2] = a[left+it1];
        it1++;
    }

    while(mid + it2 < right){
        res[it1+it2] = a[mid+it2];
        it2++;
    }

    for(int i = 0; i < it1+it2; i++){
        a[left+i] = res[i];
    }
}

void mergeSort(int *a, int left, int right){
    if(left + 1 >= right){
        return;
    }
    int mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
}


int main() {
    int len;

    int arr[] = {6, 2, 6, 3, 1, 0, 100, -5, 2};

    len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, len-1);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
