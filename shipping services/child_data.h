#include <iostream>
using namespace std;

#define infoData(P) P->infoData
#define nextData(P) P->nextData

struct infotype_data{
    string jenis_kargo;
    int jumlah;
    float berat;
    int bayar;
    string tujuan;
    string nama_pengirim;
};
typedef struct elmData *adrData;
struct elmData {
    infotype_data infoData;
    adrData nextData;
};

adrData createElm_data(string jenis_kargo, int jumlah, float berat, string tujuan, string nama_pengirim);
void insertFirst_data(adrData &data1, adrData &data2);
void insertLast_data(adrData &data1, adrData &data2);
void insertAfter_data(adrData &prec, adrData &data2);
void insertData(adrData &data1, adrData &data2);
void deleteFirst_data(adrData &data1, adrData &data2);
void deleteLast_data(adrData &data1, adrData &data2);
void deleteAfter_data(adrData &prec, adrData &data2);
void deleteData(adrData &data1, adrData delData, adrData &data2);
adrData findData(adrData data1, string nama_pengirim);
adrData findLastelm(adrData data1);
void showData(adrData data1);
void showSuatu_data(adrData data1);


