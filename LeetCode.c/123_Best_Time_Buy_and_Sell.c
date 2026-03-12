#include <limits.h>
int maxProfit(int* prices, int pricesSize) {
// Verilen fiyatlar dizisinde en fazla karı elde etmek için MAX 2 GÜN satış ve alışa izin verilen bir soru.
// Biz ilk satıştan elde edilen karı bir indirim kuponu gibi kullanıp 2. alış ücretini minimuma indireceğiz
int ilk_alim = INT_MAX,ikinci_alim = INT_MAX;
int ilk_satistan_kar=0,ikinci_satis=0;
for(int i=0;i<pricesSize;i++){
    if(prices[i]<ilk_alim) ilk_alim = prices[i]; // Karımız yüksek olsun diye ucuzu seçiyoruz
    if(prices[i]-ilk_alim>ilk_satistan_kar){    // Ucuz gelmediği takdirde "Acaba şu an satsam, önceki farktan(kardan) büyük olur mu"
        ilk_satistan_kar= prices[i]-ilk_alim;  // İndirim kuponumuz buradaki fark işte, bununla karımızı arttıracağız
    }                                         // İkinci alımda olabilecek en alt seviyenin karşılığını arıyoruz
                                             // Sonra bu indirimli halini o günkü fiyattan çıkarıp en büyük farkı(karı) sorguluyoruz
    if(prices[i]-ilk_satistan_kar<ikinci_alim) ikinci_alim = prices[i]-ilk_satistan_kar;
    if(prices[i]-ikinci_alim>ikinci_satis) ikinci_satis = prices[i]-ikinci_alim;
}
return ikinci_satis;
}