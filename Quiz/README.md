Identitas Diri
Nama Lengkap : Naila Azzahra
NIM          : 251401026
Lab          : 3

Deskripsi Singkat Setiap Program

soal1_nilai_mahasiswa.cpp (Sistem Pengelolaan Nilai Mahasiswa) Program ini dibuat untuk mengelola data mahasiswa yang terdiri dari NIM, nama, dan nilai. Data mahasiswa disimpan menggunakan Single Linked List, sedangkan kumpulan nilainya disalin ke Dynamic Array lalu diurutkan dari yang terkecil ke terbesar menggunakan Insertion Sort. Dilengkapi juga fitur pencarian mahasiswa berdasarkan NIM menggunakan Linear Search dan pencarian nilai tertentu menggunakan Binary Search.

soal2_perpustakaan.cpp (Sistem Antrean dan Pengelolaan Buku Perpustakaan) Program ini mensimulasikan alur pelayanan di perpustakaan kampus. Di dalamnya menggunakan struktur data Queue untuk antrean peminjaman buku (FIFO), Stack untuk riwayat pengembalian buku (LIFO), dan Binary Search Tree (BST) untuk menyimpan serta mencari ID buku, lengkap dengan traversal Pre-Order, In-Order, dan Post-Order.

soal3_rute_kampus.cpp (Sistem Pencarian Rute di Lingkungan Kampus) Program ini memodelkan peta rute antar lokasi di area kampus (vertex A sampai F) menggunakan representasi Adjacency Matrix. Program dapat menelusuri graf menggunakan algoritma BFS (Breadth-First Search) dan DFS (Depth-First Search), serta mencari rute terpendek beserta total jaraknya menggunakan algoritma Dijkstra. Pengguna dapat memilih sendiri vertex awal dan vertex tujuan.

soal4_hash_table.cpp (Pengelolaan Data Mahasiswa Menggunakan Hash Table) Program ini menyimpan data NIM dan nama mahasiswa menggunakan Hash Table berukuran 20. Program menerapkan metode Double Hashing untuk mengatasi tabrakan data (collision) serta fitur lazy deletion (penandaan slot DELETED) agar penghapusan data tidak memutus jalur pencarian data lain. Tersedia fitur Insert, Search, Remove, Display, dan pengujian otomatis dengan 15 data.

Struktur Folder Proyek
TugasLab_StrukturData/Quiz/

├── soal1_nilai_mahasiswa.cpp

├── soal2_perpustakaan.cpp

├── soal3_rute_kampus.cpp

├── soal4_hash_table.cpp

└── README.md

Cara Menjalankan Program
Bisa dengan klik ikon panah (Run) pada VS Code yang berisi kodingan, atau lewat terminal:

1. Kompilasi dan Jalankan Soal 1
g++ soal1_nilai_mahasiswa.cpp -o soal1
./soal1

2. Kompilasi dan Jalankan Soal 2
g++ soal2_perpustakaan.cpp -o soal2
./soal2

3. Kompilasi dan Jalankan Soal 3
g++ soal3_rute_kampus.cpp -o soal3
./soal3

4. Kompilasi dan Jalankan Soal 4
g++ soal4_hash_table.cpp -o soal4
./soal4


Tautan Video Penjelasan YouTube
https://youtu.be/VdBzeqdLt1g (hanya soal 1, waktu tidak cukup kalau mau nambah lagi :')
