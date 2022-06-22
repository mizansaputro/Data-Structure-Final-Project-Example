#include "parent_tipe.h"

void addJasapengguna_toTipe(adrTipe &tipe , adrData &data2);
void deleteJasapengguna_inTipe(adrTipe &tipe, adrData delData, adrData &data2);
void showSuatu_jasaPengguna(adrData P);
void showSemua_jasaPengguna(adrData data1);
void showSemua_jasaPengguna_inAlltipe(List L);
adrData findSuatu_jasaPengguna_inSemua(List L, string nama_pengirim);
adrData findSuatu_jasaPengguna_inSuatu(adrData P, string nama_pengirim);
int sumTotal_barang(List L);
float sumTotal_berat(List L);
int sumTotal_uang(List L);
int countJasapengguna(List L);
int maxBayar(List L);
