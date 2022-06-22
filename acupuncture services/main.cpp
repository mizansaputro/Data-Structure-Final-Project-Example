#include "menu.h"

int main()
{
    List L;
    int pilih;

    createList(L);
    do
    {
        system("cls");
        menu();
        cin >> pilih;
        system("cls");

        switch(pilih){
        case 1:
            tambahMesin(L);
            cout << endl; system("pause");
            break;
        case 2:
            tambahPelanggan(L);
            cout << endl; system("pause");
            break;
        case 3:
            lihatSemua_mesin(L);
            cout << endl; system("pause");
            break;
        case 4:
            cari_lihat_sebuahMesin(L);
            cout << endl; system("pause");
            break;
        case 5:
            lihatSemua_mesin_pelanggan(L);
            cout << endl; system("pause");
            break;
        case 6:
            cari_lihat_pelanggan_diSemua_mesin(L);
            cout << endl; system("pause");
            break;
        case 7:
            cari_lihat_pelanggan_diSebuah_mesin(L);
            cout << endl; system("pause");
            break;
        case 8:
            hapusMesin(L);
            cout << endl; system("pause");
            break;
        case 9:
            hapusPelanggan(L);
            cout << endl; system("pause");;
            break;
        case 10:
            lihatBanyak_pelanggan(L);
            cout << endl; system("pause");
            break;
        case 11:
            lihatJumlah_uangMasuk(L);
            cout << endl; system("pause");
            break;
        default:
            if(pilih != 0){
                cout << "INPUT TIDAK DIKENAL!" << endl;
                cout << endl; system("pause");
            }
            break;
        }
    }while (pilih != 0);
}
