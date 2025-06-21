#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

// Menambah pembersih layar terminal atau console
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Menambahkan struktur node tiket
struct Tiket {
    string namaPembeli;
    string judulFilm;
    int jumlahTiket;
    int hargaPerTiket;
    Tiket* next;
};

 // Menambahkan tiket baru ke dalam linked list
void tambahTiket(Tiket*& head, string nama, string judul, int jumlah, int harga) {
    Tiket* baru = new Tiket{nama, judul, jumlah, harga, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Tiket* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
    cout << "\nTiket berhasil ditambahkan atas nama " << nama << endl;
}

 // Menambahkan tampilan semua tiket
void tampilkanTiket(Tiket* head) {
    if (head == nullptr) {
        cout << "\nBelum ada data pembelian tiket.\n";
        return;
    }
    cout << "Daftar Pemesanan Tiket:\n";
    while (head != nullptr) {
        cout << "- Nama Pemesan : " << head->namaPembeli << endl;
        cout << "  Judul Film   : " << head->judulFilm << endl;
        cout << "  Jumlah Tiket : " << head->jumlahTiket << endl;
        cout << "  Harga/Tiket  : Rp" << head->hargaPerTiket << endl;
        cout << "  Total Bayar  : Rp" << head->jumlahTiket * head->hargaPerTiket << "\n\n";
        head = head->next;
    }
}

// Menambahkan tampilan daftar film dan harga
void tampilkanFilmSedangTayang() {
    cout << "===== FILM SEDANG TAYANG =====\n";
    cout << "1. Jumbo\n";
    cout << "2. Agak Laen\n";
    cout << "3. Laskar Pelangi\n";
    cout << "4. Dua Garis Biru\n";
    cout << "5. Kisah Tanah Jawa\n";
    cout << "6. Habibie dan Ainun\n\n";
    cout << "========= HARGA TIKET ========\n";
    cout << "REGULER: Rp. 45.000\n";
    cout << "PREMIERE: Rp. 70.000\n";
}