#include "SLL.h"

void createList(List &L){
    first(L) = nil;
}

address newElement(infotype dataBaru){
    address newCur = new element;
    info(newCur) = dataBaru;
    next(newCur) = nil;

    return newCur;
}

bool isEmpty(List L){
    if(first(L) == nil){
        return true;
    }

    return false;
}

void insertFirst(List &L, address cur){
    if(isEmpty(L)){
        first(L) = cur;
    }else{
        next(cur) = first(L);
        first(L) = cur;
    }
}

void insertLast(List &L, address cur);

void deleteFirst(List &L, address &cur);

void deleteLast(List &L, address &cur);

void showList(List L);