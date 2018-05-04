#include "headListMhs.h"
void createListMhs(ListMhs &L)
{
    first(L) = NULL;
}
addressMhs alokasiMhs(Mahasiswa mhs)
{
    addressMhs m = new elemenMhs;
    info(m) = mhs;
    next(m) = NULL;
    return m;
}
void insertFirstMhs(ListMhs &L, addressMhs mhs)
{
    //1301164283
    if (first(L)==NULL) {
        first(L)=mhs;

    }else{
        next(mhs)=first(L);
        first(L)=mhs;
        }
    //-----------------------
}
void insertAfterMhs(ListMhs &L,addressMhs prec, addressMhs mhs)
{
    //1301164283
    //-----your code here----
    next(mhs)=next(prec);
    next(prec)=mhs;
    //-----------------------
}
void insertLastMhs(ListMhs &L, addressMhs mhs)
{
    //1301164283
    //-----your code here----
    if (first(L)=NULL){
        first(L)=mhs;

    }else{
        addressMhs Q=first(L);
        while (next(Q)!=NULL){
            Q=next(Q);

        }
        next(Q)=mhs;
        }
    //-----------------------
}
void deleteFirstMhs(ListMhs &L, addressMhs &mhs)
{
    //1301164283
    //-----your code here----
    if (next(first(L))==NULL){
        mhs=first(L);
        first(L)=NULL;

    }else{
        mhs=first(L);
        first(L)=next(mhs);
        next(mhs)=NULL;
    }
    //-----------------------
}
void deleteAfterMhs(ListMhs &L,addressMhs prec, addressMhs &mhs)
{
    //1301164283
    //-----your code here----
    mhs=next(prec);
    next(prec)=next(mhs);
    next(mhs)=NULL;
    //-----------------------
}
void deleteLastMhs(ListMhs &L, addressMhs &mhs)
{
    //1301164283
    //-----your code here----
    if (next(first(L))==NULL){
        mhs=first(L);
        first(L)=NULL;

    }else{
        addressMhs Q=first(L);
        while (next(next(Q))==NULL){
            Q=next(Q);

        }
        mhs=next(Q);
        next(Q)=NULL;
    }
    //-----------------------
}

addressMhs findMahasiswa(ListMhs L, string NIM)
{
    //1301164283
    addressMhs adrMhs = first(L);
    while(adrMhs != NULL && info(adrMhs).nim != NIM)
    {
        adrMhs = next(adrMhs);
    }
    return adrMhs;
}

void inputMahasiswa(ListMhs &L)
{
    //1301164283
    char choice = 'Y';
    do
    {
        Mahasiswa mhs;
        cout << "====INPUT MAHASISWA====\n";
        cout << "Masukkan Nama : ";
        char nama[100];
        cin.ignore();
        cin.getline(nama, sizeof(nama));
        mhs.nama = nama;
        cout << "Masukkan NIM : ";
        cin >> mhs.nim;
        cout << "Masukkan Jurusan : ";
        cin.ignore();
        cin.getline(nama, sizeof(nama));
        mhs.prodi = nama;
        addressMhs adrMhs = findMahasiswa(L, mhs.nim);
        if (adrMhs == NULL)
        {
            insertFirstMhs(L, alokasiMhs(mhs));
            cout << "Berhasil menambahkan data mahasiswa baru\n";
        }
        else
        {
            cout << "Mahasiswa dengan NIM : " << mhs.nim << " sudah Terdaftar\n";
        }
        cout << "Apakah anda ingin mendaftarkan mahasiswa baru lagi ? (Y/N) : ";
        cin >> choice;
    } while((choice == 'Y') || (choice == 'y'));
}

void showMahasiswa(ListMhs L)
{
    //1301164283
    if (first(L) == NULL)
    {
        cout << "Tidak ada mahasiswa\n";
    }
    else
    {
        addressMhs P = first(L);
        int i = 1;
        cout << "+--+------------------------+-------------+-----------+\n";
        cout << "|NO|          NAMA          |     NIM     |   PRODI   |\n";
        cout << "+--+------------------------+-------------+-----------+\n";
        while(P != NULL)
        {
            cout << "|";
            if (i<10) cout << 0;
            cout << i << "|" << info(P).nama;
            gotoxy(28, i+2);
            cout << "|" << info(P).nim;
            gotoxy(42, i+2);
            cout << "|" << info(P).prodi;
            gotoxy(54, i+2);
            cout << "|\n";
            P = next(P);
            i++;
        }
        cout << "+--+------------------------+-------------+-----------+\n";
    }
    _getch();
}
