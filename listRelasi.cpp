#include "headListRelasi.h"

void createListRelasi(ListRelasi &L)
{
    first(L) = NULL;
    last(L) = NULL;
}
addressRelasi alokasiRelasi(addressMhs mhs, addressBuku buku, Tanggal pinjam, Tanggal kembali)
{
    //1301164283
    addressRelasi P = new elemenRelasi;
    mahasiswa(P) = mhs;
    buku(P) = buku;
    pinjam(P) = pinjam;
    kembali(P) = kembali;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirstRelasi(ListRelasi &L, addressRelasi relasi)
{
    //1301164283
    if (first(L) == NULL)
    {
        first(L) = relasi;
        next(relasi) = relasi;
        prev(relasi) = relasi;
        last(L) = relasi;
    }
    else
    {
        next(relasi) = first(L);
        next(last(L)) = relasi;
        prev(first(L)) = relasi;
        first(L) = relasi;
    }
}
void insertAfterRelasi(ListRelasi &L,addressRelasi prec, addressRelasi relasi)
{
    //1301164283
    if (prec == NULL) return;
    if(prec == last(L))
    {
        insertFirstRelasi(L, relasi);
    }
    else
    {
        next(relasi) = next(prec);
        prev(next(prec)) = relasi;
        next(prec) = relasi;
        prev(relasi) = prec;
    }
}
void insertLastRelasi(ListRelasi &L, addressRelasi relasi)
{
    //1301164283
    if(first(L) == NULL)
    {
        insertFirstRelasi(L, relasi);
    }
    else
    {
        next(relasi) = first(L);
        prev(first(L)) = relasi;
        next(last(L)) = relasi;
        prev(relasi) = last(L);
        last(L) = relasi;
    }
}
void deleteFirstRelasi(ListRelasi &L, addressRelasi &relasi)
{
    //1301164283
    if (first(L)==NULL) return;
    if(next(first(L) == first(L)))
    {
        relasi = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        relasi = first(L);
        first(L) = next(relasi);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }
}
void deleteAfterRelasi(ListRelasi &L,addressRelasi prec, addressRelasi &relasi)
{
    //1301164283
    if (prec == last(L))
    {
        deleteFirstRelasi(L, relasi);
    }
    else if(next(prec) == last(L))
    {
        deleteLastRelasi(L, relasi);
    }
    else
    {
        relasi = next(prec);
        next(prec) = next(relasi);
        prev(next(relasi)) = prec;
    }
}
void deleteLastRelasi(ListRelasi &L, addressRelasi &relasi)
{
    //1301164283
    if ((first(L) == NULL) || (first(L) == relasi))
    {
        deleteFirstRelasi(L, relasi);
    }
    else
    {
        relasi = last(L);
        next(prev(relasi)) = first(L);
        prev(first(L)) = prev(relasi);
        last(L) = prev(relasi);
        next(relasi) = NULL;
        prev(relasi) = NULL;
    }
}

Tanggal getCurrentDate()
{
    //1301164283
    time_t ti = time(0);
    struct tm * now = localtime( & ti );
    Tanggal t;
    t.tanggal = now->tm_mday;
    t.bulan = now->tm_mon + 1;
    t.tahun = now->tm_year + 1900;
    return t;
}

Tanggal getCurrentDate(int x)
{
    //1301164114
    time_t ti = time(0);
    struct tm * now = localtime( & ti );
    Tanggal t;
    t.tanggal = now->tm_mday + x;
    t.bulan = now->tm_mon + 1;
    t.tahun = now->tm_year + 1900;
    if(t.tanggal > 30)
    {
        t.tanggal = 1;
        t.bulan++;
    }
    if(t.bulan>12)
    {
        t.bulan = 1;
        t.tahun++;
    }
    return t;
}
void cetakTanggal(Tanggal t)
{
    //1301164283
    cout << setw(2) << setfill('0') << t.tanggal;
    cout << " - ";
    cout << setw(2) << setfill('0') << t.bulan << " - " << t.tahun;
}

string tanggalToString(Tanggal t)
{
    //1301164283
    string tgl;
    if(t.tanggal < 10) tgl.append("0");
    tgl.append(SSTR(t.tanggal));
    tgl.append(" - ");
    if(t.bulan < 10) tgl.append("0");
    tgl.append(SSTR(t.bulan));
    tgl.append(" - ");
    tgl.append(SSTR(t.tahun));
    return tgl;
}
bool lessThan(Tanggal t1, Tanggal t2)
{
    //1301164283
    if(t1.tahun < t2.tahun) return true;
    if(t1.tahun > t2.tahun) return false;
    if(t1.bulan < t2.bulan) return true;
    if(t1.bulan < t2.bulan) return false;
    if(t1.tanggal <= t2.tanggal) return true;
    else return false;
}
bool isBorrow(ListRelasi L, string NIM)
{
    //1301164283
    addressRelasi P = first(L);
    if(P == NULL) return false;
    while(next(P) != first(L) && info(mahasiswa(P)).nim != NIM)
    {
        P = next(P);
    }

    return (info(mahasiswa(P)).nim == NIM);
}

void pinjamBuku(ListBuku LB, ListMhs LM, ListRelasi &LR)
{
    //1301164114
    while(true)
    {
        string nim;
        cout << "Masukkan NIM \t: ";
        cin >> nim;
        addressMhs mhs = findMahasiswa(LM, nim);

        if (mhs == NULL)
        {
            cout << "NIM belum terdatar!!\n";
            _getch();
            return;
        }
        else
        {
            clean();
            if (isBorrow(LR, info(mhs).nim))
            {
                cout << "Mahasiswa ini sudah meminjam buku!!\n";
                _getch();
                return;
            }
            char pil;
            cout << "Nama : " << info(mhs).nama << endl;
            cout << "====PINJAM BUKU====\n";
            cout << "1. LIHAT SEMUA BUKU\n";
            cout << "2. CARI BUKU\n";
            cout << "3. KEMBALI\n";
            cout << "Masukkan pilihan : ";
            cin >> pil;
            clean();
            cout << "Nama : " << info(mhs).nama << endl;
            if (pil == '1')
            {
                showBuku(LB, 1);
                cout << "Pilih nomor buku : ";
                int num;
                cin >> num;
                addressBuku B = findBukuByNum(LB, num);
                if (B == NULL)
                {
                    cout << "Nomor salah!\n";
                }
                else
                {
                    if(info(B).stok<=0)
                    {
                        cout << "Stok habis\n";
                    }
                    else
                    {
                        info(B).terpinjam++;
                        info(B).stok--;
                        addressRelasi R = alokasiRelasi(mhs, B, getCurrentDate(), getCurrentDate(7));
                        insertLastRelasi(LR, R);
                        cout << "Berhasil menambahkan\n";
                    }
                }
            }
            else if (pil == '2')
            {
                string keyword;
                cariBuku(LB, 1, keyword);
                cout << "Pilih nomor buku : ";
                int num;
                cin >> num;
                addressBuku P = first(LB);
                int i = 1;
                while(P != NULL)
                {
                    if (contains(info(P).judul, keyword) || contains(info(P).penulis, keyword) || contains(info(P).kategori, keyword))
                    {
                        if(i == num) break;
                        i++;
                    }
                    P = next(P);
                }
                if (P == NULL)
                {
                    cout << "Nomor salah\n";
                }
                else
                {
                    if(info(P).stok<=0)
                    {
                        cout << "Stok habis\n";
                    }
                    else
                    {
                        info(P).terpinjam++;
                        info(P).stok--;
                        addressRelasi R = alokasiRelasi(mhs, P, getCurrentDate(), getCurrentDate(7));
                        insertLastRelasi(LR, R);
                        cout << "Berhasil menambahkan\n";
                    }
                }
            }
            else
            {
                return;
            }
            _getch();
        }
    }
}

void returnBuku(ListRelasi &L)
{
    //1301164283
    cout << "Masukkan NIM \t: ";
    string nim;
    cin >> nim;
    addressRelasi P = first(L);
    if(P == NULL)
    {
        cout << "NIM tidak ditemukan\n";
        _getch();
        return;
    }
    while(next(P) != first(L) && info(mahasiswa(P)).nim != nim)
    {
        P = next(P);
    }
    clean();
    if (info(mahasiswa(P)).nim == nim)
    {
        cout << "Buku \t: " << info(buku(P)).judul << endl;
        cout << "Tanggal pinjam\t: "; cetakTanggal(pinjam(P)); cout << endl;
        cout << "Tanggal kembali\t: "; cetakTanggal(kembali(P)); cout << endl;
        cout << "Tanggal hari ini\t: "; cetakTanggal(getCurrentDate()); cout << endl;
        int denda = 0;
        if(!lessThan(getCurrentDate(), kembali(P)))
        {
            denda = 10000;
        }
        cout << "Denda\t: Rp." << denda << endl;
        addressRelasi R;
        info(buku(P)).stok++;
        deleteAfterRelasi(L, prev(P), R);
        delete R;

    }
    else
    {
        cout << "NIM tidak ditemukan\n";
    }
    _getch();
}

void mostBorrowed(ListRelasi L)
{
    //1301164283
    addressRelasi P = first(L);
    if(first(L) == NULL)
    {
        cout << "Belum ada yang meminjam\n";
    }
    else
    {
        do{
            addressRelasi Q = P;
            int max = info(buku(P)).terpinjam;
            do{
                if(info(buku(Q)).terpinjam > max)
                    max = info(buku(Q)).terpinjam;
                addressBuku tempB = buku(P);
                buku(P) = buku(Q);
                buku(Q) = tempB;
                addressMhs tempM = mahasiswa(P);
                mahasiswa(P) = mahasiswa(Q);
                mahasiswa(Q) = tempM;
                Tanggal tempP = pinjam(P);
                pinjam(P) = pinjam(Q);
                pinjam(Q) = tempP;
                Tanggal tempK = kembali(P);
                kembali(P) = kembali(Q);
                kembali(Q) = tempK;
                Q = next(Q);
            } while(next(Q) != first(L));
            P = next(P);
        } while(next(P) != first(L));
        P = first(L);
        int i = 1;
        cout << "+--+------------------------+---------+\n";
        cout << "|NO|          BUKU          |TERPINJAM|\n";
        cout << "+--+------------------------+---------+\n";
        do{
            cout << "|" << setw(2) << setfill('0') << i << "|" << info(buku(P)).judul;
            gotoxy(28, i+2);
            cout << "|" << setw(9) << setfill('0') << info(buku(P)).terpinjam << "|\n";
            P = next(P);
        }while (next(P) != first(L));
        cout << "+--+------------------------+---------+\n";
    }
    _getch();
}

void TampilkanDataRelasi(ListRelasi L, int offset)
{
    //1301164283
    addressRelasi P = first(L);
    int i = 1;
    cout << "+--+------------------------+------------------+--------------+---------------+\n";
    cout << "|NO|          NAMA          |       BUKU       |TANGGAL PINJAM|TANGGAL KEMBALI|\n";
    cout << "+--+------------------------+------------------+--------------+---------------+\n";
    do {
        cout << "|";
        cout << setw(2) << setfill('0') << i << "|" << info(mahasiswa(P)).nama;
        gotoxy(28, i+2+offset);
        cout << "|" << info(buku(P)).judul;
        gotoxy(47, i+2+offset);
        cout << "|"; cetakTanggal(pinjam(P)); cout << "|"; cetakTanggal(kembali(P)); cout << " |\n";
        i++;
        P = next(P);
    }while(P!= first(L));
    cout << "+--+------------------------+------------------+--------------+---------------+\n";
}


void resumePeminjaman(ListRelasi L)
{
    //1301164283
    addressRelasi P = first(L);
    if(P == NULL)
    {
        cout << "Belum ada yang meminjam\n";
    }
    else
    {
        while(true)
        {
            cout << "====INFO PEMINJAM BUKU====\n";
            cout << "1. TAMPILKAN SEMUA BUKU\n";
            cout << "2. CARI BUKU\n";
            cout << "3. KEMBALI\n";
            char pil;
            cout << "Masukkan pilihan : ";
            cin >> pil;
            clean();
            if(pil == '1')
            {
                TampilkanDataRelasi(L, 0);

            }
            else if (pil == '2')
            {
                cout << "Masukkan kata kunci : ";
                char keyword[100];
                cin.ignore();
                cin.getline(keyword, sizeof(keyword));
                string key = keyword;
                ListRelasi R;
                createListRelasi(R);
                do {
                    if(contains(info(buku(P)).judul, keyword) || contains(info(mahasiswa(P)).nama, keyword) ||
                       contains(info(mahasiswa(P)).nim, keyword) || contains(tanggalToString(pinjam(P)), keyword) ||
                       contains(tanggalToString(kembali(P)), keyword))
                       {
                            insertLastRelasi(R, alokasiRelasi(mahasiswa(P), buku(P), pinjam(P), kembali(P)));
                       }
                       P = next(P);
                } while(P != first(L));
                TampilkanDataRelasi(R, 1);
            }
            else
            {
                return;
            }
            _getch();
        }
    }
}

