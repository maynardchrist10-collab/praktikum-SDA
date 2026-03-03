#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];
    int Ntinggi = 0;

    for(int i = 0; i < 5; i++) {
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: "; cin >> mhs[i].nama;
        cout << "NIM : "; cin >> mhs[i].nim;
        cout << "IPK : "; cin >> mhs[i].ipk;
        
        if(mhs[i].ipk > mhs[Ntinggi].ipk) {
            Ntinggi = i;
        }
        cout << "--------------------" << endl;
    }

    cout << "\nMahasiswa dengan IPK Tertinggi:\n";
    cout << "Nama: " << mhs[Ntinggi].nama << " (" << mhs[Ntinggi].nim << ")" << endl;
    cout << "IPK : " << mhs[Ntinggi].ipk << endl;

    return 0;
}