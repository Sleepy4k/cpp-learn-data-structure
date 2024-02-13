#include <iostream>

using namespace std;

// Deklarasi single linked list
struct Buku {
  // Komponen dari Linked List
  string judul;
  string pengarang;
  int tahunterbit;

  // Penunjuk node selanjutnya
  Buku *next;
};

int main() {
  // Inisiasi single linked list
  Buku *node1, *node2, *node3;

  /**
   * Terdapat 2 cara untuk menginisiasi single linked list
   * 1. Menggunakan malloc yaitu untuk inisiasi memory
   *   (Buku*) malloc(sizeof(Buku));
   * 2. Menggunakan inisiasi object
   *    new Buku();
   */
  node1 = new Buku();
  node2 = new Buku();
  node3 = new Buku();

  // Pengisian data dari node 1
  node1->judul = "Matematika";
  node1->pengarang = "Ahli Matematika";
  node1->tahunterbit = 1995;
  node1->next = node2;

  // Pengisian data dari node 2
  node2->judul = "Kakaku";
  node2->pengarang = "Adiknya";
  node2->tahunterbit = 2005;
  node2->next = node3;

  // Pengisian data dari node 3
  node3->judul = "Dia";
  node3->pengarang = "Aku";
  node3->tahunterbit = 2020;
  node3->next = NULL;

  // Menampilkan data dari single linked list
  Buku *data;
  data = node1;

  while (data != NULL) {
    cout << endl;
    cout << "Judul buku : " << data->judul << endl;
    cout << "Pengarang buku : " << data->pengarang << endl;
    cout << "Tahun terbit buku : " << data->tahunterbit << endl;

    data = data->next;
  }
}