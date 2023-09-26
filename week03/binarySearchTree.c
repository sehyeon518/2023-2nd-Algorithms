/*
 * binarySearchTree.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   5 3 4 5 1 2
   1 1
   5 1 2 3 4 5
 * test case output
   5 2 15 12 3 4 5 1 2 5 4 3 2 1 5 4 2 1 3 0
   1 0 1 1 1 1 1 0
   5 4 15 15 1 2 3 4 5 5 4 3 2 1 5 4 3 2 1 0 
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;           // 노드에 저장되는 정수 데이터
    struct node *left;  // 왼쪽 서브트리
    struct node *right; // 오른쪽 서브트리
};

void insert(struct node** root, int data); // 루트노드가 root 인 이진검색트리에 데이터 data 를 입력하는 함수
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);

int main() {
    struct node *root = NULL;
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int num;
        scanf("%d", &num);

        for (int n = 0; n < num; n++) {
            int r;
            scanf("%d", &r);
            insert(&root, r);
        }
        printf("%d\n", size(root));
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root); printf("\n");
        inOrder(root); printf("\n");
        postOrder(root); printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제
        if (root == NULL)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = (*root)->right = NULL;
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int size(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int height(struct node* root) {
    if (root == NULL) {
        return -1;
    }
    int lnode = height(root->left);
    int rnode = height(root->right);
    return lnode>rnode ? 1 + lnode : 1 + rnode;
}
int sumOfWeight(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
}
int maxPathWeight(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int lnode = maxPathWeight(root->left);
    int rnode = maxPathWeight(root->right);
    return lnode > rnode ? root->data + lnode : root->data + rnode;
}
void mirror(struct node** root) {
    if (*root == NULL) {
        return ;
    }

    struct node* tmp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = tmp;

    mirror(&((*root)->left));
    mirror(&((*root)->right));
}
void destruct(struct node** root) {
    if (*root == NULL) {
        return;
    }

    destruct(&((*root)->left));
    destruct(&((*root)->right));

    free(*root);
    *root = NULL;
}