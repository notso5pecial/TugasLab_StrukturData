#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

const int EMPTY = 0;
const int OCCUPIED = 1;
const int DELETED = 2;

class HashTable {
private:
    vector<pair<long long, string>> table; // pair: NIM, nama
    vector<int> slotStatus;

    int primaryHash(long long nim) {
        return nim % TABLE_SIZE;
    }

    int secondaryHash(long long nim) {
        return 7 - (nim % 7);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        slotStatus.resize(TABLE_SIZE, EMPTY);
    }

    void insert(long long nim, string name) {
        int index = primaryHash(nim);
        int step = secondaryHash(nim);
        int startIndex = index;
        int deletedIndex = -1; 

        do {
            if (slotStatus[index] == OCCUPIED && table[index].first == nim) {
                table[index].second = name;
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
                return;
            }

            index = (index + step) % TABLE_SIZE;
        } while (index != startIndex);

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(nim, name);
            slotStatus[deletedIndex] = OCCUPIED;
        } else {
            cout << "Tabel penuh, NIM " << nim << " gagal disimpan" << endl;
        }
    }

    void search(long long nim) {
        int index = primaryHash(nim);
        int step = secondaryHash(nim);
        int startIndex = index;

        while (slotStatus[index] != EMPTY) {
            if (slotStatus[index] == OCCUPIED && table[index].first == nim) {
                cout << "Data ditemukan di index " << index << " : "
                     << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == startIndex) {
                break;
            }
        }

        cout << "Data dengan NIM " << nim << " tidak ditemukan" << endl;
    }

    void remove(long long nim) {
        int index = primaryHash(nim);
        int step = secondaryHash(nim);
        int startIndex = index;

        while (slotStatus[index] != EMPTY) {
            if (slotStatus[index] == OCCUPIED && table[index].first == nim) {
                slotStatus[index] = DELETED;
                cout << "Data NIM " << nim << " berhasil dihapus" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == startIndex) {
                break;
            }
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

int main() {
    HashTable hashTable;
    int choice;

    do {
        cout << "\n MENU HASH TABLE (Double Hashing)" << endl;
        cout << "1. Insert data mahasiswa" << endl;
        cout << "2. Search data berdasarkan NIM" << endl;
        cout << "3. Remove data berdasarkan NIM" << endl;
        cout << "4. Tampilkan hash table" << endl;
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
        } else if (choice != 0) {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 0);

    cout << "\nIsi hash table setelah seluruh operasi:" << endl;
    hashTable.display();

    return 0;
}