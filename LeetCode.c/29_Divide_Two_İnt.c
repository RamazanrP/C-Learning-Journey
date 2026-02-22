#include <stdlib.h>
int divide(int dividend, int divisor) {
if(dividend== -2147483648 && divisor == -1) return 2147483647; // Sorunun verdiği kısıtlama
int eksi_mi = (dividend < 0) ^ (divisor < 0); // Eğer iki değer farklı ise sonuç 1 çıkacak. 1 çıktığı sürece -bolen döndüreceğiz
long long katlanan,bolum=0; // Katlanan long long olmasaydı bolen 1 olursa overflow olabilir (ki oldu da :)))
long long bolen = llabs((long long)divisor), bolunen = llabs((long long)dividend); // Mutlak değerini aldık
while(bolunen>=bolen){
    katlanan=1; // Her seferinde 1'den başlatmalı!
    long long yedekbolen = bolen;
    long long yedekbolunen = bolunen;
    while(yedekbolunen>=(yedekbolen << 1)){
        katlanan+=katlanan;
        yedekbolen+=yedekbolen; // Veya yedekbolen = yedekbolen << 1 de denebilir. Sola doğru gitmesi iki ile çarpılması demektir
    }                           // 101(2) = 5 iken 1010(2) = 10 aynı şekilde sağa gitmesi de 10(2) = 2 yani ikiye bölünmesi demek
    bolum+=katlanan;
    bolunen -= yedekbolen; // bolunen giderek küçülürken (ilk while'ı tehdit ederken) yedekbolunen sabit olmalı!
}                          // İkinci while'ı tehdit eden şey yedekbolunen değil yedekbolen olmalı. Tehdit edip çıktıktan sonra geri eski haline dönmeli!
if(eksi_mi) return -bolum;
else return bolum;
}