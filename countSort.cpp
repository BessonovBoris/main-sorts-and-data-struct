#include <iostream>

using namespace std;

void countSort(int *arr, int len){
    int max = arr[0];
    int answer[len];

    for(int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        answer[i] = 0;
    }

    int numbers[max+1];
    for(int i = 0; i <= max; i++){
        numbers[i] = 0;
    }

    for(int i = 0; i < len; i++){
        numbers[arr[i]]++;
    }

    for(int i = 1; i <= max; i++){
        numbers[i] = numbers[i] + numbers[i-1];
    }

    for(int i = len-1; i >= 0; i--){
        answer[numbers[arr[i]]-1] = arr[i];
        numbers[arr[i]]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = answer[i];
    }
}

int main() {
    int len;

    int arr[] = {6, 2, 6, 3, 1, 0, 100, 56, 2};

    len = sizeof(arr)/sizeof(arr[0]);

    countSort(arr, len);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
