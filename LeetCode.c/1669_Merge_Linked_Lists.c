#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
// list1'deki a b değerleri arasını silip a-1'den sonra list2'yi yerleştirip  list1 b+1'den devam edip tamamlansın istenioyr
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
if(list1 == NULL || list2 == NULL) return NULL;
int sayac = 0;
struct ListNode* aNode = list1, *pre_aNode = NULL;
while(sayac < a){
    pre_aNode = aNode;
    aNode = aNode->next;
    sayac++;
}
struct ListNode* bNode = list1;
sayac = 0;
while(sayac <= b){
    bNode = bNode->next;
    sayac++;
}
pre_aNode->next = list2;
struct ListNode* temp = list2;
while(temp->next){
    temp = temp->next;
}
temp->next = bNode;
return list1;
}