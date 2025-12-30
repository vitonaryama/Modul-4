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


    //       NOMOR 2

    address P;

    // hapus node 9 → deleteFirst
    deleteFirst(L, P);
    dealokasi(P);

    // hapus node 2 → deleteLast
    deleteLast(L, P);
    dealokasi(P);

    // hapus node 8 → deleteAfter
    deleteAfter(L, L.First, P); // L.First adalah node 12
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
