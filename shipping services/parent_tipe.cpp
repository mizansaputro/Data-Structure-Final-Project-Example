#include "parent_tipe.h"

void createList(List &L){
    First(L) = NULL;
    Last(L) = NULL;
}
adrTipe createElm_tipe(int id, string tipe){
    adrTipe P = new elmTipe;

    infoTipe(P).id = id;
    infoTipe(P).tipe = tipe;
    infoTipe(P).total_barang = 0;
    infoTipe(P).total_berat = 0;
    infoTipe(P).total_uang = 0;
    data(P) = NULL;
    nextTipe(P) = NULL;
    prevTipe(P) = NULL;

    return P;
}
bool isEmpty(List L){
    return First(L)==NULL && Last(L)==NULL;
}
void insertFirst_tipe(List &L, adrTipe P){
    if (isEmpty(L)){
        First(L) = P;
        Last(L) = P;
    }else{
        nextTipe(P) = First(L);
        prevTipe(First(L)) = P;
        First(L) = P;
    }
    nextTipe(Last(L)) = First(L);
    prevTipe(First(L)) = Last(L);
}
void insertLast_tipe(List &L, adrTipe P){
    if (isEmpty(L)){
        First(L) = P;
        Last(L) = P;
    }else{
        nextTipe(Last(L)) = P;
        prevTipe(P) = Last(L);
        Last(L) = P;
    }
    nextTipe(Last(L)) = First(L);
    prevTipe(First(L)) = Last(L);
}

void insertAfter_tipe(adrTipe &prec, adrTipe &P){
    nextTipe(P) = nextTipe(prec);
    prevTipe(nextTipe(prec)) = P;
    nextTipe(prec) = P;
    prevTipe(P) = prec;
}
void insertTipe(List &L, adrTipe P){
    if (isEmpty(L)){
        insertFirst_tipe(L,P);
        cout << "PROSES INPUT....." << endl;
        cout << "TIPE DITAMBAHKAN (INSERT FIRST)" << endl << endl;
    }else{
        if (infoTipe(First(L)).id>infoTipe(P).id){
            insertFirst_tipe(L,P);
            cout << "PROSES INPUT....." << endl;
            cout << "TIPE DITAMBAHKAN (INSERT FIRST)" << endl << endl;
        }else if (infoTipe(Last(L)).id<infoTipe(P).id){
            insertLast_tipe(L,P);
            cout << "PROSES INPUT....." << endl;
            cout << "TIPE DITAMBAHKAN (INSERT LAST)" << endl << endl;
        }else{
            adrTipe Q = First(L);
            while (infoTipe(nextTipe(Q)).id<infoTipe(P).id){
                Q = nextTipe(Q);
            }
            insertAfter_tipe(Q,P);
            cout << "PROSES INPUT....." << endl;
            cout << "TIPE DITAMBAHKAN (INSERT AFTER)" << endl << endl;
        }
    }
}
void deleteFirst_tipe(List &L, adrTipe &P){
    if (isEmpty(L)){
        cout << "TIDAK ADA DATA TIPE!" << endl;
    }else if (First(L)==Last(L)){
        P = First(L);
        First(L) = NULL;
        Last(L) = NULL;
        nextTipe(P) = NULL;
        prevTipe(P) = NULL;
        data(P) = NULL;
        delete P;
    }else{
        P = First(L);
        First(L) = nextTipe(P);
        nextTipe(Last(L)) = First(L);
        prevTipe(First(L)) = Last(L);
        nextTipe(P) = NULL;
        prevTipe(P) = NULL;
        data(P) = NULL;
        delete P;
    }
}
void deleteLast_tipe(List &L, adrTipe &P){
    if (isEmpty(L)){
        cout << "TIDAK ADA DATA TIPE!" << endl;
    }else if (First(L)==Last(L)){
        P = Last(L);
        First(L) = NULL;
        Last(L) = NULL;
        nextTipe(P) = NULL;
        prevTipe(P) = NULL;
        data(P) = NULL;
        delete P;
    }else{
        P = Last(L);
        Last(L) = prevTipe(P);
        nextTipe(Last(L)) = First(L);
        prevTipe(First(L)) = Last(L);
        nextTipe(P) = NULL;
        prevTipe(P) = NULL;
        data(P) = NULL;
        delete P;

    }
}
void deleteAfter_tipe(adrTipe &prec, adrTipe &P){
    P = nextTipe(prec);
    nextTipe(prec) = nextTipe(P);
    prevTipe((nextTipe(P))) = prec;
    nextTipe(P) = NULL;
    prevTipe(P) = NULL;
    data(P) = NULL;
    delete P;
}
void deleteTipe(List &L, adrTipe tipe, adrTipe &P){
    if (isEmpty(L)){
        cout << "TIDAK ADA DATA TIPE!" << endl;
    }else {
        if (First(L)==tipe){
            deleteFirst_tipe(L,P);
        }else if (Last(L)==tipe){
            deleteLast_tipe(L,P);
        }else{
            adrTipe Q = First(L);
            while (nextTipe(Q)!=tipe){
                Q = nextTipe(Q);
            }
            deleteAfter_tipe(Q,P);
        }
    }
}
adrTipe findTipe(List L, int id){
    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            if (infoTipe(P).id==id){
                return P;
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return NULL;
}
void showTipe(List L){
    if (isEmpty(L)){
        cout << "TIDAK ADA DATA TIPE!" << endl;
    }else{
        adrTipe P = First(L);
        do{
            showSuatu_tipe(P);
            P = nextTipe(P);
        }while (P!=First(L));
    }
}
void showSuatu_tipe(adrTipe P){
    cout << "--------------------TIPE " << infoTipe(P).tipe << "--------------------"  << endl;
    cout << "ID\t\t: " << infoTipe(P).id << endl; ;
    cout << "JUMLAH\t\t: " << infoTipe(P).total_barang << endl;
    cout << "TOTAL BERAT\t: " << infoTipe(P).total_berat << "Kg" << endl;
    cout << "TOTAL BAYAR\t: " << infoTipe(P).total_uang << endl << endl;
}
