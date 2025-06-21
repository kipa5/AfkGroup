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