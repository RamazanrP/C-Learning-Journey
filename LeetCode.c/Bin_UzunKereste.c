#include <stdio.h>
//Kullanıcı bize dizi ve parça sayısı versin,
//Öyle bir uzun X değeri bulalım ki hem uzun olsun hem de yeteri kadar parça çıksın
int main () {
int keresteX, toplam=0,i,odunlar,max=0,alt,ust,miktar,yedek;
int dizi[20];
printf("Dizinizin eleman sayisini giriniz: ");
scanf("%d", &odunlar);
printf("istediginiz parca miktarini giriniz: ");
scanf("%d", &miktar);
printf("Dizinizi giriniz: ");
for(i=0;i<odunlar;i++){
    scanf("%d", &dizi[i]);
    if(dizi[i]> max){
        max=dizi[i];
    }
}   
alt=1,ust=max;
while(alt<=ust){
    keresteX= alt+ (ust-alt)/2; //For hesabı yaptı mı yeni alt-ust ile KeresteX'i belirleriz
    toplam=0;                   //Bu yeni keresteX ile işleme tabi tutmadan önce toplamı 0lamak lazım
    for(i=0;i<odunlar;i++){
        toplam+= dizi[i]/keresteX;
    }
    if(toplam<miktar){
        ust=keresteX-1;
    }else if(toplam>=miktar){ // toplam==miktar koysak da gene açgözlülüğümüz devam edecekti. İkisini buluşturduk
    yedek=keresteX; //Bu değeri cebimize attık ama hala açgözlüyüz, eğer while bozulursa bu değerle yetineceğiz.
    alt= keresteX+1;
    }
}
printf("Kesilecek en uzun parca uzunlugu %d", yedek);
return 0;
}