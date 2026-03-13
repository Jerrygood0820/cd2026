#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char ch;         
    int count;          
    struct node *next;  
} Node;


Node* findChar(Node *head, char c) {
    Node *current = head;
    while (current != NULL) {
        if (current->ch == c) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


Node* addNode(Node *head, char c) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗\n");
        exit(1);
    }
    newNode->ch = c;
    newNode->count = 1;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main() {
    FILE *fp;
    fp = fopen("main.c", "r");

    if (fp == NULL) {
        printf("無法開啟檔案 main.c\n");
        return 1;
    }

    Node *head = NULL;
    char c;


    while ((c = fgetc(fp)) != EOF) {
        Node *found = findChar(head, c);
        if (found != NULL) {
            found->count++;
        } else {
            head = addNode(head, c);
        }
    }

    fclose(fp);
    Node *current = head;
    while (current != NULL) {
        printf("%c : %d\n", current->ch, current->count);
        current = current->next;
    }
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
