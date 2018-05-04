#ifndef MAINHEAD_H_INCLUDED
#define MAINHEAD_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <sstream>



using namespace std;

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last
#define mahasiswa(P) P->mhs
#define buku(P) P->buku
#define pinjam(P) P->pinjam
#define kembali(P) P->kembali

void gotoxy(int x,int y);
bool contains(string domain, string keyword);
void clean();

#endif // MAINHEAD_H_INCLUDED
