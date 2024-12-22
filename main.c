#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head->next == NULL) {
        head = NULL;
        return head;
    }
    struct ListNode* temp = head;
    struct ListNode* temp1 = temp;

    while (temp1->next != NULL) {
        temp1 = temp;
        
        for (int i = 0; i < n; i++) {
            temp1 = temp1->next;
        }

        if (temp1 == NULL) {
            head = temp->next;
            return head;
        }

        if (temp1->next != NULL) {
            temp = temp->next;
        } else {
            temp->next = temp->next->next;
        }
    }
    return head;
}

int main() {
    // Test the removeNthFromEnd function
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    struct ListNode* newHead = removeNthFromEnd(head, 2);

    // Output the modified linked list
    struct ListNode* current = newHead;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }

    return 0;
}