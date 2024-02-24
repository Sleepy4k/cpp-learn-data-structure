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
    cout << "===============================" << endl;

    cur = cur->next;
  }

  cout << "\n" << endl;
}

/**
 * @brief Mengatur form data menggunakan pointer agar data dapat diubah
 * 
 * @param judul 
 * @param pengarang 
 * @param tahunTerbit
 * 
 * @return void
 */
void handleDataForm(string *judul, string *pengarang, int *tahunTerbit) {
  cout << "Masukan judul buku : ";
  cin >> *judul;

  cout << "Masukan pengarang buku : ";
  cin >> *pengarang;

  cout << "Masukan tahun terbit buku : ";
  cin >> *tahunTerbit;
}

int main() {
  int pilihan;
  bool isRunning = true;

  do {
    pilihan = 0;
    cout << "Menu Single Linked List" << endl;
    cout << "1. Inisiasi Single Linked List" << endl;
    cout << "2. Menambahkan data" << endl;
    cout << "3. Menghapus data" << endl;
    cout << "4. Mengubah data" << endl;
    cout << "5. Menampilkan data" << endl;
    cout << "6. Keluar" << endl;
    cout << "===============================" << endl;
    cout << "Masukan pilihan : ";
    cin >> pilihan;

    string judul, pengarang;
    int tahunTerbit, posisi;

    switch (pilihan) {
      case 1:
        handleDataForm(&judul, &pengarang, &tahunTerbit);
        initSingleLinkedList(judul, pengarang, tahunTerbit);
        break;
      case 2:
        cout << "Menu menambahkan data" << endl;
        cout << "1. Menambahkan data pada head" << endl;
        cout << "2. Menambahkan data pada tail" << endl;
        cout << "3. Menambahkan data pada tengah" << endl;
        cout << "===============================" << endl;
        cout << "Masukan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
          case 1:
            handleDataForm(&judul, &pengarang, &tahunTerbit);
            addHead(judul, pengarang, tahunTerbit);
            break;
          case 2:
            handleDataForm(&judul, &pengarang, &tahunTerbit);
            addTail(judul, pengarang, tahunTerbit);
            break;
          case 3:
            handleDataForm(&judul, &pengarang, &tahunTerbit);

            cout << "Masukan posisi buku : ";
            cin >> posisi;

            addMiddle(judul, pengarang, tahunTerbit, posisi);
            break;
          default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
        break;
      case 3:
        cout << "Menu menghapus data" << endl;
        cout << "1. Menghapus data pada head" << endl;
        cout << "2. Menghapus data pada tail" << endl;
        cout << "3. Menghapus data pada tengah" << endl;
        cout << "===============================" << endl;
        cout << "Masukan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
          case 1:
            removeHead();
            break;
          case 2:
            removeTail();
            break;
          case 3:
            cout << "Masukan posisi buku : ";
            cin >> posisi;

            removeMiddle(posisi);
            break;
          default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
        break;
      case 4:
        cout << "Menu mengubah data" << endl;
        cout << "1. Mengubah data pada head" << endl;
        cout << "2. Mengubah data pada tail" << endl;
        cout << "3. Mengubah data pada tengah" << endl;
        cout << "===============================" << endl;
        cout << "Masukan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
          case 1:
            handleDataForm(&judul, &pengarang, &tahunTerbit);
            changeHead(judul, pengarang, tahunTerbit);
            break;
          case 2:
            handleDataForm(&judul, &pengarang, &tahunTerbit);
            changeTail(judul, pengarang, tahunTerbit);
            break;
          case 3:
            handleDataForm(&judul, &pengarang, &tahunTerbit);

            cout << "Masukan posisi buku : ";
            cin >> posisi;

            changeMiddle(judul, pengarang, tahunTerbit, posisi);
            break;
          default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
        break;
      case 5:
        printSingleLinkedList();
        break;
      case 6:
        isRunning = false;
        break;
      default:
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }
  } while (isRunning);

  cout << "Program selesai" << endl;

  return 0;
}
