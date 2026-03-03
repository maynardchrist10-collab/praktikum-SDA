#include <iostream>
using namespace std;

int FindMin(int A[], int n) {
    int min = A[0];
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            minIndex = i;
        }
    }
    
    cout << "Indeks elemen minimum : " << minIndex << endl; 
    return min;
}

int main() {
    int arr[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int hasilMin = FindMin(arr, n);
    cout << "Nilai elemen minimum  : " << hasilMin << endl;

    return 0;
}