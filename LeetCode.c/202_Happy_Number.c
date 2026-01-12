#include <stdio.h>
#include <stdbool.h>

// Sayının rakamlarının karelerini toplayan yardımcı fonksiyon
int kareleriTopla(int n) {
    int toplam = 0;
    while (n > 0) {
        int rakam = n % 10;     // En sağdaki rakamı aldık
        toplam += rakam * rakam; // Karesini ekledik
        n /= 10;                // Sayıyı küçülttük
    }
    return toplam;
}

bool isHappy(int n) {
    // Bir döngü olup olmadığını anlamak için biri yavaş biri hızlı iki değişken kullanacağız
    int yavas = n;
    int hizli = kareleriTopla(n);

    // Eğer hızlı olan 1'e ulaşmazsa ve yavaş olana yetişmezse devam et
    while (hizli != 1 && yavas != hizli) {
        yavas = kareleriTopla(yavas);                // Buradaki 1 adım atıyor
        hizli = kareleriTopla(kareleriTopla(hizli)); // Bu 2 adım atıyor, bir süre sonra yavaşı yaklayacak ve sonsuz döngüden çıkcak
    }

    return hizli == 1; // Eğer 1'de durduysa mutludur!
}

int main(void) {
    // n değişkenini tanımlıyoruz ve test etmek istediğimiz değeri atıyoruz.
int n; 
printf("Sayinizi giriniz: ");
scanf("%d", &n);
if (isHappy(n)) {
    printf("Result: %d is a Happy Number.\n", n);
} else {
    printf("Result: %d is not a Happy Number.\n", n);
}

return 0;
}