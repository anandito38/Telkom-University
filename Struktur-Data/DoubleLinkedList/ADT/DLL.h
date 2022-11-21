#include <bits/stdc++.h>
using namespace std;

#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef int infotype;
typedef struct element *address;

struct element{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

void createList(List &L);
bool isEmpty(List L);
void insertFirst(List &L, address cur);
void insertAfter(List &L, address prec, address cur);
void insertLast(List &L, address cur);
void deleteFirst(List &L, address &cur);
void deleteAfter(List &L, address prec, address &cur);
void deleteLast(List &L, address &cur);
void showInfo(List L);