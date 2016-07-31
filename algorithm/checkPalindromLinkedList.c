#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
    char c;
    struct node *next;
};

bool isPalinUtil(struct node **left, struct node *right) {

    if (right == NULL) {
        return true;
    }
    
    bool isPal = isPalinUtil(left, right->next);

    if ( isPal == false) {
        return false;
    }

    bool check = ((*left)->c == right->c);
    (*left) = (*left)->next;
    return check;
}

bool isPalindrom(struct node* head) {
    return isPalinUtil(&head, head);
}




void push_data(struct node **head, char c) {
    struct node *list = (struct node*)malloc(sizeof(struct node));
    list->c = c;
    list->next = *head;
    *head = list;
}

void print_node(struct node *ptr) {
     while (ptr != NULL) {
         printf("%c\n", ptr->c);
         ptr = ptr->next;
     }
}


int main() {

    struct node *linkedList = NULL;

    char s[] = "nitini";

    for (int i=0; s[i] != '\0'; i++) {
        push_data(&linkedList, s[i]);
        printf("%c",s[i]);
    }
    printf("\n");
    print_node(linkedList);
    // palindrom check
    isPalindrom(linkedList) ? printf("LinkedList is palindrom\n") : printf("LinkedList is not palindrom");
    return 0;
}
