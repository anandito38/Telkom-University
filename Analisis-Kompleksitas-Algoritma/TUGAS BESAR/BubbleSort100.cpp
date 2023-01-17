#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
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
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    printArray(arr, N);
    return 0;
}
