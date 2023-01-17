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
    int arr[] = {61, 63, 51, 35, 96, 45, 93, 28, 8, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    printArray(arr, N);
    return 0;
}