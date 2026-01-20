int maxSubArray(int* nums, int numsSize) {
int n = numsSize,guncelsum=0;
int maxsum = nums[0];
for(int i=0;i<n;++i){
    guncelsum += nums[i];
    if(guncelsum > maxsum) maxsum = guncelsum; // Full negatif bir dizideki en büyüğü (mutlak en küçüğü) görmek için
    if(guncelsum<0) guncelsum = 0;             // Önce max ataması yapacaz, sonra günceli 0'a eşitleyeceğiz
} 
return maxsum;
}