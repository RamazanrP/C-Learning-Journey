#include <stdio.h>
// Sliding Window sorusu, k-> pencere uzunluğu, o pencere büyükten küçüğe ve de ardışık ise en büyüğü sonuç arrayine yaz
// Bir şekilde bozuluyorsa -1 yazdır, sonuç arrayi numsSize-k+1 boyutunda olur, kendisi vermiş
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
*returnSize = numsSize-k+1;
int* result = (int*)malloc((*returnSize)*sizeof(int));
int i = 0, j, bozuldu, yaz=0;
while(i<=(numsSize-k)){ // Boyut da pencere de 3 olsa 3-3 = 0, while'a girmezdi, o yüzden eşitlik işareti!
    bozuldu = 1;
    for(j=i; j< i+k-1 && j< numsSize; j++){
        if(nums[j+1] - nums[j] != 1) bozuldu=0;
    }
    if(bozuldu) result[yaz] = nums[j]; // Eğer hiç bozulmadan geldiyse tam o an baktığımız sayı en büyük sayıdır
    else result[yaz] = -1;
    yaz++, i++;
}
return result;
}