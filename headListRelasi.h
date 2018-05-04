#ifndef HEADLISTRELASI_H_INCLUDED
#define HEADLISTRELASI_H_INCLUDED

#include "mainHead.h"
#include "headListBuku.h"
#include "headListMhs.h"

struct Tanggal
{
    int tanggal, bulan, tahun;
};
typedef struct elemenRelasi* addressRelasi;
struct elemenRelasi
{
    addressRelasi next, prev;
    addressMhs mhs;
    addressBuku buku;
    Tanggal pinjam, kembali;
};

struct ListRelasi
{
    addressRelasi first, last;
};

void createListRelasi(ListRelasi &L);
addressRelasi alokasiRelasi(addressMhs mhs, addressBuku buku, Tanggal pinjam, Tanggal kembali);
void insertFirstRelasi(ListRelasi &L, addressRelasi relasi);
void insertAfterRelasi(ListRelasi &L,addressRelasi prec, addressRelasi relasi);
void insertLastRelasi(ListRelasi &L, addressRelasi relasi);
void deleteFirstRelasi(ListRelasi &L, addressRelasi &relasi);
void deleteAfterRelasi(ListRelasi &L,addressRelasi prec, addressRelasi &relasi);
void deleteLastRelasi(ListRelasi &L, addressRelasi &relasi);

Tanggal getCurrentDate();
Tanggal getCurrentDate(int x);
void pinjamBuku(ListBuku LB, ListMhs LM, ListRelasi &LR);
void resumePeminjaman(ListRelasi L);
void returnBuku(ListRelasi &L);
#endif // HEADLISTRELASI_H_INCLUDED
