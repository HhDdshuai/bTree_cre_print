#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef int elemType;
typedef struct b_node{
    elemType data;
    struct b_node *lchild,*rchild;
}b_node,*b_tree;
//按数组顺序创建二叉树
void createTree(b_tree *T,elemType a[],int len,int index){ //修改一个指针 要用二级指针
    if(index >= len)
        return;
    *T = (b_node *)malloc(sizeof(b_node));
    if(a[index] == -1)
        *T = NULL;
    (*T)->data = a[index];
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    createTree(&((*T)->lchild),a,len,2 * index);   //从数组a[0]开始为 2*index+1
    createTree(&((*T)->rchild),a,len,2 * index + 1);                //2*index+2
}
//先序递归遍历二叉树
void preOrder(b_tree T){
    if(T != NULL){
        printf("%d ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
int main()
{
    elemType a[] = {-999,1,2,3,4,5,6,7,8,9,10,11,12};
    b_tree T = NULL;
    int len = sizeof(a)/sizeof(elemType);
    createTree(&T,a,len,1);
    preOrder(T);
    return 0;
}
