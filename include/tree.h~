#ifndef TREE_H
#define TREE_H

#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h> 

struct BTreeNode  //结点类型定义  
{  
    char data;            //值域  
    struct BTreeNode* left;   //左指针域  
    struct BTreeNode* right;  //右指针域  
};

void InitBTree(struct BTreeNode** BT) ;
void CreateBTree(struct BTreeNode** BT, char* string);
int BTreeEmpty(struct BTreeNode* BT) ;
int BTreeDepth(struct BTreeNode* BT) ;
char* FindBTree(struct BTreeNode* BT, char x);
void PrintBTree(struct BTreeNode* BT)  ;
void ClearBTree(struct BTreeNode** BT) ;
void Preorder(struct BTreeNode* BT) ;
void Inorder(struct BTreeNode* BT)  ;
void Postorder(struct BTreeNode* BT)  ;
void Levelorder(struct BTreeNode* BT)  ;

#endif
