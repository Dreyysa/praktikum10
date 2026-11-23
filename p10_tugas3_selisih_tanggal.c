/* Tugas 10.3 - Menghitung selisih dua tanggal (dalam hari) */
#include <stdio.h>

struct Tanggal {
    int tanggal, bulan, tahun;
};

int kabisat(int tahun) {
    return (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
}

int hariDalamBulan(int bulan, int tahun) {
    static const int hari[] = {0, 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    if (bulan == 2 && kabisat(tahun))
        return 29;
    return hari[bulan];
}

int valid(struct Tanggal t) {
    if (t.tahun < 1 || t.bulan < 1 || t.bulan > 12)
        return 0;
    return t.tanggal >= 1 && t.tanggal <= hariDalamBulan(t.bulan, t.tahun);
}

/* Jumlah hari sejak 01-01-0001 (hari ke-1) sampai tanggal t */
long hitungHari(struct Tanggal t) {
    long total = 0;
    int y, m;

    for (y = 1; y < t.tahun; y++)
        total += kabisat(y) ? 366 : 365;
    for (m = 1; m < t.bulan; m++)
        total += hariDalamBulan(m, t.tahun);
    total += t.tanggal;
    return total;
}

int main(void) {
    struct Tanggal t1, t2;
    long d;

    printf("Masukkan tanggal pertama (dd-mm-yyyy): ");
    if (scanf("%d-%d-%d", &t1.tanggal, &t1.bulan, &t1.tahun) != 3 || !valid(t1)) {
        printf("Tanggal pertama tidak valid.\n");
        return 1;
    }
    printf("Masukkan tanggal kedua   (dd-mm-yyyy): ");
    if (scanf("%d-%d-%d", &t2.tanggal, &t2.bulan, &t2.tahun) != 3 || !valid(t2)) {
        printf("Tanggal kedua tidak valid.\n");
        return 1;
    }

    d = hitungHari(t2) - hitungHari(t1);
    if (d < 0)
        d = -d;
    printf("Selisih: %ld hari\n", d);
    return 0;
}
