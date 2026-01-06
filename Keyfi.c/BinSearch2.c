#include <stdio.h>
//math.h kullanmadan karekökü veya en yakın (bir alt değeri) yazdıran kod, tabi ki Bin arama ile
int main () {
int alt=0,N,ust,yakindeger=0;
long long kok;
printf("Degerinizi giriniz: ");
scanf("%d", &N);
ust=N;
while(alt<=ust){  //While'ı sayılarla kuramayız, sınırlarla kuracağız
    kok=alt+(ust-alt)/2;
    if(kok*kok==N){
        printf("Sayinizin karekoku %d", kok); //Karekök ise direkt işlem bitsin
        return 0;
    } else if(kok*kok>N){
        ust= kok-1;
    } else{
        alt= kok+1;
        yakindeger=kok;              //Keninden küçük değeri de yazdırabileceğimiz için bunu bir değere atadım
    }
}
printf("Sayinizin yakin deger karekoku %d", yakindeger);
}