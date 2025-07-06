#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node* head) {
    Node* temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        else
            printf("->NULL\n");
        temp = temp->next;
    }
}
int search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target)
            return 1;
        temp = temp->next;
    }
    return 0;
}
int main(void) {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    printList(head);
    int x;
    printf("Nhap 1 so can tim: ");
    scanf("%d", &x);
    if (search(head, x))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}