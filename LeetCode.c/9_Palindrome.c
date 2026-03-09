#include <stdbool.h>
bool isPalindrome(int x) {
if(x<0) return false;
if(x != 0 && x%10==0) return false;  // Sayı 0 değilse ve son hanesi 0 ise false
int yarisi = 0;
while(x>yarisi){                    // Sayının hepsini çevirmeye gerek yok. yarısını veya ortanca hanesine kadar çevirmek kafi
    yarisi = yarisi*10 + x%10;
    x /= 10;
}   // 12321 için yarisi=123 x = 12 -> true, 1221 için yarisi=12 x = 12 -> true. Sırf şu alttaki satır için yazmak istedim soruyu
return (x==yarisi || x == yarisi/10);
}