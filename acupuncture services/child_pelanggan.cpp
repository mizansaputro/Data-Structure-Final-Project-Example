#include "child_pelanggan.h"

adrPel createElm_pel(int id, string nama, string jenis, int banyak, int bayar, string tanggal_masuk, string tanggal_keluar){
    adrPel P = new elmPelanggan;

    infoPel(P).id = id;
    infoPel(P).nama = nama;
    infoPel(P).jenis = jenis;
    infoPel(P).banyak = banyak;
    infoPel(P).bayar = bayar;
    infoPel(P).tanggal_masuk = tanggal_masuk;
    infoPel(P).tanggal_keluar = tanggal_keluar;
    nextPel(P) = NULL;

    return P;

}
adrPel findLast_elmPel(adrPel P1){
    adrPel Q = P1;
    if (P1!=NULL){
        Q = P1;
        while (nextPel(Q)!=NULL){
            Q = nextPel(Q);
        }
    }
    return Q;
}
adrPel findPel(adrPel P1, int id){
    adrPel Q = P1;
    if (P1!=NULL){
        Q = P1;
        while (Q!=NULL && infoPel(Q).id!=id){
            Q = nextPel(Q);
        }
    }
    return Q;
}
void insertFirst_pel(adrPel &P1, adrPel &P2){
    if (P1==NULL){
        P1 = P2;
    }else{
        nextPel(P2) = P1;
        P1 = P2;
    }
}
void insertLast_pel(adrPel &P1, adrPel &P2){
    if (P1==NULL){
        P1 = P2;
    }else{
        adrPel elmLast_pel = findLast_elmPel(P1);
        nextPel(elmLast_pel) = P2;
    }
}
void insertAfter_pel(adrPel &prec, adrPel &P2){
    nextPel(P2)= nextPel(prec);
    nextPel(prec) = P2;
}
void insertPel(adrPel &P1, adrPel &P2){
    if (P1==NULL){
        insertFirst_pel(P1,P2);
        cout << "JENIS INSERT\t: INSERT FIRST CHILD" << endl;
    }else{
        adrPel lastElm_pel = findLast_elmPel(P1);
        if (infoPel(P1).id>infoPel(P2).id){
            insertFirst_pel(P1,P2);
            cout << "JENIS INSERT\t: INSERT FIRST CHILD" << endl;
        }else if (infoPel(lastElm_pel).id<infoPel(P2).id){
            insertLast_pel(P1,P2);
            cout << "JENIS INSERT\t: INSERT LAST CHILD" << endl;
        }else{
            adrPel prec = P1;
            while (infoPel(nextPel(P1)).id<infoPel(P2).id){
                prec = nextPel(prec);
            }
            insertAfter_pel(prec,P2);
            cout << "JENIS INSERT\t: INSERT AFTER CHILD" << endl;
        }
    }
}
void deleteFirst_pel(adrPel &P1, adrPel &P2){
    P2 = P1;
    if (nextPel(P1)==NULL){
        P1 = NULL;
    }else{
        P1 = nextPel(P2);
    }
    nextPel(P2) = NULL;
    delete P2;
}
void deleteLast_pel(adrPel &P1, adrPel &P2){
    P2 = findLast_elmPel(P1);
    if (nextPel(P1)==NULL){
        P1 = NULL;
    }else{
        adrPel Q = P1;
        while (nextPel(Q)!=P2){
            Q = nextPel(Q);
        }
        nextPel(Q) = NULL;
    }
    nextPel(P2) = NULL;
    delete P2;
}
void deleteAfter_pel(adrPel &prec, adrPel &P2){
    P2 = nextPel(prec);
    nextPel(prec) = nextPel(P2);
    nextPel(P2) = NULL;
    delete P2;
}
void deletePel(adrPel &P1, adrPel pel, adrPel &P2){
    if (P1==NULL){
        cout << "TIDAK ADA PELANGGAN!" << endl;
    }else{
        adrPel lastElm_pel = findLast_elmPel(P1);
        if (P1==pel){
            deleteFirst_pel(P1,P2);
            cout << "JENIS DELETE\t: DELETE FIRST CHILD" << endl;
        }else if (lastElm_pel==pel){
            deleteLast_pel(P1,P2);
            cout << "JENIS DELETE\t: DELETE LAST CHILD" << endl;
        }else{
            adrPel prec = P1;
            while (prec!=NULL && nextPel(prec)!=pel){
                prec = nextPel(prec);
            }
            deleteAfter_pel(prec,P2);
            cout << "JENIS DELETE\t: DELETE AFTER CHILD" << endl;
        }
    }
}
void viewA_pel(adrPel pel){
    int id;
    string nama;
    string jenis;
    int banyak;
    int bayar;
    string tanggal_masuk;
    string tanggal_keluar;
    cout << ">>>>>>>>>>>>>>>>ID " << infoPel(pel).id << "<<<<<<<<<<<<<<<<" << endl;
    cout << "NAMA\t\t: " << infoPel(pel).nama << endl;
    cout << "JENIS\t\t: " << infoPel(pel).jenis << endl;
    cout << "BANYAK (PASANG)\t: " << infoPel(pel).banyak << endl;
    cout << "BAYAR\t\t: " << infoPel(pel).bayar << endl;
    cout << "TANGGAL MASUK\t: " << infoPel(pel).tanggal_masuk << endl;
    cout << "TANGGAL KELUAR\t: " << infoPel(pel).tanggal_keluar << endl;
}
void viewAll_pel(adrPel P1){
    if (P1==NULL){
        cout << "TIDAK ADA PELANGGAN!" << endl;
    }else{
        adrPel P = P1;
        while (P!=NULL){
            viewA_pel(P);
            P = nextPel(P);
        }
    }
}
