#include <stdio.h>
// LeetCode 179. soru -> Verilen dizideki sayıları yan yana yazıldıklarında en büyüğü verecek şekilde yazdırmak
long long basamakKati(int n) {
    if (n == 0) return 10;
    long long kat = 1;
    while (n > 0) {
        kat *= 10;
        n /= 10;
    }
    return kat;
}
int main() {
int N;
printf("Kac sayi gireceksiniz? ");
scanf("%d", &N);
int nums[100];
printf("Sayilari giriniz: ");
for(int i = 0; i < N; i++) {
    scanf("%d", &nums[i]);
}

// BUBBLE SORT (Sıralama)
for(int i = 0; i < N - 1; i++) {
    for(int j = 0; j < N - 1 - i; j++) {
            
        int A = nums[j];
        int B = nums[j+1];

        // MATEMATİKSEL BİRLEŞTİRME
            
        // Kombinasyon 1 (A önce, B sonra): 
        // Örn: A=3, B=30 -> 3 * 100 + 30 = 330
        long long AB = A * basamakKati(B) + B;
            
        // Kombinasyon 2 (B önce, A sonra):
        // Örn: B=30, A=3 -> 30 * 10 + 3 = 303
        long long BA = B * basamakKati(A) + A;

        // Eğer BA daha büyükse (303 < 330 olduğu için yer değiştirmez)
        // Ama mesela 9 ve 50 olsa: 950 > 509 (Yer değiştirmez)
        // 50 ve 9 olsa: 509 < 950 (Yer değişir)
            
        // Biz büyük olanı başa istiyoruz. 
        // Eğer BA > AB ise, demek ki B'nin öne gelmesi daha karlı. SWAP yap.
        if (BA > AB) {
            int temp = nums[j];
            nums[j] = nums[j+1];
            nums[j+1] = temp;
        }
    }
}
printf("Sonuc: ");
// Eğer en baştaki sayı 0 ise sadece 0 yaz (000 olmasın diye)
if (nums[0] == 0) {
    printf("0");
} else {
     for(int i = 0; i < N; i++) {
        printf("%d", nums[i]);
    }
}
printf("\n");
return 0;
}