#include <iostream>
#include <queue>
#define MAX_SIZE 100
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

// create queue
struct node** createQueue(int *front, int *rear) {
    struct node **queue = (struct node**)malloc(MAX_SIZE * sizeof(struct node*));
    *front = *rear = 0;
    return queue;
}

// Enqueue
void enqueue( struct node **queue, struct node* newnode, int *rear ) {
    queue[*rear] = newnode;
    (*rear)++;
}

// Dequeue
struct node *dequeue( struct node** queue, int *front) {
    (*front)++;
    return queue[*front -1];
}


void printBreadFirstNewLine(struct node* root) {
    int rear, front, curLevel=1, nextLevel=0;
    struct node **queue = createQueue(&front, &rear);
    struct node* temp = root;
    while ( temp ) {
        curLevel--;
        cout << temp->data;
        //add the left and right child into the tree queue
        if ( temp->left ) {
            enqueue(queue, temp->left, &rear);
	    nextLevel++;
        }
        if ( temp->right ) {
            enqueue(queue, temp->right, &rear);
	    nextLevel++;
        }
        if ( curLevel == 0 ) {
            cout<<endl;
            curLevel = nextLevel;
        }
        temp = dequeue(queue, &front);
    }
}

int main() {
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    printBreadFirstNewLine(root); 
    return 0;
}
