#include "resto.h"

void createList_menu(listMenu &LM){
    firstMenu(LM) = NULL;
}

adrMenu newElement_menu(menu x){
    adrMenu P = new elmMenu;
    infoMenu(P) = x;
    nextMenu(P) = NULL;

    return P;
}

void insertLast_menu(listMenu &LM, adrMenu P){
    adrMenu Q;
    if(firstMenu(LM) == NULL){
        firstMenu(LM) = P;
    }else{
        Q = firstMenu(LM);
        while(nextMenu(Q) != NULL){
            Q = nextMenu(Q);
        }
        nextMenu(Q) = P;
    }
}

void printInfo_menu(listMenu LM){
    if(firstMenu(LM) == NULL){
        cout << "Menu kosong, silahkan masukkan menu yang terdaftar.." << endl << endl; 
    }else{
        adrMenu P = firstMenu(LM);
        cout << "==============================" << endl;
        cout << "|   NO   |     NAMA MENU     |" << endl;
        cout << "==============================" << endl;
        while(P != NULL){
            cout << "| " << setiosflags(ios::left) <<  setw(7) << infoMenu(P).noMenu << "|";
            cout << " " << setiosflags(ios::left) << setw(18) << infoMenu(P).namaMenu << "|" << endl;
            P = nextMenu(P);
        }
        cout << "==============================" << endl;
    }
}

adrMenu find_menu(listMenu LM, int indexCari){
    adrMenu P = firstMenu(LM);
    while(P != NULL){
        if(infoMenu(P).noMenu == indexCari){
            return P;
        }
        P = nextMenu(P);
    }

    return NULL;
}

void addMenu_menu(listMenu &LM, int &nMenu){
    menu infoM; adrMenu P;
    nMenu++;
    cout << "========== ADD MENU ==========" << endl;
    cout << "Masukkan nama menu: "; cin.ignore(); getline(cin, infoM.namaMenu);
    infoM.noMenu = nMenu;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);
    cout << endl << "Menu telah masuk database" << endl;
}

void createList_pelanggan(listPelanggan &LP){
    firstPelanggan(LP) = NULL;
}

adrPelanggan newElement_pelanggan(pelanggan y){
    adrPelanggan P = new elmPelanggan;
    infoPelanggan(P) = y;
    nextPelanggan(P) = NULL;
    nextPesanan(P) = NULL;

    return P;
}

void insertLast_pelanggan(listPelanggan &LP, adrPelanggan P){
    adrPelanggan Q;
    if(firstPelanggan(LP) == NULL){
        firstPelanggan(LP) = P;
    }else{
        Q = firstPelanggan(LP);
        while(nextPelanggan(Q) != NULL){
            Q = nextPelanggan(Q);
        }
        nextPelanggan(Q) = P;
    }
}

void printInfopesanan_pelanggan(listPelanggan LP){
    if(firstPelanggan(LP) == NULL){
        cout << "Antrian pelanggan tidak tersedia..." << endl << endl; 
    }else{
        adrPelanggan P = firstPelanggan(LP);
        cout << "=============================================================" << endl;
        cout << "|   ANTRIAN   |     NAMA PELANGGAN     |   BANYAK PESANAN   |" << endl;
        cout << "=============================================================" << endl;
        while(P != NULL){
            cout << "| " << setiosflags(ios::left) << setw(12) << infoPelanggan(P).noAntrian << "|";
            cout << " " << setiosflags(ios::left) << setw(23) << infoPelanggan(P).namaPelanggan << "|";
            cout << " " << setiosflags(ios::left) << setw(19) << banyakPesanan(LP, P) << "|" << endl;
            P = nextPelanggan(P);
        }
        cout << "=============================================================" << endl << endl;
    }
}

adrPesanan newElement_pesanan(pesanan z){
    adrPesanan P = new elmPesanan;
    infoPesanan(P) = z;
    nextPesanan(P) = NULL;

    return P;
}

