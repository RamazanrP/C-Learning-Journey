#include <stdio.h>
// LeetCode 33. Soru -> Sıralı olan bir dizi bir yerde kesiliyor,  bu bozuk halinde target kaçıncı indexte
// Bozuk olsa bile bizim arama yaptığım yerin ya sağı ya solu sıralı olacak. Buna bakacağız. Bulunmazsa -1 yazdıracaz
int main () {
int i,low,high,mid,N,dizi[50],bulundumu=-1,target;
printf("dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("İstediginiz sayiyi giriniz: ");
scanf("%d", &target);
printf("Kesilmis haldeki dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
low=0,high=N-1;
while(low<=high){ //Tek elemanlı olursa diye  = koyduk
    mid= low + (high-low)/2; // Formülü böyle yazmak önemli!
    if(dizi[mid] == target){
        printf("%d", mid);
        bulundumu=1;
        return 0;
    }
    if(dizi[low] <= dizi[mid]){ // Sol taraf sıralıysa hemen sorgulayalım 
        if(target >= dizi[low] && target < dizi[mid]){ // Target low'dan >= mi ve targettan küçük  mü
            high = mid-1;                              // Bu iki şart sağlıyorsa aralığı sol'a çekelim
        }else{
            low = mid+1; //sol taraf sıralı ama target burda değilse sağda arıyoruz 
        }
    }else{               //Sağ taraf sıralıysa
        if(target <= dizi[high] && target > dizi[mid]){ //Target high ile mid arasındaysa aralığı sağ'a çek
            low = mid+1;
        }else{
            high = mid-1;                               //Sağ taraf sıralı olmasına rağmen burda yoksa aralığı sol'a çek
        }
    }
}
printf("-1");
return 0;
}