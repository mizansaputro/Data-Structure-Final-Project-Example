#include "mobil.h"

void addCostumer_toMobil(adrCostumer &cMobil, adrCostumer c);
void deleteCostumer_inMobil(adrCostumer &cMobil, adrCostumer thisC, adrCostumer &c);
void deleteAllcostumer_inMobil(adrCostumer &cMobil, adrCostumer thisC, adrCostumer &c);
adrCostumer findCostumer_inMobil(adrCostumer cMobil, string no_ktp);
adrCostumer findCostumer_inListmobil(List L, string no_ktp);
void viewAllcostumer_inMobil(adrCostumer cMobil);
void viewAllcostumer_inListmobil(List L);
void viewSomecostumer_inListmobil(List L, string no_ktp);
int countAllcostumer(List L);
int sumPenghasilan(List L);

