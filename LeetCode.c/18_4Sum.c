#include <stdio.h>
//Verilen target ı oluşturan ve sadece unique diziyi döndüren, 4 sayının indisini yazdıran kod
long long dizi[200], N, target, i, j, sol, sag, temp;
int main() {
printf("Dizinizin uzunlugunu giriniz: ");
scanf("%lld", &N);
printf("Dizinizi giriniz: ");
for(i = 0; i < N; i++) {
    scanf("%lld", &dizi[i]);
}
printf("Target'i giriniz: ");
scanf("%lld", &target);
for(i = 0; i < N - 1; i++) {
    for(j = i + 1; j < N; j++) {
        if(dizi[j] > dizi[i]) { // Büyükten küçüğe sıraladık
            temp = dizi[j];
            dizi[j] = dizi[i];
            dizi[i] = temp;
        }
    }
}

for(i = 0; i < N - 3; ++i) {
    // 1. KOPYA KONTROLÜ (i için):
    // Eğer bu sayı bir öncekiyle aynıysa boşuna bakma, devam et.
    if(i > 0 && dizi[i] == dizi[i-1]) continue; // i>0 diyerek -1'e bakmadan yaptık
    for(j = i + 1; j < N - 2; ++j) {
        // 2. KOPYA KONTROLÜ (j için):
        // j, i'nin hemen yanı değilse ve öncekiyle aynıysa atla.
        if(j > i + 1 && dizi[j] == dizi[j-1]) continue;
        sol = j+1; 
        sag = N-1;
        while(sol < sag) {
            long long toplam = dizi[i] + dizi[j] + dizi[sol] + dizi[sag];
            if(toplam > target) {
                ++sol; //Toplamımız büyük çıktı, ileriye gidip küçüklerden denemeliyiz
            } 
            else if(toplam < target) {
                --sag;
            } 
            else {
                // Target'a ulaştık ama burada da işlem yapmalıyız yoksa while'da takılır kalır
                printf("[%lld %lld %lld %lld]\n", dizi[i], dizi[j], dizi[sol], dizi[sag]);
                ++sol;
                --sag;

                // 3. KOPYA KONTROLÜ (sol ve sag için):
                // Bulduktan sonra, aynı sayılar gelmeye devam ediyorsa onları da hızlıca geçmeliyiz
                    
                // Sol taraftaki kopyaları atla
                while(sol<sag && dizi[sol] == dizi[sol-1]){
                    sol++; //Zaten birbirlerine eşit olduğu için korkmadan sol'u arttırabiliyoruz. Sol zaten artmaya meyilli
                }          //Burada önemli olan sol ile sol+1'i değil sol-1'i karşılaştırmak!
                    
                // Sağ taraftaki kopyaları atlıyoruz
                while(sol < sag && dizi[sag] == dizi[sag+1]) sag--;
            } //Burada da sag+1 önemsiz. Bizim sol ve sağ'ı yakınlaştırıp bulmamız lazım. En sağ ve en son hep atlanır
        }
    }
}
return 0;
}