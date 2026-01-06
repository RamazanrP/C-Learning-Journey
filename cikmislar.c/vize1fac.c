#include <stdio.h>

int main()
{
   int grd;
   int asal_mi=1;
    scanf("%d", &grd);
    for(int i=2; i<grd;i++) {
        
        if (grd%i==0) {
            // Asallık bozuldu ise 0
            asal_mi=0;
            continue;
        }
        printf("%d\n",i);
        
    }
    if(asal_mi==0) { 
        printf("sayiniz asal degil");
    } 
    else {
        printf("asal sayi girdiniz");
    }
   
} //sadece 2 yazdırır
  // 2 ve 3 yazdırır sonra break olur