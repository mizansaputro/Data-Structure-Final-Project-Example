#include "menu.h"

void menu(){
    system("cls");
    cout << "==================================JASA CUCI SEPATU AHOOY==================================\n" << endl;
    cout << "0) KELUAR" << endl;
    cout << "1) Tambah Mesin (Insert Parent)" << endl;
    cout << "2) Tambah Pelanggan Ke Dalam Suatu Mesin (Insert Child to X Parent) " << endl;
    cout << "3) Lihat Detail Semua Mesin (Show Parent)" << endl;
    cout << "4) Cari & Lihat Mesin (Find & Show Parent)" << endl;
    cout << "5) Lihat Info Semua Mesin+Pelanggan (Show Info Form All Data Parent & Child)" << endl;
    cout << "6) Cari & Lihat Detail Pelanggan (Find From All Data Parent & Show A Child Info)" << endl;
    cout << "7) Cari & Lihat Detail Pelanggan Di Suatu Mesin (Find From Parent X & show A Child Info)" << endl;
    cout << "8) Hapus Data Sebuah Mesin (Delete Parent)" << endl;
    cout << "9) Hapus Data Sebuah Pelanggan Dari Data Mesin (Delete Child Of Parent X)" << endl;
    cout << "10) Lihat Banyak Pelanggan (Count 'Pelanggan' From All Data Parent & Child)" << endl;
    cout << "11) Lihat Jumlah Uang Masuk (Sum 'Uang Masuk' From All Data Parent & Child" << endl;
    cout << "\nPilih menu: ";
}
void tambahMesin(List &L){
    string jenis_layanan;
    int no_mesin, pilih;

    cout << ">>>>>>>>>>TAMBAH MESIN<<<<<<<<<<" << endl;
    cout << "NO MESIN\t: ";
    cin >> no_mesin;
    adrMesin pFind = findMesin(L,no_mesin);
    if (pFind!=NULL){
        cout << "INPUT GAGAL: NO MESIN SUDAH ADA!" << endl;
    }else{
        cout << "JENIS LAYANAN\t: " << endl;
        cout << "Tekan '1' (REGULER)" << endl;
        cout << "Tekan '2' (KILAT)" << endl;
        cout << "PILIH\t: ";
        cin >> pilih;
        while (pilih<=0 || pilih>2){
            cout << "INPUT SALAH: INPUTAN TIDAK DIKENAL!" << endl;
            cout << "PILIH\t: ";
            cin >> pilih;
        }
        if (pilih==1){
            jenis_layanan = "REGULER";
        }else{
            jenis_layanan = "KILAT";
        }

        adrMesin P = createElm_mesin(no_mesin, jenis_layanan);
        insertMesin(L,P);
    }
}
void tambahPelanggan(List &L){
    string jenis_layanan, nama, jenis, tanggal_masuk, tanggal_keluar;
    int no_mesin, pilih, id, banyak, bayar;

    cout << ">>>>>>>>>>CARI MESIN<<<<<<<<<<" << endl;
    cout << "NO MESIN\t: ";
    cin >> no_mesin;
    adrMesin pFind = findMesin(L,no_mesin);
    if (pFind!=NULL){
        cout << ">>>>>>>>>>TAMBAH PELANGGAN<<<<<<<<<<" << endl;
        cout << "ID\t\t\t: ";
        cin >> id;
        adrPel pFind2 = findPelanggan_inAllmesin(L,id);
        if (pFind2==NULL){
            cout << "NAMA\t\t\t: ";
            cin >> nama;
            cout << "JENIS\t\t\t: ";
            cin >> jenis;
            cout << "BANYAK (PASANG)\t\t: ";
            cin >> banyak;
            cout << "TANGGAL MASUK (DD-MM-YYYY)\t: ";
            cin >> tanggal_masuk;

            bayar = infoMesin(pFind).harga*banyak;

            int tglM = stoi(tanggal_masuk.substr(0,2));
            int blnM = stoi(tanggal_masuk.substr(3,5));
            int tahunM = stoi(tanggal_masuk.substr(6,10));

            while (tglM>30 || blnM>12){
                cout << "INPUT SALAH: INPUTKAN TANGGAL DENGAN BENAR!" << endl;
                cout << "TANGGAL MASUK (DD-MM-YYYY)\t: ";
                cin >> tanggal_masuk;
                tglM = stoi(tanggal_masuk.substr(0,2));
                blnM = stoi(tanggal_masuk.substr(3,5));
                tahunM = stoi(tanggal_masuk.substr(6,10));
            }

            tglM = tglM+infoMesin(pFind).estimasi_pengerjaan;
            if (tglM>30){
                tglM = tglM-30;
                blnM = blnM+1;
            }
            if (blnM>12){
                blnM = blnM-12;
                tahunM = tahunM+1;
            }
            string tglK,blnK,thnK;

            if (tglM<10){
                tglK = "0"+to_string(tglM);
            }else{
                tglK = to_string(tglM);
            }

            if(blnM<10){
                blnK = "0"+to_string(blnM);
            }else{
                blnK = to_string(blnM);
            }
            thnK = to_string(tahunM);

            tanggal_keluar = tglK+"-"+blnK+"-"+thnK;

            adrPel P = createElm_pel(id,nama,jenis,banyak,bayar,tanggal_masuk,tanggal_keluar);
            insertPel(pelanggan(pFind),P);

        }else{
            cout << "INPUT GAGAL: ID SUDAH ADA!" << endl;
        }

    }else{
        cout << "INPUT GAGAL: NO MESIN TIDAK DITEMUKAN!" << endl;
    }
}
void lihatSemua_mesin(List L){
    viewAll_mesin(L);
}
void cari_lihat_sebuahMesin(List L){
   int no_mesin;

    cout << ">>>>>>>>>>CARI MESIN<<<<<<<<<<" << endl;
    cout << "NO MESIN\t: ";
    cin >> no_mesin;
    adrMesin pFind = findMesin(L,no_mesin);
    if (pFind!=NULL){
        viewA_mesin(pFind);
    }else{
        cout << "INPUT GAGAL: NO MESIN TIDAK ADA!" << endl;
    }
}
void lihatSemua_mesin_pelanggan(List L){
    viewAllpelanggan_inAllmesin(L);
}
void cari_lihat_pelanggan_diSemua_mesin(List L){
    int id;

    cout << ">>>>>>>>>>CARI PELANGGAN<<<<<<<<<<" << endl;
    cout << "ID\t\t: ";
    cin >> id;
    adrPel pFind2 = findPelanggan_inAllmesin(L,id);
    if (pFind2!=NULL){
        viewA_pel(pFind2);
    }else{
        cout << "INPUT GAGAL: TIDAK ADA PELANGGAN DITEMUKAN!" << endl;
    }
}
void cari_lihat_pelanggan_diSebuah_mesin(List L){
    int no_mesin, id;

    cout << ">>>>>>>>>>CARI MESIN<<<<<<<<<<" << endl;
    cout << "NO MESIN\t: ";
    cin >> no_mesin;
    adrMesin pFind = findMesin(L,no_mesin);
    if (pFind!=NULL){
        cout << ">>>>>>>>>>CARI PELANGGAN<<<<<<<<<<" << endl;
        cout << "ID\t\t: ";
        cin >> id;
        adrPel pFind2 = findPel(pelanggan(pFind),id);
        if (pFind2!=NULL){
            viewA_pel(pFind2);
        }else{
            cout << "INPUT GAGAL: TIDAK DITEMUKAN DATA PELANGGAN!" << endl;
        }
    }else{
        cout << "INPUT GAGAL: TIDAK ADA MESIN DITEMUKAN!" << endl;
    }
}
void hapusMesin(List &L){
    int no_mesin, id;
    adrMesin P;

    cout << ">>>>>>>>>>HAPUS MESIN<<<<<<<<<<" << endl;
    cout << "NO MESIN\t: ";
    cin >> no_mesin;
    adrMesin pFind = findMesin(L,no_mesin);
    if (pFind!=NULL){
        deleteMesin(L,pFind,P);
    }else{
        cout << "INPUT GAGAL: TIDAK ADA MESIN DITEMUKAN!" << endl;
    }
}
void hapusPelanggan(List &L){
    int no_mesin, id;
    adrPel P;
    cout << ">>>>>>>>>>CARI MESIN<<<<<<<<<<" << endl;
    cout << "NO MESIN\t: ";
    cin >> no_mesin;
    adrMesin pFind = findMesin(L,no_mesin);
    if (pFind!=NULL){
        cout << ">>>>>>>>>>HAPUS PELANGGAN<<<<<<<<<<" << endl;
        cout << "ID\t\t: ";
        cin >> id;
        adrPel pFind2 = findPel(pelanggan(pFind),id);
        if (pFind2!=NULL){
            deletePel(pelanggan(pFind),pFind2,P);
        }else{
            cout << "INPUT GAGAL: TIDAK DITEMUKAN DATA PELANGGAN!" << endl;
        }
    }else{
        cout << "INPUT GAGAL: TIDAK ADA MESIN DITEMUKAN!" << endl;
    }
}
void lihatBanyak_pelanggan(List L){
    cout << "BANYAK PELANGGAN\t: " << countPelanggan(L) << endl;
}
void lihatJumlah_uangMasuk(List L){
    cout << "JUMLAH UANG MASUK\t: " << sumUangmasuk(L) << endl;
}



