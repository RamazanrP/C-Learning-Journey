// Soru bizden subarray dediği için direkt histogram ile işi bitiremiyoruz. Yeni eleman görünce geçmiş elemanları diziden atmak lazım
int maximumUniqueSubarray(int* nums, int numsSize) {
int n = numsSize;
int maxsum = 0,guncelsum=0,solind=0; // Bu solind, yeni sayı önceden var ise o yeni sayıya kadar olan hepsini silmek için var
int goruldu[10001] = {0}; // En büyük sayıya göre histogram açtık
for(int i=0;i<n;++i){
    while(goruldu[nums[i]] == 1){ // Önceden bir sayı varsa buraya girecek ve silme sürecini başlatacak,if + while'a gerek yok o yüzden
        goruldu[nums[solind]] = 0; // Eski haline getirdik
        guncelsum -= nums[solind];      // Listeden çıkardığımızı matematiksel olarak da çıkarmalıyız
        solind++; // Liste temizlenene kadar gidiyoruz
    }
    goruldu[nums[i]] = 1; // Temizlendiyse veya hiç aynı sayı yoksa 1'liyoruz
    guncelsum += nums[i];
    if(guncelsum > maxsum) maxsum = guncelsum;
}
return maxsum;
}