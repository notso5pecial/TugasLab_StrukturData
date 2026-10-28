#include <iostream>
#include <string>
using namespace std;

int main(){
    string data[100];
    int n;

    cout << "Masukkan jumlah kata: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    for (int i = 1; i < n; i++){
        string key = data[i];
        int j = i - 1;

        cout << "\nLangkah " << i << " (key = " << key << ")" << endl;

        while (j >= 0 && data[j] > key){
            cout << "  Geser " << data[j] << " dari index " << j << " ke index " << j + 1 << endl;
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;

        cout << "  Hasil: ";
        for (int k = 0; k < n; k++){
            cout << data[k] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Insertion Sort: ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    return 0;
}