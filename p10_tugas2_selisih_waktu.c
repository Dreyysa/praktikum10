/* Tugas 10.2 - Menghitung selisih dua waktu */
#include <stdio.h>

struct Waktu {
    int jam, menit, detik;
};

int valid(struct Waktu w) {
    return w.jam >= 0 && w.jam < 24 &&
           w.menit >= 0 && w.menit < 60 &&
           w.detik >= 0 && w.detik < 60;
}

long keDetik(struct Waktu w) {
    return w.jam * 3600L + w.menit * 60L + w.detik;
}

struct Waktu selisih(struct Waktu a, struct Waktu b) {
    struct Waktu hasil;
    long d = keDetik(b) - keDetik(a);

    hasil.jam = (int)(d / 3600);
    hasil.menit = (int)((d % 3600) / 60);
    hasil.detik = (int)(d % 60);
    return hasil;
}

int main(void) {
    struct Waktu w1, w2, s;

    printf("Masukkan waktu pertama (jj:mm:dd): ");
    if (scanf("%d:%d:%d", &w1.jam, &w1.menit, &w1.detik) != 3 || !valid(w1)) {
        printf("Waktu pertama tidak valid.\n");
        return 1;
    }
    printf("Masukkan waktu kedua   (jj:mm:dd): ");
    if (scanf("%d:%d:%d", &w2.jam, &w2.menit, &w2.detik) != 3 || !valid(w2)) {
        printf("Waktu kedua tidak valid.\n");
        return 1;
    }
    if (keDetik(w2) < keDetik(w1)) {
        printf("Waktu kedua tidak boleh lebih awal dari waktu pertama.\n");
        return 1;
    }

    s = selisih(w1, w2);
    printf("Selisih: %d jam %d menit %d detik\n", s.jam, s.menit, s.detik);
    return 0;
}
