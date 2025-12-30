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

// deklarasi isi data
typedef mahasiswa dataMahasiswa;
typedef struct node* address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

// semua procedure dan function yang dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &P);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
