// Bölme işlemi yasak
// Her bir nums[i] için sağa ayrı sola ayrı gitmek yerine yığın gibi üzerine ekleme ile çözeceğiz.
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
int n = numsSize;
int* answer = (int*)malloc(n*sizeof(int)); // Direkt answer[n] diyemiyoruz
answer[0]=1;
for(int i=1;i<n;++i){ // 1'den başlattık, answer'ı dolduruyoruz.
    answer[i] = answer[i-1]*nums[i-1];
}
int sagcarpim=1;
for(int i=n-1;i>=0;--i){ //Zaten şu an sol çarpımlar üzerine yazılı, direkt sağdan gelen ile çarparsak dizi tamamlanmış olur
    answer[i] = answer[i]*sagcarpim;
    sagcarpim*=nums[i]; // Sağ çarpım giderek büyüyor
}
*returnSize = n;
return answer;
}