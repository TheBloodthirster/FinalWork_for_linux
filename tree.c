#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>  
 
#include "include/tree.h"

  
//1、初始化二叉树  
void InitBTree(struct BTreeNode** BT)  
{  
    *BT = NULL; //把树根指针置空  
}  
  
//2、建立二叉树，采用广义表表示的输入法，如：A（B（C，D），E（，F（G）））  
void CreateBTree(struct BTreeNode** BT, char* string)  
{  
    struct BTreeNode* p;  
    struct BTreeNode* s[10]; //定义s数组作为存储根结点的指针的栈使用  
    int top = -1; //栈顶指针置为-1，表示空栈  
    int k; //k作为处理结点的标志，k=1处理左子树，k=2处理右子树  
    int i = 0; //用i扫描数组string中存储的二叉树广义表字符串，初值为0  
    *BT = NULL; //把树根指针置空，即从空树开始建立二叉树  
    while (string[i])  
    {  
        switch (string[i])  
        {  
            case ' ':break;  
            case '(':  
            {  
                if (top == 10 - 1)  
                {  
                    printf("栈空间太小，需增加10!\n");  
                    exit(1);  
                }  
                top++;  
                s[top] = p;  
                k = 1;  
                break;  
            }  
            case ')':  
            {  
                if (top == -1)  
                {  
                    printf("二叉树广义表字符串错！\n");  
                    exit(1);  
                }  
                top--;  
                break;  
            }  
            case ',':k = 2;break;  
            default:  
            {  
                p = malloc(sizeof(struct BTreeNode));  
                p->data = string[i];  
                p->left = p->right = NULL;  
                if (*BT == NULL)  
                    *BT = p;  
                else  
                {  
                    if (k == 1)  
                        s[top]->left = p;  
                    else  
                        s[top]->right = p;  
                }  
            }  
        }//switch end  
        i++;  
    }//while end  
}  
  
//3、检查二叉树是否为空  
int BTreeEmpty(struct BTreeNode* BT)  
{  
    if (BT == NULL)  
        return 1;  
    else  
        return 0;  
}  
  
//4、求二叉树深度  
int BTreeDepth(struct BTreeNode* BT)  
{  
    if (BT == NULL)  
        return 0;  
    else  
    {  
        int dep1 = BTreeDepth(BT->left); //计算左子树深度  
        int dep2 = BTreeDepth(BT->right);//计算右子树深度  
        if (dep1 > dep2)  
            return dep1 + 1;  
        else  
            return dep2 + 1;  
    }  
}  
  
//5、从二叉树中查找值为x的结点，若存在则返回元素存储位置，否则返回空值(算法类似于前序遍历)  
char* FindBTree(struct BTreeNode* BT, char x)  
{  
    if (BT == NULL)  
        return NULL;  
    else  
    {  
        if (BT->data == x)  
            return &(BT->data);  
        else  
        {  
            char* p;  
            if (p = FindBTree(BT->left, x))  
                return p;  
            if (p = FindBTree(BT->right, x))  
                return  p;  
            return NULL;  
        }  
    }  
}  
  
//6、输出二叉树，可在前序遍历的基础上修改。采用广义表输出格式：A（B（C，D），E（，F（G）））  
void PrintBTree(struct BTreeNode* BT)  
{  
    if (BT != NULL)  
    {  
        printf("%c", BT->data); //输出根结点的值  
        if (BT->left != NULL || BT->right != NULL)  
        {  
            printf("(");  
            PrintBTree(BT->left); //输出左子树  
            if (BT->right != NULL)  
                printf(",");  
            PrintBTree(BT->right); //输出右子树  
            printf(")");  
        }  
    }  
}  
  
//7、清除二叉树，使之变为一棵空树，算法类似于后序递归遍历  
void ClearBTree(struct BTreeNode** BT)  
{  
    if (*BT != NULL)  
    {  
        ClearBTree(&((*BT)->left));//删除左子树  
        ClearBTree(&((*BT)->right));//删除右子树  
        free(*BT);            //释放根结点  
        *BT = NULL;           //置根指针为空  
    }  
}  
  
//8、前序遍历  
void Preorder(struct BTreeNode* BT)  
{  
    if (BT != NULL)  
    {  
        printf("%c,", BT->data);  
        Preorder(BT->left);  
        Preorder(BT->right);  
    }  
}  
//9、中序遍历  
void Inorder(struct BTreeNode* BT)  
{  
    if (BT != NULL)  
    {  
        Inorder(BT->left);  
        printf("%c,", BT->data);  
        Inorder(BT->right);  
    }  
}  
//10、后序遍历  
void Postorder(struct BTreeNode* BT)  
{  
    if (BT != NULL)  
    {  
        Postorder(BT->left);  
        Postorder(BT->right);  
        printf("%c,", BT->data);  
    }  
}  
//11、按层遍历  
//按层遍历算法需要使用一个队列，开始时把整个树的根结点入队，然后每从队列中删除一个结点并输出该结点时，  
//都把它的非空的左右孩子结点入队，当队列为空时算法结束。  
//算法中，队列的最大长度不会超过二叉树中相邻两层的最大结点数，  
//所以在提前在程序开始处定义最大队列长度20大于队列的最大长度，就无需考虑队满溢出的事了  
void Levelorder(struct BTreeNode* BT)  
{  
    struct BTreeNode* p;  
    struct BTreeNode* q[20];//定义队列所使用的数组空间，元素类型为指向结点的指针类型  
    int front = 0;  
    int rear = 0;  
    if (BT != NULL)//将树根指针入队  
    {  
        q[rear] = BT;  
        rear = (rear + 1) % 20;  
    }  
    while (front != rear)//当队列非空时执行循环  
    {  
        p = q[front];//保存队首元素  
        front = (front + 1) % 20;//删除队首元素，使队首指针指向队首元素  
        printf("%c,", p->data);//输出队首元素  
        if (p->left != NULL)//若结点存在左孩子，则左孩子结点指针入队  
        {  
            q[rear] = p->left;  
            rear = (rear + 1) % 20;  
        }  
        if (p->right != NULL)//若结点存在右孩子，则左孩子结点指针入队  
        {  
            q[rear] = p->right;  
            rear = (rear + 1) % 20;  
        }  
    }  
}  
  

