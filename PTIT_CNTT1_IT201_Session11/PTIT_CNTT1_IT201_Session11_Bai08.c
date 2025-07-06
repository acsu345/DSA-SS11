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
Node* deletePosition(Node* head, int position) {
    if (head == NULL || position <= 0) {
        printf("Danh sach rong");
        return head;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }
    Node* temp = head;
    int index = 1;
    while (temp != NULL && index < position) {
        temp = temp->next;
        index++;
    }
    if (temp == NULL) {
        printf("Khong the tren vao danh sach");
        return head;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
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
    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);
    head = deletePosition(head, pos);
    printList(head);
    return 0;
}