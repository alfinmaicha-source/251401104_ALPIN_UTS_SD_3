#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void tambahNode(Node*& head, int nilai) {
    Node* nodeBaru = new Node{nilai, nullptr};

    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    Node* bantu = head;
    while (bantu->next != nullptr) {
        bantu = bantu->next;
    }
    bantu->next = nodeBaru;
}
void tampilkan(Node* head) {
    if (head == nullptr) {
        cout << "linked list kosong";
    } else {
        while (head != nullptr) {
            cout << head->data;
            if (head->next != nullptr) {
                cout << " -> ";
            }
            head = head->next;
        }
    }
    cout << endl;
}

void hapusSetelah(Node* head, int nilai) {
    while (head != nullptr && head->data != nilai) {
        head = head->next;
    }

    if (head == nullptr) {
        cout << "nilai tidak ditemukan" << endl;
    } else if (head->next == nullptr) {
        cout << "tidak ada node setelah nilai tersebut" << endl;
    } else {
        Node* hapus = head->next;
        head->next = hapus->next;
        delete hapus;
        cout << "node setelah " << nilai << " berhasil dihapus" << endl;
    }
}

void balikList(Node*& head) {
    Node* sebelumnya = nullptr;
    Node* sekarang = head;

    while (sekarang != nullptr) {
        Node* berikutnya = sekarang->next;
        sekarang->next = sebelumnya;
        sebelumnya = sekarang;
        sekarang = berikutnya;
    }
    head = sebelumnya;
}

void hapusSemua(Node*& head) {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main() {
    Node* head = nullptr;
    int jumlah, nilai, dicari;
    cout << "masukkan jumlah bilangan: ";
    cin >> jumlah;
    if (jumlah < 0) {
        cout << "jumlah bilangan tidak boleh negatif" << endl;
        return 1;
    }
    for (int i = 0; i < jumlah; i++) {
        cout << "masukkan bilangan ke-" << i + 1 << ": ";
        cin >> nilai;
        tambahNode(head, nilai);
    }
    cout << "data linked list: ";
    tampilkan(head);
    cout << "masukkan nilai yang node setelahnya akan dihapus: ";
    cin >> dicari;
    hapusSetelah(head, dicari);
    cout << "data setelah penghapusan: ";
    tampilkan(head);
    balikList(head);
    cout << "data setelah dibalik: ";
    tampilkan(head);
    hapusSemua(head);
    return 0;
}