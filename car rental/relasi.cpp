#include "relasi.h"

void addCostumer_toMobil(adrCostumer &cMobil, adrCostumer c){
    insertCostumer(cMobil, c);
}
void deleteCostumer_inMobil(adrCostumer &cMobil, adrCostumer thisC, adrCostumer &c){
    deleteCostumer(cMobil, thisC, c);
}
void deleteAllcostumer_inMobil(adrCostumer &cMobil, adrCostumer thisC, adrCostumer &c){
    if (cMobil==NULL){
        cout << "SISTEM: DATA COSTUMER TIDAK ADA!" << endl;
    }else{
        adrCostumer P = cMobil;
        while (P!=NULL){
            deleteCostumer_inMobil(cMobil, P, c);
            P = cMobil;
        }
    }
}
adrCostumer findCostumer_inMobil(adrCostumer cMobil, string no_ktp){
    if (cMobil!=NULL){
         adrCostumer P = findCostumer(cMobil, no_ktp);
         return P;
    }
    return NULL;
}
adrCostumer findCostumer_inListmobil(List L, string no_ktp){
    adrMobil P = First(L);
    do {
        adrCostumer Q = costumer(P);
        while (Q!=NULL){
            if (infoCostumer(Q).no_ktp==no_ktp){
                return Q;
            }
            Q = nextCostumer(Q);
        }
        P = nextMobil(P);
    }while (P!=First(L));
    return NULL;
}
void viewAllcostumer_inMobil(adrCostumer cMobil){
    viewAllcostumer(cMobil);
}
void viewAllcostumer_inListmobil(List L){
    if (isEmpty(L)){
        cout << "SISTEM: TIDAK ADA DATA MOBIL!" << endl;
    }else{
        adrMobil P =First(L);
        do {
            cout << "|||||||||||||||MOBIL " << infoMobil(P).nama << "|||||||||||||||" << endl;
            viewAllcostumer_inMobil(costumer(P));
            P = nextMobil(P);
        }while (P!=First(L));
    }
}
void viewSomecostumer_inListmobil(List L, string no_ktp){
    if (!isEmpty(L)){
        adrMobil P = First(L);
        do{
           adrCostumer Q = costumer(P);
           while (Q!=NULL){
                if (infoCostumer(Q).no_ktp==no_ktp){
                    cout << "============================" << endl;
                    cout << "NAMA MOBIL\t: " << infoMobil(P).nama << endl;
                    cout << "NO POLISI\t: " << infoMobil(P).nomor_polisi << endl;
                }
                Q=nextCostumer(Q);
           }
           P = nextMobil(P);
        }while (P!=First(L));
    }
}
int countAllcostumer(List L){
    int count = 0;

    if (!isEmpty(L)){
        adrMobil P = First(L);
        do{
            adrCostumer Q = costumer(P);
            while (Q!=NULL){
                count++;
                Q = nextCostumer(Q);
            }
            P = nextMobil(P);
        }while (P!=First(L));
    }
    return count;
}
int sumPenghasilan(List L){
    int penghasilan = 0;

    if (!isEmpty(L)){
        adrMobil P = First(L);
        do{
            adrCostumer Q = costumer(P);
            while (Q!=NULL){
                penghasilan = penghasilan+infoCostumer(Q).harga;
                Q = nextCostumer(Q);
            }
            P = nextMobil(P);
        }while (P!=First(L));
    }
    return penghasilan;
}
