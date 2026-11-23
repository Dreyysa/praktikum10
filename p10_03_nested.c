/* Nama file: p10_03_nested.c */
#include <stdio.h>
#include <string.h>

struct Tanggal {
    int tanggal, bulan, tahun;
};

struct Mahasiswa {
    int nim;
    char nama[50];
    struct Tanggal lahir;
};

int main(void) {
    struct Mahasiswa mhs;

    mhs.nim = 123456;
    strcpy(mhs.nama, "Siti Aminah");
    mhs.lahir.tanggal = 12;
    mhs.lahir.bulan = 8;
    mhs.lahir.tahun = 2005;

    printf("NIM       : %d\n", mhs.nim);
    printf("Nama      : %s\n", mhs.nama);
    printf("Tgl Lahir : %02d-%02d-%04d\n",
           mhs.lahir.tanggal, mhs.lahir.bulan, mhs.lahir.tahun);
    return 0;
}
