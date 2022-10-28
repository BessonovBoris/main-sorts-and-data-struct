#include <iostream>

using namespace std;

void quickSort(int *mas, int first, int last)
{
    int mid, count;
    int f = first;
    int l = last;

    mid = mas[(f+l) / 2];
    while (f<l){
        while (mas[f]<mid){
            f++;
        }
        while (mas[l]>mid){
            l--;
        }

        if (f <= l){
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    }
    if (first<l){
        quickSort(mas, first, l);
    }
    if (f<last){
        quickSort(mas, f, last);
    }
}

int main() {
    int len;

    int arr[] = {6, 2, 6, 3, 1, 0, 100, -5, 2};

    len = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, len-1);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
