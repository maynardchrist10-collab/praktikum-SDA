#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    string kelas;
    int harga;
};

#define MAX 100
Kereta daftarKereta[MAX];
int n = 0;

// ================= SWAP =================
void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

// ================= TAMPIL =================
void tampil(Kereta *arr, int n) {
    cout << "\n=== DATA KERETA ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->nomor << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->asal << " -> "
             << (arr + i)->tujuan << " | "
             << (arr + i)->kelas << " | Rp"
             << (arr + i)->harga << endl;
    }
}

// ================= TAMBAH =================
void tambah(Kereta *arr, int &n) {
    cout << "\n=== Tambah Data Kereta ===\n";

    cout << "Nomor: ";
    cin >> (arr + n)->nomor;
    cin.ignore();

    cout << "Nama: ";
    getline(cin, (arr + n)->nama);

    cout << "Asal: ";
    getline(cin, (arr + n)->asal);

    cout << "Tujuan: ";
    getline(cin, (arr + n)->tujuan);

    int pilih;
    cout << "\nPilih Kelas:\n";
    cout << "1. Ekonomi   (150000)\n";
    cout << "2. Bisnis    (250000)\n";
    cout << "3. Eksekutif (350000)\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            (arr + n)->kelas = "Ekonomi";
            (arr + n)->harga = 150000;
            break;
        case 2:
            (arr + n)->kelas = "Bisnis";
            (arr + n)->harga = 250000;
            break;
        case 3:
            (arr + n)->kelas = "Eksekutif";
            (arr + n)->harga = 350000;
            break;
        default:
            cout << "Pilihan tidak valid! Default Ekonomi\n";
            (arr + n)->kelas = "Ekonomi";
            (arr + n)->harga = 150000;
    }

    n++;
}

// ================= LINEAR SEARCH =================
void linearSearch(Kereta *arr, int n) {
    string asal, tujuan;
    cin.ignore();
    cout << "\nCari Asal: "; getline(cin, asal);
    cout << "Cari Tujuan: "; getline(cin, tujuan);

    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        cout << "Iterasi ke-" << i << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan\n";
}

// ================= JUMP SEARCH =================
int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->nomor < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if ((arr + i)->nomor == key)
            return i;
    }

    return -1;
}

// ================= MERGE SORT =================
void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama < R[j].nama)
            *(arr + k++) = L[i++];
        else
            *(arr + k++) = R[j++];
    }

    while (i < n1)
        *(arr + k++) = L[i++];

    while (j < n2)
        *(arr + k++) = R[j++];
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ================= SELECTION SORT =================
void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga)
                minIdx = j;
        }
        swap((arr + i), (arr + minIdx));
    }
}

// ================= MAIN =================
int main() {
    int pilihan, cari;

    do {
        cout << "\n=== SISTEM KERETA API ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor\n";
        cout << "5. Urut Nama\n";
        cout << "6. Urut Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambah(daftarKereta, n); break;
            case 2: tampil(daftarKereta, n); break;
            case 3: linearSearch(daftarKereta, n); break;

            case 4:
                cout << "Masukkan nomor: ";
                cin >> cari;
                {
                    int idx = jumpSearch(daftarKereta, n, cari);
                    if (idx != -1)
                        cout << "Ditemukan: " << (daftarKereta + idx)->nama << endl;
                    else
                        cout << "Tidak ditemukan\n";
                }
                break;

            case 5:
                mergeSort(daftarKereta, 0, n - 1);
                cout << "Berhasil diurutkan (Nama)\n";
                break;

            case 6:
                selectionSort(daftarKereta, n);
                cout << "Berhasil diurutkan (Harga)\n";
                break;
        }

    } while (pilihan != 0);

    return 0;
}