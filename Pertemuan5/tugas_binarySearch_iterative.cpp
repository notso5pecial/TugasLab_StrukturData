#include <iostream>
using namespace std;

void urutkanAscending(int data[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int binarySearch(int data[], int n, int target){
    int l = 0, r = n-1;
    while (l <= r){
        int mid = l + (r-l)/2;
        
        if (data[mid] == target) return mid;
        else if ((data[mid] < target)) l = mid + 1;
        else r = mid - 1;
    }
    return -1; 
}

int main(){
    int data[100];
    int n;
    int target;

    cout << "Masukkan jumlah data nilai mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Nilai ke-" << i+1 << ": ";
        cin >> data[i];
    }
    urutkanAscending(data, n);

    cout << "Data setelah diurutkan (ascending): ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    int hasil = binarySearch(data, n, target);
    if (hasil != -1){
        cout << "Data ditemukan pada indeks: " << hasil << endl;
    }else{
        cout << "Data tidak ditemukan" << endl;
    }
}