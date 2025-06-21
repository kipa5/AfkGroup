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