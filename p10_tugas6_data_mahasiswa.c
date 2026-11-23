/* Tugas 10.6 - Aplikasi data mahasiswa berbasis file */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMA_FILE "mahasiswa.txt"

struct Mahasiswa {
    int nim;
    char nama[40];
    float ipk;
};

/* Membaca satu baris dari stdin lalu membuang newline */
static int bacaBaris(char *buf, size_t n) {
    if (fgets(buf, (int)n, stdin) == NULL)
        return 0;
    buf[strcspn(buf, "\n")] = '\0';
    return 1;
}

void tambahData(void) {
    struct Mahasiswa m;
    char buf[64];
    FILE *file;

    printf("NIM  : ");
    if (!bacaBaris(buf, sizeof buf)) return;
    m.nim = atoi(buf);

    printf("Nama : ");
    if (!bacaBaris(m.nama, sizeof m.nama)) return;
    if (strchr(m.nama, ';') != NULL) {
        printf("Nama tidak boleh mengandung tanda titik koma.\n");
        return;
    }

    printf("IPK  : ");
    if (!bacaBaris(buf, sizeof buf)) return;
    m.ipk = (float)atof(buf);

    file = fopen(NAMA_FILE, "a");
    if (file == NULL) {
        perror("File gagal dibuka");
        return;
    }
    fprintf(file, "%d;%s;%.2f\n", m.nim, m.nama, m.ipk);
    fclose(file);
    printf("Data berhasil ditambahkan.\n");
}

void tampilData(void) {
    struct Mahasiswa m;
    FILE *file = fopen(NAMA_FILE, "r");

    if (file == NULL) {
        printf("File %s belum tersedia atau gagal dibuka.\n", NAMA_FILE);
        return;
    }
    printf("NIM   | NAMA | IPK\n");
    while (fscanf(file, "%d;%39[^;];%f", &m.nim, m.nama, &m.ipk) == 3) {
        printf("%d | %s | %.2f\n", m.nim, m.nama, m.ipk);
        int ch;
        while ((ch = fgetc(file)) != '\n' && ch != EOF) { }
    }
    fclose(file);
}

void cariData(void) {
    struct Mahasiswa m;
    char buf[64];
    int nimCari, ketemu = 0;
    FILE *file;

    printf("Masukkan NIM yang dicari: ");
    if (!bacaBaris(buf, sizeof buf)) return;
    nimCari = atoi(buf);

    file = fopen(NAMA_FILE, "r");
    if (file == NULL) {
        printf("File %s belum tersedia atau gagal dibuka.\n", NAMA_FILE);
        return;
    }
    while (fscanf(file, "%d;%39[^;];%f", &m.nim, m.nama, &m.ipk) == 3) {
        if (m.nim == nimCari) {
            printf("Data ditemukan: %d | %s | %.2f\n", m.nim, m.nama, m.ipk);
            ketemu = 1;
            break;
        }
        int ch;
        while ((ch = fgetc(file)) != '\n' && ch != EOF) { }
    }
    fclose(file);
    if (!ketemu)
        printf("NIM %d tidak ditemukan.\n", nimCari);
}

int main(void) {
    char buf[16];
    int pilih;

    do {
        printf("\n=== DATA MAHASISWA ===\n");
        printf("1. Tambah data\n");
        printf("2. Tampilkan semua data\n");
        printf("3. Cari berdasarkan NIM\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        if (!bacaBaris(buf, sizeof buf))
            break;
        pilih = atoi(buf);

        switch (pilih) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: cariData();   break;
            case 0: printf("Program selesai.\n"); break;
            default: printf("Pilihan tidak valid.\n");
        }
    } while (pilih != 0);
    return 0;
}
