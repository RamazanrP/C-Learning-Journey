#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Telefon tuş takımındaki rakamların indekslerine göre harf karşılıkları:
const char* tuslar[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};
// Seçilen harfleri current'ta biriktirip \0 görünce sonuc'a atar:
void backtrack(char* digits, int index, char* current, char** sonuc, int* returnSize){
if(digits[index] == '\0'){ // digits'in uzunluğu ile oluşturulacak kombinasyonlar aynı uzunlukta zaten, ikisi de aynı anda biter
    current[index] = '\0';
    sonuc[*returnSize] = strdup(current);
    (*returnSize)++;
    return;
}
int rakam = digits[index] - '0';
const char* harfler = tuslar[rakam];
// Önce hep "son tuşlanan" Sayıda bu for kalır. 23 tuşlandıysa ince ad,ae,af yazılır, sonra 2'nin harflerine geçer:
for(int i=0; harfler[i] != '\0'; i++){
    current[index] = harfler[i]; //  a'yı aldı, sonra d'yi aldı. Bitti, e'ye geçer. For bitince 3 için kombinasyon bitmiş demektir.
    backtrack(digits, index+1, current, sonuc, returnSize);
}
}
char** letterCombinations(char* digits, int* returnSize) {
*returnSize = 0;
if(!digits || digits[0] == '\0') return NULL;
char** sonuc = malloc(sizeof(char*) * 257); // 4 tuş her biri 4 harf olsa 4^4 = 256 olur
char current[5]; // mesela turk diye 4 hane tutuyor. Max 4 harf + \0
backtrack(digits, 0, current, sonuc, returnSize);
return sonuc;
}