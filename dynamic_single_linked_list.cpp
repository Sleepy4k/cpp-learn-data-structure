#include <iostream>

using namespace std;

/**
 * Mendeklarasikan sebuah struktur buku
 * Dan membuat variable pendukung untuk linked list
 */
struct Buku {
  string judul;
  string pengarang;
  int tahunTerbit;

  Buku *next;
} *head, *tail, *cur, *newNode, *del, *before;

/**
 * @brief Membuat prosedural untuk menginisiasi data pada single linked list
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * 
 * @return void
 */
void initSingleLinkedList(string judul, string pengarang, int tahunTerbit) {
  head = new Buku();
  head->judul = judul;
  head->pengarang = pengarang;
  head->tahunTerbit = tahunTerbit;
  head->next = NULL;
  tail = head;
}

/**
 * @brief Menghitung total data pada single linked list
 * 
 * @return void
 */
int countSingleLinkedList() {
  cur = head;

  int totalData = 0;

  while (cur != NULL) {
    totalData++;
    cur = cur->next;
  }

  return totalData;
}

/**
 * @brief Menambahkan data pada head sehingga menjadi data pertama atau leader
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * 
 * @return void
 */
void addHead(string judul, string pengarang, int tahunTerbit) {
  newNode = new Buku();
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tahunTerbit;
  newNode->next = head;
  head = newNode;
}

/**
 * @brief Menambahkan data pada ekor sehingga menjadi data terkahir atau tail paling akhir
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * 
 * @return void
 */
void addTail(string judul, string pengarang, int tahunTerbit) {
  newNode = new Buku();
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tahunTerbit;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

/**
 * @brief Menambahkan data diantara head dan tail sehingga data berada di tengah tengah
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * @param posisi integer
 * 
 * @return void
 */
void addMiddle(string judul, string pengarang, int tahunTerbit, int posisi) {
  if (posisi < 1 || posisi > countSingleLinkedList()) cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1) cout << "Posisi berada pada head, silahkan gunakan addHead" << endl;
  else {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
  
    cur = head;
    int nomor = 1;

    while (nomor < posisi -1) {
      cur = cur->next;
      nomor++;
    }

    newNode->next = cur->next;
    cur->next = newNode;
  }
}

/**
 * @brief Menghapus data head sehingga head di gantikan data ke 2
 * 
 * @return void
 */
void removeHead() {
  del = head;
  head = head->next;
  delete del;
}

/**
 * @brief Menghapus data head sehingga head di gantikan data ke 2
 * 
 * @return void
 */
void removeTail() {
  del = tail;
  cur = head;

  while (cur->next != del) {
    cur = cur->next;
  }

  tail = cur;
  tail->next = NULL;
  delete del;
}

/**
 * @brief Menghapus data tengah sehingga data tengah di gantikan oleh data selanjutnya
 * 
 * @param posisi integer
 * 
 * @return void
 */
void removeMiddle(int posisi) {
  if (posisi < 1 || posisi > countSingleLinkedList()) cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1) cout << "Posisi berada pada head, silahkan gunakan removeHead" << endl;
  else {
    cur = head;
    int nomor = 1;

    while (nomor <= posisi) {
      if (nomor == posisi - 1) before = cur;
      if (nomor == posisi) del = cur;

      cur = cur->next;
      nomor++;
    }

    before->next = cur;
    delete del;
  }
}

/**
 * @brief Mengubah nilai data dari head
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * 
 * @return void
 */
void changeHead(string judul, string pengarang, int tahunTerbit) {
  head->judul = judul;
  head->pengarang = pengarang;
  head->tahunTerbit = tahunTerbit;
}

/**
 * @brief Mengubah nilai data dari tail
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * 
 * @return void
 */
void changeTail(string judul, string pengarang, int tahunTerbit) {
  tail->judul = judul;
  tail->pengarang = pengarang;
  tail->tahunTerbit = tahunTerbit;
}

/**
 * @brief Mengubah nilai data dari data tengah
 * 
 * @param judul string
 * @param pengarang string 
 * @param tahunTerbit integer
 * @param posisi integer
 * 
 * @return void
 */
void changeMiddle(string judul, string pengarang, int tahunTerbit, int posisi) {
  if (posisi < 1 || posisi > countSingleLinkedList()) cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1) cout << "Posisi berada pada head, silahkan gunakan changeHead" << endl;
  else {
    cur = head;
    int nomor = 1;

    while (nomor < posisi) {
      cur = cur->next;
      nomor++;
    }

    cur->judul = judul;
    cur->pengarang = pengarang;
    cur->tahunTerbit = tahunTerbit;
  }
}

/**
 * @brief Mencetak data pada single linked list
 * 
 * @return void
 */
void printSingleLinkedList() {
  cout << "Menemukan total " << countSingleLinkedList() << " data pada single linked list" << endl;

  cur = head;

  while (cur != NULL) {
    cout << "Judul buku : " << cur->judul << endl;
    cout << "Pengarang buku : " << cur->pengarang << endl;
    cout << "Tahun terbit buku : " << cur->tahunTerbit << endl;

    cur = cur->next;
  }
}

int main() {
  initSingleLinkedList("Kata", "dia", 2018);

  printSingleLinkedList();

  cout << "\n" << endl;

  addHead("Dia adalah kakakku", "Gak paham", 2009);

  printSingleLinkedList();

  cout << "\n" << endl;

  addTail("Aroma Karsa", "dee", 2018);

  printSingleLinkedList();

  cout << "\n" << endl;

  removeHead();

  printSingleLinkedList();

  cout << "\n" << endl;

  addTail("11.11", "fiera", 2018);

  printSingleLinkedList();

  cout << "\n" << endl;

  removeTail();

  printSingleLinkedList();

  cout << "\n" << endl;

  changeHead("Berhenti", "Gia", 2018);

  printSingleLinkedList();

  cout << "\n" << endl;

  addMiddle("Manusia", "Toer", 2005, 2);

  printSingleLinkedList();

  cout << "\n" << endl;

  addMiddle("Menara", "Ahmad", 2009, 2);

  printSingleLinkedList();

  cout << "\n" << endl;

  removeMiddle(5);

  printSingleLinkedList();

  cout << "\n" << endl;

  changeMiddle("sang", "Andrea", 2006, 2);

  printSingleLinkedList();

  cout << "\n" << endl;
}