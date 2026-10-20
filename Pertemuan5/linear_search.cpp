#include <iostream>
using namespace std;

int linearSearch(int data[], int n, int target){
    for (int i = 0; i < n; i++){
        if (data[i] == target) return i;
    }
    return -1; 
}

int main(){
    int data[] = {80, 100, 3, 40, 0, 22, 11};
    int n = 7;
    int target = 3;

    int hasil = linearSearch(data, n, target);

    if (hasil != -1){
        cout << "Data ditemukan pada indeks: " << hasil << endl;
    }else{
        cout << "Data tidak ditemukan" << endl;
    }

}