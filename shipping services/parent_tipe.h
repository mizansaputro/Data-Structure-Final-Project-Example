#include "child_data.h"

#define infoTipe(P) P->infoTipe
#define data(P) P->data
#define nextTipe(P) P->nextTipe
#define prevTipe(P) P->prevTipe
#define First(L) L.First
#define Last(L) L.Last

struct infotype_tipe{
    int id;
    string tipe;
    int total_barang;
    float total_berat;
    int total_uang;
};
typedef struct elmTipe *adrTipe;
struct elmTipe{
    infotype_tipe infoTipe;
    adrData data;
    adrTipe nextTipe;
    adrTipe prevTipe;
};
struct List{
    adrTipe First;
    adrTipe Last;
};

void createList(List &L);
adrTipe createElm_tipe(int id, string tipe);
bool isEmpty(List L);
void insertFirst_tipe(List &L, adrTipe P);
void insertLast_tipe(List &L, adrTipe P);
void insertAfter_tipe(adrTipe &prec, adrTipe &P);
void insertTipe(List &L, adrTipe P);
void deleteFirst_tipe(List &L, adrTipe &P);
void deleteLast_tipe(List &L, adrTipe &P);
void deleteAfter_tipe(adrTipe &prec, adrTipe &P);
void deleteTipe(List &L, adrTipe tipe, adrTipe &P);
adrTipe findTipe(List L, int id);
void showTipe(List L);
void showSuatu_tipe(adrTipe P);
