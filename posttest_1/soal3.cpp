#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;          
    int* end = arr + (n - 1);  
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int prima[] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Sebelum dibalik (Alamat Memori):" << endl;
    for(int i = 0; i < n; i++) {
        cout << *(prima + i) << " [" << (prima + i) << "]" << endl;
    }

    reverseArray(prima, n);

    cout << "\nSesudah dibalik:" << endl;
    for(int i = 0; i < n; i++) {
        cout << *(prima + i) << " [" << (prima + i) << "]" << endl;
    }

    return 0;
}