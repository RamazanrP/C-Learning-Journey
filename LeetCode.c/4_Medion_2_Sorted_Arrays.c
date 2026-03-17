// Soru bizden log(m+n) sürede iki diziyi de ortadan ayıracak. Sağdaki herkesi soldan >= yapacak değeri döndürmemizi istiyor
// Her değere dokunmadan dizilerin yarısını atarak (Binary Search ile yapacağız)
// Dizi1'in sol en büyüğü dizi1'in sağ en küçüğünden küçük olduğu gibi DİZİ2'NİN DE sağ en küçüğünden KÜÇÜK OLMALI. Bunu çapraz şekilde sorgulayacağız
// Dizilerin tek veya çift olması bize EN SONDA, return'de gerekli. Şimdilik (m+n+1)/2 diyip mükemmel yeri bulana kadar Bin. S. yapacağız
#include <limits.h>
int max(int a,int b) {return (a>b) ? a:b;}
int min(int a, int b) {return(a<b) ? a:b;}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
int m=nums1Size,n=nums2Size; 
if(m>n){ // Soruda medyan için i ve medyan-i kullanacağımız için kısa olana göre hareket etmeliyiz. Yoksa medyan-i değeri kısa dizide bulunmaz
    return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
} 
int sol=0,sag=m;
while(sol<=sag){
    int ayrim_1 = (sag+sol)/2; // Her döngü başında kısa dizi için mükemmel çizgiyi arıyoruz
    int ayrim_2 = (m+n+1)/2 - ayrim_1; // m+n+1/2 bizim toplam KÜÇÜKLER KAPASİTEMİZ, bu yüzden geri kalan küçükler kısmunu uzun diziden alıyoruz
    int maxsol1 = (ayrim_1 == 0) ? INT_MIN:nums1[ayrim_1-1]; // Sol taraf boşta kalıyorsa sağdaki elemandan KESİNLİKLE KÜÇÜK olması için dedik
    int minsag1 = (ayrim_1 == m) ? INT_MAX:nums1[ayrim_1]; // Sağ tarafa eleman kalmadıysa soldaki HERKESTEN BÜYÜK olması için dedik
    int maxsol2 = (ayrim_2 == 0) ? INT_MIN:nums2[ayrim_2-1];
    int minsag2 = (ayrim_2 == n) ? INT_MAX:nums2[ayrim_2];
    if(maxsol1 <= minsag2 && maxsol2 <= minsag1) {
        if((m+n) %2 == 0){ // Eleman sayısı çift ise soldaki en büyük ve sağdaki en küçük lazım
            return (max(maxsol1,maxsol2) + min(minsag1,minsag2)) / 2.0;
        }else { // Eleman sayısı tek ise m+n+1 ÇİFT olacaktır. BU çiftlik FAZLALIK ile sağlanır. Biz de o fazlalığı medyan seçeceğiz
                // 1 3 5 7 10 15 20 dersek 1 3 5 7 küçükler kulübünde olur. En büyüğü seçersek 7 gelecektir. 7+1 / 2 = 4. eleman
            return max(maxsol1,maxsol2);
        }
    }else if(maxsol1 > minsag2) sag = ayrim_1-1; // Çok fazla sağa çekilmiş SOLA GİT
    else sol = ayrim_1+1; 
} 
return 0.0;  
}