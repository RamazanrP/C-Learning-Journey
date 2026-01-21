// Toplam 4 adet çarpanı olan sayıların çarpan toplamlarını istiyor (ne kadar sayı varsa, genel toplam)
int sumFourDivisors(int* nums, int numsSize) {
int Total=0,carpan;
for(int i=0;i<numsSize;++i){
    int k=1;
    int sum=0;
    int sayac = 0;
    while(k*k <= nums[i]){
        if(k*k == nums[i]){ //Tam kareleri atlamak için yukarda <= koyduk ama eşittir olursa aşağıda Total += ataması olmasın diye sayacı bozuyoruz
            sayac = 0;
            break;
        }
        if(nums[i]%k==0){
            sayac++;
            carpan = nums[i] / k; // 21 için 3'ü bulduk ama bize hem 3 hem 7 lazım. O yüzden ikisini ekliyoruz
            sum = sum + carpan + (nums[i] / carpan);
        }
        k++;
        if(sayac > 2) break;
    }
    if(sayac == 2) Total += sum;
}
return Total;    
}