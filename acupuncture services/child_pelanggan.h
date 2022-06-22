#include <iostream>
using namespace std;

#define infoPel(P) P->infoPel
#define nextPel(P) P->nextPel

struct infotypePel{
    int id;
    string nama;
    string jenis;
    int banyak;
    int bayar;
    string tanggal_masuk;
    string tanggal_keluar;
};
typedef struct elmPelanggan *adrPel;
struct elmPelanggan{
    infotypePel infoPel;
    adrPel nextPel;
};

adrPel createElm_pel(int id, string nama, string jenis, int banyak, int bayar, string tanggal_masuk, string tanggal_keluar);
adrPel findLast_elmPel(adrPel P1);
adrPel findPel(adrPel P1, int id);
void insertFirst_pel(adrPel &P1, adrPel &P2);
void insertLast_pel(adrPel &P1, adrPel &P2);
void insertAfter_pel(adrPel &prec, adrPel &P2);
void insertPel(adrPel &P1, adrPel &P2);
void deleteFirst_pel(adrPel &P1, adrPel &P2);
void deleteLast_pel(adrPel &P1, adrPel &P2);
void deleteAfter_pel(adrPel &prec, adrPel &P2);
void deletePel(adrPel &P1, adrPel pel, adrPel &P2);
void viewA_pel(adrPel pel);
void viewAll_pel(adrPel P1);


