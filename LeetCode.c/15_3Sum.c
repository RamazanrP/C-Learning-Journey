#include <stdlib.h>
int sirala(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // a-b negatifse yer değiştirmiyor, pozitifse demek a büyük diyor, ileri taşıyor
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
qsort(nums, numsSize, sizeof(int), sirala);
int** result = (int**)malloc(3000*sizeof(int*));
int returnColumnSizes = (int*)malloc(3000*sizeof(int));
int returnSize = 0;
int i,sol,sag,sayac=0;
for(i=0;i<numsSize-2;++i){
    sol=i+1,sag=numsSize-1;
    while(nums[i] != nums[i+1] && sol < sag){
        if(nums[i]+nums[sol]+nums[sag] > 0) sag--;
        else if(nums[i]+nums[sol]+nums[sag] < 0) sol++;
        else{
            result[sayac] = (int*)malloc(3*sizeof(int)); // 3 tane sütun açtık
            result[sayac][0] = nums[i];
            result[sayac][1] = nums[sol];
            result[sayac][2] = nums[sag];
            (*returnColumnSizes)[sayac] = 3;
            sayac++; // Satır arttı
            while(sol < sag && nums[sol] == nums[sol+1]) sol++; // Art arda hep aynı sayı varsa aynıları geçelim
            while(sol<sag && nums[sag] == nums[sag-1]) sag--;   // Aynı olmayan indis olunca en son aynı'da i çıkar
            sol++,sag--;                                        // Bir kere daha artınca bu sefer farklı olanı çekmiş oluyoruz
        }
    }
}
*returnSize = sayac;
return result;
}