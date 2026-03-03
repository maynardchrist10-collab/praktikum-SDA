#include <iostream>
using namespace std;


void menukarNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai A: "; cin >> x;
    cout << "Masukkan nilai B: "; cin >> y;

    cout << "\nSebelum swap: A = " << x << ", B = " << y << endl;
    
    menukarNilai(x, y);

    cout << "Sesudah swap: A = " << x << ", B = " << y << endl;

    return 0;
}