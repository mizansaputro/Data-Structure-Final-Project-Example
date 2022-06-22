#include "mobil.h"

void createList(List &L){
    First(L) = NULL;
    Last(L) = NULL;
}
adrMobil createElmmobil(string nama, string nomor_polisi){
    adrMobil P = new elmMobil;

    infoMobil(P).nama = nama;
    infoMobil(P).nomor_polisi = nomor_polisi;
    costumer(P) = NULL;
    nextMobil(P) = NULL;
    prevMobil(P) = NULL;

    return P;
}
bool isEmpty(List L){
    return First(L) == NULL && Last(L)==NULL;
}
void insertFirst_mobil(List &L, adrMobil P){
    if (isEmpty(L)){
        First(L) = P;
        Last(L) = P;
    }else{
        nextMobil(P) = First(L);
        prevMobil(First(L)) = P;
        First(L) = P;
    }
    prevMobil(First(L)) = Last(L);
    nextMobil(Last(L)) = First(L);
}
void insertLast_mobil(List &L, adrMobil P){
    if (isEmpty(L)){
        First(L) = P;
        Last(L) = P;
    }else{
        nextMobil(Last(L)) = P;
        prevMobil(P) = Last(L);
        Last(L) = P;
    }
    prevMobil(First(L)) - Last(L);
    nextMobil(Last(L)) = First(L);
}
void insertAfter_mobil(adrMobil &prec, adrMobil &P){
    nextMobil(P) = nextMobil(prec);
    prevMobil(nextMobil(prec)) = P;
    nextMobil(prec) = P;
    prevMobil(P) = prec;
}
void insertMobil(List &L, adrMobil P){
    if (isEmpty(L)){
        insertFirst_mobil(L,P);
    }else{
        if (infoMobil(First(L)).nama>=infoMobil(P).nama){
            insertFirst_mobil(L,P);
        }else if (infoMobil(Last(L)).nama<=infoMobil(P).nama){
            insertLast_mobil(L,P);
        }else{
            adrMobil Pf = First(L);
            while (Pf!=Last(L) && infoMobil(nextMobil(Pf)).nama<=infoMobil(P).nama){
                Pf = nextMobil(Pf);
            }
            insertAfter_mobil(Pf,P);
        }
    }
    cout << "SISTEM: DATA BERHASIL DIINPUTKAN!" << endl;
}
void deleteFirst_mobil(List &L, adrMobil &P){
    if (isEmpty(L)){
        cout << "SISTEM: GAGAL, TIDAK ADA DATA MOBIL DI LIST!" << endl;
    }else{
        P = First(L);
        First(L) = next(P);
        nextMobil(Last(L)) = First(L);
        prevMobil(First(L)) = Last(L);
        nextMobil(P) = NULL;
        prevMobil(P) = NULL;
        costumer(P) = NULL;
        delete P;
    }
}
void deleteLast_mobil(List &L, adrMobil &P){
    if (isEmpty(L)){
        cout << "SISTEM: GAGAL, TIDAK ADA DATA MOBIL DI LIST!" << endl;
    }else{
        P = Last(L);
        Last(L) = prevMobil(Last(L));
        nextMobil(Last(L)) = First(L);
        prevMobil(First(L)) = Last(L);
        costumer(P) = NULL;
        nextMobil(P) = NULL;
        prevMobil(P) = NULL;
        delete P;
    }
}
void deleteAfter_mobil(adrMobil &prec, adrMobil &P){
    P = nextMobil(prec);
    nextMobil(prec) = nextMobil(P);
    prevMobil(nextMobil(P)) = prec;
    costumer(P) = NULL;
    nextMobil(P) = NULL;
    prevMobil(P) = NULL;
    delete P;
}
void deleteMobil(List &L, adrMobil thisP, adrMobil &P){
    if (isEmpty(L)){
        cout << "SISTEM: GAGAL, TIDAK ADA DATA MOBIL DI LIST!" << endl;
    }else if (First(L)==Last(L) && First(L)==thisP){
        P = First(L);
        First(L) = NULL;
        costumer(P) = NULL;
        nextMobil(P) = NULL;
        prevMobil(P) = NULL;
        Last(L) = NULL;
    }else{
        if (thisP==First(L)){
            deleteFirst_mobil(L,P);
        }else if (thisP==Last(L)){
            deleteLast_mobil(L,P);
        }else{
            adrMobil Pf = First(L);
            while (nextMobil(Pf)!=thisP){
                Pf = nextMobil(Pf);
            }
            deleteAfter_mobil(Pf,P);
        }
         cout << "SISTEM: DATA BERHASIL DIHAPUS!" << endl;
    }
}
void viewAllmobil(List L){
    adrMobil P = First(L);
    int i = 1;
    do{
        cout << "=============MOBIL KE- " << i << "=============" << endl;
        cout << "NAMA\t\t\t: " << infoMobil(P).nama << endl;
        cout << "NOMOR POLISI\t\t: " << infoMobil(P).nomor_polisi << endl;
        P = nextMobil(P);
        i++;
    }while (P!=First(L));
    cout << "BANYAK MOBIL\t\t: " << i-1 << endl;
}
void viewSomecar(List L, string nama){
    if (isEmpty(L)){
        cout << "SISTEM: GAGAL, TIDAK ADA DATA MOBIL DI LIST!" << endl;
    }else{
        adrMobil P = First(L);
        int i = 0;
        cout << "=============MOBIL " << nama << "=============" << endl;
        do{
            if (infoMobil(P).nama==nama){
                i++;
                cout << "NOMOR POLISI\t: " << infoMobil(P).nomor_polisi << endl;
            }
            P = nextMobil(P);
        }while (P!=First(L));
        if (i==0){
            cout << "TIDAK ADA NAMA KENDARAAN YANG SESUAI!" << endl;
        }else{
            cout << "==========================================" << endl;
            cout << "BANYAK KENDARAAN: " << i << endl;
        }
    }
}
adrMobil findMobil(List L, string nama, string nomor_polisi){
    if (isEmpty(L)){
        return NULL;
    }else{
        adrMobil P = First(L);
        do{
            if (infoMobil(P).nama==nama && infoMobil(P).nomor_polisi==nomor_polisi){
                return P;
            }
            P = nextMobil(P);
        }while (P!=First(L));
    }
    return NULL;
}
bool findNopolisi(List L, string nomor_polisi){
    if (isEmpty(L)){
        return false;
    }else{
        adrMobil P = First(L);
        do{
            if (infoMobil(P).nomor_polisi==nomor_polisi){
                return true;
            }
            P = nextMobil(P);
        }while (P!=First(L));
    }
    return false;
}
