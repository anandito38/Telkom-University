#include <bits/stdc++.h>
using namespace std;

#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

typedef int infotype;
typedef struct element *address;

struct element{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address newElement(infotype dataBaru);
bool isEmpty(List L);
void insertFirst(List &L, address cur);
void insertAfter(List &L, address prec, address cur);
void insertLast(List &L, address cur);
void deleteFirst(List &L, address &cur);
void deleteAfter(List &L, address prec, address &cur);
void deleteLast(List &L, address &cur);
void showList(List L);