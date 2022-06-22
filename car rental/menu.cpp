#include "menu.h"

void mainMenu(){
    system("cls");
    cout << "==================================MENU==================================\n" << endl;
    cout << "0) EXIT" << endl;
    cout << "1) Menambahkan Data Mobil" << endl;
    cout << "2) Menambahkan Costumer Ke Dalam Data Sebuah Mobil" << endl;
    cout << "3) Menampilkan Semua Data Mobil" << endl;
    cout << "4) Menampilakan Data Mobil Berdasarkan Nama Mobil" << endl;
    cout << "5) Menampilkan Semua Data Costumer Di Semua Data Mobil" << endl;
    cout << "6) Mencari & Menampilkan Data Costumer Tertentu di Mobil Tertentu" << endl;
    cout << "7) Mencari & Menampilkan Semua Data Costumer Di Mobil Tertentu" << endl;
    cout << "8) Menghapus Data Mobil Tertentu" << endl;
    cout << "9) Menghapus Data Costumer Tertentu Di Data Mobil Tertentu" << endl;
    cout << "10) Menghapus Semua Data Costumer Di Data Mobil Tertentu" << endl;
    cout << "11) Menampilkan Semua Jumlah Penghasilan" << endl;
    cout << "12) Menampilkan Banyaknya Costumer Keseluruhan" << endl;
    cout << "\nPilih menu: ";
}
void tambahMobil(List &L){
    string nama, no_polisi;

    cout << "===========TAMBAH MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;
    cout << "NO POLISI\t: ";
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL){
        cout << "SISTEM: GAGAL, DATA MOBIL SUDAH ADA!" << endl;
    }else{
        if (!findNopolisi(L, no_polisi)){
            adrMobil P = createElmmobil(nama,no_polisi);
            insertMobil(L,P);
        }else{
            cout << "SISTEM: GAGAL, DATA MOBIL SUDAH ADA!" << endl;
        }
    }
}
void tambahCostumer_keElmmobil(List &L){
    string nama, no_polisi;
    string namaC, no_ktp, tanggal_sewa, jam_sewa;
    int lama_sewa;
    infotype_date cMobil_habisSewa, cMobil_tanggalSewa;

    cout << "===========MASUKAN DATA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;
    cout << "NO POLISI\t: ";
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL ){
        cout << "===========MASUKAN DATA COSTUMER===========" << endl;
        cout << "NAMA\t\t\t\t: ";
        cin.ignore();
        getline(cin, namaC);
        cout << "NO KTP\t\t\t\t: ";
        cin >> no_ktp;
        cout << "LAMA SEWA\t\t\t: ";
        cin >> lama_sewa;
        cout << "TANGGAL SEWA (DD/MM/YYYY)\t: ";
        cin >> tanggal_sewa;
        cout << "JAM_SEWA (HH:MM)\t\t: ";
        cin >> jam_sewa;

        adrCostumer cMobil = costumer(Pf);
        adrCostumer Q;
        adrCostumer P = createElmcostumer(namaC,no_ktp,lama_sewa,tanggal_sewa,jam_sewa);
        int tglS = stoi(infoCostumer(P).tanggal_sewa.substr(0,2));
        int bulanS = stoi(infoCostumer(P).tanggal_sewa.substr(3,5));
        int tahunS = stoi(infoCostumer(P).tanggal_sewa.substr(6,10));

        bool ketemu = false;
        while (cMobil!=NULL && !ketemu) {
            cMobil_habisSewa = convertDate_toInt(infoCostumer(cMobil).habis_sewa.substr(0,2),
                                                               infoCostumer(cMobil).habis_sewa.substr(3,5),
                                                               infoCostumer(cMobil).habis_sewa.substr(6,10));
            cMobil_tanggalSewa = convertDate_toInt(infoCostumer(cMobil).tanggal_sewa.substr(0,2),
                                                   infoCostumer(cMobil).tanggal_sewa.substr(3,5),
                                                   infoCostumer(cMobil).tanggal_sewa.substr(6,10));
            if (cMobil_habisSewa.tahun==tahunS || cMobil_tanggalSewa.tahun==tahunS){
                if (cMobil_habisSewa.bulan==bulanS || cMobil_tanggalSewa.bulan==bulanS){
                    if (cMobil_habisSewa.tgl>=tglS || cMobil_tanggalSewa.tgl==tglS){
                        ketemu = true;
                    }
                }
            }
            Q = cMobil;
            cMobil = nextCostumer(cMobil);
        }
        if (ketemu==false){
            insertCostumer(costumer(Pf), P);
        }else{
            if (tglS==cMobil_habisSewa.tgl){
                if (stoi(infoCostumer(Q).jam_sewa.substr(0,2))<stoi(infoCostumer(P).jam_sewa.substr(0,2))){
                    insertCostumer(costumer(Pf), P);
                }else if (stoi(infoCostumer(Q).jam_sewa.substr(0,2))==stoi(infoCostumer(P).jam_sewa.substr(0,2))){
                    if (stoi(infoCostumer(Q).jam_sewa.substr(3,5))<=stoi(infoCostumer(P).jam_sewa.substr(3,5))){
                        insertCostumer(costumer(Pf), P);
                    }else{
                            cout << "SISTEM: GAGAL, MOBIL TIDAK TERSEDIA!" << endl;
                    }
                }else{
                    cout << "SISTEM: GAGAL, MOBIL TIDAK TERSEDIA!" << endl;
                }
            }else{
                cout << "SISTEM: GAGAL, MOBIL TIDAK TERSEDIA!" << endl;
            }
        }
    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void lihatDatamobil(List L){
    if (!isEmpty(L)){
        viewAllmobil(L);
    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void lihatDatamobil_berdasarPencarian(List L){
    string nama;

    cout << "===========MASUKAN NAMA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;


    viewSomecar(L, nama);
}
void lihatSemuacostumer(List L){
    viewAllcostumer_inListmobil(L);
}
void cariCostumer_diMobiltertentu(List L){
    string no_ktp,no_polisi, nama;

    cout << "===========MASUKAN DATA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;
    cout << "NO POLISI\t: ";
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL){
        cout << "===========MASUKAN NO KTP COSTUMER===========" << endl;
        cout << "NO KTP\t\t\t: ";
        cin >> no_ktp;

        adrCostumer C = costumer(Pf);
        while (C!=NULL){
            if (infoCostumer(C).no_ktp==no_ktp){
                cout << "NAMA\t\t\t: " << infoCostumer(C).nama << endl;
                cout << "NO KTP\t\t: " << infoCostumer(C).no_ktp << endl;
                cout << "LAMA SEWA\t: " << infoCostumer(C).lama_sewa << endl;
                cout << "TANGGAL SEWA\t: " << infoCostumer(C).tanggal_sewa << endl;;
                cout << "JAM SEWA\t\t: " << infoCostumer(C).jam_sewa << endl;
                cout << "HABIS SEWA\t: " << infoCostumer(C).habis_sewa << endl;
                cout << "HARGA\t\t: " << infoCostumer(C).harga << endl;
            }
            C = nextCostumer(C);
        }
        cout << "SISTEM: PENCARIAN SELESAI" << endl;
    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void cariMobil_tampilSemuacostumer(List L){
    string nama, no_polisi;

    cout << "===========MASUKAN DATA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;
    cout << "NO POLISI\t: ";
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL){
        if (costumer(Pf)!=NULL){
            viewAllcostumer_inMobil(costumer(Pf));
        }else{
            cout << "SISTEM: TIDAK ADA DATA COSTUMER!" << endl;
        }

    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void hapusSuatuMobil(List &L){
    string nama, no_polisi;
    adrMobil P;

    cout << "===========MASUKAN DATA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;;
    cout << "NO POLISI\t: ";
    //cin.ignore();
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL){
        deleteMobil(L, Pf, P);
    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void hapusSuatucostumer_diMobiltertentu(List &L){
    string nama, no_polisi, no_ktp;
    adrCostumer Cdel;

    cout << "===========MASUKAN DATA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;
    cout << "NO POLISI\t: ";
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL){
        cout << "===========MASUKAN NO KTP COSTUMER===========" << endl;
        cout << "NO KTP\t\t\t: ";
        cin >> no_ktp;

        adrCostumer C = findCostumer_inMobil(costumer(Pf), no_ktp);
        if (C!=NULL){
            cout << "LAGI DI SINI" << endl;
            deleteCostumer_inMobil(costumer(Pf), C, Cdel);
        }else{
            cout << "SISTEM: DATA COSTUMER TIDAK DITEMUKAN!" << endl;
        }
    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void hapusSemuacostumer_diMobiltertentu(List &L){
    string nama, no_polisi, no_ktp;
    adrCostumer Cdel;

    cout << "===========MASUKAN DATA MOBIL===========" << endl;
    cout << "NAMA MOBIL\t: ";
    cin >> nama;
    cout << "NO POLISI\t: ";
    cin >> no_polisi;

    adrMobil Pf = findMobil(L, nama, no_polisi);
    if (Pf!=NULL){
        if (costumer(Pf)==NULL){
            cout << "SISTEM: TIDAK ADA DATA COSTUMER!" << endl;
        }else{
            adrCostumer C = costumer(Pf);
            deleteAllcostumer_inMobil(costumer(Pf),C,Cdel);
        }
    }else{
        cout << "SISTEM: GAGAL, DATA MOBIL TIDAK ADA!" << endl;
    }
}
void lihatJumlahuang(List L){
    cout << "JUMLAH UANG MASUK: " << sumPenghasilan(L) << endl;
}
void lihatBanyakcostumer(List L){
    cout << "BANYAK COSTUMER: " << countAllcostumer(L) << endl;
}

