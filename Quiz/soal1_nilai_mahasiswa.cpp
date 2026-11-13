#include <iostream>
#include <string>
using namespace std;

// Single Linked List untuk menyimpan data mahasiswa
struct Mahasiswa {
    long long nim;
    string nama;
    int nilai;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;
Mahasiswa* tail = nullptr;
int jumlah = 0;

// Dynamic Array untuk menyimpan kumpulan nilai
int* arrNilai = nullptr;

void tambahMahasiswa(long long nim, string nama, int nilai) {
    Mahasiswa* baru = new Mahasiswa();
    baru->nim = nim;
    baru->nama = nama;
    baru->nilai = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    jumlah++;
}

// Membuat dynamic array dari nilai yang ada di linked list
void buatArrayNilai() {
    delete[] arrNilai;
    arrNilai = new int[jumlah];

    Mahasiswa* temp = head;
    int i = 0;
    while (temp != nullptr) {
        arrNilai[i++] = temp->nilai;
        temp = temp->next;
    }
}

// Insertion Sort ascending (terkecil -> terbesar)
void insertionSort(int data[], int n) {
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Linear Search berdasarkan NIM pada linked list
Mahasiswa* linearSearchNIM(long long nim) {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        if (temp->nim == nim) return temp;
        temp = temp->next;
    }
    return nullptr;
}

// Binary Search nilai pada array yang sudah terurut
int binarySearch(int data[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (data[mid] == target) return mid;
        else if (data[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void tampilData() {
    cout << "\nData Mahasiswa:" << endl;
    cout << "NIM\t\tNama\t\tNilai" << endl;
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        cout << temp->nim << "\t" << temp->nama << "\t\t" << temp->nilai << endl;
        temp = temp->next;
    }
}

void tampilNilai(int data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long nim;
        string nama;
        int nilai;

        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NIM   : ";
        cin >> nim;
        cin.ignore();
        cout << "Nama  : ";
        getline(cin, nama);
        cout << "Nilai : ";
        cin >> nilai;

        tambahMahasiswa(nim, nama, nilai);
    }

    buatArrayNilai();

    // Tampilkan data awal
    tampilData();
    cout << "\nNilai sebelum diurutkan : ";
    tampilNilai(arrNilai, jumlah);

    // Urutkan nilai dengan Insertion Sort
    insertionSort(arrNilai, jumlah);
    cout << "Nilai setelah diurutkan (terkecil -> terbesar) : ";
    tampilNilai(arrNilai, jumlah);

    int pilihan;
    do {
        cout << "\nMENU PENCARIAN" << endl;
        cout << "1. Cari mahasiswa berdasarkan NIM (Linear Search)" << endl;
        cout << "2. Cari nilai tertentu (Binary Search)" << endl;
        cout << "3. Tampilkan data dan hasil pengurutan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            long long nim;
            cout << "Masukkan NIM yang dicari: ";
            cin >> nim;

            Mahasiswa* hasil = linearSearchNIM(nim);
            if (hasil != nullptr) {
                cout << "Data ditemukan -> NIM: " << hasil->nim
                     << ", Nama: " << hasil->nama
                     << ", Nilai: " << hasil->nilai << endl;
            } else {
                cout << "Data dengan NIM " << nim << " tidak ditemukan" << endl;
            }
        } else if (pilihan == 2) {
            int target;
            cout << "Masukkan nilai yang dicari: ";
            cin >> target;

            int idx = binarySearch(arrNilai, jumlah, target);
            if (idx != -1) {
                cout << "Nilai " << target << " ditemukan pada indeks " << idx
                     << " (setelah diurutkan)" << endl;
                cout << "Mahasiswa dengan nilai tersebut:" << endl;
                Mahasiswa* temp = head;
                while (temp != nullptr) {
                    if (temp->nilai == target) {
                        cout << "- " << temp->nim << " | " << temp->nama << endl;
                    }
                    temp = temp->next;
                }
            } else {
                cout << "Nilai " << target << " tidak ditemukan" << endl;
            }
        } else if (pilihan == 3) {
            tampilData();
            cout << "\nNilai terurut : ";
            tampilNilai(arrNilai, jumlah);
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    // Bebaskan memori
    delete[] arrNilai;
    while (head != nullptr) {
        Mahasiswa* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}
