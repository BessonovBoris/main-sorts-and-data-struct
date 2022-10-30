#include <iostream>

using namespace std;

int bin_search_left(int *arr, int key, int len){
    int left = -1;
    int right = len;

    int mid;

    while(right - left > 1){
        mid = (left + right)/2;
        if(arr[mid] < key){
            left = mid;
        } else {
            right = mid;
        }
    }

    if(arr[right] != key){
        return -1;
    }

    return right+1;
}

int bin_search_right(int *arr, int key, int len){
    int left = -1;
    int right = len;

    int mid;

    while(right - left > 1){
        mid = (left + right)/2;
        if(arr[mid] <= key){
            left = mid;
        } else {
            right = mid;
        }
    }

    if(arr[left] != key){
        return -1;
    }

    return left+1;
}

int main() {
    int len;

    int arr[] = {1, 1, 1, 2, 2, 3, 3,4, 5, 6, 6, 7};

    len = sizeof(arr)/sizeof(arr[0]);

    int first_in = bin_search_left(arr, 3, len);
    int second_in = bin_search_right(arr, 3, len);

    cout << "Left border: " << first_in << "| Right border: " << second_in;

    return 0;
}
