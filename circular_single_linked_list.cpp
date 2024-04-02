#include <iostream>

using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Mahasiswa{
  string npm, nama, jurusan;

  Mahasiswa *next;
} *head, *tail, *newNode, *cur, *del;

// Membuat prosedural untuk melakukan inisiasi node pada circular single linked list
void createCircularSingleLinkedList(string dataBaru[3]) {
  // Inisasi head dengan data baru
  head = new Mahasiswa();

  head->npm = dataBaru[0];
  head->nama = dataBaru[1];
  head->jurusan = dataBaru[2];

  // Set nilai tail dengan data baru yaitu head
  tail = head;

  // Set node selanjutnya dari tail menjadi data baru yaitu head
  tail->next = head;
}

// Membuat prosedural untuk melakukan penambahan data awal
void addFirst( string data[3] ){
  if (head == NULL) cout << "Buat Linked List dulu" << endl;
  else {
    // Iniasiasi new node dengan data baru
    newNode = new Mahasiswa();

    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    
    // Set nilai lanjutan tail menjadi node baru
    tail->next = newNode;

    // Set nilai head menjadi new node
    head = newNode;
  }
}

// Membuat prosedural untuk menambahkan data terakhir
void addLast(string data[3]) {
  if (head == NULL) cout << "Buat Linked List dulu" << endl;
  else {
    // Inisiasi new node dengan data baru
    newNode = new Mahasiswa();

    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
  
    // Set nilai lanjutan tail menjadi node baru
    tail->next = newNode;

    // Set nilai tail menjadi new node
    tail = newNode;
  }
}

// Membuat prosedural untuk menambahkan data tengah
void addMiddle(string data[3], int posisi) {
  if (head == NULL) cout << "Buat Linked List dulu" << endl;
  else {
    if (posisi == 1) cout << "Posisi satu bukan posisi tengah" << endl;
    else {
      // Inisiasi variable new node dengan data baru
      newNode = new Mahasiswa();

      newNode->npm = data[0];
      newNode->nama = data[1];
      newNode->jurusan = data[2];

      // Melakukan transfer nilai next dan prev pada sekitar indeks new node
      int number = 1;

      cur = head;
      
      while (number < posisi - 1) {
        number++;

        // Set nilai cur menjadi node selanjutnya dari nilai cur
        cur = cur->next;
      }

      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

// Membuat prosedural untuk menghapuskan data pertama
void removeFirst() {
  if (head == NULL) cout << "Buat Linked List dulu" << endl;
  else {
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// Membuat prosedural untuk menghapus data terakhir
void removeLast() {
  if (head == NULL) cout << "Buat Linked List dulu" << endl;
  else {
    del = tail;
    cur = head;
  
    while( cur->next != tail ){
      cur = cur->next;
    }

    tail = cur;
    tail->next = head;
    delete del;
  }
}

// Membuat prosedural untuk menghapus data tengah
void removeMiddle(int posisi) {
  if (head == NULL) cout << "Buat Linked List dulu" << endl;
  else {
    // tranversing
    int number = 1;
    
    cur = head;
    
    while (number < posisi - 1) {
      cur = cur->next;
      number++;
    }

    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}

// Membuat prosedural untuk mencetak nilai circuar single linked list
void printCircular() {
  if (head == NULL) cout << "Buat Linked List dulu!!" << endl;
  else {
    cout << "Data Mahasiswa " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| NPM\t\t| Nama\t\t\t| Jurusan\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    
    cur = head;
    
    while (cur->next != head) {
      // print
      cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t\t|" << endl;
      cur = cur->next;
    }

    cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"19312009", "Yunus Febriansyah", "Informatika"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"19312079", "M Rizky Fadhilah", "Informatika"};
  addFirst(data);

  printCircular();

  string data2[3] = {"19312015", "Gilang Ramadan", "Sistem Informasi"};
  addLast(data2);

  printCircular();

  string data3[3] = {"19312024", "Verdian Galang", "Teknik Elektro"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
