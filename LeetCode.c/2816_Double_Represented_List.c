#include <stdio.h>
/*Input: head = [1,8,9]
Output: [3,7,8]*/
// 189*2 = 378 (Eğer basamak sayısını geçerse yeni Node yaratabilriz)
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* doubleIt(struct ListNode* head) {
if(head->val >= 5){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = 0;
    newNode->next = head;
    head = newNode;
}
struct ListNode* temp = head;
int elde = 0;
while(temp){
    temp->val = (temp->val*2) % 10;
    if(temp->next && temp->next->val >= 5) temp->val++; // Bu satır sayesinde elde veya kalan gibi değişkenleri kullanmadan çözdük
    // Binevi geleceği görerek şimdikini arttırmak
    temp = temp->next;
}
return head;
}