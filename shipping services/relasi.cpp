#include "relasi.h"

void addJasapengguna_toTipe(adrTipe &tipe , adrData &data2){
    infoTipe(tipe).total_barang = infoTipe(tipe).total_barang+infoData(data2).jumlah;
    infoTipe(tipe).total_berat = infoTipe(tipe).total_berat+infoData(data2).berat;
    infoTipe(tipe).total_uang = infoTipe(tipe).total_uang+infoData(data2).bayar;
    insertData(data(tipe),data2);
}
void deleteJasapengguna_inTipe(adrTipe &tipe, adrData delData, adrData &data2){
    infoTipe(tipe).total_barang = infoTipe(tipe).total_barang-infoData(delData).jumlah;
    infoTipe(tipe).total_berat = infoTipe(tipe).total_berat-infoData(delData).berat;
    infoTipe(tipe).total_uang = infoTipe(tipe).total_uang-infoData(delData).bayar;
    deleteData(data(tipe), delData, data2);
}
void showSuatu_jasaPengguna(adrData P){
    showSuatu_data(P);
}
void showSemua_jasaPengguna_inTipe(adrData data1){
    showData(data1);
}
void showSemua_jasaPengguna_inAlltipe(List L){
    if (isEmpty(L)){
        cout << "TIDAK ADA DATA TIPE!" << endl;
    }else{
        adrTipe P = First(L);
        do{
            showSuatu_tipe(P);
            cout << "---------------------------------" << endl;
            if (data(P)==NULL){
                cout << "TIDAK ADA DATA JASA PENGGUNA!" << endl;
            }else{
                adrData Q = data(P);
                while (Q!=NULL){
                    showSuatu_jasaPengguna(Q);
                    Q = nextData(Q);
                }
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
}
adrData findSuatu_jasaPengguna_inSemua(List L, string nama_pengirim){
    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            adrData Q = data(P);
            while (Q!=NULL){
                if (infoData(Q).nama_pengirim==nama_pengirim){
                    return Q;
                }
                Q = nextData(Q);
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return NULL;
}
adrData findSuatu_jasaPengguna_inSuatu(adrData P, string nama_pengirim){
    findData(P, nama_pengirim);
}
int sumTotal_barang(List L){
    int totBarang = 0;

    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            adrData Q = data(P);
            while (Q!=NULL){
                totBarang = totBarang+infoTipe(P).total_barang;
                Q = nextData(Q);
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return totBarang;
}
float sumTotal_berat(List L){
    int totBerat = 0;

    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            adrData Q = data(P);
            while (Q!=NULL){
                totBerat = totBerat+infoTipe(P).total_berat;
                Q = nextData(Q);
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return totBerat;
}
int sumTotal_uang(List L){
    int totUang = 0;

    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            adrData Q = data(P);
            while (Q!=NULL){
                totUang = totUang+infoTipe(P).total_uang;
                Q = nextData(Q);
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return totUang;
}
int countJasapengguna(List L){
    int count = 0;

    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            adrData Q = data(P);
            while (Q!=NULL){
                count = count+1;
                Q = nextData(Q);
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return count;
}
int maxBayar(List L){
    int max = 0;

    if (!isEmpty(L)){
        adrTipe P = First(L);
        do{
            adrData Q = data(P);
            while (Q!=NULL){
                if (max<infoData(Q).bayar){
                    max = infoData(Q).bayar;
                }
                Q = nextData(Q);
            }
            P = nextTipe(P);
        }while (P!=First(L));
    }
    return max;
}
