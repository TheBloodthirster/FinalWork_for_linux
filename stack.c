#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>  
 
#include "include/stack.h"
int InitStack(stack *s)//s是变量名，stack *表示s只能存储stack类型的变量地址  
{  
    s->base=(elemtype *)malloc(100*sizeof(elemtype));  
    s->top=s->base;   
    s->strcksize=100;  
    return 1;  
}  

//将元素e压入栈  
int Push(stack *s,elemtype e)  
{  
    if(s->top-s->base>=s->strcksize)//栈满追加空间  
    {  
        s->base=(elemtype *)realloc(s->base,(s->strcksize+10)*sizeof(elemtype));  
        s->strcksize=s->strcksize+(s->strcksize+10);  
    }  
    if(!s->base)  
        exit(0);  
    *(s->top)=e;  
    s->top++;  
    printf("分配的存储空间为：%d\n",s->strcksize);  
    return 1;  
}  

//删除栈顶元素  
elemtype Pop(stack *s,elemtype e)  
{  
    if(s->top==s->base)  
    {  
        printf("出错！\n");  
        exit(0);  
    }  
    s->top--;  
    e=*(s->top);  
    printf("删除栈顶元素成功！\n");  
    return e;  
}  
 
//用e返回栈顶元素  
elemtype GetTop(stack *s,elemtype e)  
{  
    if(s->top==s->base)  
    {  
        printf("Error!\n");  
        exit(0);  
    }  
    s->top=s->top-1;  
    e=*(s->top);  
    s->top=s->top+1;  
    return e;  
}  
 
//返回栈的元素个数，即栈的长度  
int StackLength(stack *s)  
{  
    int length;  
    length=s->strcksize;  
    return length;  
}  
