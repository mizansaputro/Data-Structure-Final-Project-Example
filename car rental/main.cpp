#include "menu.h"

int main()
{
    List L;
    int pilih;

    createList(L);

       do
    {
        system("cls");
        mainMenu();
        cin >> pilih;
        system("cls");

        switch(pilih){
        case 1:
            tambahMobil(L);
            cout << endl; system("pause");
            break;
        case 2:
            tambahCostumer_keElmmobil(L);
            cout << endl; system("pause");
            break;
        case 3:
            lihatDatamobil(L);
            cout << endl; system("pause");
            break;
        case 4:
            lihatDatamobil_berdasarPencarian(L);
            cout << endl; system("pause");
            break;
        case 5:
            lihatSemuacostumer(L);
            cout << endl; system("pause");
            break;
        case 6:
            cariCostumer_diMobiltertentu(L);
            cout << endl; system("pause");
            break;
        case 7:
            cariMobil_tampilSemuacostumer(L);
            cout << endl; system("pause");
            break;
        case 8:
            hapusSuatuMobil(L);
            cout << endl; system("pause");
            break;
        case 9:
            hapusSuatucostumer_diMobiltertentu(L);
            cout << endl; system("pause");;
            break;
        case 10:
            hapusSemuacostumer_diMobiltertentu(L);
            cout << endl; system("pause");
            break;
        case 11:
            lihatJumlahuang(L);
            cout << endl; system("pause");
            break;
        case 12:
            lihatBanyakcostumer(L);
            cout << endl; system("pause");
            break;
        default:
            if(pilih != 0){
                cout << "SISTEM: INPUT TIDAK DIKENAL!" << endl;
                cout << endl; system("pause");
            }
            break;
        }
    }while (pilih != 0);
}

