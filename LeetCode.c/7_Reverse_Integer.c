#include <limits.h> // INT_MAX ve MIN için şart
int reverse(int x){
int sonuc=0, son_hane;
while(x != 0){ // Hem negatif hem pozitifleri de işleme sokmak için sadece != 0 şartı koyduk, sayımızı daraltıyoruz
son_hane = x%10;// sonuc*10 demek yerine INT_MAX/10 dedik çünkü *10 taşabilirdi, büyüğü KÜÇÜLTMELİYİZ
if(sonuc > INT_MAX/10 || sonuc == INT_MAX/10 && son_hane > 7){ 
    return 0;
}// Negatifler için if bloğumuz, burada >8 değil <-8 demeliyiz çünkü son_hane'yi ekliyoruz, ekleyince sonu 9 olmamalı
if(sonuc < INT_MIN/10 || sonuc== INT_MIN/10 && son_hane < -8){
    return 0;
}
sonuc = (sonuc*10) + son_hane;
x /= 10;
}
return sonuc;
}