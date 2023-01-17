#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    int min_idx;
    for (int i = 0; i < n-1; i++){
        min_idx = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        if(min_idx!=i){
            swap(arr[min_idx], arr[i]);
        }
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {112, 27, 114, 129, 111, 17, 140, 13, 61, 86, 130, 85, 96, 21, 76, 59, 47, 147, 108, 90, 118, 120, 101, 97, 45, 41, 128, 115, 132, 77, 67, 141, 23, 8, 139, 28, 70, 14, 138, 82, 127, 133, 81, 55, 105, 3, 34, 11, 75, 64, 83, 107, 10, 134, 142, 9, 65, 52, 50, 63, 84, 124, 104, 95, 79, 42, 102, 20, 33, 29, 73, 117, 48, 31, 80, 56, 121, 144, 89, 19, 5, 60, 148, 100, 126, 143, 131, 146, 98, 78, 32, 99, 16, 38, 40, 109, 110, 145, 51, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
