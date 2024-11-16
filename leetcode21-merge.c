#include <stdio.h>
#include <stdlib.h>

struct ListNode* mergeTwoList(struct ListNode*, struct ListNode*);

struct ListNode{
  int val;
  struct ListNode *next;
};


struct ListNode* createNode(int value){
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}


int main(){
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    struct ListNode* head2 = createNode(1);
    head2->next = createNode(4);
    head2->next->next = createNode(5);
    head2->next->next->next = createNode(6);
    mergeTwoList(head, head2);
}


struct ListNode* mergeTwoList(struct ListNode* list1, struct ListNode* list2){
    struct ListNode dummy; //why do i need a dummy 
    struct ListNode* tail = &dummy; 
    dummy.next = NULL;
    while (list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
            tail->next = list1; //tail -> next = list1;
            list1 = list1->next;
        }
        else if (list1->val > list2->val){
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail -> next;
    }
    while (list1 != NULL){
        tail -> next = list1;
        list1 = list1 -> next;
        tail = tail->next;
    }   
    while (list2 != NULL){
        tail -> next = list2;
        list2 = list2 -> next;
        tail = tail->next;
    }
    return dummy.next;
}
