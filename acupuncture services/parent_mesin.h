#include "child_pelanggan.h"

#define infoMesin(P) P->infoMesin
#define nextMesin(P) P->nextMesin
#define pelanggan(P) P->pelanggan
#define first(L) L.first

struct infotypeMesin{
    int no_mesin;
    string jenis_layanan;
    int harga;
    int estimasi_pengerjaan;
};
typedef struct elmMesin *adrMesin;
struct elmMesin{
    infotypeMesin infoMesin;
    adrPel pelanggan;
    adrMesin nextMesin;
};
struct List{
    adrMesin first;
};

void createList(List &L);
adrMesin createElm_mesin(int no_mesin, string jenis_layanan);
adrMesin findLast_elmMesin(List L);
adrMesin findMesin(List L, int no_mesin);
void insertFirst_mesin(List &L, adrMesin &P);
void insertLast_mesin(List &L, adrMesin &P);
void insertAfter_mesin(adrMesin &prec, adrMesin &P);
void insertMesin(List &L, adrMesin &P);
void deleteFirst_mesin(List &L, adrMesin &P);
void deleteLast_mesin(List &L, adrMesin &P);
void deleteAfter_mesin(adrMesin &prec, adrMesin &P);
void deleteMesin(List &L, adrMesin mesin ,adrMesin &P);
void viewA_mesin(adrMesin P);
void viewAll_mesin(List L);

