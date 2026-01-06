#include <stdio.h>
//LeetCode 32. sorunun kendime göre kodu. yüksek ihtimal hatalı olacaktır :)
long long i=0,sayac=0,nihai=0;
int main () {
char deneme[3] = {'(','a',')'};
char s[30000];
int k=1;
printf("Stringinizi giriniz: ");
scanf("%s", s);
while(s[i] != '\0'){
    if(s[i] == '('){
        sayac = 1;
        while(s[i+1] != '\0' && s[i+1] == deneme[1+k]){
            sayac++;
            k = k*-1;
        }
        i++;
        if(sayac > nihai){
            nihai = sayac;
        }
    }else{
        i++;
    }
}
printf("%lld", nihai);
}