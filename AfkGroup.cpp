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

// Menambahkan hapus sebagian atau semua tiket berdasarkan nama dan judul film
void hapusTiket(Tiket*& head, string nama, string judul) {
    Tiket* temp = head;
    Tiket* prev = nullptr;
    while (temp != nullptr) {
        if (temp->namaPembeli == nama && temp->judulFilm == judul) {
            cout << "\nJumlah tiket yang dipesan : " << temp->jumlahTiket << endl;
            int jumlahHapus;
            cout << "Jumlah tiket yang ingin dibatalkan : ";
            cin >> jumlahHapus;
            if (jumlahHapus <= 0 || jumlahHapus > temp->jumlahTiket) {
                cout << "Jumlah tiket tidak valid.\n";
                return;
            }
            if (jumlahHapus == temp->jumlahTiket) {
                if (prev == nullptr)
                    head = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                cout << "\nSemua tiket atas nama \"" << nama << "\" untuk film \"" << judul << "\" telah dihapus/dibatalkan.\n";
            } else {
                temp->jumlahTiket -= jumlahHapus;
                cout << "\n" << jumlahHapus << " tiket berhasil dibatalkan. Sisa tiket yang dimiliki : " << temp->jumlahTiket << endl;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "\nTiket atas nama \"" << nama << "\" untuk film \"" << judul << "\" tidak ditemukan.\n";
}

// Menambahkan hitung total pendapatan
int hitungPendapatan(Tiket* head) {
    int total = 0;
    while (head != nullptr) {
        total += head->jumlahTiket * head->hargaPerTiket;
        head = head->next;
    }
    return total;
}

// Menambahkan hapus semua data atau tiket
void hapusSemua(Tiket*& head) {
    while (head != nullptr) {
        Tiket* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nSemua data tiket telah dihapus.\n";
}

// Menambahkan fungsi utama
int main() {
    Tiket* daftarTiket = nullptr;
    int pilihan;
    string nama, judul;
    int jumlah, harga;
    char input;

    do {
        clearScreen();
        cout << "==============================";
        cout << "\n===== MENU TIKET BIOSKOP =====";
        cout << "\n==============================\n";
        cout << "1. Daftar Film Dan Harga\n";
        cout << "2. Pesan Tiket\n";
        cout << "3. Lihat Daftar Pesanan Tiket\n";
        cout << "4. Batalkan Tiket Yang Dipesan\n";
        cout << "5. Hitung Total Pendapatan\n";
        cout << "6. Hapus Semua Data Tiket\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                clearScreen();
                tampilkanFilmSedangTayang();
                cout << "\nTekan 'q' untuk kembali ke menu utama...";
                while ((input = getch()) != 'q');
                break;
            case 2:
                clearScreen();
                tampilkanFilmSedangTayang();
                cout << "\nNama Pemesan: ";
                getline(cin, nama);
                cout << "Judul Film  : ";
                getline(cin, judul);
                cout << "Jumlah Tiket: ";
                cin >> jumlah;
                cout << "Harga Tiket : Rp";
                cin >> harga;
                tambahTiket(daftarTiket, nama, judul, jumlah, harga);
                cout << "\nTekan 'q' untuk kembali ke menu...";
                while ((input = getch()) != 'q');
                break;
            case 3:
                clearScreen();
                tampilkanTiket(daftarTiket);
                cout << "\nTekan 'q' untuk kembali ke menu...";
                while ((input = getch()) != 'q');
                break;
            case 4:
                clearScreen();
                cout << "Masukkan Nama Pemesan : ";
                getline(cin, nama);
                cout << "Masukkan judul film  : ";
                getline(cin, judul);
                hapusTiket(daftarTiket, nama, judul);
                cout << "\nTekan 'q' untuk kembali ke menu...";
                while ((input = getch()) != 'q');
                break;
            case 5:
                clearScreen();
                cout << "Total pendapatan : Rp" << hitungPendapatan(daftarTiket) << endl;
                cout << "\nTekan 'q' untuk kembali ke menu...";
                while ((input = getch()) != 'q');
                break;
            case 6:
                clearScreen();
                hapusSemua(daftarTiket);
                cout << "\nTekan 'q' untuk kembali ke menu...";
                while ((input = getch()) != 'q');
                break;
            case 0:
                clearScreen();
                cout << "\nTerima kasih telah menggunakan sistem ini.\n";
                cout << "===========================================";
                cout << "\nNama Kelompok : Group AFK";
                cout << "\n================================";
                cout << "\nNama Anggota : ";
                cout << "\nMuhammad Aditya Ariyandi C030324129\n";
                cout << "Muhammad Faris Ryadinnor C030324085\n";
                cout << "Muhammad Jawamiul Khairi C030324089\n";
                break;
            default:
                clearScreen();
                cout << "\nPilihan tidak valid.\n";
                cout << "\nTekan 'q' untuk kembali ke menu...";
                while ((input = getch()) != 'q');
        }
    } while (pilihan != 0);

    return 0;
}