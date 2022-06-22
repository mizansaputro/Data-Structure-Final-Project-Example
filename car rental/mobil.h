#include "costumer.h"


#define infoMobil(P) P->infoMobil
#define costumer(P) P->costumer
#define nextMobil(P) P->nextMobil
#define prevMobil(P) P->prevMobil
#define First(L) L.First
#define Last(L) L.Last

struct infotypeMobil{
    string nama;
    string nomor_polisi;
};
typedef struct elmMobil *adrMobil;

struct elmMobil{
    infotypeMobil infoMobil;
    adrCostumer costumer;
    adrMobil nextMobil;
    adrMobil prevMobil;
};
struct List{
    adrMobil First;
    adrMobil Last;
};

void createList(List &L);
adrMobil createElmmobil(string nama, string nomor_polisi);
bool isEmpty(List L);
void insertFirst_mobil(List &L, adrMobil P);
void insertLast_mobil(List &L, adrMobil P);
void insertAfter_mobil(adrMobil &prec, adrMobil &P);
void insertMobil(List &L, adrMobil P);
void deleteFirst_mobil(List &L, adrMobil &P);
void deleteLast_mobil(List &L, adrMobil &P);
void deleteAfter_mobil(adrMobil &prec, adrMobil &P);
void deleteMobil(List &L, adrMobil thisP, adrMobil &P);
void viewAllmobil(List L);
void viewSomecar(List L, string nama);
adrMobil findMobil(List L, string nama, string nomor_polisi);
bool findNopolisi(List L, string nomor_polisi);




