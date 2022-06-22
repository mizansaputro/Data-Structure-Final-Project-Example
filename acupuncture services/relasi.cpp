#include "relasi.h"

void viewAllpelanggan_inAllmesin(List L){
    if (first(L)==NULL){
        cout << "LIST MESIN KOSONG!" << endl;
    }else{
        adrMesin P = first(L);
        do{
            viewA_mesin(P);
            adrPel pel = pelanggan(P);
            if (pel==NULL){
                cout << "TIDAK ADA PELANGGAN!" << endl;
            }else{
                while (pel!=NULL){
                    viewA_pel(pel);
                    pel = nextPel(pel);
                }
            }
            P = nextMesin(P);
        }while (P!=first(L));
    }
}
adrPel findPelanggan_inAllmesin(List L, int id){
    if (first(L)==NULL){
        return NULL;
    }else{
        adrMesin P = first(L);
        do{
            adrPel pel = pelanggan(P);
            while (pel!=NULL){
                if (infoPel(pel).id==id){
                    return pel;
                }
                pel = nextPel(pel);
            }
            P = nextMesin(P);
        }while (P!=first(L));
    }
    return NULL;
}
int countPelanggan(List L){
    int count = 0;

    if(first(L)!=NULL){
        adrMesin P = first(L);
        do{
            adrPel pel = pelanggan(P);
            while (pel!=NULL){
                count++;
                pel = nextPel(pel);
            }
            P = nextMesin(P);
        }while (P!=first(L));
    }
    return count;
}
int sumUangmasuk(List L){
    int sum = 0;

    if(first(L)!=NULL){
        adrMesin P = first(L);
        do{
            adrPel pel = pelanggan(P);
            while (pel!=NULL){
                sum = sum+infoPel(pel).bayar;
                pel = nextPel(pel);
            }
            P = nextMesin(P);
        }while (P!=first(L));
    }
    return sum;
}
