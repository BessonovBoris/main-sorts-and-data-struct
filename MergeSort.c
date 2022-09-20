#include <stdio.h>

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

void mergeS(int *a, int left, int right){
    if(left + 1 >= right){
        return;
    }
    int mid = (left + right)/2;
    mergeS(a, left, mid);
    mergeS(a, mid, right);
    merge(a, left, mid, right);
}

int main() {
    int n;
    int a[] = {5, 7, 6, 1, 3, 2, 4};
    n = sizeof(a)/sizeof(a[0]);

    mergeS(a, 0, n);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
