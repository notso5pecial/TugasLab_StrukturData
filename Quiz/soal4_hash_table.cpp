#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 20;

const int EMPTY = 0;
const int OCCUPIED = 1;
const int DELETED = 2;

class HashTable {
private:
    vector<pair<long long, string>> table; 
    vector<int> slotStatus;

    int hash1(long long key) {
        return key % 20;
    }

    int hash2(long long key) {
        return 19 - (key % 19);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        slotStatus.resize(TABLE_SIZE, EMPTY);
    }

    void insert(long long nim, string name) {
        int index = hash1(nim);
        int step = hash2(nim);
        int deletedIndex = -1;

        if (slotStatus[index] == OCCUPIED && table[index].first != nim) {
            cout << "[Collision] NIM " << nim << " bentrok di index " << index
                 << ", pakai step " << step << endl;
        }

        // maksimal TABLE_SIZE kali percobaan agar tidak looping selamanya
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (slotStatus[index] == OCCUPIED && table[index].first == nim) {
                table[index].second = name; // NIM sudah ada, update nama
                cout << "NIM " << nim << " sudah ada, nama diperbarui" << endl;
                return;
            }

            if (slotStatus[index] == DELETED && deletedIndex == -1) {
                deletedIndex = index;
            }

            if (slotStatus[index] == EMPTY) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }
                table[index] = make_pair(nim, name);
                slotStatus[index] = OCCUPIED;
                cout << "NIM " << nim << " disimpan di index " << index << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(nim, name);
            slotStatus[deletedIndex] = OCCUPIED;
            cout << "NIM " << nim << " disimpan di index " << deletedIndex << endl;
        } else {
            cout << "Tabel penuh, NIM " << nim << " gagal disimpan" << endl;
        }
    }

    void search(long long nim) {
        int index = hash1(nim);
        int step = hash2(nim);

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (slotStatus[index] == EMPTY) break;

            if (slotStatus[index] == OCCUPIED && table[index].first == nim) {
                cout << "Data ditemukan di index " << index << " : "
                     << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;
        }

        cout << "Data dengan NIM " << nim << " tidak ditemukan" << endl;
    }

    void remove(long long nim) {
        int index = hash1(nim);
        int step = hash2(nim);

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (slotStatus[index] == EMPTY) break;

            if (slotStatus[index] == OCCUPIED && table[index].first == nim) {
                slotStatus[index] = DELETED;
                cout << "Data NIM " << nim << " berhasil dihapus dari index " << index << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;
        }

        cout << "Data dengan NIM " << nim << " tidak ditemukan" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            if (slotStatus[i] == OCCUPIED) {
                cout << table[i].first << " - " << table[i].second;
            } else if (slotStatus[i] == DELETED) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }
            cout << endl;
        }
    }
};

void pengujian(HashTable& ht) {
    string nama[15] = {"Andi", "Budi", "Citra", "Dewi", "Eko", "Fajar", "Gita", "Hana",
                       "Indra", "Joko", "Kiki", "Lina", "Maya", "Nando", "Putri"};
    long long nim[15] = {2501, 2502, 2503, 2504, 2505, 2521, 2523, 2507, 2541, 2509,
                         2510, 2511, 2512, 2513, 2525};

    cout << "=== INSERT 15 DATA ===" << endl;
    for (int i = 0; i < 15; i++) {
        ht.insert(nim[i], nama[i]);
    }

    cout << "\n=== ISI HASH TABLE ===" << endl;
    ht.display();

    cout << "\n=== SEARCH ===" << endl;
    ht.search(2541);  
    ht.search(9999); 

    cout << "\n=== REMOVE ===" << endl;
    ht.remove(2521);  
    ht.remove(9999);  

    cout << "\n=== SETELAH PENGHAPUSAN ===" << endl;
    ht.display();

    cout << "\n=== SEARCH SETELAH HAPUS ===" << endl;
    ht.search(2521); 
    ht.search(2541);  

    cout << "\n=== INSERT ULANG SETELAH HAPUS ===" << endl;
    ht.insert(2561, "Rani"); 
    ht.display();
}

int main() {
    HashTable hashTable;
    int choice;

    do {
        cout << "\nMENU HASH TABLE (Double Hashing, ukuran 20)" << endl;
        cout << "1. Insert data mahasiswa" << endl;
        cout << "2. Search data berdasarkan NIM" << endl;
        cout << "3. Remove data berdasarkan NIM" << endl;
        cout << "4. Tampilkan hash table" << endl;
        cout << "5. Jalankan pengujian otomatis (15 data)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        if (choice == 1) {
            long long nim;
            string name;

            cout << "Masukkan NIM  : ";
            cin >> nim;
            cin.ignore();
            cout << "Masukkan nama : ";
            getline(cin, name);

            hashTable.insert(nim, name);
        } else if (choice == 2) {
            long long nim;
            cout << "Masukkan NIM yang dicari: ";
            cin >> nim;
            hashTable.search(nim);
        } else if (choice == 3) {
            long long nim;
            cout << "Masukkan NIM yang dihapus: ";
            cin >> nim;
            hashTable.remove(nim);
        } else if (choice == 4) {
            hashTable.display();
        } else if (choice == 5) {
            pengujian(hashTable);
        } else if (choice != 0) {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 0);

    return 0;
}
