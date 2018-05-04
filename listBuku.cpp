#include "headListBuku.h"
void createListBuku(ListBuku &L)
{
    first(L) = NULL;
}
addressBuku alokasiBuku(Buku buku)
{
    addressBuku b = new elemenBuku;
    info(b) = buku;
    next(b) = NULL;
    prev(b) = NULL;
    return b;
}
void insertFirstBuku(ListBuku &L, addressBuku buku)
{
    //1301164114
    if (first(L)==NULL){
        first(L)=buku;

    }else{
        next(buku)=first(L);
        prev(first(L))=buku;
        first(L)=buku;
    }
    //-----------------------
}
void insertAfterBuku(ListBuku &L,addressBuku prec, addressBuku buku)
{
    //1301164114
    if (first(L) != NULL)
    {
        if (next(prec) == NULL)
        {
            insertLastBuku(L, buku);
        }
        else
        {
            next(buku)=next(prec);
            next(prec)=buku;
            prev(buku)=prec;
            prev(next(buku))=buku;
        }
        cout << "success";
    }
    else
    {
        cout << "List kosong";
    }
    //-----------------------
}
void insertLastBuku(ListBuku &L, addressBuku buku)
{
    //1301164114
    if (first(L)==NULL){
        first(L)=buku;

    }else{
        addressBuku Q=first(L);
        while (next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=buku;
        prev(buku)=Q;

        }
    //-----------------------
}
void deleteFirstBuku(ListBuku &L, addressBuku &buku)
{
    //1301164114
    buku=first(L);
    first(L)=next(buku);
    next(buku)=NULL;
    prev(first(L))=NULL;
    //-----------------------
}
void deleteAfterBuku(ListBuku &L,addressBuku prec, addressBuku &buku)
{
    //130116414
    buku=next(prec);
    next(prec)=next(buku);
    prev(next(buku))=prec;
    next(buku)=NULL;
    prev(buku)=NULL;
    //-----------------------
}
void deleteLastBuku(ListBuku &L, addressBuku &buku)
{
    //1301164114
    if (next(first(L)) == NULL)
    {
        buku = first(L);
        first(L) = NULL;
    }
    else
    {
        addressBuku Q = first(L);
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        buku = next(Q);
        next(Q) = NULL;
        prev(buku) = NULL;
    }
    //-----------------------
}

addressBuku findBukuByJudul(ListBuku L, string Judul)
{
    //1301164114
    addressBuku P = first(L);
    while(P != NULL && info(P).judul != Judul)
    {
        P = next(P);
    }
    return P;
}

addressBuku findBukuByCategory(ListBuku L, string Category)
{
    //1301164114
    addressBuku P = first(L);
    while(P != NULL && info(P).kategori != Category)
    {
        P = next(P);
    }
    return P;
}

addressBuku findBukuByNum(ListBuku L, int num)
{
    //1301164114
    addressBuku P = first(L);
    int i = 1;
    while(P != NULL && i < num)
    {
        P = next(P);
        i++;
    }
    if (i == num)
    {
        return P;
    }
    return NULL;
}

void insertByCategory(ListBuku &L, addressBuku P)
{
    //1301164114
    if (first(L) == NULL)
    {
        insertFirstBuku(L, P);
    }
    else
    {
        addressBuku Q = findBukuByCategory(L, info(P).kategori);
        if (Q != NULL)
        {
            insertAfterBuku(L, Q, P);
        }
        else
        {
            insertLastBuku(L, P);
        }
    }
}

void insertBefore(ListBuku &L, addressBuku nec, addressBuku P)
{
    //1301164114
    if(first(L) == nec)
    {
        insertFirstBuku(L, P);
    }
    else
    {
        insertAfterBuku(L, prev(nec), P);
    }
}

void inputBuku(ListBuku &L)
{
    //1301164114
    char pil = 'N';
    do
    {
        Buku b;
        cout << "====INPUT BUKU====\n";
        cout << "Masukkan Judul buku : ";
        char judul[100];
        cin.ignore();
        cin.getline(judul, sizeof(judul));
        b.judul = judul;
        cout << "Masukkan stok buku : ";
        cin >> b.stok;
        cout << "Masukkan penulis buku : ";
        cin.ignore();
        cin.getline(judul, sizeof(judul));
        b.penulis = judul;
        cout << "Masukkan kategori buku : ";
        cin >> b.kategori;
        b.terpinjam = 0;
        addressBuku P = findBukuByJudul(L, b.judul);
        if (P == NULL)
        {
            insertByCategory(L, alokasiBuku(b));
            cout << "Berhasil menambahkan buku\n";
        }
        else
        {
            cout << "Buku dengan judul : " << b.judul << " sudah terdaftar\n";
        }
        cout << "Mau menambahkan buku lagi ? (Y/N) : ";
        cin >> pil;
    } while((pil == 'Y') || (pil == 'y'));
}

void printInfo(addressBuku P, int offset, int num)
{
    //1301164114
    cout << "|";
    if (offset<10) cout << "0";
    cout << num << "|";
    cout << info(P).kategori;
    gotoxy(18, offset+2);
    cout << "|" << info(P).penulis;
    gotoxy(30, offset+2);
    cout << "|" << info(P).judul;
    gotoxy(74, offset+2);
    cout << "|" << setw(4) << setfill('0') << info(P).stok << "|\n";
}

void showBuku(ListBuku L, int offset)
{
    //1301164114
    if (first(L) == NULL)
    {
        cout << "Belum ada buku yang terdaftar\n";
    }
    else
    {
        addressBuku P = first(L);
        int i = 1;
        cout << "+--+--------------+-----------+-------------------------------------------+----+\n";
        cout << "|NO|   KATEGORI   |  PENULIS  |                   JUDUL                   |STOK|\n";
        cout << "+--+--------------+-----------+-------------------------------------------+----+\n";
        while(P != NULL)
        {
            printInfo(P, i+offset, i);
            P = next(P);
            i++;
        }
        cout << "+--+--------------+-----------+-------------------------------------------+----+\n";
    }
}

void cariBuku(ListBuku L, int offset, string &key)
{
    //1301164114
    cout << "====CARI BUKU====\n";
    cout << "Masukkan kata kunci : ";
    char keyword[100];
    cin.ignore();
    cin.getline(keyword, sizeof(keyword));
    addressBuku P = first(L);
    int i = 1;
    cout << "+--+--------------+-----------+-------------------------------------------+----+\n";
    cout << "|NO|   KATEGORI   |  PENULIS  |                   JUDUL                   |STOK|\n";
    cout << "+--+--------------+-----------+-------------------------------------------+----+\n";
    while(P != NULL)
    {
        if (contains(info(P).judul, keyword) || contains(info(P).penulis, keyword) || contains(info(P).kategori, keyword))
        {
            printInfo(P, i+offset+2, i);
            i++;
        }
        P = next(P);
    }
    cout << "+--+--------------+-----------+-------------------------------------------+----+\n";
    key = keyword;
}

void mostBorrowed(ListBuku L)
{
    //1301164114
    if(first(L) == NULL)
    {
        cout << "Belum ada buku\n";
    }
    else
    {
        addressBuku P = first(L);
        ListBuku B;
        createListBuku(B);
        while(P != NULL)
        {
            if(first(B) == NULL)
            {
                insertFirstBuku(B, alokasiBuku(info(P)));
            }
            else
            {
                addressBuku Q = first(B);
                while(Q != NULL && info(P).terpinjam < info(Q).terpinjam)
                {
                    Q = next(Q);
                }
                if(Q == NULL)
                {
                    insertLastBuku(B, alokasiBuku(info(P)));
                }
                else
                {
                    insertBefore(B, Q, alokasiBuku(info(P)));
                }
            }
            P = next(P);
        }

        P = first(B);
        if(P == NULL)
        {
            cout << "Tidak ada buku\n";
        }
        else
        {
            cout << "+--+--------------------+------+\n";
            cout << "|NO|     JUDUL BUKU     |JUMLAH|\n";
            cout << "+--+--------------------+------+\n";
            int i = 1;
            while(P != NULL)
            {
                cout << "|";
                if(i<10) cout << 0;
                cout << i << "|" << info(P).judul;
                gotoxy(24, 2+i);
                cout << "|" << setw(6) << setfill('0') << info(P).terpinjam << "|\n";
                i++;
                P = next(P);
            }
            cout << "+--+--------------------+------+\n";
        }
    }
    _getch();
}
