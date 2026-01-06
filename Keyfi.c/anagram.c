#include <stdio.h>
#include <string.h>   
int main () {
char kelime1[50];
char kelime2[50];
char temp;
int denklik=0;
scanf("%s", kelime1);
int uzunluk1= strlen(kelime1);
scanf("%s", kelime2);
int uzunluk2= strlen(kelime2);
if (uzunluk1!= uzunluk2) {
    printf("Kelimeleriniz anagram degil");
    return 0;
}

for (int i=0; i<uzunluk1; i++) {
    for (int j=0; j< (uzunluk1 -1); j++) {
        if(kelime1[j]< kelime1[j+1])  {
            temp= kelime1[j]; //Kelimenin harflerini büyükten küçüğe sıraladık ve de yer değiştirirken temp tuttuk yoksa kelime j gidecekti
            kelime1[j]= kelime1[j+1]; //Büyük olan öne geçti
            kelime1[j+1]= temp; //Küçük olan geriledi ama temp ile atadık
        }
    }
}

for (int i=0; i<uzunluk2; i++) {
    for (int j=0; j< (uzunluk2 -1); j++) {
        if(kelime2[j]< kelime2[j+1])  {
            temp= kelime2[j];
            kelime2[j]= kelime2[j+1];
            kelime2[j+1]= temp;
        }
    }
}

for (int i=0; i<uzunluk1; i++) {
    if (kelime1[i]!= kelime2[i]) {
        denklik=1;
    }
}
if (denklik==0) {
    printf("Kelimeleriniz Anagram");
}
else {
    printf("Kelimeleriniz Anagram Degil");
}

}