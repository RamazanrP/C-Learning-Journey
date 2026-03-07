int longestNiceSubarray(int* nums, int numsSize) {
// Verilen sayılar 10^9'dan küçük olduğu için en fazla 30 bit tutar. Bu sebeple unsigned int diye define ettik
int max=0,sol=0,sag;
unsigned int kullanilan=0;
for(sag=0;sag<numsSize;sag++){ // Klasik KAYAN PENCERE yöntemini uyguluyoruz
    while((kullanilan&nums[sag])!=0){ //Kullanılan'daki bitlerle yeni gelen nums[sag]'ın bitleri çakışırsa 1&1=1 çıkar, 0'dan farklı olur
        kullanilan^=nums[sol]; //Çakışma olmamış haline döndürmek için XOR'ladık. 0^0 zaten 0 kalacak. 1^1 de 0'a dönecek
        sol++;                 //Böylece dolu olan bitleri (1'leri) 0'lamış yani ÇIKARMIŞ oluyoruz
    }
    kullanilan |= nums[sag]; // Şimdi bu temiz/çakışmayan hali KAYDETMEMİZ lazım. OR ile nums[sag]'daki dolu bitleri kullanilan'daki 0'ların üstüne aldık
    int guncel = sag-sol+1;  // Burada çakışma yok çünkü yukarda o ihtimali TEMİZLEDİK. Rahatça kaydedebiliriz.
    max = (guncel>max) ? guncel:max;
}
return max;
}