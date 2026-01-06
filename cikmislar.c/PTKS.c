#include <stdio.h>
//p^t= tks olan tüm sayıları yazdıran kod
int main (){
int i;
int p,t,k,s,us;
for(p=0;p<=9;p++){
    for(t=1;t<=9;t++){
        us=1;
        for(i=0;i<t;i++){
            us=us*p;
        }
        if((us/100)==t){
            k= (us%100)/10;
            s= (us%100)%10;
            printf("p= %d t=%d k=%d s=%d \n", p,t,k,s);
        }
    }
}
}