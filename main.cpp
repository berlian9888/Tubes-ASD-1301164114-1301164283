#include "headListBuku.h"
#include "headListMhs.h"
#include "headListRelasi.h"


ListMhs LMhs;
ListBuku LBuku;
ListRelasi LRelasi;

void menuRegistrasi();
void menuMahasiswa();
void menuBuku();


int main()
{
    char pil;
    while (true)
    {
        system("cls");
        cout << "====MENU UTAMA====\n";
        cout << "1. REGISTRASI\n";
        cout << "2. MAHASISWA\n";
        cout << "3. BUKU\n";
        cout << "4. KELUAR\n";
        cout << "==================\n";
        cout << "Masukkan pilihan : ";
        cin >> pil;
        if (pil == '1')
        {
            menuRegistrasi();
        }
        else if (pil == '2')
        {
            menuMahasiswa();
        }
        else if(pil == '3')
        {
            menuBuku();
        }
        else
        {
            return 0;
        }

    }
    return 0;
}

void menuRegistrasi()
{
    char pil;
    while(true)
    {
        system("cls");
        cout << "====MENU REGISTRASI====\n";
        cout << "1. PINJAM BUKU\n";
        cout << "2. KEMBALIKAN BUKU\n";
        cout << "3. KEMBALI\n";
        cout << "Masukkan Pilihan : ";
        cin >> pil;
        clean();
        switch(pil)
        {
        case '1':
            pinjamBuku(LBuku, LMhs, LRelasi);
            break;
        case '2':
            returnBuku(LRelasi);
            break;
        default:
            return;
        }
    }
}

void menuMahasiswa()
{
    char pil;

    while(true)
    {
        system("cls");
        cout << "====MENU MAHASISWA====\n";
        cout << "1. INPUT MAHASISWA\n";
        cout << "2. TAMPILKAN DATA MAHASISWA\n";
        cout << "3. KEMBALI\n";
        cout << "======================\n";
        cout << "Masukkan Pilihan : ";
        cin >> pil;
        system("cls");
        switch(pil)
        {
        case '1':
            inputMahasiswa(LMhs);
            break;
        case '2':
            showMahasiswa(LMhs);
            break;
        default:
            return;
        }
    }
}

void menuBuku()
{
    char pil;
    while(true)
    {
        system("cls");
        cout << "====MENU BUKU====\n";
        cout << "1. INPUT BUKU\n";
        cout << "2. TAMPILKAN DATA BUKU\n";
        cout << "3. CARI BUKU\n";
        cout << "4. BUKU PALING SERING DIPINJAM\n";
        cout << "5. RESUME BUKU YANG SEDANG DIPINJAM\n";
        cout << "6. KEMBALI\n";
        cout << "==================\n";
        cout << "Masukkan Pilihan : ";
        cin >> pil;
        string key;
        system("cls");
        switch(pil)
        {
        case '1':
            inputBuku(LBuku);
            break;
        case '2':
            showBuku(LBuku, 0);
            _getch();
            break;
        case '3':
            cariBuku(LBuku, 0, key);
            _getch();
            break;
        case '4':
            mostBorrowed(LBuku);
            break;
        case '5':
            resumePeminjaman(LRelasi);
            break;
        default:
            return;
        }
    }
}
