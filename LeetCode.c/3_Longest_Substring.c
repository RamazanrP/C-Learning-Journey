#include <string.h>
// Sadece yan yana olanları değil bütün bi substringi kontrol etmemiz lazım, bunun için histogram kullanacağız
int lengthOfLongestSubstring(char* s) {
int hafizaDefteri[128] = {0}; 
int enBuyukUzunluk = 0;
int pencereBasi = 0; // Substring'in başlangıcı, artmıyor ZIPLIYOR
for (int suanki = 0; s[suanki] != '\0'; suanki++) { // İşçimiz, mevcut indexi gösteriyor
    char gelenHarf = s[suanki];
        if (hafizaDefteri[gelenHarf] > pencereBasi) { // Histogramda bu harfi daha önce gördüğüm index (görmeden önce tüm harfler için 0)
            pencereBasi = hafizaDefteri[gelenHarf];   // Eğer 0'dan farklı (yani bir kere görmüşüm) ve de başlangıçtan büyükse
        }                                             // Yani gördüm ve de 2. kez denk geldiyse substring bozuldu!!!
        hafizaDefteri[gelenHarf] = suanki + 1; // 0'dan farklı olması için BÜTÜN HARFLERİN yerini belirleyeceğiz/güncelleyeceğiz her zaman (if'e girse de girmese de)
        int guncelUzunluk = suanki - pencereBasi + 1; // Uzunluk hesabı son-baş+1 (Burda suanki düzenli artıyor ama pencerebasi zıplarsa eğer gunceluzunluk küçülüyor)
        if (guncelUzunluk > enBuyukUzunluk) {
            enBuyukUzunluk = guncelUzunluk;
        }
    }
return enBuyukUzunluk;
}