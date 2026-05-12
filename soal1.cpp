#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nim, nama;
    int semester;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa 1 sampe 5: ";
    cin >> jumlah;

    if (jumlah < 1 || jumlah > 5) {
        cout << "Masukin jumlah mahasiswa 1-5 yh bg" << endl;
        return 1;
    }

    cout << "\n--- Input Data Mahasiswa ---" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "NIM      : ";
        cin >> mhs[i].nim;
        
        cin.ignore(); 
        cout << "Nama     : ";
        getline(cin, mhs[i].nama);
        
        cout << "Semester : ";
        cin >> mhs[i].semester;
        
        cout << "IPK      : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    cout << "\n--- Tabel Data Mahasiswa ---\n";
    cout << left << setw(4) << "No" << " | "
         << setw(12) << "NIM" << " | "
         << setw(20) << "Nama" << " | "
         << setw(10) << "Semester" << " | "
         << "IPK" << endl;
    cout << "--------------------------------------------------------------\n";
    
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(4) << i + 1 << " | "
             << setw(12) << mhs[i].nim << " | "
             << setw(20) << mhs[i].nama << " | "
             << setw(10) << mhs[i].semester << " | "
             << fixed << setprecision(2) << mhs[i].ipk << endl;
    }

    int nilaiTertinggi = 0;
    float totalIPK = 0.0;

    for (int i = 0; i < jumlah; i++) {
        if (mhs[i].ipk > mhs[nilaiTertinggi].ipk) {
            nilaiTertinggi = i;
        }
        totalIPK += mhs[i].ipk;
    }

    float rataRata = totalIPK / jumlah;

    cout << "\n--- Statistik ---" << endl;
    cout << "Mahasiswa dengan IPK Tertinggi:" << endl;
    cout << "- NIM      : " << mhs[nilaiTertinggi].nim << endl;
    cout << "- Nama     : " << mhs[nilaiTertinggi].nama << endl;
    cout << "- Semester : " << mhs[nilaiTertinggi].semester << endl;
    cout << "- IPK      : " << mhs[nilaiTertinggi].ipk << endl;
    
    cout << "\nRata-rata IPK seluruh mahasiswa: " << rataRata << endl;

    int cariSemester;
    bool ketemu = false;

    cout << "\n--- Pencarian Data ---" << endl;
    cout << "Masukkan nomor semester yang dicari: ";
    cin >> cariSemester;

    cout << "Hasil pencarian mahasiswa di semester" << cariSemester << ":" << endl;
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i].semester == cariSemester) {
            cout << "- " << mhs[i].nama << " (NIM: " << mhs[i].nim << ")" << endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "Tidak ada mahasiswa pada semester tersebut" << endl;
    }

    return 0;
}