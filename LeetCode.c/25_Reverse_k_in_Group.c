#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
struct ListNode* current = head;
int sayac = 0;
while(current != NULL && sayac < k){
    current = current->next;
    sayac++;
}
if(sayac == k){ // Yani k adet düğümü yakalamışsak bunları ters çevirelim ve de RECURSİVE şekilde çözelim, fonksiyonu yeniden çağıralım
    struct ListNode *next=NULL, *prev=NULL, *temphead=head;
    for(int i=0; i<k; i++){ // Biz zaten burada k adet düğümü bulduğumuz için NULL kontrollü bir şey yazmamıza gerek yok, sadece geri gidicez
        next = temphead->next;
        temphead->next = prev;
        prev = temphead;
        temphead = next;
    }
    if(next != NULL){ // Eğer devamı varsa
        head->next = reverseKGroup(next,k); // Önceki paketin başı, şu an sonda. O yüzden head->next dedik.
    } // rekürsif için: 1 2 3 4 & k=2 olsun. 2 1 4 3 diye çevrilmesi lazım, 1 2 ters çevrilir, 1->next = fonksiyon yazdık...
      // İşte burada 1'in next'i havada kaldı. fonksiyonun cevabını bekliyor. O nedenle return prev dedik. Oradan 4 dönecek ve 1'e bağlanacak
      // En sona kadar paketlemeler bitince en baştaki previmiz yani o zamandaki büyük reversün başı, direkt LeetCode'a döndürülecek
      return prev; // prev, ters çevrilmiş paketlemenin başı.
}
return head; // Eğer 1 2 3 4 5 olsaydı sonraki 5 için count < k olacaktı ve 23. satırda 3->next'in çağırdığı fonksiyon bu aşağıdaki return'e gelecekti
}