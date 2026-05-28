/*
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
==> 7243 + 564 = 7807
*/
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head){
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
struct ListNode* head = NULL; // Aşağıdaki newNode oluşturuldukça bu head ilerlyor, en büyük haneye kadar ilerler
struct ListNode* r1 = reverseList(l1);
struct ListNode* r2 = reverseList(l2);
int kalan = 0, totalSum;
while(r1 || r2 || kalan != 0){ // r1 ve r2 bitse bile elimizde hala kalan varsa onu da en sona eklemeliyiz, o yüzden şart bloğunda yazdık
    totalSum = kalan; // Bir sonraki Node kalan'ın üstüne ekliyecek
    if(r1){
        totalSum += r1->val;
        r1 = r1->next;
    }
    if(r2){
        totalSum += r2->val;
        r2 = r2->next;
    }
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    kalan = totalSum / 10;
    totalSum %= 10;
    newNode->val = totalSum;
    newNode->next = head; // Yeni oluşturulan Node ile head'i bağlayalım. Birler basamağından başladık. birler bas -> NULL
    head = newNode; // Sonraki döngüde onlar -> birler olması için head'i ileri taşıdık
}
return head; // En büyük hanede kalır
}