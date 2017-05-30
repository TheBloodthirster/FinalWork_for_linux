#ifndef STACK_H
#define STACK_H

#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h> 
typedef struct SElemType  
{  
    char data;  
}elemtype;  

typedef struct SqStack  
{  
    elemtype *base;//base是变量名字，elemtype *表示base只能存储elemtype类型的变量的地址//int *表示存储整型变量地址  
    elemtype *top;//top是变量名字，elemtype *表示top只能存储elemtype类型的变量的地址,指针就是地址，地址就是指针！  
    int strcksize;  
}stack,*pstack;
    int Push(stack *s,elemtype e);  
    int InitStack(stack *s);  
    elemtype Pop(stack *s,elemtype e);  
    elemtype GetTop(stack *s,elemtype e);  
    int StackLength(stack *s);    

#endif
