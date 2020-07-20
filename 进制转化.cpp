#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack *S){
	S->base=(int *)malloc(sizeof(int)*20);
	if(!S->base){
		exit(OVERFLOW);
	}
	S->top=S->base;
	S->stacksize=20;
	return OK; 
}
int StackEmpty(SqStack S){
	if(S.base==S.top){
		return TRUE;
	}else{
		return FALSE;
	}
}
int Push(SqStack *S,int e){
	if(S->top-S->base>=S->stacksize){
		S->base=(int *)realloc(S->base,(S->stacksize+5)*sizeof(int));
		if(!S->base){
			exit(OVERFLOW);
		}
		S->top=S->base+S->stacksize;
		S->stacksize+=5;
	}
	*S->top++=e;
	return OK;
}
int GetTop(SqStack S,int *e){
	if(S.base==S.top){
		return ERROR;
	}
	*e=*(S.top-1);
	return OK;
}
int Pop(SqStack *S,int *e){
	if(S->base==S->top){
		return ERROR;
	}
	*e=*(--S->top);
	return OK;
}
int StackTraverse(SqStack *S){
	if(S->base==S->top){
		return ERROR;
	}
	int *p;
	p=S->top;
	while(p!=S->base){
		p--;
		printf("%d",*p);
	}
}
int StackLength(SqStack S){
	int i=0,*p;
	p=S.top;
	while(p!=S.base){
		i++;
		p--;
	}
	return i;
}
void DtoO(){
	int num,N;
	SqStack dto;
	InitStack(&dto);
	printf("��������Ҫת����ʮ������:");
	scanf("%d",&num);
	N=num;
	while(N){
		Push(&dto,N%8);
		N/=8;
	}
	printf("%dת��Ϊ�˽���Ϊ:",num);
	while(!StackEmpty(dto)){
		int e;
		Pop(&dto,&e);
		printf("%d",e);
	}
	printf("\n");
}
void ft(int e){
	char ch[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	printf("%c",ch[e]);
}
void DtoH(){
	int num,N;
	SqStack dth;
	InitStack(&dth);
	printf("��������Ҫת����ʮ������:");
	scanf("%d",&num);
	N=num;
	while(N){
		Push(&dth,N%16);
		N/=16;
	}
	printf("%dת��Ϊʮ������Ϊ:",num);
	while(!StackEmpty(dth)){
		int e;
		Pop(&dth,&e);
		ft(e);
	}
	printf("\n");
}
void DtoB(){
	int num,N;
	SqStack dtb;
	InitStack(&dtb);
	printf("��������Ҫת����ʮ������:");
	scanf("%d",&num);
	N=num;
	while(N){
		Push(&dtb,N%2);
		N/=2;
	}
	printf("%dת��Ϊ������Ϊ:",num);
	while(!StackEmpty(dtb)){
		int e;
		Pop(&dtb,&e);
		printf("%d",e);
	}
	printf("\n");
}
int main(){
	int choice=0;
	while(1){
		printf("����1����ʮ������ת��Ϊ������\n");
		printf("����2����ʮ������ת��Ϊ�˽���\n");
		printf("����3����ʮ������ת��Ϊʮ������\n");
		printf("����4��������\n");
		printf("��������Ҫ�����Ķ���:");
		scanf("%d", &choice);
		if (choice < 1 || choice > 4) {
			printf("������������, ����������\n");
			continue;
		}
		int flag=0;
		switch(choice){
			case 1:DtoB();break;
			case 2:DtoO();break;
			case 3:DtoH();break;
			case 4:flag=1;break;
		}
		if(flag){
			break;
		}
	}
	return 0;
} 
