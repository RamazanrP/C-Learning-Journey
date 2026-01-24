#include <string.h>
int getVal(char c) { // Çok fazla switch-case olmaması için case kurduk
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int romanToInt(char* s) {
    int toplam = 0;
    int n = strlen(s);
    int i = 0;
    while(s[i] != '\0') {
        int suan = getVal(s[i]); // Harflerin ASCII'lerini değil getVal değerlerini karşılaştırmalıyız
        int sonraki = getVal(s[i+1]); // Sonraki stirngin dışına çıkamaz çünkü \0'ı 0 olarak tanımladık, her zaman güvenli 
        if(sonraki > suan){
            toplam += sonraki - suan;
            i += 2; // iki tane harf atlaması önemli
        }else{
            toplam += suan;
            i++;
        }
    }
    
    return toplam;
}