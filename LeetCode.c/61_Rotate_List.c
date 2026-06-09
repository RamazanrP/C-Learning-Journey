#include <stdio.h>
// k kere sondaki Node'u al, başa getir
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
if(head == NULL || head->next == NULL || k == 0) return head;
int sayac = 0;
struct ListNode* temp = head;
while(temp){
    temp = temp->next;
    sayac++;
}
k = k%sayac; // Modunu alınca da 0'a eşit olabilir!
if (k == 0) return head;
for(int i=0; i<k; i++){
    struct ListNode* prev_temp = head; // En sondakini başa atayınca o sondan öncekinin next'i NULL olsun diye onu da tutuyoruz
    struct ListNode* temp = head->next;
    while(temp->next){
        prev_temp = temp;
        temp = temp->next;
    }
    temp->next = head;
    prev_temp->next =  NULL;
    head = temp; // Her for ilerlemesinde doğru atamalar yapılsın diye head'i güncelledik
}
return head;
}