void insertLast_pesanan(adrPesanan X, adrPelanggan P, adrMenu Q){
    infoPesanan(X).namaPesanan = infoMenu(Q).namaMenu; 
    if(nextPesanan(P) == NULL){
        nextPesanan(P) = X;
    }else{
        adrPesanan A = nextPesanan(P);
        while(nextPesanan(A) != NULL){
            A = nextPesanan(A);
        }
        nextPesanan(A) = X;
    }
}

adrPelanggan find_pelanggan_adr(listPelanggan LP, pelanggan infoP){
    adrPelanggan P = firstPelanggan(LP);
    while(P != NULL){
        if(infoPelanggan(P).namaPelanggan == infoP.namaPelanggan || infoPelanggan(P).noAntrian == infoP.noAntrian){
            return P;
        }
        P = nextPelanggan(P);
    }

    return NULL;
}

bool find_pelanggan(listPelanggan LP, pelanggan infoP){
    adrPelanggan P = firstPelanggan(LP);
    while(P != NULL){
        if(infoPelanggan(P).namaPelanggan == infoP.namaPelanggan){
            return true;
        }
        P = nextPelanggan(P);
    }

    return false;
}

void insertPelanggan(listPelanggan &LP, listMenu LM, int &nPelanggan){
    pelanggan infoP; adrPelanggan Q;
    pesanan infopes; adrMenu Z; adrPesanan X, C;
    nPelanggan++;
    cout << "========== ADD ANTRIAN PELANGGAN ==========" << endl;
    cout << "Masukkan nama pelanggan: "; cin.ignore(); getline(cin, infoP.namaPelanggan);
    infoP.noAntrian = nPelanggan;

    if(find_pelanggan(LP, infoP)){
        nPelanggan--;
        cout << "Pelanggan dengan nama " << infoP.namaPelanggan << " telah terdaftar.." << endl << endl;
    }else{
        Q = newElement_pelanggan(infoP);
        insertLast_pelanggan(LP, Q);
        cout << endl << "Pelanggan dengan nama " << infoP.namaPelanggan << " masuk ke antrian, silahkan pilih pesanan..." << endl;

        pause;
        clear;

        printInfo_menu(LM);
        cout << "Nama pelanggan: " << infoP.namaPelanggan << endl;
        cout << "Masukkan menu pesanan (angka): "; cin >> infopes.indexPesanan;
        cout << "Masukkan banyak yang dipesan: "; cin >> infopes.countPesanan;
        Z = find_menu(LM, infopes.indexPesanan);
        if(Z != NULL){
            X = newElement_pesanan(infopes);
            insertLast_pesanan(X, Q, Z);
            while(Z != NULL){
                cout << endl;
                cout << "Masukkan menu pesanan (angka): "; cin >> infopes.indexPesanan;
                cout << "Masukkan banyak yang dipesan: "; cin >> infopes.countPesanan;
                X = newElement_pesanan(infopes);
                Z = find_menu(LM, infopes.indexPesanan);
                C = find_pesanan(LP, Q, X, infopes.indexPesanan);
                if(Z == NULL){
                    cout << endl << "Menu tidak tersedia..\nKembali ke menu utama..." << endl << endl;
                    break;
                }

                if(C != NULL){
                    infoPesanan(C).countPesanan += infopes.countPesanan;
                }else{
                    insertLast_pesanan(X, Q, Z);
                }
            }   
        }else{
            cout << endl << "Menu tidak tersedia..\nKembali ke menu utama..." << endl << endl;
        }
    }

}

