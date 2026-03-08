#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char ch;
    int count;
    struct node *next;
} Node;

Node* find(Node *head, char c) {
    Node *temp = head;
    
    while (temp != NULL) {
        if (temp->ch == c) {
            return temp;
        }
        temp = temp->next;
    }
    
    return NULL;
}

Node* addNode(Node *head, char c) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    
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
        printf("Cannot open file\n");
        return 1;
    }

    Node *head = NULL;

    char c;

    while ((c = fgetc(fp)) != EOF) {

        Node *found = find(head, c);

        if (found != NULL) {
            found->count++;
        }
        else {
            head = addNode(head, c);
        }
    }

    fclose(fp);

    Node *temp = head;

    while (temp != NULL) {

        printf("%c : %d\n", temp->ch, temp->count);

        temp = temp->next;
    }

    return 0;
}
