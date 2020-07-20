#include "stdio.h"
#include "stdlib.h" 
typedef struct BiTreeNode{
	char data;
	struct BiTreeNode *Lchild,*Rchild;
}BTNode,*BiTree;
//���������������������
void CreateTreeDLR(BiTree *Tree){
	char ch;
	ch=getchar();
	if(ch=='?'){
		*Tree=NULL;
	}
	else{
		*Tree=(BiTree)malloc(sizeof(BTNode));
		(*Tree)->data=ch;
		CreateTreeDLR(&((*Tree)->Lchild));
		CreateTreeDLR(&((*Tree)->Rchild));
	}
}
//�������
void PreOrderTraverse(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOrderTraverse(T->Lchild);
		PreOrderTraverse(T->Rchild);
	}
}
//�������
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->Lchild);
		printf("%c",T->data);
		InOrderTraverse(T->Rchild);
	}
}
//������� 
void PostOrderTraverse(BiTree T){
	if(T){
		PostOrderTraverse(T->Lchild);
		PostOrderTraverse(T->Rchild);
		printf("%c",T->data);
	}
}
int main(){
	BiTree T=NULL;
	printf("��������Ҫ�����Ķ�������������չ���У�����ʾ�ս�㣩��");
	CreateTreeDLR(&T);
	printf("\n�������\t");
	PreOrderTraverse(T);
	printf("\n�������\t");
	InOrderTraverse(T);
	printf("\n�������\t");
	PostOrderTraverse(T);
}