void printInfo_pelanggan_pesanan(listPelanggan LP){
    adrPelanggan P; adrPesanan Q;
    if(firstPelanggan(LP) == NULL){
        cout << "Antrian pelanggan tidak tersedia..." << endl << endl; 
    }else{
        P = firstPelanggan(LP);
        while(P != NULL){ 
            cout << "========================================" << endl;
            cout << "|   ANTRIAN   |     NAMA PELANGGAN     |" << endl;
            cout << "========================================" << endl;
            cout << "| " << setiosflags(ios::left) << setw(12) << infoPelanggan(P).noAntrian << "|";
            cout << " " << setiosflags(ios::left) << setw(23) << infoPelanggan(P).namaPelanggan << "|" << endl;
            Q = nextPesanan(P);
            cout << "========================================" << endl;
            cout << "|    JUMLAH    |     NAMA  PESANAN     |" << endl;
            cout << "========================================" << endl;
            while(Q != NULL){
                cout << "| " << setiosflags(ios::left) << setw(13) << infoPesanan(Q).countPesanan << "|";
                cout << " " << setiosflags(ios::left) << setw(22) << infoPesanan(Q).namaPesanan << "|" << endl;
                Q = nextPesanan(Q);
            }
            cout << "========================================" << endl;
            cout << endl;
            P = nextPelanggan(P);
        }
    }
}

adrPesanan find_pesanan(listPelanggan LP, adrPelanggan Z, adrPesanan X, int indexCari){
    if(firstPelanggan(LP) == NULL){
        return NULL;
    }else{
        adrPelanggan P = firstPelanggan(LP);
        while(P != NULL && infoPelanggan(P).namaPelanggan != infoPelanggan(Z).namaPelanggan){
            P = nextPelanggan(P);
        }

        if(P == NULL || nextPesanan(P) == NULL){
            return NULL;
        }

        adrPesanan Q = nextPesanan(P);
        while(Q != NULL && infoPesanan(Q).indexPesanan != indexCari){
            Q = nextPesanan(Q);
        }

        return Q;
    }
}

int banyakPesanan(listPelanggan LP, adrPelanggan P){
    int sum = 0;
    if(firstPelanggan(LP) == NULL){
        cout << "Data antrian tidak ada.." << endl;
    }else{
        adrPelanggan Z = firstPelanggan(LP);
        while(Z != NULL && Z != P){
            Z = nextPelanggan(Z);
        }

        if(Z != NULL){
            adrPesanan X = nextPesanan(Z);
            while(X != NULL){
                sum++;
                X = nextPesanan(X);
            }
        }
    }

    return sum;
}

void deleteAntrian_pelanggan(listPelanggan &LP, int &nPelanggan){
    if(firstPelanggan(LP) == NULL){
        cout << "Antrian tidak tersedia.." << endl;
    }else if(nextPelanggan(firstPelanggan(LP)) == NULL){
        nPelanggan--;
        firstPelanggan(LP) = NULL;
    }else{
        adrPelanggan X = firstPelanggan(LP);
        adrPelanggan Z = nextPelanggan(firstPelanggan(LP));
        nPelanggan--;
        firstPelanggan(LP) = Z;
        nextPelanggan(X) = NULL;
        nextPesanan(X) = NULL;
        while(Z != NULL){
            infoPelanggan(Z).noAntrian--;
            Z = nextPelanggan(Z);
        }
    }

    cout << "Antrian pertama telah dihapus.." << endl << endl;
}

