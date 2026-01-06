#include <stdio.h>
//Sıralı ve elemanları tekrar edebilen bir dizide hedef sayının tekrar başladığı İLK İNDİS
int main () {
int hedef,i,n,alt,ust,mid,dizi[50];
int ilkbulunanyer=-1; //Bu -1 olarak kalırsa sayı yok demektir, değişmişse en küçük indisi gösterecek
printf("Dizinizin eleman sayisini giriniz: ");
scanf("%d", &n);
printf("Dizinizi giriniz: ");
for(i=0;i<n;i++){
    scanf("%d", &dizi[i]);
}
printf("Hedef sayinizi giriniz: ");
scanf("%d", &hedef);
alt=0;ust=n-1;
while(alt<=ust){
    mid= alt+ (ust-alt)/2;
    if(dizi[mid]<hedef){
        alt=mid+1;
    } else if(dizi[mid]>hedef){
        ust=mid-1;
    } else{ 
        ilkbulunanyer=mid;
        ust=mid-1; //Böyle yaptık ki hala açgözlü olduğumuz belli olsun
    }
    
}
if(ilkbulunanyer==-1){
    printf("Sayiniz bulunamadi");
}else {
    printf("Sayinizin bulundugu ilk indis %d", ilkbulunanyer);
}
}