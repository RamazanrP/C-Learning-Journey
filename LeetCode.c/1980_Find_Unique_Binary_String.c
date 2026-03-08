#include <stdlib.h>
char* findDifferentBinaryString(char** nums, int numsSize) {
int* yoklama = (int*)calloc(numsSize+1,sizeof(int));
for(int i=0;i<numsSize;i++){
    int onluk_taban = 0;
    for(int j=0;j<numsSize;j++){
        if(nums[i][j]== '1'){ // Sayımız 101 olsun yani 5. 2^2 ve 2^0 da 1'lerimiz var. Ama binary sağa değil sola doğru okunuyor
            onluk_taban |= (1 << (numsSize - 1 - j)); // Bu yüzden j=0 için 2^2'yi kaydeder. j=2 için 2^0'ı kaydeder.
        }                                             // Terse göre okuyoruz yani. Soldan 0. indeks = sağdan numsSize-1-j. indeks
    }
    if(onluk_taban<= numsSize){
        yoklama[onluk_taban] = 1;
    }
}
int eksik_sayi = 0;
for(int i=0;i<=numsSize;i++){
    if(yoklama[i]==0){
        eksik_sayi = i;
        break;
    }
}
char* ans = (char*)malloc((numsSize+1)*sizeof(char));
for(int i=numsSize-1;i>=0;i--){ // Yukardaki aynı mantık ile de ters şekilde yazdıracağız (int->char). Sayımız 2 olsun. Size=3
    if(eksik_sayi%2==1){ // i=2 başladık. 2%2=0 olduğu için EN SAĞA 0 yazdık. sayı/2=1 oldu. Bu if'e girdi ve ans[1]='1' yazıldı
        ans[i] = '1';
    }else{
        ans[i] = '0';
    }
    eksik_sayi /=2;
}
ans[numsSize] = '\0'; // String kabul edilmesi için UNUTMA!
free(yoklama);        // Tutulan defteri serbest bırakalım
return ans;
}