void deletePesanan_pelanggan(listPelanggan &LP){
    if(firstPelanggan(LP) == NULL){
        cout << "Antrian tidak tersedia.." << endl;
    }else{
        pelanggan infoP; pesanan infopes;
        printInfopesanan_pelanggan(LP);

        cout << "Masukkan NO antrian pesanan yang akan dihapus: "; cin >> infoP.noAntrian;
        adrPelanggan Z = find_pelanggan_adr(LP, infoP);

        if(Z != NULL){
            adrPesanan prec;
            adrPesanan X = nextPesanan(Z);
            adrPesanan last = nextPesanan(Z);
            if(X == NULL){
                cout << "Pelanggan dengan nama " << infoPelanggan(Z).namaPelanggan << " tidak tersedia" << endl;
            }else{
                cout << "===========================================" << endl;
                cout << "|    INDEX MENU    |     NAMA PESANAN     |" << endl;
                cout << "===========================================" << endl;

                while(nextPesanan(last) != NULL){
                    last = nextPesanan(last);
                }
            
                while(X != NULL){
                    cout << "| " << setiosflags(ios::left) << setw(17) << infoPesanan(X).indexPesanan << "|";
                    cout << " " << setiosflags(ios::left) << setw(21) << infoPesanan(X).namaPesanan << "|" << endl;
                    X = nextPesanan(X);
                }

                cout << "===========================================" << endl;

                cout << endl << "Masukkan menu makanan yang akan dihapus: "; cin >> infopes.indexPesanan;
                X = nextPesanan(Z);

                while(X != NULL && infoPesanan(X).indexPesanan != infopes.indexPesanan){
                    X = nextPesanan(X);
                }

                if(X == nextPesanan(Z)){
                    deleteFirst_pesanan(Z);
                }else if(X == last){
                    deleteLast_pesanan(Z);
                }else{
                    deleteAfter_pesanan(Z, X);
                }

            }
        }
        
    }   
}

void deleteFirst_pesanan(adrPelanggan &P){
    if(nextPesanan(nextPesanan(P)) == NULL){
        nextPesanan(P) = NULL;
    }else{
        adrPesanan Z = nextPesanan(P);
        nextPesanan(P) = nextPesanan(Z);
        nextPesanan(Z) = NULL;
    }
}

void deleteLast_pesanan(adrPelanggan &P){
    adrPesanan Z = nextPesanan(P);
    while(nextPesanan(nextPesanan(Z)) != NULL){
        Z = nextPesanan(Z);
    }
    nextPesanan(Z) = NULL;
}

void deleteAfter_pesanan(adrPelanggan &P, adrPesanan Q){
    adrPesanan Z = nextPesanan(P);
    adrPesanan prec;
    while(nextPesanan(Z) != Q){
        Z = nextPesanan(Z);
    }
    prec = Z;

    nextPesanan(prec) = nextPesanan(Q);
    nextPesanan(Q) = NULL;
}

void defaultMenu(listMenu &LM){
    menu infoM; adrMenu P;
    infoM.namaMenu = "Spicy Chicken";
    infoM.noMenu = 1;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Crispy Chicken";
    infoM.noMenu = 2;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "French Fries";
    infoM.noMenu = 3;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Cheese Burger";
    infoM.noMenu = 4;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Beef Burger";
    infoM.noMenu = 5;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Iced Coffee";
    infoM.noMenu = 6;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Mineral Water";
    infoM.noMenu = 7;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Cola";
    infoM.noMenu = 8;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Iced Chocolate";
    infoM.noMenu = 9;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);

    infoM.namaMenu = "Milo";
    infoM.noMenu = 10;
    P = newElement_menu(infoM);
    insertLast_menu(LM, P);
}

int selectHome_all(){
    system("cls");
    cout << "=========================================" << endl;
    cout << "     Resto Gatau bingung kasih nama      " << endl;
    cout << "      Jln. ini aja yang ada yaa...       " << endl;
    cout << "=========================================" << endl;
    cout << "1. Tampilkan menu yang tersedia" << endl;
    cout << "2. Tambahkan menu baru" << endl;
    cout << "3. Tambahkan antrian pelanggan baru" << endl;
    cout << "4. Tampilkan data pelanggan dan menu yang dipesan" << endl;
    cout << "5. Tampilkan banyak pesanan semua pelanggan" << endl;
    cout << "6. Hapus antrian pelanggan tertentu" << endl;
    cout << "7. Hapus pesanan dari pelanggan tertentu" << endl;
    cout << "0. Exit program" << endl;
    
    int input; cout << "Masukkan pilihan: "; cin >> input;
    
    return input;
}