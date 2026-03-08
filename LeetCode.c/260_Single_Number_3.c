int* singleNumber(int* nums, int numsSize, int* returnSize) {
// Dizide iki tane yalnız eleman var. Bunları bulmak için önce kabacac hepsini XOR'layıp yalnızların XOR'unu elde edeceğiz
// Mesela 3 ve 5 için 3^5=6 olacaktır. Bu 6'yı -6 ile AND'lersek sadece EN SAĞDAKİ 1 BİTİ hayatta kalır
unsigned int karmasik = 0; // 0000 0110 & 1111 1010 = 0000 0010 İşte bu sağdan 2. 1 biti 3 ve 5'i AYIRAN BİT. Buna göre gruplayacağız
for(int i=0;i<numsSize;i++){
    karmasik ^= nums[i];
}
unsigned int gosterge = karmasik & -(karmasik);
int imposterA=0,imposterB=0;
for(int i=0;i<numsSize;i++){
    if(nums[i]&gosterge){ // İlk grubumuz bu gösterge bite sahip olan imposter ve çiftler olsun (çiftler XOR'u etkilemiyecek)
        imposterA ^= nums[i];
    }else{
        imposterB ^= nums[i]; // Diğerini de bulduk. Cevap dizisine atıp döndürüyoruz
    }
}
int* ans = (int*)malloc(2*sizeof(int));
ans[0] = imposterA;
ans[1] = imposterB;
*returnSize = 2;
return ans;
}