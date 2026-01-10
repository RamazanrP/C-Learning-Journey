#include <stdio.h>
// LeetCode 34. soru -> dizide varsa ilk ve son indisini, yoksa -1 -1 yazdıran kod
// iki farklı while kurup birinde sola diğerinde sağa gitmeyi önceleyeceğiz
int main () {
int varmi=0,i,j,N,sol,sag,mid,target,dizi[50],ilkindex=-1,sonindex=-1;
printf("Dizinizin eleman sayisini ve target'i giriniz: ");
scanf("%d %d", &N, &target);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
sol=0,sag = N-1;
while(sol<=sag){
    mid = sol + (sag-sol)/2;
    if(dizi[mid] == target){
        ilkindex = mid;
        sag = mid-1;
    }else if(dizi[mid] < target){
        sol = mid+1;
    }else{
        sag = mid-1;
    }
}
sol=0,sag=N-1;
while(sol<=sag){
    mid = sol+ (sag-sol)/2;
    if(dizi[mid] == target){
        sonindex = mid;
        sol = mid+1;
    }else if(dizi[mid] > target){
        sag = mid-1;
    }else{
        sol = mid+1;
    }
}
printf("%d %d", ilkindex, sonindex);
}