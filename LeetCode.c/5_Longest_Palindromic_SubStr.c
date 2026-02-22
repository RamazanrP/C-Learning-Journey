#include <string.h>
char* longestPalindrome(char* s) {
int n = strlen(s),i,j,max=0,maxsol=0,maxsag=0; // strlen sonraki null'u saymaz, o sebeple for'da i<n diyeceğiz
for(i=0;i<n;i++){
    int sag=i,sol=i; //Önce tek haneli bir string olduğunu kabul ettik ve sağa sola ilerlettik polindrom mu diye görmek için
    while(sol>=0 && sag<n && s[sag]==s[sol]){
        sol--,sag++;
    }
    int guncel = sag-sol-1;//while bitince sol ve sağ arasındaki mesafe bize lazım olandan fazla, o yüzden -1 dedik
    if(guncel > max){
        max = guncel;
        maxsol=sol+1,maxsag=sag-1; //Soru bizden output olarak substring istiyor. Yani indisleri kaydetmeliyiz
    }
    if(i!=n-1 && s[i]==s[i+1]){ //Burada da çift haneli subs olma ihtimali üzerine düşünüyoruz
        sol=i,sag=i+1;
        while(sol>=0 && sag<n && s[sag]==s[sol]){
            sol--;sag++;
        }
        int cift_uzunluk = sag-sol-1;
        if(cift_uzunluk > max){
            max = cift_uzunluk;
            maxsol=sol+1,maxsag=sag-1;
        }
    }
} // Buraya geldiğimizde artık NET OLARAK max değerlerimiz biliniyor. Bunları biliyorsa artık substringi dizmeye başlayabiliriz
char* maxsubs = (char*)malloc((max + 1) * sizeof(char)); // +1 null için
int k=0; //kelimenin 0. indisi için j'yi kullanamam. Mecburen 2 farklı değişken oluşturduk
for(j=maxsol;j<=maxsag;j++){
    maxsubs[k] = s[j];
    k++;
}
maxsubs[k]='\0'; //String olması için bunu  unutma!
return maxsubs;
}