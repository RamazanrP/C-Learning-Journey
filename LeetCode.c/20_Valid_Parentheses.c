#include <stdbool.h>
#include <string.h>
bool isValid(char* s) {
int length = strlen(s);
if(length%2 != 0) return false; // uzunluğu tek ise veya kapalı ile başlıyorsa direkt false çevir
if(s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
char* yigin = (char*)malloc(length*sizeof(char));
int k=0; // Yığınımızı bu ilerletecek
for(int i=0;i<length;++i){
    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
        yigin[k] = s[i]; // Açık parantez ise yığına koyduk, k'yı arttırdık
        k++;
    }else if(k==0){ // Eğer kapalı geldiyse ve k 0'lanmışsa demek fazlalık oldu, direkt false
        return false;
    }else if(s[i] == ')'){
        if(yigin[k-1] == '(') k--; // Bir öncekine bakıyoruz hep, istediğimiz değilse false, istediğimiz ise k azalsın, yığından çıksın
        else return false;
    }else if(s[i] == '}'){
        if(yigin[k-1] == '{') k--;
        else return false;
    }else if(s[i] == ']'){
        if(yigin[k-1] == '[') k--;
        else return false;
    }
}
if(k==0) return true; // En sonda yığın BOŞ mu kontrol etmeliyiz, boşsa işlem tmm
else return false;
}