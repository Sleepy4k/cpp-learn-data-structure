#include <iostream>

using namespace std;

/**
 * Deklarasi struktur dengan nama
 */
struct Siswa {
  string nama;
  int umur;
  string hobi[3];
};

int main() {
  /**
   * Biasanya kita mendeklarasikan struktur pada variable
   * Dengan cara "Siswa siswa1", hal tersebut memang sudah biasa digunakan
   * Namun jika kita menggunakan nya untuk 100 data maka waktu kita
   * Akan habis untuk mendeklarasikan variable,
   * 
   * Kita dapat mengatasi nya dengan array struktur, dengan contoh
   * 
   * Siswa siswa[2];
   * siswa[0] = {"Abdul", 20, {"Makan", "Mancing", "Tidur"}}
   * 
   * Dengan ini kita dapat menghemat efisiensi kerja kita
   */

  Siswa siswa[2];
 
  siswa[0] = {"Abdul", 20, {"Makan", "Mancing", "Tidur"}};
  siswa[1] = {"Iqbal", 23, {"Renang", "Mendaki", "Tidur"}};

  for (int i = 0; i < 2; i++) {
    cout << "Nama siswa " << i + 1 << " : " << siswa[i].nama << endl;
    cout << "Umur siswa " << i + 1 << " : " << siswa[i].umur << endl;
    cout << "Hobi siswa " << i + 1 << " : ";

    for (int j = 0; j < 3; j++) {
      cout << siswa[i].hobi[j];

      if (j < 2) cout << ", ";
      else cout << endl;
    }

    cout << endl;
  }
}

