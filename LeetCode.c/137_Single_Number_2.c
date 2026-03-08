int singleNumber(int* nums, int numsSize) {
// sayılar 3 kere veriliyor, sadece 1 tanesi 1 kere veriliyor. 3 kere verildiği için XOR bizi kurtarmıyor. Sum tutacağız
int ans = 0,i,j,sum;
for(i=0;i<32;i++){ // Yatay olarak 32 dikey olarak numsSize kadar bir tablo oluştuğunu düşünelim
    sum=0; // Her sütunda sum'ı sıfırlayalım
    for(j=0;j<numsSize;j++){
        if((nums[j]>>i)&1) sum++; // Sayıyı i kadar sağa kaydırıp son bite bakıyoruz. 3'lü gruplarda 0 da 1 de olsa 3'ün katı olacak
    }                             // Ama eğer imposter i kadar kaydırınca son biti 1 ise 1&1 = 1 olacak, mod != 0 olacak. 
                                  //Böylece diyeceğiz ki o bitte imposter'ın biti varmış. Ve de bunu ans'a kaydedeceğiz
    if(sum%3!=0){
        ans |= ((unsigned int)1<<i); // Biz bu fazlalığı i. sütunda bulduğumuz için ans'ın i. sütununa kadar 0001'i götürmeliyiz
    }
}
return ans;
}