#include <stdio.h>
struct ListNode {
    int val;
   struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head){ // Önce ters çevireceğiz, doğru bağlantıları yapıp tekrar ters çevireceğiz
    struct ListNode* prev = NULL;
    struct ListNode* temp;
    while(head){
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
if(head == NULL || head->next == NULL) return head;
head = reverse(head);
struct ListNode* maxNode = head; // En sondaki (şu an en baş) nod'u max atadık
struct ListNode* currnode = head->next;
while(currnode){
    if(currnode->val >= maxNode->val){
        maxNode->next = currnode;
        maxNode = currnode;
    }
    currnode = currnode->next;
}
maxNode->next = NULL; // Burada maxNode en büyüğü tutuyor, ama şu an en sonda, ters çevirip LeetCode'a teslim ediyoruz
head = reverse(head);
return head;
}