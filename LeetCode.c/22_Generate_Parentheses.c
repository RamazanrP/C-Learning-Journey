#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void generate(char** result, int* returnSize, char* guncel, int imlec, int n, int open , int close){
    if(imlec == 2*n){ // Tamamlanan olursa sonuc'a KOPYALAMALIYIZ
        guncel[imlec] = '\0'; // Stirng sayılması için 
        result[*returnSize] = (char*)malloc((2*n+1)*sizeof(char));
        strcpy(result[*returnSize], guncel);
        (*returnSize)++; // Parantez şart, ++ > * olmaması için
        return;
    }
    if(open < n){ // toplam n tane '(' açabilirdik
        guncel[imlec] = '(';
        generate(result,returnSize,guncel,imlec+1,n,open+1,close); // Devamlı olsun diye kendisini (open+1 halini) çağırıyoruz
    }
    if(close < open){ // kapalı parantez ise ne kadar açılmışsa o kadar olabilir (bir tane artınca == olacak ve sonra çağrılmayacak)
        guncel[imlec] = ')';
        generate(result,returnSize,guncel,imlec+1,n,open,close+1);
    }
}
char** generateParenthesis(int n, int* returnSize) { // Ana fonksiyonumuz
char** result = (char**)malloc(15000*sizeof(char*)); // n= 8 ise 14300 tane oluyor
char* guncel = (char*)malloc((2*n+1)*sizeof(char)); // Her bi alt string için yer açtık
*returnSize = 0; // Kaç tane alt string olduğunun sayısı
generate(result,returnSize,guncel,0,n,0,0);
free(guncel); // İşimiz bitince günceli bıraktık, result'ı gönderdik
return result;
}