#include <iostream>

using namespace std;

/**
 * Pendeklarasian struktur dapat kita buat dengan format
 * 
 * struct nama_struktur {
 *  tipe_data nama_variable;
 * };
 */
struct Siswa {
  string nama;
  int umur;
};

/**
 * Namun kita dapat langsung membuat variable ke dalam struktur
 * Terdapat 2 cara, membuat struktur dengan nama, atau tanpa nama
 * Untuk struktur dengan nama kita dapat membuat dengan format
 * 
 * struct Mahasiswa {
 *  tipe_data nama_variable;
 * } mhs1, mhs2;
 * 
 * Perlu di catat bahwa, struktur dengan nama dan terdapat variable
 * Semua akan termasuk global data karena dapat digunakan di semua function atau kode
 */
struct {
  string nim;
  string nama;
  string jurusan;
  int umur;
} mhs1, mhs2;

int main() {
  /**
   * Memasukan value pada struktur terdapat beberapa cara
   * Untuk cara yang paling tradisional atau paling mudah yaitu
   * Memasukan value pada tiap variable nya, dengan contoh
   * 
   * mhs1.nim = "123"
   * mhs1.nama = "Abdul"
   * mhs1.jurusan = "Sistem Informasi"
   * mhs1.umur = 20
   * 
   * Namun hal ini memakan banyak waktu karena harus menuliskan
   * Tiap tiap variable pada struktur, Kita bisa gunakan cara modern
   * Namun perlu diingat cara ini resiko error yang cukup tinggi,
   * Karena membutuhkan ketelitian, Berikut contoh nya
   * 
   * mhs1 = {"123", "Abdul", "Sistem Informasi", 20}
   */

  mhs1.nim = "19321314242";
  mhs1.nama = "Budi Sudrajat";
  mhs1.jurusan = "Teknik Informatika";
  mhs1.umur = 21;

  mhs2 = {"32432443545", "Panjar Granowo", "Teknik Elektro", 43};

  cout << "NIM Mahasiswa 1 : " << mhs1.nim << endl;
  cout << "Nama Mahasiswa 1 : " << mhs1.nama << endl;
  cout << "Jurusan Mahasiswa 1 : " << mhs1.jurusan << endl;
  cout << "Umur Mahasiswa 1 : " << mhs1.umur << endl;

  cout << "NIM Mahasiswa 2 : " << mhs2.nim << endl;
  cout << "Nama Mahasiswa 2 : " << mhs2.nama << endl;
  cout << "Jurusan Mahasiswa 2 : " << mhs2.jurusan << endl;
  cout << "Umur Mahasiswa 2 : " << mhs2.umur << endl;

  Siswa siswa1;

  siswa1.nama = "Munaroh";
  siswa1.umur = 18;

  cout << "Nama Siswa 1 : " << mhs2.nama << endl;
  cout << "Umur Siswa 1 : " << mhs2.umur << endl;

  return 0;
}
