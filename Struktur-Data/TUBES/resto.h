#include <bits/stdc++.h>
using namespace std;

#define firstMenu(P) ((P).firstMenu)
#define infoMenu(P) (P)->infoMenu
#define nextMenu(P) (P)->nextMenu
#define firstPelanggan(P) ((P).firstPelanggan)
#define infoPelanggan(P) (P)->infoPelanggan
#define nextPelanggan(P) (P)->nextPelanggan
#define infoPesanan(P) (P)->infoPesanan
#define nextPesanan(P) (P)->nextPesanan
#define clear system("cls")
#define pause system("PAUSE")

struct menu{
    string namaMenu;
    int noMenu;
};

typedef struct elmMenu *adrMenu;

struct elmMenu{
    menu infoMenu;
    adrMenu nextMenu;
};

struct listMenu{
    adrMenu firstMenu;
};

//////////////////////////////////////////////////////////

struct pelanggan{
    string namaPelanggan;
    int noAntrian;
};

struct pesanan{
    int indexPesanan;
    string namaPesanan;
    int countPesanan;
};

typedef struct elmPelanggan *adrPelanggan;
typedef struct elmPesanan *adrPesanan;

struct elmPelanggan{
    pelanggan infoPelanggan;
    adrPelanggan nextPelanggan;
    adrPesanan nextPesanan;
};

struct elmPesanan{
    pesanan infoPesanan;
    adrPesanan nextPesanan;
};

struct listPelanggan{
    adrPelanggan firstPelanggan;
};

//////////////////////////////////////////////////////////

void createList_menu(listMenu &LM);
adrMenu newElement_menu(menu x);
void insertLast_menu(listMenu &LM, adrMenu P);
void printInfo_menu(listMenu LM);
adrMenu find_menu(listMenu LM, int indexCari);
void addMenu_menu(listMenu &LM, int &nMenu);

void createList_pelanggan(listPelanggan &LP);
adrPelanggan newElement_pelanggan(pelanggan y);
void insertLast_pelanggan(listPelanggan &LP, adrPelanggan P);
bool find_pelanggan(listPelanggan LP, pelanggan infoP);
adrPelanggan find_pelanggan_adr(listPelanggan LP, pelanggan infoP);
void printInfopesanan_pelanggan(listPelanggan LP);
int banyakPesanan(listPelanggan LP, adrPelanggan P);

adrPesanan find_pesanan(listPelanggan LP, adrPelanggan Z, adrPesanan X, int indexCari);
adrPesanan newElement_pesanan(pesanan z);
void insertLast_pesanan(adrPesanan X, adrPelanggan P, adrMenu Q);

void deleteAntrian_pelanggan(listPelanggan &LP, int &nPelanggan);
void deletePesanan_pelanggan(listPelanggan &LP);

void deleteFirst_pesanan(adrPelanggan &P);
void deleteLast_pesanan(adrPelanggan &P);
void deleteAfter_pesanan(adrPelanggan &P, adrPesanan Q);

void insertPelanggan(listPelanggan &LP, listMenu LM, int &nPelanggan);
void printInfo_pelanggan_pesanan(listPelanggan LP);
void defaultMenu(listMenu &LM);
int selectHome_all();