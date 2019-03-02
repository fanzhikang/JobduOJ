//
// Created by Fan Zhikang on 2019-03-02.
//

#include <stdio.h>

int buf[101];
struct Node {
    Node *lchild;
    Node *rchild;
    int c;
} Tree[101];
int loc;

Node *creat() {
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void postOrder(Node *tree) {
    if (tree->lchild != NULL) {
        postOrder(tree->lchild);
    }
    if (tree->rchild != NULL) {
        postOrder(tree->rchild);
    }
    printf("%d ", tree->c);
}

void inOrder(Node *T) {
    if (T->lchild != NULL) {
        inOrder(T->lchild);
    }
    printf("%d ", T->c);
    if (T->rchild != NULL) {
        inOrder(T->rchild);
    }
}

void preOrder(Node *T) {
    printf("%d ", T->c);
    if (T->lchild != NULL) {
        preOrder(T->lchild);
    }
    if (T->rchild != NULL) {
        preOrder(T->rchild);
    }
}

Node *Insert(Node *T, int x) {
    if (T == NULL) {
        T = creat();
        T->c = x;
        return T;
    } else if (x > T->c) {
        T->rchild = Insert(T->rchild, x);
    } else if (x < T->c) {
        T->lchild = Insert(T->lchild, x);
    }
    return T;
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int loc = 0;
        Node *T = NULL;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            T = Insert(T, x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}