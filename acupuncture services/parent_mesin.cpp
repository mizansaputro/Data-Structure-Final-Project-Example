#include "parent_mesin.h"

void createList(List &L){
    first(L) = NULL;
}
adrMesin createElm_mesin(int no_mesin, string jenis_layanan){
    adrMesin P = new elmMesin;

    infoMesin(P).no_mesin = no_mesin;
    infoMesin(P).jenis_layanan = jenis_layanan;
    if (jenis_layanan=="REGULER"){
        infoMesin(P).harga = 30000;
        infoMesin(P).estimasi_pengerjaan = 3;
    }else{
        infoMesin(P).harga = 50000;
        infoMesin(P).estimasi_pengerjaan = 1;
    }
    pelanggan(P) = NULL;
    nextMesin(P) = NULL;

    return P;

}
adrMesin findLast_elmMesin(List L){
    if (first(L)==NULL){
        return NULL;
    }else{
        adrMesin P = first(L);
        while (nextMesin(P)!=first(L)){
            P = nextMesin(P);
        }
        return P;
    }
    return NULL;
}
adrMesin findMesin(List L, int no_mesin){
    if (first(L)!=NULL){
        adrMesin P = first(L);
        do{
            if (infoMesin(P).no_mesin==no_mesin){
                return P;
            }
            P = nextMesin(P);
        }while (P!=first(L));
    }
    return NULL;
}
void insertFirst_mesin(List &L, adrMesin &P){
    adrMesin lastElm_mesin;
    if (first(L)==NULL){
        first(L) = P;
        nextMesin(P) = P;
    }else{
        lastElm_mesin = findLast_elmMesin(L);
        nextMesin(P) = first(L);
        first(L) = P;
        nextMesin(lastElm_mesin) = P;
    }
}
void insertLast_mesin(List &L, adrMesin &P){
    adrMesin lastElm_mesin;
    if (first(L)==NULL){
        first(L) = P;
        nextMesin(P) = P;
    }else{
        lastElm_mesin = findLast_elmMesin(L);
        nextMesin(lastElm_mesin) = P;
        nextMesin(P) = first(L);
    }
}
void insertAfter_mesin(adrMesin &prec, adrMesin &P){
    nextMesin(P) = nextMesin(prec);
    nextMesin(prec) = P;
}
void insertMesin(List &L, adrMesin &P){
    if (first(L)==NULL){
        insertFirst_mesin(L,P);
        cout << "JENIS INSERT\t: INSERT FIRST PARENT" << endl;
    }else{
        adrMesin lastElm_mesin = findLast_elmMesin(L);
        if (infoMesin(first(L)).no_mesin>infoMesin(P).no_mesin){
            insertFirst_mesin(L,P);
            cout << "JENIS INSERT\t: INSERT FIRST PARENT" << endl;
        }else if (infoMesin(lastElm_mesin).no_mesin<infoMesin(P).no_mesin){
            insertLast_mesin(L,P);
            cout << "JENIS INSERT\t: INSERT LAST PARENT" << endl;
        }else{
            adrMesin prec = first(L);
            while (prec!=lastElm_mesin &&
                   infoMesin(nextMesin(prec)).no_mesin<infoMesin(P).no_mesin){
                prec = nextMesin(prec);
            }
            insertAfter_mesin(prec,P);
            cout << "JENIS INSERT\t: INSERT AFTER PARENT" << endl;
        }
    }
}
void deleteFirst_mesin(List &L, adrMesin &P){
    if (first(L)==NULL){
        cout << "LIST MESIN KOSONG!" << endl;
    }else if (nextMesin(first(L))==first(L)){
        P = first(L);
        first(L) = NULL;
        pelanggan(P) = NULL;
        nextMesin(P) = NULL;
        delete P;
    }else{
        adrMesin lastElm_mesin = findLast_elmMesin(L);
        P = first(L);
        first(L) = nextMesin(P);
        nextMesin(lastElm_mesin) = first(L);
        nextMesin(P) = NULL;
        pelanggan(P) = NULL;
        delete P;
    }
}
void deleteLast_mesin(List &L, adrMesin &P){
    if (first(L)==NULL){
        cout << "LIST MESIN KOSONG!" << endl;
    }else if (nextMesin(first(L))==first(L)){
        P = first(L);
        first(L) = NULL;
        pelanggan(P) = NULL;
        nextMesin(P) = NULL;
        delete P;
    }else{
        P = findLast_elmMesin(L);
        adrMesin Q = first(L);
        while (nextMesin(Q)!=P){
            Q=nextMesin(Q);
        }
        nextMesin(Q) = first(L);
        nextMesin(P) = NULL;
        pelanggan(P) = NULL;
        delete P;
    }
}
void deleteAfter_mesin(adrMesin &prec, adrMesin &P){
    P = nextMesin(prec);
    nextMesin(prec) = nextMesin(P);
    nextMesin(P) = NULL;
    pelanggan(P) = NULL;
    delete P;
}
void deleteMesin(List &L, adrMesin mesin ,adrMesin &P){
    if (first(L)==NULL){
        cout << "LIST MESIN KOSONG!" << endl;
    }else{
        adrMesin lastElm_mesin = findLast_elmMesin(L);
        if (first(L)==mesin){
            deleteFirst_mesin(L,P);
            cout << "JENIS DELETE\t: DELETE FIRST" << endl;
        }else if (lastElm_mesin==mesin){
            deleteLast_mesin(L,P);
            cout << "JENIS DELETE\t: DELETE LAST" << endl;
        }else{
            adrMesin prec = first(L);
            while (nextMesin(prec)!=mesin){
                prec = nextMesin(prec);
            }
            deleteAfter_mesin(prec,P);
            cout << "JENIS DELETE\t: DELETE AFTER" << endl;
        }
    }
}
void viewA_mesin(adrMesin P){
    cout << "===============MESIN " << infoMesin(P).no_mesin << "===============" << endl;
    cout << "JENIS LAYANAN\t\t: " << infoMesin(P).jenis_layanan << endl;
    cout << "HARGA (PER PASANG)\t: " << infoMesin(P).harga << endl;
    cout << "ESTIMASI WAKTU\t\t: " << infoMesin(P).estimasi_pengerjaan << endl;
}
void viewAll_mesin(List L){
    if (first(L)==NULL){
        cout << "LIST MESIN KOSONG!" << endl;
    }else{
        adrMesin P = first(L);
        do{
            viewA_mesin(P);
            P = nextMesin(P);
        }while (P!=first(L));
    }
}
