// Diziyi k kere ters çevirmemizi istiyor. Mesela 1,2,3,4,5 ve k=2 olsun. Dizimiz -> 4,5,1,2,3 olmalı
// 1- Önce baştan sona ters çevireceğiz -> 5,4,3,2,1
// 2- Sonra ilk k elemanı kendi arasında ters çevireceğiz -> 4,5,3,2,1
// 3- ilk k elemandan sonrasını da kendi arasında ters çevireceğiz -> 4,5,1,2,3
// 3 kere ters çevirme olduğu için yardımcı fonksiyon yazdım.
void terscevir(int* nums, int bas, int son){ 
    while(bas<son){                 // Uzunluk/2 gibi şeylerle uğraşmaya gerek yok. Başlangıç bitişten önde olsun yeter
        int gecici = nums[son];
        nums[son] = nums[bas];
        nums[bas] = gecici;
        bas++,son--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize; // k, uzunluktan büyükse boş yere dönecek !
    if(k==0) return;
    terscevir(nums,0,numsSize-1);
    terscevir(nums,0,k-1);
    terscevir(nums,k,numsSize-1);
}