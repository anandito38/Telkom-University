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

void insertAfter(List &L, address prec, address cur){
    if(!isEmpty(L)){
        next(cur) = next(prec);
        next(prec) = cur;
    }
}

void insertLast(List &L, address cur){
    if(isEmpty(L)){
        first(L) = cur;
    }else{
        address pos = first(L);
        while (next(pos) != nil){
            pos = next(pos);
        }
        next(pos) = cur;
    }
}

void deleteFirst(List &L, address &cur){
    if(isEmpty(L)){
        cur = nil;
    }else if(next(first(L)) == nil){
        cur = first(L);
        first(L) = nil;
    }else{
        cur = first(L);
        first(L) = next(cur);
        next(cur) = nil;
    }
}

void deleteAfter(List &L, address prec, address &cur){
    if(!isEmpty(L)){
        cur = next(prec);
        next(prec) = next(cur);
        next(cur) = nil;
    }
}

void deleteLast(List &L, address &cur){
    if(isEmpty(L)){
        cur = nil;
    }else if(next(first(L)) == nil){
        cur = first(L);
        first(L) = nil;
    }else{
        address pos = first(L);
        while(next(next(pos)) != nil){
            pos = next(pos);
        }
        cur = next(pos);
        next(pos) = nil;
    }
}

void showList(List L){
    if(isEmpty(L)){
        cout << "Empty List!" << endl;
    }else{
        address pos = first(L);
        while(pos != nil){
            cout << info(pos) << " ";
            pos = next(pos);
        }
        cout << endl;
    }
}
