#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
// Sondan n. kutuyu silmemizi istiyor ama bunda risk çok. Önde giden pointer NULL olabilir veya sondan n. baştan 1. olabilir!
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
struct ListNode dummy; // Başu tutması için dummy oluşturup pointerları bundan başlatacağız
dummy.next = head;
struct ListNode *arkada = &dummy, *onde = &dummy;
for(int i=0; i< n+1; i++){ // Mantığımız iki pointer arasında n+1 tane kutu farkı olursa arkadaki tam da silinmesi gerekenin bir arkasında duracak
    onde = onde->next;
}
while(onde){
    onde = onde->next;
    arkada = arkada->next;
}
struct ListNode* silinecek = arkada->next;
arkada->next = arkada->next->next; // Aradaki kutuyu sildik
free (silinecek);
return dummy.next;    
}