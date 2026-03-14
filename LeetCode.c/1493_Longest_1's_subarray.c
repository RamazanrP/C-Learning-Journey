int max(int enuzun, int x){
    return (enuzun>x)?enuzun:x;
}
// 0 ve 1'lerden oluşan dizide bir 0 silinirse oluşan en uzun kopmaz 1 zinciri?
// Kayan pencere taktiği ile çözdük. sifir_sayaci 12i geçince 0'a gelene kadar alanı daraltıp her zaman en büyüğü sorguluyoruz
int longestSubarray(int* nums, int numsSize) {
int sifir_sayaci = 0, enuzun=0, baslangic=0;
for(int i=0;i<numsSize;i++){
    enuzun += nums[i];
    if(nums[i]==0) sifir_sayaci++;
    while(sifir_sayaci>1){
        if(nums[baslangic] == 0){
            sifir_sayaci--;
            break;
        }
        baslangic++;
    }
    enuzun = max(enuzun, i-baslangic);
}
return enuzun;
}