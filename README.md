# <h1 align="center">Laporan Praktikum Modul-4 Single Linked List</h1>
<p align="center">Vito Naryama Pramudito</p>

## Dasar Teori

Single Linked List adalah struktur data linear yang terdiri dari serangkaian node yang saling terhubung. Setiap node memiliki dua bagian utama: data yang menyimpan informasi, dan pointer next yang menunjuk ke node berikutnya dalam list. Node terakhir dalam linked list menunjuk ke NULL (Nil), menandakan akhir dari list.

Berbeda dengan array yang menyimpan data secara kontinu di memori, linked list menyimpan data secara tersebar. Setiap node dapat berada di lokasi memori yang berbeda, dan hubungan antar node dijaga melalui pointer. Hal ini membuat linked list lebih fleksibel dalam alokasi memori dibanding array.

Operasi dasar pada linked list meliputi:
1. **Insert (Penambahan)**: Menambahkan node baru ke dalam list, bisa di awal (insertFirst), di akhir (insertLast), atau setelah node tertentu (insertAfter)
2. **Delete (Penghapusan)**: Menghapus node dari list, bisa dari awal (deleteFirst), dari akhir (deleteLast), atau setelah node tertentu (deleteAfter)
3. **Traversal**: Menelusuri seluruh list untuk menampilkan atau memproses data
4. **Search**: Mencari node dengan data tertentu

Manajemen memori sangat penting dalam linked list. Fungsi alokasi digunakan untuk membuat node baru dengan operator `new`, sedangkan dealokasi menggunakan operator `delete` untuk mengembalikan memori ke sistem dan mencegah memory leak.

## Guided

### 1. [Implementasi Linked List untuk Data Mahasiswa]

```cpp
// list.h
#ifndef LISH_H
#define LISH_H
#define Nil NULL
#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node* address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &P);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

```cpp
// list.cpp
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama 
                 << ", NIM : " << nodeBantu->isidata.nim 
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

```cpp
// main.cpp
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    
    createList(List);
    
    dataMahasiswa mhs;
    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);
    
    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    
    return 0;
}
```

Program ini mengimplementasikan single linked list untuk menyimpan data mahasiswa yang terdiri dari nama, NIM, dan umur. Program membuat 5 node mahasiswa dan memasukkannya ke dalam list menggunakan berbagai metode insert (insertFirst, insertLast, insertAfter). Fungsi printList digunakan untuk menampilkan semua data mahasiswa yang ada dalam list. Manajemen memori diterapkan melalui fungsi alokasi dan dealokasi untuk membuat dan menghapus node.

## Unguided

### 1. [Program Operasi Insert dan Delete pada Single Linked List]

```cpp
// Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

#define Nil NULL
typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

```cpp
// Singlylist.cpp
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P != Nil) {
        L.First = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    address Q = L.First;
    if (Q == Nil) return;
    
    if (Q->next == Nil) {
        P = Q;
        L.First = Nil;
        return;
    }
    
    while (Q->next->next != Nil) {
        Q = Q->next;
    }
    P = Q->next;
    Q->next = Nil;
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

```cpp
// main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    
    CreateList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    // Output nomor 1
    printInfo(L);
    
    // NOMOR 2
    address P;
    
    // hapus node 9 → deleteFirst
    deleteFirst(L, P);
    dealokasi(P);
    
    // hapus node 2 → deleteLast
    deleteLast(L, P);
    dealokasi(P);
    
    // hapus node 8 → deleteAfter
    deleteAfter(L, L.First, P);
    dealokasi(P);
    
    // cetak hasil
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;
    
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    
    return 0;
}
```

#### Output:
<img width="559" height="188" alt="image" src="https://github.com/user-attachments/assets/de5bc459-25a6-4404-8615-c1f15740c3ee" />


Program ini mendemonstrasikan operasi insert dan delete pada single linked list dengan tipe data integer. Pertama, program membuat 5 node dengan nilai 2, 0, 8, 12, dan 9 yang dimasukkan menggunakan insertFirst, sehingga urutan akhir menjadi 9, 12, 8, 0, 2. Kemudian dilakukan tiga operasi delete: deleteFirst untuk menghapus node pertama (9), deleteLast untuk menghapus node terakhir (2), dan deleteAfter untuk menghapus node setelah node pertama (8). Setelah operasi delete, list hanya berisi 12 dan 0. Program juga menampilkan jumlah node menggunakan fungsi nbList, dan terakhir menghapus seluruh list menggunakan deleteList.

#### Full code Screenshot:
<img width="747" height="868" alt="image" src="https://github.com/user-attachments/assets/f9e666e5-be98-49b7-934c-37ea68cb2c3e" />
<img width="382" height="550" alt="image" src="https://github.com/user-attachments/assets/b20ae864-7e81-4e70-bbe9-629e4d3410be" />
<img width="266" height="891" alt="image" src="https://github.com/user-attachments/assets/37264027-094f-41cd-8716-1615a0c66b06" />



## Kesimpulan

Dari praktikum ini dapat disimpulkan bahwa single linked list adalah struktur data yang sangat fleksibel untuk menyimpan dan mengelola data secara dinamis. Linked list memungkinkan operasi insert dan delete yang efisien karena tidak perlu menggeser elemen seperti pada array. 

Operasi insert dapat dilakukan di berbagai posisi (awal, tengah, akhir) dengan kompleksitas waktu yang berbeda. InsertFirst memiliki kompleksitas O(1), sedangkan insertLast dan insertAfter memiliki kompleksitas O(n) karena perlu traversal. Operasi delete juga dapat dilakukan di berbagai posisi dengan prinsip yang sama.

Manajemen memori sangat penting dalam implementasi linked list untuk mencegah memory leak. Setiap node yang dihapus harus didealokasi dengan benar menggunakan operator delete. Linked list cocok digunakan ketika ukuran data tidak diketahui sebelumnya atau sering berubah, namun membutuhkan memori tambahan untuk menyimpan pointer dan akses random lebih lambat dibanding array.

## Referensi

[1] Drozdek, A. (2012). Data Structures and Algorithms in C++. Cengage Learning.

[2] Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley Professional.

[3] Karumanchi, N. (2016). Data Structures and Algorithms Made Easy. CareerMonk Publications.
