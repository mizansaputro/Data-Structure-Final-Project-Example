#include "costumer.h"

adrCostumer createElmcostumer(string nama, string no_ktp, int lama_sewa,
                              string tanggal_sewa, string jam_sewa){
    adrCostumer P = new elmCostumer;

    infoCostumer(P).nama = nama;
    infoCostumer(P).no_ktp = no_ktp;
    infoCostumer(P).lama_sewa = lama_sewa;
    infoCostumer(P).tanggal_sewa = tanggal_sewa;
    infoCostumer(P).jam_sewa = jam_sewa;
    infoCostumer(P).harga = 400000*lama_sewa;
    //habis_sewa
    //DD/MM/YYYY
    int tgl = stoi(tanggal_sewa.substr(0,2));
    int bulan = stoi(tanggal_sewa.substr(3,5));
    int tahun = stoi(tanggal_sewa.substr(6,10));

    tgl = tgl+lama_sewa;
    if (tgl>30){
        bulan = bulan+1;
        tgl = tgl-30;
    }
    if (bulan>12){
        tahun = tahun+1;
        bulan = bulan-12;
    }
    string tglS;
    if (tgl<10){
        tglS = "0"+to_string(tgl);
    }else{
        tglS = to_string(tgl);
    }
    string bulanS;
    if (bulan<10){
        bulanS = "0"+to_string(bulan);
    }else{
        bulanS = to_string(bulan);
    }
    string tahunS = to_string(tahun);

    infoCostumer(P).habis_sewa = tglS+"/"+bulanS+"/"+tahunS;

    nextCostumer(P) = NULL;
    return P;
}
void insertFirst_costumer(adrCostumer &c1, adrCostumer &c2){
    if (c1==NULL){
        c1 = c2;
    }else{
        nextCostumer(c2) = c1;
        c1 = c2;
    }
}
void insertLast_costumer(adrCostumer &c1, adrCostumer &c2){
    adrCostumer lastElm = findLastelm(c1);

    nextCostumer(lastElm) = c2;
}
void insertAfter_costumer(adrCostumer &cPrec, adrCostumer &c2){
    nextCostumer(c2) = nextCostumer(cPrec);
    nextCostumer(cPrec) = c2;
}
void insertCostumer(adrCostumer &c1, adrCostumer &c2){
    if (c1==NULL){
        insertFirst_costumer(c1,c2);
    }else{
        adrCostumer P = findLastelm(c1);
        if (infoCostumer(c1).harga>=infoCostumer(c2).harga){
            insertFirst_costumer(c1,c2);
        }else if (infoCostumer(P).harga<=infoCostumer(c2).harga){
            insertLast_costumer(c1,c2);
        }else{
            adrCostumer prec = c1;
            while (prec!=NULL && infoCostumer(nextCostumer(prec)).harga<=infoCostumer(c2).harga){
                prec = nextCostumer(prec);
            }
            insertAfter_costumer(prec,c2);
        }

    }
}
void deleteFirst_costumer(adrCostumer &c1, adrCostumer &c2){
    if (c1==NULL){
        cout << "SISTEM: DATA COSTUMER KOSONG!" << endl;
    }else if (nextCostumer(c1)==NULL){
        c2 = c1;
        c1 = NULL;
        delete c2;
    }else{
        c2 = c1;
        c1 = nextCostumer(c2);
        nextCostumer(c2) = NULL;
        delete c2;
    }
}
void deleteLast_costumer(adrCostumer &c1, adrCostumer &c2){
    if (c1==NULL){
        cout << "SISTEM: DATA COSTUMER KOSONG!" << endl;
    }else if (nextCostumer(c1)==NULL){
        c2 = c1;
        c1 = NULL;
        delete c2;
    }else{
        c2 = findLastelm(c1);
        adrCostumer P = c1;
        while (nextCostumer(P)!=c2){
            P=nextCostumer(P);
        }
        nextCostumer(P) = NULL;
        delete c2;
    }
}
void deleteAfter_costumer(adrCostumer &cPrec, adrCostumer &c2){
    c2 = nextCostumer(cPrec);
    nextCostumer(cPrec) = nextCostumer(c2);
    nextCostumer(c2) = NULL;
    delete c2;
}
void deleteCostumer(adrCostumer &c1,adrCostumer thisC, adrCostumer &c2){
    adrCostumer P = findLastelm(c1);
    if (c1==NULL){
        cout << "SISTEM: DATA COSTUMER KOSONG!" << endl;
    }else{
        if (thisC==c1){
            deleteFirst_costumer(c1,c2);
        }else if (thisC==P){
            deleteLast_costumer(c1,c2);
        }else{
            adrCostumer Q = c1;
            while (nextCostumer(Q)!= thisC){
                Q=nextCostumer(Q);
            }
            deleteAfter_costumer(Q,c2);
        }
        cout << "SISTEM: DATA COSTUMER BERHASIL DIHAPUS!" << endl;
    }

}
adrCostumer findLastelm(adrCostumer c1){
    adrCostumer P = c1;
    if (P!=NULL){
        while (nextCostumer(P)!=NULL){
            P = nextCostumer(P);
        }
        return P;
    }
    return NULL;
}
adrCostumer findCostumer(adrCostumer c1, string no_ktp){
    if (c1!=NULL){
        adrCostumer P = c1;
        while (P!=NULL){
            if (infoCostumer(P).no_ktp.compare(no_ktp)==0){
                return P;
            }
            P = nextCostumer(P);
        }
    }
    return NULL;
}
void viewAllcostumer(adrCostumer c1){
    if (c1==NULL){
        cout << "SISTEM: TIDAK ADA DATA COSTUMER!" << endl;
    }else{
        int i = 1;
        adrCostumer P = c1;
        while (P!=NULL){
            cout << "==================COSTUMER KE- " << i << "==================" << endl;
            cout << "NAMA \t\t: " << infoCostumer(P).nama << endl;
            cout << "NO KTP\t\t: " << infoCostumer(P).no_ktp << endl;
            cout << "LAMA SEWA\t: " << infoCostumer(P).lama_sewa << endl;
            cout << "TANGGAL SEWA\t: " << infoCostumer(P).tanggal_sewa << endl;;
            cout << "JAM SEWA\t: " << infoCostumer(P).jam_sewa << endl;
            cout << "HABIS SEWA\t: " << infoCostumer(P).habis_sewa << endl;
            cout << "HARGA\t\t: " << infoCostumer(P).harga << endl;
            P = nextCostumer(P);
            i++;
        }
        cout << "BANYAK COSTUMER\t: " << i-1 << endl;
    }
}
void viewAcostumer(adrCostumer c1, string no_ktp){
    if (c1==NULL){
        cout << "SISTEM: TIDAK ADA DATA COSTUMER!" << endl;
    }else{
        adrCostumer P = c1;
        while (P!=NULL){
            if (infoCostumer(P).no_ktp==no_ktp){
                cout << "NAMA \t\t: " << infoCostumer(P).nama << endl;
                cout << "NO KTP\t\t: " << infoCostumer(P).no_ktp << endl;
                cout << "LAMA SEWA\t: " << infoCostumer(P).lama_sewa << endl;
                cout << "TANGGAL SEWA\t: " << infoCostumer(P).tanggal_sewa << endl;;
                cout << "JAM SEWA\t: " << infoCostumer(P).jam_sewa << endl;
                cout << "HABIS SEWA\t: " << infoCostumer(P).habis_sewa << endl;
                cout << "HARGA\t\t: " << infoCostumer(P).harga << endl;
            }
            P = nextCostumer(P);
        }
        if (P==NULL){
            cout << "SISTEM: DATA COSTUMER TIDAK DITEMUKAN!" << endl;
        }
    }
}
infotype_date convertDate_toInt(string tgl, string bulan, string tahun){
    infotype_date date;

    date.tgl = stoi(tgl);
    date.bulan = stoi(bulan);
    date.tahun = stoi(tahun);

    return date;
}
