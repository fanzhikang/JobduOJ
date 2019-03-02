//
// Created by Fan Zhikang on 2019-03-02.
//

#include <stdio.h>

#include <string.h>

struct Node {
    Node *lchild;
    Node *rchild;
    int c;
} Tree[100];
int loc;

Node *creat() {
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

char str1[25], str2[25];
int size1, size2;
char *str;
int *size;

void postPrder(Node *T) {
    if (T->lchild != NULL) {
        postPrder(T->lchild);
    }
    if (T->rchild != NULL) {
        postPrder(T->rchild);
    }
    str[(*size)++] = T->c + '0';
}

void inOrder(Node *T) {
    if (T->lchild != NULL) {
        inOrder(T->lchild);
    }
    str[(*size)++] = T->c + '0';
    if (T->rchild != NULL) {
        inOrder(T->rchild);
    }
}

Node *Insert(Node *T, int x) {
    if (T == NULL) {
        T = creat();
        T->c = x;
        return T;
    } else if (T->c > x) {
        T->lchild = Insert(T->lchild, x);
    } else if (T->c < x) {
        T->rchild = Insert(T->rchild, x);
    }
    return T;
}

int main() {
    int n;
    char tmp[12];
    while (scanf("%d", &n) != EOF) {
        loc = 0;
        Node *T = NULL;
        scanf("%s", tmp);
        for (int i = 0; tmp[i] != 0; ++i) {
            T = Insert(T, tmp[i] - '0');
        }
        size1 = 0;
        str = str1;
        size = &size1;
        postPrder(T);
        inOrder(T);
        str1[size1] = 0;
        while (n-- != 0) {
            scanf("%s", tmp);
            Node *T2 = NULL;
            for (int i = 0; tmp[i] != 0; ++i) {
                T2 = Insert(T2, tmp[i] - '0');
            }
            size2 = 0;
            str = str2;
            size = &size2;
            postPrder(T2);
            inOrder(T2);
            str2[size2] = 0;
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
        }
    }
    return 0;
}
