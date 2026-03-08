int singleNonDuplicate(int* nums, int numsSize) {
// Sıralı bir dizide her eleman iki kere yazılmış. Sadece biri tek sefer yazılmış. Log n sürede bulmak amaçlanıyor
// Burada sag sol aşamasını mid'in öncesine/sonrasına bakarak yapacağız.
// Düzenli olan tarafta çift indeks ile hemen sonraki indeks AYNIDIR. Tek için de ÖNCEKİ aynıdır. Eğer değilse atama yaparız
if(numsSize == 1) return nums[0];
int sol=0,sag=numsSize-1;
int mid;
while(sol<sag){                       // While'dan çıkma şartı < çünkü sağ=sol olur ve de sağ=mid satırına girerse SONSUZ DÖNGÜ
    mid = sol + (sag-sol)/2;          // Biz emin olarak gitmiyoruz, alanı daraltıp tek çarenin == olması durumuna çekiyoruz
    if(mid%2==0){
        if(mid<numsSize-1 && nums[mid]==nums[mid+1]){ // bu sağlanıyorsa demek buraya kadar herkes çift. SAĞA GİT
        sol = mid+2;                                  // +2 yazmamızın sebebi zaten mid ile mid+1 AYNI. mid+2'ye bakmalıyız
    }else{
        sag = mid;                                    // mid-1 değil mid dedik çünkü mid'in imposter olmadığından EMİN DEĞİLİZ
    }                                                 
    }
    if(mid%2==1){
         if(mid>=1 && nums[mid]==nums[mid-1]){       // Bu sağlanıyorsa demek hala bozulmamış. SAĞA GİT
        sol = mid+1;                                 // Ama bak burada +1 dedik çünkü mid+1'deki eleman bizim yeni grubumuzun başı
    }else{
        sag = mid-1;                                // Demek ki SOLDA.Buranın trick'i şu --> İmposter ASLA TEK İNDEKSTE OLAMAZ
    }                                               // Burada if'e girerken mid'imiz tekti. Demek mid, KESİNLİKLE İMPOSTER DEĞİL
}                                                   // Bu eminlikten dolayı sağ = mid-1 diyebildik.
}
    
return nums[sol];    // nums[mid] değil de sağ veya sol dedik çünkü zaten == durumunda sağ da sol da imposter'ı gösteriyor
}