int climbStairs(int n) {
if(n<=2) return n;
int biradim=1,ikiadim=2,Totalstep; // Fibonacci mantığı ile ilerleyeceğiz. birer ikişer adım atlamak yerine atama yapacağız
for(int i=3;i<=n;++i){
    Totalstep = biradim + ikiadim; //Bulunan yere gelme yolları bir ve iki adımların toplam gelme yollarıdır.
    biradim = ikiadim;
    ikiadim = Totalstep;
}
return Totalstep;
}