#include <iostream>

using namespace std;

// Deklarasi double linked list
struct DataUser{
  string nama, username, email, password;
  DataUser *prev;
  DataUser *next;
} *head, *tail, *cur, *newNode, *del, *afterNode;

// Membuat fungsi untuk membuat data pada double linked list
void createDoubleLinkedList(string data[4]) {
  // Inisiasi variable head untuk data baru
  head = new DataUser();
  
  head->nama = data[0];
  head->username = data[1];
  head->email = data[2];
  head->password = data[3];
  head->prev = NULL;
  head->next = NULL;

  // Set nilai tail menjadi head
  tail = head;
}

// Membuat fungsi untuk menghitung jumlah data double linked list
int countDoubleLinkedList() {
  if (head == NULL) {
    cout << "Double linked list belum dibuat" << endl;
  
    return 0;
  } else {
    int total = 0;

    cur = head;

    while (cur != NULL) {
      total++;

      // Mengambil node selanjutnya
      cur = cur->next;
    }

    return total;
  }
}

// Membuat prosedural untuk menambahkan data pertama pada linked list
void addFirst(string data[4]) {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    // Inisiasi variable new node dengan data baru
    newNode = new DataUser();

    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = NULL;
    newNode->next = head;

    // Set head lama nilai prev menjadi node baru
    head->prev = newNode;

    // Set head menjadi node baru
    head = newNode;
  }
}

// Membuat prosedural untuk menambahkan data terakhir pada linked list
void addLast(string data[4]) {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    // Inisiasi variable new node dengan data baru
    newNode = new DataUser();

    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = tail;
    newNode->next = NULL;

    // Set tail lama nilai next menjadi node baru
    tail->next = newNode;

    // Set tail menjad node baru
    tail = newNode;
  }
}

// Membuat prosedural untuk menambahkan data tengah pada linked list
void addMiddle(string data[4], int posisi) {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    if (posisi == 1) cout << "Posisi 1 itu bukan posisi tengah" << endl;
    else if (posisi < 1 || posisi > countDoubleLinkedList()) cout << "Posisi diluar jangkauan!!!" << endl;
    else {
      // Insiasi variable new node dengan data baru
      newNode = new DataUser();

      newNode->nama = data[0];
      newNode->username = data[1];
      newNode->email = data[2];
      newNode->password = data[3];

      // Melakukan transfer nilai next dan prev
      int number = 1;

      cur = head;

      while (number <  posisi - 1) {
        number++;

        // set nilai cur menjadi node selanjutnya
        cur = cur->next;
      }

      // Set next dan prev data menjadi terurut dengan node baru
      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }

  }
}

// Membuat prosedural untuk menghapus node pertama
void removeFirst() {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}

// Membuat prosedural untuk menghapus node terakhir
void removeLast() {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}

// Membuat prosedural untuk menghapus nilai tengah
void removeMiddle(int posisi) {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    if (posisi == 1 || posisi == countDoubleLinkedList()) cout << "Posisi bukan posisi tegah!!" << endl;
    else if (posisi < 1 || posisi > countDoubleLinkedList()) cout << "Posisi diluar jangkauan!!" << endl;
    else{
      int number = 1;

      cur = head;
      
      while (number < posisi - 1 ){
        number++;

        // Set nilai cur menjadi node selanjutnya
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

// Membuat prosedural untuk mencetak semua data node
void printDoubleLinkedList() {
  if (head == NULL) cout << "Double Linked List belum dibuat" << endl;
  else {
    cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    
    cur = head;

    while( cur != NULL ){
      // print
      cout << "Nama User : " << cur->nama << endl;
      cout << "Username User : " << cur->username << endl;
      cout << "Email User : " << cur->email << endl;
      cout << "Password User : " << cur->password << "\n" << endl;
      //step
      cur = cur->next;
    }
  }
}

int main(){
  string newData[4] = {"Yunus Febriansyah", "yuunuss", "yunus@gmail.com", "gampangAja"};
  createDoubleLinkedList(newData);

  printDoubleLinkedList();

  string data2[4] = {"Bambang", "bmb", "bambangdong@gmail.com", "dongBambang"};

  addFirst( data2 );

  printDoubleLinkedList();

  string data3[4] = {"Siti Hidayah", "sitii", "sisiti@gmail.com", "sitiAja"};

  addLast( data3 );

  printDoubleLinkedList();

  string data4[4] = {"Mamat Hermawan", "mam", "mamatHer@yahoo.com", "hermawanMamat"};
  addMiddle(data4, 3);

  printDoubleLinkedList();

  removeMiddle(2);

  printDoubleLinkedList();
}
