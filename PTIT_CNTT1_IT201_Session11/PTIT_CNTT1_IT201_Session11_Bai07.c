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
Node* insertPosition(Node* head, int value, int position) {
    if (position <= 0) {
        printf("Vị trí không hợp lệ!\n");
        return head;
    }
    if (position == 1) {
        Node* newNode = createNode(value);
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    int index = 1;
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }
    if (temp == NULL) {
        printf("Khong the tren vao lien ket");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
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
    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them: ");
    scanf("%d", &position);
    head = insertPosition(head, value, position);
    printList(head);
    return 0;
}