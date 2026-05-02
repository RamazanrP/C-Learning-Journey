#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
// Baştan n. kutu ile sondan n. kutuyu buluyoruz
// Soru bizden kutuları değil içindeki value'ları değiştirmemizi istiyor. Düğüm karmaşasına girmeycez
struct ListNode* swapNodes(struct ListNode* head, int k) {
struct ListNode *first = head, *fast = head, *second = head;
for(int i=1; i<k; i++){ // Liste 1-indexed o yüzden 1'den başlattık
    first = first->next;
}
fast = first; // second ile fast arasında şu an k kadar fark var. fast'ı en sona kadar götüreceğiz
while(fast->next != NULL){
    fast = fast->next;
    second = second->next;
}
int temp = second->val;
second->val = first->val;
first->val = temp;
return head;
}