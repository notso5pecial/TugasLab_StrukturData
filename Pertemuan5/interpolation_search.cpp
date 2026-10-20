#include <iostream>
using namespace std;

//membuat fungsi
int interpolationSearch (int data[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && 
           target >= data[low] &&
           target <= data[high]) { // memastikan target berada dalam rentang data
        
        if (data[low] == data[high]) {
            if (data[low] == target) {
                return low; // 8
            } 
            return -1;
        }
        
        // mengubah int ke double
        int pos = low + (int)(double)(target - data[low]) / 
                (data[high] - data[low]) * (high - low); // 4

        if (data[pos] == target) { //20
            return pos; // return indeks
        } else if (data[pos] < target) {
            low = pos + 1; // target di kanan
        } else {
            high = pos - 1; // target di kiri
        }
    }

    return -1;
}

int main() {
    int data[] = {0, 5, 10, 15, 20, 25};
    int n = 6;
    int target = 20;

    // position = (20 - 0) / (25 - 0) * (5 - 0) + 0 = 4 -> nilai 20

    int hasil = interpolationSearch(data, n, target); // hasil = 4

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}