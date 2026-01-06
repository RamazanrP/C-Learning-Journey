#include <stdio.h>
// LeetCode 179. soru -> Verilen dizideki sayıları yan yana yazıldıklarında en büyüğü verecek şekilde yazdırmak (Stringe çevirmeden)
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
int i,j,N;
printf("Kac sayi gireceksiniz? ");
scanf("%d", &N);
int nums[100];
printf("Sayilari giriniz: ");
for(i=0;i<N;i++) {
    scanf("%d", &nums[i]);
}

// BUBBLE SORT (Sıralama)
for(i=0;i<N-1;i++) {
    for(j=0;j<N-1-i;j++) {
            
        int A = nums[j];
        int B = nums[j+1]; // Önemli olan j! i bize sadece dizinin en son indexlerine gereksiz bakmamızı sağlıyor

        long long AB = A * basamakKati(B) + B; // Örn: A=3, B=30 -> 3 * 100 + 30 = 330
            
        long long BA = B * basamakKati(A) + A; // Örn: B=30, A=3 -> 30 * 10 + 3 = 303

        // Biz büyük olanı başa istiyoruz. 
        // Eğer BA > AB ise, demek ki B'nin öne gelmesi daha karlı. SWAP yapmalıyız.
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
     for(i=0;i<N;i++) {
        printf("%d", nums[i]);
    }
}
printf("\n");
return 0;
}