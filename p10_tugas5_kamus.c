/* Tugas 10.5 - Kamus menggunakan array struktur */
#include <stdio.h>
#include <string.h>

#define JUMLAH 6

struct Entri {
    char kata[30];
    char definisi[100];
};

int cariKata(const struct Entri kamus[], int n, const char *kata) {
    for (int i = 0; i < n; i++) {
        if (strcmp(kamus[i].kata, kata) == 0)
            return i;
    }
    return -1;
}

int main(void) {
    struct Entri kamus[JUMLAH] = {
        {"pointer",  "Variabel yang menyimpan alamat memori suatu objek."},
        {"struct",   "Tipe data bentukan yang mengelompokkan beberapa anggota."},
        {"array",    "Kumpulan elemen bertipe sama yang disimpan berurutan."},
        {"fungsi",   "Blok program bernama yang dapat dipanggil berulang kali."},
        {"compiler", "Program yang menerjemahkan kode sumber menjadi program mesin."},
        {"variabel", "Tempat penyimpanan nilai yang memiliki nama dan tipe data."}
    };
    char kata[30];
    char lagi = 'y';

    while (lagi == 'y' || lagi == 'Y') {
        printf("Masukkan kata yang dicari: ");
        if (scanf("%29s", kata) != 1)
            break;

        int idx = cariKata(kamus, JUMLAH, kata);
        if (idx >= 0)
            printf("Definisi %s: %s\n", kamus[idx].kata, kamus[idx].definisi);
        else
            printf("Kata \"%s\" tidak ditemukan.\n", kata);

        printf("Cari lagi? (y/n): ");
        if (scanf(" %c", &lagi) != 1)
            break;
    }
    return 0;
}
