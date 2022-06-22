#include "menu.h"

int main()
{
    List L;
    int klik;

    createList(L);
    do
    {
        system("cls");
        menu();
        cin >> klik;
        system("cls");

        switch(klik){
        case 1:
            tambahTipe(L);
            cout << endl; system("pause");
            break;
        case 2:
            tambahPengguna(L);
            cout << endl; system("pause");
            break;
        case 3:
            lihatTipe(L);
            cout << endl; system("pause");
            break;
        case 4:
            cari_lihat_tipe(L);
            cout << endl; system("pause");
            break;
        case 5:
            lihatSemua_jasaPengguna(L);
            cout << endl; system("pause");
            break;
        case 6:
            cari_lihat_penggunaJasa(L);
            cout << endl; system("pause");
            break;
        case 7:
            cari_lihat_penggunaJasa_diTipe(L);
            cout << endl; system("pause");
            break;
        case 8:
            hapusTipe(L);
            cout << endl; system("pause");
            break;
        case 9:
            hapusSemua_pnggunaJasa_diTipe(L);
            cout << endl; system("pause");;
            break;
        case 10:
            hapusSuatu_pnggunaJasa_diTipe(L);
            cout << endl; system("pause");
            break;
        case 11:
            lihatTotal_uangMasuk(L);
            cout << endl; system("pause");
            break;
        case 12:
            lihatTotal_berat(L);
            cout << endl; system("pause");
            break;
        case 13:
            lihatTotal_jumlahBarang(L);
            cout << endl; system("pause");
            break;
        case 14:
            lihatTotal_jasaPengguna(L);
            cout << endl; system("pause");
            break;
        case 15:
            lihatBayartertinggi(L);
            cout << endl; system("pause");
            break;
        default:
            if(klik != 0){
                cout << "INPUT SALAH!" << endl;
                cout << endl; system("pause");
            }
            break;
        }
    }while (klik != 0);
}
