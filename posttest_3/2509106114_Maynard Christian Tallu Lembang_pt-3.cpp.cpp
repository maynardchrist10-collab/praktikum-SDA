#include <iostream>
#include <string>
#define MAX 5
using namespace std;

// ===== STRUCT =====
struct Tiket {
    string nama;
    string rute;
    int harga;
};

// ===== STACK =====
Tiket stack[MAX];
int top = -1;

// ===== QUEUE =====
Tiket queueArr[MAX];
int front = -1, rear = -1;

// ===== CEK KONDISI =====
bool isFullQueue() {
    return rear == MAX - 1;
}

bool isEmptyQueue() {
    return front == -1 || front > rear;
}

bool isFullStack() {
    return top >= MAX - 1;
}

bool isEmptyStack() {
    return top < 0;
}

// ===== INPUT TIKET =====
void inputTiket(Tiket *t) {
    int pilih;

    cout << "Nama: ";
    getline(cin, t->nama);

    cout << "\n=== DAFTAR RUTE KERETA KALIMANTAN ===\n";
    cout << "1. Samarinda - Balikpapan (180000)\n";
    cout << "2. Balikpapan - Bontang (200000)\n";
    cout << "3. Samarinda - Bontang (170000)\n";
    cout << "4. Samarinda - Sangatta (220000)\n";
    cout << "5. Balikpapan - Penajam (150000)\n";
    cout << "6. Samarinda - Tenggarong (120000)\n";
    cout << "7. Bontang - Sangatta (140000)\n";
    cout << "8. Balikpapan - Samarinda (180000)\n";
    cout << "9. Samarinda - Kutai Barat (300000)\n";
    cout << "10. Balikpapan - Kutai Timur (320000)\n";
    cout << "Pilih rute: ";
    cin >> pilih;
    cin.ignore();

    switch(pilih) {
        case 1: t->rute = "Samarinda - Balikpapan"; t->harga = 180000; break;
        case 2: t->rute = "Balikpapan - Bontang"; t->harga = 200000; break;
        case 3: t->rute = "Samarinda - Bontang"; t->harga = 170000; break;
        case 4: t->rute = "Samarinda - Sangatta"; t->harga = 220000; break;
        case 5: t->rute = "Balikpapan - Penajam"; t->harga = 150000; break;
        case 6: t->rute = "Samarinda - Tenggarong"; t->harga = 120000; break;
        case 7: t->rute = "Bontang - Sangatta"; t->harga = 140000; break;
        case 8: t->rute = "Balikpapan - Samarinda"; t->harga = 180000; break;
        case 9: t->rute = "Samarinda - Kutai Barat"; t->harga = 300000; break;
        case 10: t->rute = "Balikpapan - Kutai Timur"; t->harga = 320000; break;
        default:
            cout << "Pilihan tidak valid!\n";
            t->rute = "-";
            t->harga = 0;
    }
}

// ===== ENQUEUE =====
void enqueue(Tiket t) {
    if (isFullQueue()) {
        cout << "Queue overflow\n";
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    *(queueArr + rear) = t;
    cout << "Penumpang masuk antrian\n";
}

// ===== DEQUEUE =====
Tiket dequeue() {
    Tiket t;

    if (isEmptyQueue()) {
        cout << "Queue underflow\n";
        t.nama = "";
        return t;
    }

    t = *(queueArr + front);
    front++;

    if (isEmptyQueue()) {
        front = rear = -1;
    }

    return t;
}

// ===== PUSH =====
void push(Tiket t) {
    if (isFullStack()) {
        cout << "Stack overflow\n";
        return;
    }

    top++;
    *(stack + top) = t;
}

// ===== POP =====
void pop() {
    if (isEmptyStack()) {
        cout << "Stack underflow\n";
        return;
    }

    cout << "Hapus transaksi: "
         << stack[top].nama << endl;

    top--;
}

// ===== PEEK =====
void peek() {
    if (!isEmptyQueue()) {
        cout << "Antrian depan: "
             << queueArr[front].nama << endl;
    } else {
        cout << "Queue kosong\n";
    }

    if (!isEmptyStack()) {
        cout << "Transaksi terakhir: "
             << stack[top].nama << endl;
    } else {
        cout << "Stack kosong\n";
    }
}

// ===== TAMPIL QUEUE =====
void tampilQueue() {
    if (isEmptyQueue()) {
        cout << "Queue kosong\n";
        return;
    }

    cout << "\n=== Antrian ===\n";
    for (Tiket *p = queueArr + front; p <= queueArr + rear; p++) {
        cout << "Nama: " << p->nama
             << " | Rute: " << p->rute
             << " | Harga: " << p->harga << endl;
    }
}

// ===== TAMPIL STACK =====
void tampilStack() {
    if (isEmptyStack()) {
        cout << "Stack kosong\n";
        return;
    }

    cout << "\n=== Riwayat ===\n";
    for (Tiket *p = stack; p <= stack + top; p++) {
        cout << "Nama: " << p->nama
             << " | Rute: " << p->rute
             << " | Harga: " << p->harga << endl;
    }
}

// ===== MAIN =====
int main() {
    int pilih;
    Tiket t;

    do {
        cout << "\n=== SISTEM KERETA API ===\n";
        cout << "1. Pesan Tiket (Enqueue)\n";
        cout << "2. Proses Tiket (Dequeue)\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat\n";
        cout << "5. Hapus Riwayat (Pop)\n";
        cout << "6. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                inputTiket(&t);
                enqueue(t);
                break;

            case 2: {
                Tiket hasil = dequeue();
                if (hasil.nama != "") {
                    cout << "Diproses: "
                         << hasil.nama << " | "
                         << hasil.rute << " | "
                         << hasil.harga << endl;

                    push(hasil);
                }
                break;
            }

            case 3:
                tampilQueue();
                break;

            case 4:
                tampilStack();
                break;

            case 5:
                pop();
                break;

            case 6:
                peek();
                break;
        }

    } while (pilih != 0);

    return 0;
}