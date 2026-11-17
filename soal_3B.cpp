#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

void tambahPelanggan(Node*& front, Node*& rear, int& jumlah, string nama) {
    Node* baru = new Node{nama, nullptr};
    if (rear == nullptr) {
        front = baru;
        rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    jumlah++;
    cout << nama << " masuk ke antrean" << endl;
}

void layaniPelanggan(Node*& front, Node*& rear, int& jumlah) {
    if (front == nullptr) {
        cout << "antrean kosong" << endl;
        return;
    }
    Node* hapus = front;
    cout << front->nama << " sedang dilayani" << endl;
    front = front->next;
    delete hapus;
    jumlah--;

    if (front == nullptr) {
        rear = nullptr;
    }
}

void tampilkanDepanBelakang(Node* front, Node* rear) {
    if (front == nullptr) {
        cout << "antrean kosong" << endl;
        return;
    }
    cout << "pelanggan paling depan: " << front->nama << endl;
    cout << "pelanggan paling belakang: " << rear->nama << endl;
}

void hapusSemua(Node*& front, Node*& rear) {
    while (front != nullptr) {
        Node* hapus = front;
        front = front->next;
        delete hapus;
    }
    rear = nullptr;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    int jumlah = 0;
    int pilihan;
    do {
        cout << "\n1. tambah pelanggan" << endl;
        cout << "2. layani pelanggan" << endl;
        cout << "3. tampilkan depan dan belakang" << endl;
        cout << "4. hitung pelanggan" << endl;
        cout << "5. keluar" << endl;
        cout << "pilihan: ";
        cin >> pilihan;
        if (pilihan == 1) {
            string nama;
            cout << "nama pelanggan: ";
            cin >> nama;
            tambahPelanggan(front, rear, jumlah, nama);
        } else if (pilihan == 2) {
            layaniPelanggan(front, rear, jumlah);
        } else if (pilihan == 3) {
            tampilkanDepanBelakang(front, rear);
        } else if (pilihan == 4) {
            cout << "jumlah pelanggan menunggu: " << jumlah << endl;
        } else if (pilihan != 5) {
            cout << "pilihan tidak tersedia" << endl;
        }
    } while (pilihan != 5);
    hapusSemua(front, rear);
    return 0;
}
