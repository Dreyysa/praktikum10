/* Tugas 10.4 - Fungsi pembanding string */
#include <stdio.h>
#include <string.h>

int sama_str(char s1[], char s2[]) {
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        ++i;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 1;   /* string sama */
    return 0;       /* string berbeda */
}

int main(void) {
    char k1[50], k2[50];

    printf("Masukkan kata pertama: ");
    if (scanf("%49s", k1) != 1) return 1;
    printf("Masukkan kata kedua  : ");
    if (scanf("%49s", k2) != 1) return 1;

    if (sama_str(k1, k2))
        printf("Hasil: kedua kata SAMA.\n");
    else
        printf("Hasil: kedua kata BERBEDA.\n");
    return 0;
}
