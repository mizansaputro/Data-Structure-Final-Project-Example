#include "menu.h"

void menu(){
    system("cls");
    cout << "==================================LIPDEALS CARGO TRANSPORT==================================\n" << endl;
    cout << "0) EXIT" << endl;
    cout << "1) Tambah Data Tipe (OTOMATIS)" << endl;
    cout << "2) Tambah Data Pengguna Jasa Ke Dalam Suatu Tipe Jasa Pengiriman " << endl;
    cout << "3) Lihat Data Semua Tipe Jasa Pengiriman" << endl;
    cout << "4) Cari & Lihat Data Suatu Tipe Jasa Pengiriman" << endl;
    cout << "5) Lihat Semua Data Pengguna Jasa" << endl;
    cout << "6) Cari & Lihat Data Pengguna Jasa " << endl;
    cout << "7) Cari & Lihat Data Pengguna Jasa Di Suatu Tipe Jasa Pengiriman" << endl;
    cout << "8) Hapus Data Suatu Tipe Jasa Pengiriman" << endl;
    cout << "9) Hapus Data Semua Pengguna Jasa Di Suatu Tipe Jasa Tertentu" << endl;
    cout << "10) Hapus Data Suatu Pengguna Jasa Di Suatu Tipe Jasa Tertentu" << endl;
    cout << "11) Lihat Total Uang Masuk Keseluruhan" << endl;
    cout << "12) Lihat Total Berat Keseluruhan" << endl;
    cout << "13) Lihat Total Jumlah Barang Keseluruhan" << endl;
    cout << "14) Lihat Total Jasa Pengguna Keseluruhan" << endl;
    cout << "15) Lihat Total Bayar Tertinggi" << endl;
    cout << "\nPilih menu: ";
}
void tambahTipe(List &L){
    adrTipe P1 = createElm_tipe(1, "GENERAL CARGO");
    adrTipe P2 = createElm_tipe(2, "SPECIAL CARGO");
    adrTipe P3 = createElm_tipe(3, "DANGEROUS CARGO");

    adrTipe find1 = findTipe(L,1);
    if (find1==NULL){
        insertTipe(L, P1);
    }else{
        cout << "PROSES INPUT GAGAL: GENERAL CARGO SUDAH ADA!" << endl;
    }

    adrTipe find3 = findTipe(L,3);
    if (find3==NULL){
        insertTipe(L, P3);
    }else{
        cout << "PROSES INPUT GAGAL: DANGEROUS CARGO SUDAH ADA!" << endl;
    }

    adrTipe find2 = findTipe(L,2);
    if (find2==NULL){
        insertTipe(L, P2);
    }else{
        cout << "PROSES INPUT GAGAL: SPECIAL CARGO SUDAH ADA!" << endl;
    }


    cout << "PROSES INPUT TIPE JASA PENGIRIMAN SELESAI!" << endl;
}
void tambahPengguna(List &L){
    int pilih, jenis_kargo, tujuan, jumlah;
    float berat;
    string nama_pengirim, jenis_kargoS, tujuanS;

    cout << "->PILIH TIPE<-" << endl;
    cout << "--------------" << endl;
    cout << "KLIK 1 (GENERAL CARGO)" << endl;
    cout << "KLIK 2 (SPECIAL CARGO)" << endl;
    cout << "KLIK 3 (DANGEROUS CARGO)" << endl;
    cout << "PILIH: ";
    cin >> pilih;

    while (pilih<=0 || pilih>3){
        cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
        cout << "PILIH: ";
        cin >> pilih;
    }

    adrTipe fTipe = findTipe(L, pilih);
    if (fTipe==NULL){
        cout << "TIPE KARGO BELUM DIINPUTKAN!" << endl;
    }else{
        cout << endl;
        cout << "->INPUT DATA PENGGUNA JASA<-" << endl;
        cout << "----------------------------" << endl;
        cout << "NAMA PENGIRIM\t: ";
        cin.ignore();
        getline(cin,nama_pengirim);
        cout << "JENIS KARGO\t: " << endl;
        cout << "KLIK 1 (REGULER)" << endl;
        cout << "KLIK 2 (CEPAT SAMPAI)" << endl;
        cout << "PILIH\t\t: ";
        cin >> jenis_kargo;
        while (jenis_kargo<=0 && jenis_kargo>2){
            cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
            cout << "PILIH\t\t: ";
            cin >> jenis_kargo;
        }
        cout << "JUMLAH BARANG\t: ";
        cin >> jumlah;
        cout << "BERAT (KG)\t: ";
        cin >> berat;
        cout << "TUJUAN\t\t: " << endl;
        cout << "KLIK 1 (PULAU JAWA)" << endl;
        cout << "KLIK 2 (LUAR JAWA)" << endl;
        cout << "PILIH\t\t: ";
        cin >> tujuan;
        while (tujuan<=0 && tujuan>2){
            cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
            cout << "PILIH\t\t: ";
            cin >> tujuan;
        }

        if (jenis_kargo==1){
            jenis_kargoS = "REGULER";
        }else{
            jenis_kargoS = "CEPAT SAMPAI";
        }

        if (tujuan==1){
            tujuanS = "PULAU JAWA";
        }else{
            tujuanS = "LUAR JAWA";
        }


        adrData P = createElm_data(jenis_kargoS, jumlah, berat, tujuanS, nama_pengirim);

        if (pilih==1){
            infoData(P).bayar = infoData(P).bayar+10000;
        }else if (pilih==2){
            infoData(P).bayar = infoData(P).bayar+20000;
        }else{
            infoData(P).bayar = infoData(P).bayar+30000;
        }
        addJasapengguna_toTipe(fTipe, P);
        cout << "PROSES INPUT BERHASIL..." << endl;
    }
}
void lihatTipe(List L){
    showTipe(L);
}
void cari_lihat_tipe(List L){
    int pilih;

    cout << "->PILIH TIPE<-" << endl;
    cout << "--------------" << endl;
    cout << "KLIK 1 (GENERAL CARGO)" << endl;
    cout << "KLIK 2 (SPECIAL CARGO)" << endl;
    cout << "KLIK 3 (DANGEROUS CARGO)" << endl;
    cout << "PILIH: ";
    cin >> pilih;

    while (pilih<=0 || pilih>3){
        cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
        cout << "PILIH: ";
        cin >> pilih;
    }
    adrTipe fTipe = findTipe(L, pilih);
    if (fTipe==NULL){
        cout << "TIPE TIDAK DITEMUKAN!" << endl;
    }else{
        showSuatu_tipe(fTipe);
    }
}
void lihatSemua_jasaPengguna(List L){
    showSemua_jasaPengguna_inAlltipe(L);
}
void cari_lihat_penggunaJasa(List L){
    string nama_pengirim;

    cout << "->INPUT DATA PENGGUNA JASA<-" << endl;
    cout << "----------------------------" << endl;
    cout << "NAMA PENGIRIM\t: ";
    cin.ignore();
    getline(cin,nama_pengirim);

    adrData P = findSuatu_jasaPengguna_inSemua(L, nama_pengirim);
    if (P==NULL){
        cout << "PENGGUNA JASA TIDAK DITEMUKAN!" << endl;
    }else{
        showSuatu_data(P);
    }
}
void cari_lihat_penggunaJasa_diTipe(List L){
    string nama_pengirim;
    int pilih;

    cout << "->INPUT DATA PENGGUNA JASA<-" << endl;
    cout << "----------------------------" << endl;
    cout << "NAMA PENGIRIM\t: ";
    cin.ignore();
    getline(cin,nama_pengirim);
    cout << endl;
    cout << "->PILIH TIPE<-" << endl;
    cout << "--------------" << endl;
    cout << "KLIK 1 (GENERAL CARGO)" << endl;
    cout << "KLIK 2 (SPECIAL CARGO)" << endl;
    cout << "KLIK 3 (DANGEROUS CARGO)" << endl;
    cout << "PILIH: ";
    cin >> pilih;

    while (pilih<=0 || pilih>3){
        cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
        cout << "PILIH: ";
        cin >> pilih;
    }

    adrTipe fTipe = findTipe(L, pilih);
    if (fTipe==NULL){
        cout << "TIPE KARGO BELUM DIINPUTKAN!" << endl;
    }else{
        adrData P = findData(data(fTipe),nama_pengirim);
        if (P!=NULL){
            showSuatu_data(P);
        }else{
            cout << "DATA PENGGUNA JASA TIDAK DITEMUKAN!" << endl;
        }
    }
}
void hapusTipe(List &L){
    int pilih;
    adrTipe P;

    cout << "->PILIH TIPE<-" << endl;
    cout << "--------------" << endl;
    cout << "KLIK 1 (GENERAL CARGO)" << endl;
    cout << "KLIK 2 (SPECIAL CARGO)" << endl;
    cout << "KLIK 3 (DANGEROUS CARGO)" << endl;
    cout << "PILIH: ";
    cin >> pilih;

    while (pilih<=0 || pilih>3){
        cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
        cout << "PILIH: ";
        cin >> pilih;
    }

    adrTipe fTipe = findTipe(L, pilih);
    if (fTipe==NULL){
        cout << "TIPE KARGO BELUM DIINPUTKAN!" << endl;
    }else{
        deleteTipe(L, fTipe, P);
        cout << "PROSES DELETE BERHASIL..." << endl;
    }

}
void hapusSemua_pnggunaJasa_diTipe(List &L){
    int pilih;
    adrData P;

    cout << "->PILIH TIPE<-" << endl;
    cout << "--------------" << endl;
    cout << "KLIK 1 (GENERAL CARGO)" << endl;
    cout << "KLIK 2 (SPECIAL CARGO)" << endl;
    cout << "KLIK 3 (DANGEROUS CARGO)" << endl;
    cout << "PILIH: ";
    cin >> pilih;

    while (pilih<=0 || pilih>3){
        cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
        cout << "PILIH: ";
        cin >> pilih;
    }
    cout << endl;
    adrTipe fTipe = findTipe(L, pilih);
    if (fTipe==NULL){
        cout << "TIPE KARGO BELUM DIINPUTKAN!" << endl;
    }else{
        adrData delData = findLastelm(data(fTipe));
        while (delData!=NULL){
            deleteJasapengguna_inTipe(fTipe, delData, P);
            delData = findLastelm(data(fTipe));
        }
    }
}
void hapusSuatu_pnggunaJasa_diTipe(List &L){
    int pilih;
    adrData P;

    cout << "->PILIH TIPE<-" << endl;
    cout << "--------------" << endl;
    cout << "KLIK 1 (GENERAL CARGO)" << endl;
    cout << "KLIK 2 (SPECIAL CARGO)" << endl;
    cout << "KLIK 3 (DANGEROUS CARGO)" << endl;
    cout << "PILIH: ";
    cin >> pilih;

    while (pilih<=0 || pilih>3){
        cout << "INPUT SALAH: MASUKAN PILIHAN DENGAN BENAR!" << endl;
        cout << "PILIH: ";
        cin >> pilih;
    }
    cout << endl;
    adrTipe fTipe = findTipe(L, pilih);
    if (fTipe==NULL){
        cout << "TIPE KARGO BELUM DIINPUTKAN!" << endl;
    }else{
        string nama_pengirim;

        cout << "->INPUT DATA PENGGUNA JASA<-" << endl;
        cout << "----------------------------" << endl;
        cout << "NAMA PENGIRIM\t: ";
        cin.ignore();
        getline(cin,nama_pengirim);

        adrData fData = findData(data(fTipe),nama_pengirim);
        if (fData==NULL){
            cout << "DATA PENGGUNA JASA TIDAK DITEMUKAN!" << endl;
        }else{
            deleteJasapengguna_inTipe(fTipe, fData, P);
            cout << "PROSES DELETE BERHASIL..." << endl;
        }

    }
}
void lihatTotal_uangMasuk(List L){
    cout << "TOTAL UANG MASUK\t: " << sumTotal_uang(L) << endl;
}
void lihatTotal_berat(List L){
    cout << "TOTAL BERAT\t: " << sumTotal_berat(L) << endl;
}
void lihatTotal_jumlahBarang(List L){
    cout << "TOTAL BARANG\t: " << sumTotal_barang(L) << endl;
}
void lihatTotal_jasaPengguna(List L){
    cout << "TOTAL JASA PENGGUNA\t: " << countJasapengguna(L) << endl;
}
void lihatBayartertinggi(List L){
    cout << "BAYAR TERTINGGI\t: " << maxBayar(L) << endl;
}
