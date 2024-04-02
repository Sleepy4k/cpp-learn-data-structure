#include <iostream>

using namespace std;

// struktur linked list
struct dataBarang{
  string namaBarang;
  int jumlahBarang, hargaBarang;

  // pointer
  dataBarang *prev;
  dataBarang *next;
} *head, *tail, *cur, *del, *newNode, *afterNode;


// Membuat prosedural untuk membuat inisiasi circurlar double linked list
void createDataBarang(string namaBarang, int jmlBarang, int hargaBarang) {
  // Iniasiasi variable head dengan data baru
  head = new dataBarang();

  head->namaBarang = namaBarang;
  head->jumlahBarang = jmlBarang;
  head->hargaBarang = hargaBarang;
  head->prev = head;
  head->next = head;

  // Set nilai tail menjadi data baru yaitu head
  tail = head;
}

// Membuat prosedural untuk menambahkan data pertama
void addFirst(string namaBarang, int jmlBarang, int hargaBarang) {
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    // Iniasiasi variable new node dengan data baru
    newNode = new dataBarang();

    newNode->namaBarang = namaBarang;
    newNode->jumlahBarang = jmlBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;

    // Set nilai sebelumnya pada head menjadi data baru
    head->prev = newNode;

    // Set nilai selanjutnya pada tail menjadi data baru
    tail->next = newNode;

    // Set variable head menjadi data baru
    head = newNode;
  }
}

// Membuat prosedural untuk menambahkan data terakhir
void addLast (string namaBarang, int jmlBarang, int hargaBarang) {
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    // Iniasiasi new node dengan data baru
    newNode = new dataBarang();

    newNode->namaBarang = namaBarang;
    newNode->jumlahBarang = jmlBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    
    // Set nilai sebelumnya pada head menjadi data baru
    head->prev = newNode;

    // Set nilai selanjutnya pada tail menjadi data baru
    tail->next = newNode;

    // Set variable tail menjadi data baru
    tail = newNode;
  }
}

// Membuat prosedural untuk menambahkan data tengah
void addMiddle(string namaBarang, int jmlBarang, int hargaBarang, int posisi) {
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    if (posisi == 1) cout << "Posisi 1 bukan posisi tengah" << endl;
    else if (posisi < 1) cout << "Posisi diluar jangkauan" << endl;
    else {
      // Iniasiasi variable new node dengan data baru
      newNode = new dataBarang();

      newNode->namaBarang = namaBarang;
      newNode->jumlahBarang = jmlBarang;
      newNode->hargaBarang = hargaBarang;

      // Melakukan transfer nilai next dan prev
      cur = head;

      int number = 1;
      
      while (number < posisi - 1) {
        number++;

        // Set nilai cur dengan nilai lanjutan dari cur
        cur = cur->next;
      }

      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

// Membuat prosedural untuk menghapus data pertama
void removeFirst() {
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// Membuat prosedural untuk menghapus data terakhir
void removeLast(){
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// Membuat prosedural untuk menghapus data tengah
void removeMiddle(int posisi) {
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    if (posisi == 1) cout << "Posisi 1 bukan posisi tengah" << endl;
    else if (posisi < 1) cout << "Posisi diluar jangkauan" << endl;
    else {
      // Melakukan transfer nilai next dan prev
      cur = head;

      int number = 1;
      
      while (number < posisi - 1) {
        number++;

        // Set nilai cur menjadi data lanjutan dari cur
        cur = cur->next;
      }

      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// Membuat prosedural untuk mencetak nilai circular double linked list
void printDataBarang() {
  if (head == NULL) cout << "Buat Linked List dahulu!!" << endl;
  else {
    cout << "Data Barang : " << endl;
    
    cur = head;

    while (cur->next != head) {
      // print
      cout << "Nama Barang : " << cur->namaBarang << endl;
      cout << "Jumlah Barang : " << cur->jumlahBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;

      // step
      cur = cur->next;
    }

    // print last node
    cout << "Nama Barang : " << cur->namaBarang << endl;
    cout << "Jumlah Barang : " << cur->jumlahBarang << " barang" << endl;
    cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;
  }
}

int main(){
  createDataBarang("Shampoo", 15, 5000);
  printDataBarang();

  addFirst("Sikat Gigi", 23, 7000);
  printDataBarang();

  addLast("Sabun Mandi", 11, 12000);
  printDataBarang();

  addMiddle("Pomade", 11, 20000, 6);
  printDataBarang();

  removeMiddle(6);
  printDataBarang();
}
