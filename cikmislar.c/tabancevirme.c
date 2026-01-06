#include <stdio.h>

int main () {
int i=0,k=0,j;
int deger;
int taban,carpim;
int dizi[20];
int yazdir;
printf("degerinizi giriniz: ");
scanf("%d", &deger);
printf("cevirmek istenen tabani giriniz: ");
scanf("%d", &taban);
carpim=taban;
while (deger>taban){
    taban=taban*carpim;     //taban*taban yazsaydık  2 4 16 256 gibi giderdi, iki farklı 2 değeri tuttuk, çarpım hep 2 kaldı
    i++;
}
taban=taban/carpim;         //while'ın içinde taban en sonda değeri geçmişti, While'dan sonra değeri bir kuvvet indirmezsek 0 yazdırır başta
yazdir=i+1;                 //kuvvetler 0'dan başladığı için +1 yazdık
for(i;i>=0;i--){
    if(deger>=taban){
        dizi[k]=1;
        deger=deger-taban; //değerin sadece bölünme olduğu takdirde azalmasına dikkat
    } else{
        dizi[k]=0;
    }
    taban=taban/carpim;    // her durumda da tabanımız giderek küçülmeli, dışarıya yazdık
    k++;                   //k'yı for'a sokmadık, manuel arttıracaz
}
for(j=0;j<yazdir;j++){
    printf("%d ", dizi[j]);
}
}
/*Talha'nın yazdığı kod:
#include<stdio.h> 

int a,i,k,binary[10];
int main()
{
    scanf("%d",&a);
    k=0;
    for(i=1;i<50;i=i<<1)
    {
        //printf("%d %d\n",a ,i);
        
        if(a&i)
        {
            binary[k]=1;
        }
        else
        {
            binary[k]=0;
        }
        k+=1;
    }
    for(i=9;i>=0;i--)
    {
        printf("%d",binary[i]);
    }
}  
*/