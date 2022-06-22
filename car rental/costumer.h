#include <iostream>
using namespace std;

#define infoCostumer(P) P->infoCostumer
#define nextCostumer(P) P->nextCostumer

struct infotype_date{
    int tgl;
    int bulan;
    int tahun;
};
struct infotypeCostumer{
    string nama;
    string no_ktp;
    int lama_sewa;
    string tanggal_sewa;
    string habis_sewa;
    string jam_sewa;
    int harga;
};
typedef struct elmCostumer *adrCostumer;
struct elmCostumer{
    infotypeCostumer infoCostumer;
    adrCostumer nextCostumer;
};
adrCostumer createElmcostumer(string nama, string no_ktp, int lama_sewa, string tanggal_sewa, string jam_sewa);
void insertFirst_costumer(adrCostumer &c1, adrCostumer &c2);
void insertLast_costumer(adrCostumer &c1, adrCostumer &c2);
void insertAfter_costumer(adrCostumer &cPrec, adrCostumer &c2);
void insertCostumer(adrCostumer &c1, adrCostumer &c2);
void deleteFirst_costumer(adrCostumer &c1, adrCostumer &c2);
void deleteLast_costumer(adrCostumer &c1, adrCostumer &c2);
void deleteAfter_costumer(adrCostumer &cPrec, adrCostumer &c2);
void deleteCostumer(adrCostumer &c1, adrCostumer thisC, adrCostumer &c2);
adrCostumer findLastelm(adrCostumer c1);
adrCostumer findCostumer(adrCostumer c1, string no_ktp);
void viewAllcostumer(adrCostumer c1);
void viewAcostumer(adrCostumer c1, string no_ktp);
infotype_date convertDate_toInt(string tgl, string bulan, string tahun);

