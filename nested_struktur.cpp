#include <iostream>

using namespace std;

/**
 * Dalam membuat struktur dalam struktur terapat beberapa cara
 * Yaitu inisiasi struktur di dalam struktur
 * Atau memanggil struktur di dalam struktur
 */

// Berikut contoh inisiasi struktur di dalam struktur
struct Karyawan {
  string nama;
  int umur;
  struct {
    string nama;
    string alamat;
  } toko;
};

// Berikut contoh memanggil struktur di dalam struktur
struct Kampus {
  string nama;
  string alamat;
  int tahun_berdiri;
};

struct Mahasiswa {
  string nama;
  string jurusan;
  int umur;
  Kampus kampus;
};

int main() {
  // Implementasi contoh inisiasi struktur di dalam struktur
  Karyawan bimo;
  bimo = {"Bim", 21, {"SRC", "Indonesia"}};

  cout << "Nama Karyawan : " << bimo.nama << endl;
  cout << "Umur Karyawan : " << bimo.umur << endl;
  cout << "Nama Toko Karyawan : " << bimo.toko.nama << endl;
  cout << "Alamat Toko Karyawan : " << bimo.toko.alamat << endl;

  cout << endl;

  // Implementasi contoh pemanggilan struktur di dalam struktur
  Kampus ittp;
  ittp = {"Telkom", "Panjaitan", 2005};

  Mahasiswa naka;
  naka = {"Naka", "TI", 21, ittp};

  cout << "Nama Mahasiswa : " << naka.nama << endl;
  cout << "Jurusan Mahasiswa : " << naka.jurusan << endl;
  cout << "Umur Mahasiswa : " << naka.umur << endl;
  cout << "Nama kampus Mahasiswa : " << naka.kampus.nama << endl;
  cout << "Alamat kampus Mahasiswa : " << naka.kampus.alamat << endl;
  cout << "Tahun berdiri kampus Mahasiswa : " << naka.kampus.tahun_berdiri << endl;
}