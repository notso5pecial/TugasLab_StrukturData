#include <iostream>
#include <string>
using namespace std;

struct NodeAntrean {
    string nama;
    int idBuku;
    NodeAntrean* next;
};

NodeAntrean* front = nullptr;
NodeAntrean* rear = nullptr;

void enqueue(string nama, int idBuku) {
    NodeAntrean* baru = new NodeAntrean();
    baru->nama = nama;
    baru->idBuku = idBuku;
    baru->next = nullptr;

    if (front == nullptr) {
        front = baru;
        rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
}

bool dequeue(string& nama, int& idBuku) {
    if (front == nullptr) return false;

    NodeAntrean* hapus = front;
    nama = hapus->nama;
    idBuku = hapus->idBuku;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete hapus;
    return true;
}

void tampilAntrean() {
    cout << "Antrean peminjaman (depan -> belakang):" << endl;
    if (front == nullptr) {
        cout << "(kosong)" << endl;
        return;
    }
    NodeAntrean* temp = front;
    int no = 1;
    while (temp != nullptr) {
        cout << no++ << ". " << temp->nama << " (ID buku: " << temp->idBuku << ")" << endl;
        temp = temp->next;
    }
}

struct NodeRiwayat {
    string nama;
    int idBuku;
    NodeRiwayat* next;
};

NodeRiwayat* top = nullptr;

void push(string nama, int idBuku) {
    NodeRiwayat* baru = new NodeRiwayat();
    baru->nama = nama;
    baru->idBuku = idBuku;
    baru->next = top;
    top = baru;
}

bool pop(string& nama, int& idBuku) {
    if (top == nullptr) return false;

    NodeRiwayat* hapus = top;
    nama = hapus->nama;
    idBuku = hapus->idBuku;
    top = top->next;
    delete hapus;
    return true;
}

void tampilRiwayat() {
    cout << "Riwayat pengembalian (terbaru -> terlama):" << endl;
    if (top == nullptr) {
        cout << "(kosong)" << endl;
        return;
    }
    NodeRiwayat* temp = top;
    int no = 1;
    while (temp != nullptr) {
        cout << no++ << ". " << temp->nama << " mengembalikan buku ID " << temp->idBuku << endl;
        temp = temp->next;
    }
}

struct NodeBuku {
    int id;
    NodeBuku* kiri;
    NodeBuku* kanan;
};

NodeBuku* root = nullptr;

void tambahBuku(NodeBuku*& node, int id) {
    if (node == nullptr) {
        node = new NodeBuku();
        node->id = id;
        node->kiri = nullptr;
        node->kanan = nullptr;
    } else if (id < node->id) {
        tambahBuku(node->kiri, id);
    } else if (id > node->id) {
        tambahBuku(node->kanan, id);
    } else {
        cout << "ID buku " << id << " sudah ada" << endl;
    }
}

bool cariBuku(NodeBuku* node, int id) {
    if (node == nullptr) return false;
    if (id == node->id) return true;
    if (id < node->id) return cariBuku(node->kiri, id);
    return cariBuku(node->kanan, id);
}

void preOrder(NodeBuku* node) {
    if (node != nullptr) {
        cout << node->id << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

void inOrder(NodeBuku* node) {
    if (node != nullptr) {
        inOrder(node->kiri);
        cout << node->id << " ";
        inOrder(node->kanan);
    }
}

void postOrder(NodeBuku* node) {
    if (node != nullptr) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->id << " ";
    }
}

void tampilBST() {
    if (root == nullptr) {
        cout << "BST kosong" << endl;
        return;
    }
    cout << "Pre-Order  : "; preOrder(root);  cout << endl;
    cout << "In-Order   : "; inOrder(root);   cout << endl;
    cout << "Post-Order : "; postOrder(root); cout << endl;
}

void hapusBST(NodeBuku* node) {
    if (node != nullptr) {
        hapusBST(node->kiri);
        hapusBST(node->kanan);
        delete node;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nSISTEM ANTREAN DAN PENGELOLAAN BUKU PERPUSTAKAAN" << endl;
        cout << "1. Tambah buku ke BST" << endl;
        cout << "2. Cari buku berdasarkan ID" << endl;
        cout << "3. Tambah mahasiswa ke antrean peminjaman (Enqueue)" << endl;
        cout << "4. Proses peminjaman (Dequeue)" << endl;
        cout << "5. Catat pengembalian buku (Push)" << endl;
        cout << "6. Batalkan pengembalian terakhir (Pop)" << endl;
        cout << "7. Tampilkan antrean peminjaman" << endl;
        cout << "8. Tampilkan riwayat pengembalian" << endl;
        cout << "9. Tampilkan BST (Pre-Order, In-Order, Post-Order)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            cout << "Masukkan ID buku: ";
            cin >> id;
            tambahBuku(root, id);
        } else if (pilihan == 2) {
            int id;
            cout << "Masukkan ID buku yang dicari: ";
            cin >> id;
            if (cariBuku(root, id)) cout << "Buku dengan ID " << id << " ditemukan" << endl;
            else cout << "Buku dengan ID " << id << " tidak ditemukan" << endl;
        } else if (pilihan == 3) {
            string nama;
            int id;
            cin.ignore();
            cout << "Nama mahasiswa: ";
            getline(cin, nama);
            cout << "ID buku yang dipinjam: ";
            cin >> id;
            enqueue(nama, id);
            cout << nama << " masuk antrean" << endl;
        } else if (pilihan == 4) {
            string nama;
            int id;
            if (dequeue(nama, id)) {
                if (cariBuku(root, id)) cout << nama << " berhasil meminjam buku ID " << id << endl;
                else cout << nama << " gagal meminjam, buku ID " << id << " tidak ada di BST" << endl;
            } else {
                cout << "Antrean kosong" << endl;
            }
        } else if (pilihan == 5) {
            string nama;
            int id;
            cin.ignore();
            cout << "Nama mahasiswa: ";
            getline(cin, nama);
            cout << "ID buku yang dikembalikan: ";
            cin >> id;
            push(nama, id);
            cout << "Pengembalian dicatat" << endl;
        } else if (pilihan == 6) {
            string nama;
            int id;
            if (pop(nama, id)) cout << "Riwayat terakhir dihapus: " << nama << " (ID buku " << id << ")" << endl;
            else cout << "Riwayat kosong" << endl;
        } else if (pilihan == 7) {
            tampilAntrean();
        } else if (pilihan == 8) {
            tampilRiwayat();
        } else if (pilihan == 9) {
            tampilBST();
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    string n; int i;
    while (dequeue(n, i)) {}
    while (pop(n, i)) {}
    hapusBST(root);

    return 0;
}
