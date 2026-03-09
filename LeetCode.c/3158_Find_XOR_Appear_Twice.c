int duplicateNumbersXOR(int* nums, int numsSize) {
// Dizide bazı sayılar iki kere tekrar ediyor. Bu tekrar edenleri bulup birbiriyle XOR'la ve döndür
// Maksimum 50 sayı olduğu için:
unsigned long long gorulen = 0;
int ans = 0;
for(int i=0;i<numsSize;i++){ // 1ULL : unsigned long long yani 64-bitlik 1 sayısını sayi kadar büyüt (sayi en fazla 50 olabilirdi)
    int sayi = nums[i];
    if(gorulen & (1ULL << sayi)){ // Eğer bu bit doluysa aha ikizi bulduk. Hemen XOR'layalım. 
        ans ^= sayi;
    }else{
        gorulen |= (1ULL << sayi) ; // Sayıyı ilk defa görüyorsak da kaydedelim
    }                               
}
return ans;   
}