#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama;
    int jumlah;
    string tipe;
    Node* next;


    Node(string nama, int jumlah, string tipe) {
        this->nama = nama;
        this->jumlah = jumlah;
        this->tipe = tipe;
        this->next = NULL;
    }
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;
        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk : ";
        getline(cin, nama);
        cout << "Jumlah Produk : ";
        cin >> jumlah;
        cin.ignore(); // Membersihkan buffer input
        cout << "Tipe Produk : ";
        getline(cin, tipe);

        Node* newNode = new Node(nama, jumlah, tipe);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;

            while (current != NULL) {

                cout << "Nama: " << current->nama << endl;
                cout << "Jumlah: " << current->jumlah << endl;
                cout << "Tipe: " << current->tipe << endl;
                cout << endl;
                current = current->next;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);
            Node* current = head;

            int posisi = 0;

            while (current != NULL) {
                posisi++;
                if (current->nama == targetNama) {
                    cout << "Posisi ke-" << posisi << endl;
                    cout << "Nama produk: " << current->nama << endl;
                    cout << "Jumlah produk: " << current->jumlah << endl;
                    cout << "Tipe produk: " << current->tipe << endl;

                }
                current = current->next;

            }

            if (current == NULL) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algoritmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        Node* current = head;
        Node* last = NULL;

        current = head;
        bool swapped;

        do {
            swapped = false;
            current = head;

            while (current->next != NULL) {
                last = current->next;

                if (current->jumlah > last->jumlah) {
                    // Melakukan pertukaran posisi node
                    string tempNama = current->nama;
                    int tempJumlah = current->jumlah;
                    string tempTipe = current->tipe;

                    current->nama = last->nama;
                    current->jumlah = last->jumlah;
                    current->tipe = last->tipe;

                    last->nama = tempNama;
                    last->jumlah = tempJumlah;
                    last->tipe = tempTipe;

                    swapped = true;
                }

                current = current->next;
            }
        } while (swapped);
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;

    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algoritmaSortByJumlahProduk();
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;

    } while (pilihan != 5);

    return 0;
}


//2. Single Linked-List

//3. buat node front menjadi last node dan last node menjadi new node jika antriannya kosong

//4. saat ingin mengatur urutan yang ingin dikerjakan oleh program tersebut, semisal dalam program
//   matematika yang mengharuskan perkalian dulu baru pertambahan dan pengurangan

//5. a. 5
//   b. Dengan metode Preorder Traversal:
// Metode preorder traversal membaca struktur pohon dengan urutan akar -> kiri -> kanan.Contohnya :
// Dalam preorder traversal, urutan membaca struktur pohon adalah : A - B - D - E - C - F - G.
// 50-48-30-20-15-25-32-31-35-70-65-67-66-69-90-98-94-99
