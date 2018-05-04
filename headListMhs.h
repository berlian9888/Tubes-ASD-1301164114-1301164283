#ifndef HEADLISTMHS_H_INCLUDED
#define HEADLISTMHS_H_INCLUDED

#include "mainHead.h"

struct Mahasiswa
{
    string nama;
    char nim[10];
    string prodi;
};

typedef struct elemenMhs* addressMhs;
struct elemenMhs
{
    addressMhs next;
    Mahasiswa info;
};

struct ListMhs
{
    addressMhs first;
};

void createListMhs(ListMhs &L);
addressMhs alokasiMhs(Mahasiswa mhs);
void insertFirstMhs(ListMhs &L, addressMhs mhs);
void insertAfterMhs(ListMhs &L,addressMhs prec, addressMhs mhs);
void insertLastMhs(ListMhs &L, addressMhs mhs);
void deleteFirstMhs(ListMhs &L, addressMhs &mhs);
void deleteAfterMhs(ListMhs &L,addressMhs prec, addressMhs &mhs);
void deleteLastMhs(ListMhs &L, addressMhs &mhs);
addressMhs findMahasiswa(ListMhs L, string NIM);

void inputMahasiswa(ListMhs &L);
void showMahasiswa(ListMhs L);
#endif // HEADLISTMHS_H_INCLUDED
