#include "child_data.h"

adrData createElm_data(string jenis_kargo, int jumlah, float berat, string tujuan, string nama_pengirim){
    adrData P = new elmData;
    int bayar = 0;

    infoData(P).jenis_kargo = jenis_kargo;
    infoData(P).jumlah = jumlah;
    infoData(P).berat = berat;
    infoData(P).tujuan = tujuan;
    infoData(P).nama_pengirim = nama_pengirim;

    if (jenis_kargo=="REGULER"){
        bayar = bayar+20000;
    }else{
        bayar = bayar+40000;
    }

    if (tujuan=="PULAU JAWA"){
        bayar = bayar+10000;
    }else{
        bayar = bayar+20000;
    }

    infoData(P).bayar = bayar+5000*berat;
    nextData(P) = NULL;

    return P;
}
void insertFirst_data(adrData &data1, adrData &data2){
    if (data1==NULL){
        data1 = data2;
    }else{
        nextData(data2) = data1;
        data1 = data2;
    }
}
void insertLast_data(adrData &data1, adrData &data2){
    if (data1==NULL){
        data1 = data2;
    }else{
        adrData P = findLastelm(data1);
        nextData(P) = data2;
    }
}
void insertAfter_data(adrData &prec, adrData &data2){
    nextData(data2) = nextData(prec);
    nextData(prec) = data2;

}
void insertData(adrData &data1, adrData &data2){
    if(data1==NULL){
        data1 = data2;
    }else{
        adrData P = findLastelm(data1);
        if (infoData(data1).bayar>=infoData(data2).bayar){
            insertFirst_data(data1,data2);
        }else if(infoData(P).bayar<=infoData(data2).bayar){
            insertLast_data(data1, data2);
        }else{
            adrData Q = data1;
            while (infoData(nextData(Q)).bayar<=infoData(data2).bayar){
                Q = nextData(Q);
            }
            insertAfter_data(Q,data2);
        }
    }
}
void deleteFirst_data(adrData &data1, adrData &data2){
    if (data1==NULL){
        cout << "TIDAK ADA DATA PENGGUNA JASA!" << endl;
    }else if(nextData(data1)==NULL){
        data2 = data1;
        data1 = NULL;
        delete data2;
    }else{
        data2 = data1;
        data1 = nextData(data2);
        nextData(data2) = NULL;
        delete data2;
    }
}
void deleteLast_data(adrData &data1, adrData &data2){
    if (data1==NULL){
        cout << "TIDAK ADA DATA PENGGUNA JASA!" << endl;
    }else if(nextData(data1)==NULL){
        data2 = data1;
        data1 = NULL;
        delete data2;
    }else{
        data2 = findLastelm(data1);
        adrData Q = data1;
        while (nextData(Q)!=data2){
            Q = nextData(Q);
        }
        nextData(Q) = NULL;
        delete data2;
    }
}
void deleteAfter_data(adrData &prec, adrData &data2){
    data2 = nextData(prec);
    nextData(prec) = nextData(data2);
    nextData(data2) = NULL;
    delete data2;
}
void deleteData(adrData &data1, adrData delData, adrData &data2){
    if (data1==NULL){
        cout << "TIDAK ADA DATA PENGGUNA JASA!" << endl;
    }else{
        adrData P = findLastelm(data1);
        if (data1==delData){
            deleteFirst_data(data1,data2);
        }else if (P==delData){
            deleteLast_data(data1,data2);
        }else{
            adrData Q = data1;
            while (nextData(Q)!=delData){
                Q = nextData(Q);
            }
            deleteAfter_data(Q,data2);
        }
    }
}
adrData findData(adrData data1, string nama_pengirim){
    adrData P = NULL;
    if (data1!=NULL){
        P = data1;
        while (P!=NULL && infoData(P).nama_pengirim!=nama_pengirim){
            P = nextData(P);
        }
    }
    return P;
}
adrData findLastelm(adrData data1){
    adrData P = NULL;
    if (data1!=NULL){
        P = data1;
        while (nextData(P)!=NULL){
            P = nextData(P);
        }
    }
    return P;
}
void showData(adrData data1){
    if (data1==NULL){
        cout << "TIDAK ADA DATA JASA PENGGUNA!" << endl;
    }else{
        int no = 0;
        adrData P = data1;
        while (P!=NULL){
            no++;
            cout << "PENGGUNA JASA KE- " << no << endl;
            showSuatu_data(P);
            P = nextData(P);
        }
    }
}
void showSuatu_data(adrData data1){
    cout << "JENIS KARGO\t: " << infoData(data1).jenis_kargo << endl;
    cout << "JUMLAH\t\t: " << infoData(data1).jumlah << endl;
    cout << "BERAT\t\t: " << infoData(data1).berat << endl;
    cout << "BAYAR\t\t: " << infoData(data1).bayar << endl;
    cout << "TUJUAN\t\t: " << infoData(data1).tujuan <<endl;
    cout << "NAMA PENGIRIM\t: " << infoData(data1).nama_pengirim << endl << endl;
}
