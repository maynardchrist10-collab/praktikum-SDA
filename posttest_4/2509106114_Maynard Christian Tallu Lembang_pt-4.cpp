#include <iostream>
#include <string>
using namespace std;


struct Node {
    string nama;
    string rute;
    int harga;
    Node* next;
};


Node* front = NULL;
Node* rear = NULL;

// ===== STACK =====
Node* top = NULL;


bool isEmptyQueue() {
    return front == NULL;
}

bool isEmptyStack() {
    return top == NULL;
}


void inputTiket(Node *t) {
    int pilih;

    cout << "Nama: ";
    getline(cin, t->nama);

    cout << "\n=== DAFTAR RUTE ===\n";
    cout << "1. Samarinda - Balikpapan (180000)\n";
    cout << "2. Balikpapan - Bontang (200000)\n";
    cout << "3. Samarinda - Bontang (170000)\n";
    cout << "4. Samarinda - Sangatta (220000)\n";
    cout << "Pilih: ";
    cin >> pilih;
    cin.ignore();

    switch(pilih) {
        case 1: t->rute="Samarinda-Balikpapan"; t->harga=180000; break;
        case 2: t->rute="Balikpapan-Bontang"; t->harga=200000; break;
        case 3: t->rute="Samarinda-Bontang"; t->harga=170000; break;
        case 4: t->rute="Samarinda-Sangatta"; t->harga=220000; break;
        default: t->rute="-"; t->harga=0;
    }
}


void enqueue() {
    Node* baru = new Node;
    inputTiket(baru);
    baru->next = NULL;

    if (front == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Masuk antrian!\n";
}


Node* dequeue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong\n";
        return NULL;
    }

    Node* hapus = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    return hapus;
}


void push(Node* data) {
    data->next = top;
    top = data;
}


void pop() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* hapus = top;
    cout << "Hapus: " << hapus->nama << endl;

    top = top->next;
    delete hapus;
}


void peek() {
    if (!isEmptyQueue()) {
        cout << "Depan Queue: " << front->nama << endl;
    } else {
        cout << "Queue kosong\n";
    }

    if (!isEmptyStack()) {
        cout << "Top Stack: " << top->nama << endl;
    } else {
        cout << "Stack kosong\n";
    }
}


void tampilQueue() {
    if (isEmptyQueue()) {
        cout << "Queue kosong\n";
        return;
    }

    Node* temp = front;
    cout << "\n=== ANTRIAN ===\n";

    while (temp != NULL) {
        cout << temp->nama << " | "
             << temp->rute << " | "
             << temp->harga << endl;
        temp = temp->next;
    }
}

// ===== TAMPIL STACK =====
void tampilStack() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* temp = top;
    cout << "\n=== RIWAYAT ===\n";

    while (temp != NULL) {
        cout << temp->nama << " | "
             << temp->rute << " | "
             << temp->harga << endl;
        temp = temp->next;
    }
}


int main() {
    int pilih;

    do {
        cout << "\n=== SISTEM KERETA API ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue + Push\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat\n";
        cout << "5. Pop\n";
        cout << "6. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch(pilih) {
            case 1:
                enqueue();
                break;

            case 2: {
                Node* hasil = dequeue();
                if (hasil != NULL) {
                    cout << "Diproses: " << hasil->nama << endl;
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