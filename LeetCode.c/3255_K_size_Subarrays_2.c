#include <stdio.h>
// Bu sorunun ilk hali max 500 sayılık bir dizi veriyordu, şu an 100.000 veriyor. İç içe for kuramayız!
// sayaç ile sayac == k olunca demek ki pencere tamamlandı diyeceğiz, sorun yoksa değeri, result'a yazacağız
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
*returnSize = numsSize-k+1;
int* result = malloc(sizeof(int)*(*returnSize));
int j=0, sayac = 1;
for(j=0; j< (*returnSize); j++) result[j] = -1; // Önce hepsini -1leyelim, değişiklik olursa tam noktasında değiştirelim
j=0;
for(int i=1; i<numsSize; i++){
    if(nums[i] - nums[i-1] == 1){
        sayac++; // Ardışık ise sayaç artıyor, buradaki trik sayac == değil >= çünkü sayaç=4 ama k=3 ise demek ki o zamana kadar hep ardışık, yazmaya devam 
        if(sayac >= k) result[i-k+1] = nums[i];
    }else sayac = 1;
}
return result;
}