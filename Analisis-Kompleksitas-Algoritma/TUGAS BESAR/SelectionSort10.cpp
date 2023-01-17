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
    int arr[] = {61, 63, 51, 35, 96, 45, 93, 28, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}