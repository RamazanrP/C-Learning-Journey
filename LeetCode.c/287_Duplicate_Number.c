int findDuplicate(int* nums, int numsSize) {
int slow=0,fast=0;
do{
    slow = nums[slow]; //Burada slow veya fast artmıyor, gittiği index onu zıplatıyor ileriye
    fast = nums[nums[fast]];
}while(slow != fast);
slow = 0; // Matematiksel olarak tekrar eden sayıyı bulmak için yavaşı başa çekip hızlıyı normal yerinden devam ettirmeliyiz
while(slow !=  fast){ // Çünkü işleme döküldüğünde (fast = *slow'un katettiği yol) slow bir kere eski değerine gelince fast de eski tekrarına dönecek ve eşitlenecek
    slow = nums[slow];
    fast = nums[fast]; // İkisi de birer birer zıplıyor!
}
return fast;
}