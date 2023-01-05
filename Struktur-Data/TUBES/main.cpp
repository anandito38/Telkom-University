#include "resto.cpp"

int main(){
    listMenu LM; listPelanggan LP;
    menu infoM; pelanggan infoP; pesanan infopes;
    adrMenu P; adrPelanggan Q; adrPesanan Z;
    int nMenu = 10; int nPelanggan = 0;
    createList_menu(LM);
    createList_pelanggan(LP);
    defaultMenu(LM);
    
    int pilihan = selectHome_all();

    while(true){
        if(pilihan == 1){
            clear;
            printInfo_menu(LM);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 2){
            clear;
            addMenu_menu(LM, nMenu);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 3){
            clear;
            insertPelanggan(LP, LM, nPelanggan);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 4){
            clear;
            printInfo_pelanggan_pesanan(LP);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 5){
            clear;
            printInfopesanan_pelanggan(LP);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 6){
            clear;
            deleteAntrian_pelanggan(LP, nPelanggan);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 7){
            clear;
            deletePesanan_pelanggan(LP);
            pause;
            pilihan = selectHome_all();

        }else if(pilihan == 0){
            clear;
            cout << endl << "Anda lepas dari beban tubes struktur data" << endl;
            return 0;

        }else{
            clear;
            cout << "Anda salah memasukkan input!!, silahkan masukkan ulang input" << endl;
            pause;
            pilihan = selectHome_all();
        }
    }
    
}