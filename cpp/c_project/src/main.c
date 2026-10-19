#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node và khai báo tên tắt là Node bằng typedef
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Hàm khởi tạo node mới
Node* nodeInit(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho\n");
        return NULL;
    }

    newNode->data = value; // Sửa 'value' thành 'data' và gán giá trị
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm vào đầu danh sách
void insertBeginning(Node** head, int value) {
    Node* newNode = nodeInit(value); // Sửa lỗi cú pháp -= thành =
    newNode->next = *head;
    *head = newNode; // Sửa lại cách gán head mới
}

// Hàm thêm vào cuối danh sách
void insertEnding(Node** head, int value) {
    Node* newNode = nodeInit(value); // Khởi tạo node mới cho hàm insertEnding

    if (*head == NULL) {
        *head = newNode; // Nếu danh sách rỗng thì node mới là head
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode; // Gắn node mới vào cuối
}

// Hàm in danh sách
void printValue(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertBeginning(&head, 10); // Danh sách: 10 -> NULL
    insertBeginning(&head, 9);  // Danh sách: 9 -> 10 -> NULL
    insertEnding(&head, 11);    // Danh sách: 9 -> 10 -> 11 -> NULL

    printValue(head);

    return 0;
}
