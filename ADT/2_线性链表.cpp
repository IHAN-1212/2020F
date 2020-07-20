#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW_ -2

typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType date;
	struct LNode *next;
}LNode,*LinkList;


void CreateList_before(LNode* L, int len) {
	int i;
	LNode* p;
	printf("����\n");
	for (i = len; i > 0; i--) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_after(LNode* L, int len) {
	int i;
	LNode* p,*q;
	q=L;
	printf("����\n");
	for (i = len; i > 0; i--) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next=NULL;
		q->next=p;
		q=p;
	}
}

Status InitList_L(LNode* L){
	L=(LNode*)malloc(sizeof(LNode));
	if(!L){
		return ERROR;
	}
	L->next=NULL;
	return OK;
}

Status DestroyList_L(LNode *L){
	LNode* p;
    while (L->next) {
        p=L->next;
		L->next=p->next;
		free(p);  
    }
    free(L);
    return OK;
}

Status ClearList_L(LNode* L) {
	LinkList q, p;
	p = L->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return OK;
} 

ListEmpty_L(LNode L){
	if(L.next==NULL){
		return TRUE;
	}else{
		return FALSE;
	}
}

int ListLength(LNode L){
	int len=0;
	LNode *p;
	p=L.next;
	while(p){
		++len;
		p=p->next;
	}
	return len;
}

Status GetElem_L(LNode L,int i,ElemType *e){
	LNode *p;
	p=L.next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i){
		return 0;
	}else{
		*e=p->data;
		return 1;
	}	
}
 // �������е�i �����֮ǰ�����µ�Ԫ�� e
Status ListInsert_L(LNode* L,int i,ElemType e){
	LNode *p,*s;
	p=L->next;
	int j=1;
	while(p&&j<i-1){
		p=p->next;
		++j;
	}
	if(!p||j>i){
		return 0;
	}else{
		s=(LNode *)malloc(sizeof(LNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return 1;
	}
} 
// ɾ���� L Ϊͷָ��(��ͷ���)�ĵ������е� i �����
Status ListDelete_L(LNode* L,int i,ElemType* e){
	LNode *p,*q;
	p=L;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1){
		return 0;
	}else{
		q=p->next;
		p->next=q->next;
		*e=q->data;
		free(q);
		return 1;
	}
}

Status ListTraverse_L(LNode L) {
	LNode* q;
	q = L.next;
	if (L.next == NULL) {
		printf("NULL\n");
	}else{
		printf("���\n");
		while (1) {
			if (q != NULL) {
				printf("%d ", q->data);
				q = q->next;
			}
			else {
				break;
			}
		}
	}
	return OK;
}
