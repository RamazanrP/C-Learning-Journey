#include <stdio.h>
#include <string.h>
// Leetcode 6. soru -> Verilen Kelimeyi, verilen sayı kadar satıra sahip bir matriste sağ-alt + sol-üst yazdırıp
//Satır satır ekrana basan (boşlukları okumuyoruz tabi) kod
int main () {
int i,j,k,satir,yon=1;
char zigzag[50][50], kelime[100], olusan[100];
printf("Kelimenizi ve istediginiz satir boyutunu giriniz: ");
scanf("%s %d", kelime, &satir);
if (satir == 1) { printf("%s", kelime); return 0; } //Tek satır isterse direkt kelimeyi verelim
for(i=0;i<50;i++){
    for(j=0;j<50;j++){
        zigzag[i][j] = ' '; // Okurken != ' ' diyeceğiz çünkü. Sonra olusan'a atayacağız.
    }
}
k=0,i=0,j=0; //Başlangıç değerini atamayı unutma!
while(kelime[k] != '\0'){
    while(i<satir-1 && j<50 && yon == 1 && kelime[k] != '\0'){ //Dıştaki While yetmez, burda da != '\0' demeliyiz
        zigzag[i][j] = kelime[k];
        k++,i++,j++;
        if(i== satir-1) yon = 0, i--,j++; //Tam satitr-1 olunca yon'u sol-yukarı yaptık ve bir üst satıra geçtik
    }
    while(i>0 && j<50 && yon == 0 && kelime[k] != '\0'){
        zigzag[i][j] = kelime[k];+
        k++,i--,j++;
        if(i == 0) yon = 1, i++,j++; //0'a kadar normal gelsin. i==0 olunca yon=1'miş gibi arttırmamız lazım
    }
}
k=0; //Gene unutmuyoruz
for(i=0;i<satir;i++){ //Satir'a kadar bakmak yeterli
    for(j=0;j<50;j++){
        if(zigzag[i][j] != ' '){ 
            olusan[k] = zigzag[i][j];
            k++;
        }
    }
}
olusan[k] = '\0'; //En sona non ekleyelim ki string diye anlasın makine
printf("%s" ,olusan); //Direkt yansıttık ekrana 
return 0;
}