#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>  
#include "include/queue.h"
#include "include/stack.h"
#include "include/tree.h" 
int main(void)  
     { int chioce;
 printf("测试队列：1  栈：2 树：3\n");
 printf("请输入（1-3）：");
        scanf("%d",&chioce);
if(chioce==1){
         linkqueue ptr;  
         int sel;  
         int num;
		 int yes=0;  
         initqueue(&ptr);  
         while(1)  
         {  
             menu();  
             printf("please input command:\n");  
             scanf("%d",&sel);  
             switch(sel)  
             {  
             case 1:if(yes==1)  
                    {  
                        printf("此时表已创建!不能再次创建!\n");  
                        break;  
                    }  
                 else  
                     yes=creatqueue(&ptr);break;  
             case 2:if(yes==0)  
                    {  
                        printf("此时表未创建!不能入队!\n");  
                        break;  
                    }  
                 else  
                 {  
                     printf("请输入队的元素值:");  
                     scanf("%d",&num);  
                         enqueue(&ptr,num);  
                     break;  
                 }  
             case 3:if(yes==0)  
                    {  
                        printf("此时表为创建!不能出队!\n");  
                        break;  
                    }  
                 else  
                 {  
                     num=dequeue(&ptr,num);  
                     printf("目前出队的元素是%d",num);  
                     break;  
                 }  
             case 4:if(yes==0)  
                    {  
                        printf("此时链队列未创建!不能求其长度!\n");  
                        break;  
                    }  
                 lenqueue(&ptr);  
                 break;  
             case 5:if(yes==0)  
                    {  
                        printf("此时表未创建!不能判断是否为空!\n");  
                        break;  
                    }  
                 else  
                 {  
                     if(queueempty(&ptr))  
                         printf("此时队列为空队列!\n");  
                     else  
  
                         printf("此时队列为非空队列!\n");  
  
                     break;  
                 }  
             case 6:if(yes==0)  
                    {  
                        printf("此时链队列未创建!不能输出!\n");  
                        break;  
                    }  
                            disqueue(&ptr);  
                            break;  
             case 7:if(yes==0)  
                    {  
                        printf("此时链队列未创建!不能销毁!\n");  
                        break;  
                    }  
                 destroyqueue(&ptr);  
                 printf("销毁成功\n");  
                 break;  
             case 0:exit(1);  break;
             default:printf("输入命令错误!请重新输入:\n");  
                 break;  
             }
       return 1;  
         }

}
else if(chioce==2){
    int a;  
    stack s;  
    elemtype c;
    elemtype e,del;  
    e.data='T';
    if(InitStack(&s)==1)  
        printf("构造空栈成功！\n");  
    if(Push(&s,e))  
        printf("压栈成功！\n");  
    c = GetTop(&s,e);
    printf("返回的栈顶元素为:%c\n",c.data);  
    c = Pop(&s,del);
    printf("删除的栈顶元素为：%c\n",c.data);  
    printf("该栈的长度为：%d\n",a=StackLength(&s));  
      return 1;  
}
else if(chioce==3)
{
    struct BTreeNode* bt;  
    char b[50];  
    char x, *px;  
    InitBTree(&bt);  
    printf("输入二叉树广义表字符串【例子输入：A(B(C,D),E(,F(G)))】：\n");  
    scanf("%s", b);  
    CreateBTree(&bt, b);  
    PrintBTree(bt);  
    printf("\n");  
  
    printf("前序：");  
    Preorder(bt);  
    printf("\n");  
  
    printf("中序：");  
    Inorder(bt);  
    printf("\n");  
  
    printf("后序：");  
    Postorder(bt);  
    printf("\n");  
  
    printf("按层：");  
    Levelorder(bt);  
    printf("\n");  
  
    printf("输入一个待查找的字符：\n");  
    scanf(" %c", &x); //格式串中的空格可以跳过任何空白符  
    px = FindBTree(bt, x);  
    if (px)  
        printf("查找成功：%c\n", *px);  
    else  
        printf("查找失败\n");  
  
    printf("二叉树的深度为：");  
    printf("%d\n", BTreeDepth(bt));  
    ClearBTree(&bt);
    return 1;
}
     }
