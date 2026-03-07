int longestOnes(int* nums, int numsSize, int k) {
// Bize k tane 0'ı 1'e çevirme hakkı veriliyor. En uzun 1 zincirini döndüreceğiz
// Kullanacağımız yöntem KAYAN PENCERE. Sag değişkeni i gibi ilerleyecek, ilerlerken 0'ları sayacak
//  Sayaç > k olursa sol, 0 görene kadar gelecek. Böylece sayaç=k olacak. Önceki = lenme vaktinde güncelimiz peak noktadaydı.
// Şimdi de sağ 0 görene kadar güncel büyüyecek, belki de max'ı geçecek. Max ataması hep 0 görmeyle bağlantılı.s
int max=0,sol=0,sag=0,sifir_sayaci=0,i;
for(sag=0;sag<numsSize;sag++){
    int guncel = 0;
    if(nums[sag] == 0) sifir_sayaci++;
    while(sifir_sayaci > k){
        if(nums[sol] == 0) sifir_sayaci--;
        sol++;
    }
    guncel = sag-sol+1;
    max = (guncel>max) ? guncel:max;
}
return max; 
}