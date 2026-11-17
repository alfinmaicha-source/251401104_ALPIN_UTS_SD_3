#include <iostream>
using namespace std;

int main() {
    int nilai[5][4];
    double rata[5];
    int tertinggi = 0, terendah = 0, jumlah_lulus = 0;
    for (int i = 0; i < 5; i++) {
        cout << "masukkan nilai mahasiswa ke-" << i + 1 << endl;
        cout << "tugas, kuis, uts, praktikum: ";
        for (int j = 0; j < 4; j++) {
            cin >> nilai[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        int total = 0;
        for (int j = 0; j < 4; j++) {
            total += nilai[i][j];
        }
        rata[i] = total / 4.0;
        if (rata[i] > rata[tertinggi]) {
            tertinggi = i;
        }
        if (rata[i] < rata[terendah]) {
            terendah = i;
        }
        if (rata[i] >= 75) {
            jumlah_lulus++;
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << "rata-rata mahasiswa ke-" << i + 1 << ": " << rata[i] << endl;
    }
    cout << "rata-rata tertinggi: mahasiswa ke-" << tertinggi + 1
         << " (" << rata[tertinggi] << ")" << endl;
    cout << "rata-rata terendah: mahasiswa ke-" << terendah + 1
         << " (" << rata[terendah] << ")" << endl;
    cout << "jumlah mahasiswa dengan rata-rata minimal 75: "
         << jumlah_lulus << endl;

    return 0;
}
