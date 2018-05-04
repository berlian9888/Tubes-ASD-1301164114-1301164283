#ifndef HEADLISTBUKU_H_INCLUDED
#define HEADLISTBUKU_H_INCLUDED

#include "mainHead.h"

struct Buku
{
    string judul;
    int stok;
    string penulis;
    string kategori;
    int terpinjam;
};

typedef struct elemenBuku* addressBuku;
struct elemenBuku
{
    addressBuku next, prev;
    Buku info;
};

struct ListBuku
{
    addressBuku first;
};

void createListBuku(ListBuku &L);
addressBuku alokasiBuku(Buku buku);
void insertFirstBuku(ListBuku &L, addressBuku buku);
void insertAfterBuku(ListBuku &L,addressBuku prec, addressBuku buku);
void insertLastBuku(ListBuku &L, addressBuku buku);
void deleteFirstBuku(ListBuku &L, addressBuku &buku);
void deleteAfterBuku(ListBuku &L,addressBuku prec, addressBuku &buku);
void deleteLastBuku(ListBuku &L, addressBuku &buku);

void inputBuku(ListBuku &L);
void showBuku(ListBuku L, int offset);
void cariBuku(ListBuku L, int offset, string &key);
addressBuku findBukuByNum(ListBuku L, int num);
void mostBorrowed(ListBuku L);
#endif // HEADLISTBUKU_H_INCLUDED
