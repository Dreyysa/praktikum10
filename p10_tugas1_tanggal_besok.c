/* Tugas 10.1 - Menentukan tanggal berikutnya */
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

struct Tanggal besok(struct Tanggal t) {
    if (t.tanggal < hariDalamBulan(t.bulan, t.tahun)) {
        t.tanggal++;
    } else {
        t.tanggal = 1;
        if (t.bulan < 12) {
            t.bulan++;
        } else {
            t.bulan = 1;
            t.tahun++;
        }
    }
    return t;
}

int main(void) {
    struct Tanggal t, b;

    printf("Masukkan tanggal (dd-mm-yyyy): ");
    if (scanf("%d-%d-%d", &t.tanggal, &t.bulan, &t.tahun) != 3) {
        printf("Input tidak valid.\n");
        return 1;
    }
    if (!valid(t)) {
        printf("Tanggal tidak valid.\n");
        return 1;
    }
    b = besok(t);
    printf("Tanggal besok: %02d-%02d-%04d\n", b.tanggal, b.bulan, b.tahun);
    return 0;
}
