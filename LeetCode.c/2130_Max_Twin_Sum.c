#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* ReverseList(struct ListNode* head){ // 1->2->3->4 olsun curr şu an 1
    struct ListNode *prev=NULL, *then=NULL, *curr = head;
    while(curr != NULL){
        then = curr->next; // Then = 2. Ters çevireceğimiz için önce sonraki kutuyu garantiye alalım. 2. satırda curr->next değişecek
        curr->next = prev; // 1->NULL. curr, reverse'ün başlangıcı oldu
        prev = curr; // prev = 1  “curr artık ileri değil, geriye baksın”
        curr = then; // curr = 2
    }
    return prev;
}
/* 1. İterasyon                     2. İterasyon => then = 3, 2->next = 1, prev = 2, curr = 3
NULL <- 1    2 -> 3 -> 4            NULL <- 1 <- 2    3 -> 4
        prev  curr                               prev  curr
*/  // Böyle böyle ters çevrilmiş okun başı 4 olacak. NULL <- 1 <- 2 <- 3 <- 4(prev)
int pairSum(struct ListNode* head) {
struct ListNode *fast = head, *slow = head;
while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
struct ListNode* ilk_yari = head;
struct ListNode* ikinci_yari = ReverseList(slow);
int max=0,guncel;
while(ikinci_yari != NULL){
    guncel = ilk_yari->val + ikinci_yari->val;
    if(guncel > max) max = guncel;
    ilk_yari = ilk_yari->next;
    ikinci_yari = ikinci_yari->next;
}
return max;
}