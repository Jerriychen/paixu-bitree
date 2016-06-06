//
//  main.c
//  paixu_bitree
//
//  Created by   chenzzh on 16/6/5.
//  Copyright © 2016年 chenzezhong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lson,*rson;
}*BINODE,Binode;

BINODE Insert(BINODE,BINODE);
void Preorder(BINODE root);
void Inorder(BINODE root);
void Postorder(BINODE root);


int main(int argc, const char * argv[]) {
    int n;
    BINODE root,son;
    root=son=NULL;
    printf("请输入二叉树数据:");
    scanf("%d",&n);
    while(n!=0){
        son=(BINODE)malloc(sizeof(Binode));
        son->data=n;
        son->lson=NULL;
        son->rson=NULL;
        root=Insert(root,son);
        scanf("%d",&n);
    }
    printf("先序遍历:\n");
    Preorder(root);
    printf("\n");
    
    printf("中序遍历:\n");
    Inorder(root);
    printf("\n");
    
    printf("后序遍历:\n");
    Postorder(root);
    printf("\n");
    return 0;
}



BINODE Insert(BINODE root,BINODE son)                             //排序插入结点
{
    if (root==NULL) root=son;
    else                                                          //跟为空的时候返回
    {
        if (son->data<root->data)                                 //如果小于根结点的数据
            root->lson=Insert(root->lson,son);                    //以左孩子为新的根，继续往左插入
        else if (son->data>=root->data)                           //如果大于等于根结点数据
            root->rson=Insert(root->rson,son);                    //以有孩子为新的根，往右树插入
    }
    return root;
}



void Preorder(BINODE root)
{
    if (root!=NULL)
    {
        printf("%d ",root->data);
        Preorder(root->lson);
        Preorder(root->rson);
    }
    else
        return;
}


void Inorder(BINODE root)
{
    int i=0;
    BINODE p,a[100];
    p=root;
    while (i!=0 || p!=NULL)
    {
        while (p!=NULL)
        {
            i++;
            a[i]=p;
            p=p->lson;
        }
        if (i!=0)
        {
            p=a[i];
            i--;
            printf("%d ",p->data);
            p=p->rson;
        }
    }
}

void Postorder(BINODE root)
{
    BINODE p,a[100];
    int i=0,b[100];
    p=root; a[0]=NULL;
    while (i!=0 || p!=NULL)
    {
        while (p!=NULL)
        {
            if (b[i]==2) break;
            i++;
            a[i]=p;
            b[i]=0;
            p=p->lson;
        }
        if (i!=0)
        {
            if (p==NULL)
            { b[i]++; p=a[i];}
            if (b[i]==2)
            {
                printf("%d ",p->data);
                b[i]=0;  i--;
                p=a[i]; b[i]++;
            }
            if (i==0) {p=NULL; break; }
            if (b[i]==1) p=p->rson;
        }
    }
}



