#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* kiri;
    Node* kanan;
};

Node* tambah(Node* akar, int nilai) {
    if (akar == nullptr) {
        return new Node{nilai, nullptr, nullptr};
    }
    if (nilai < akar->nilai) {
        akar->kiri = tambah(akar->kiri, nilai);
    } else {
        akar->kanan = tambah(akar->kanan, nilai);
    }
    return akar;
}

void tampilkanRentang(Node* akar, int batasBawah, int batasAtas) {
    if (akar == nullptr) {
        return;
    }
    if (akar->nilai > batasBawah) {
        tampilkanRentang(akar->kiri, batasBawah, batasAtas);
    }
    if (akar->nilai >= batasBawah && akar->nilai <= batasAtas) {
        cout << akar->nilai << " ";
    }
    if (akar->nilai < batasAtas) {
        tampilkanRentang(akar->kanan, batasBawah, batasAtas);
    }
}

bool cari (Node* akar, int nilai) {
    if (akar == nullptr) {
        return false;
    }
    if (akar->nilai == nilai) {
        return true;
    }
    if (nilai < akar->nilai) {
        return akar(akar->kiri, nilai);
    }
    return cari(akar->kanan, nilai);
}
void hapuspohon (Node* akar) {
   if (akar != nullptr) {
        hapusPohon(akar->kiri);
        hapusPohon(akar->kanan);
        delete akar;
    }
} 
int main() {
    Node* akar = nullptr;
    int nilai;

    cout << "masukkan bilangan (-1 untk stop): ";
    while (cin >> nilai && nilai != -1) {
        akar = tambah(akar, nilai);
        cout << "masukkan bilangan (-1 = stop): ";
    }
int batasBawah, batasAtas;
    cout << "masukkan batas bawah dan batas atas: ";
    if (!(cin >> batasBawah >> batasAtas)) {
        hapusPohon(akar);
        return 1;
    }
if (batasBawah > batasAtas) {
        int sementara = batasBawah;
        batasBawah = batasAtas;
        batasAtas = sementara;
    }
 cout << "nilai semua: ";
    tampilkanRentang(akar, batasBawah, batasAtas);
    cout << endl;
cout << "masukkan nilai yg mau dicari: ";
    if (!(cin >> nilai)) {
        hapusPohon(akar);
        return 1;
    }
if (cari(akar, nilai)) {
        cout << nilai << " ditemukan di dalam BST" << endl;
    } else {
        cout << nilai << " tidak ditemukan di dalam BST" << endl;
    }

    hapusPohon(akar);
    return 0;
}

