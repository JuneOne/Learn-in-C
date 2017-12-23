#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *List;
struct LNode{
	int coef;
	int exp;
	List next;
};

List CreateList()
{
	int length;
	List L, p, temp;
	scanf("%d", &length);
	if( length == 0 )
		return NULL;
	if( length != 0){
		L = (List)malloc(sizeof(struct LNode));
		scanf("%d%d", &L->coef, &L->exp);
		L->next = NULL;
		length--;
	}
	p = L;
	while( length-- )
	{
		temp = (List)malloc(sizeof(struct LNode));
		scanf("%d%d", &temp->coef, &temp->exp);
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	
	return L;
}

void print( List L )
{
	int flag = 0;
	if( L == NULL ){
		printf("0 0\n");
		return;
	}
	while( L != NULL )
	{
		if( !flag ){
			printf("%d %d", L->coef, L->exp);
			flag = 1;
		} else {
			printf(" %d %d", L->coef, L->exp);
		}
		L = L->next;
	}
	printf("\n");
}

List AddList( List L1, List L2 )
{
	// printf("L1 = "); print(L1);
	// printf("L2 = "); print(L2);
	List LAdd, p, temp;
	LAdd = (List)malloc(sizeof(struct LNode));
	LAdd->coef = 0;
	LAdd->exp = 0;
	LAdd->next = NULL;
	// if( L1 == NULL ) return L2;
	// if( L2 == NULL ) return L1;
	if( L1 && L2 ){
		if( L1->exp > L2->exp ){
			LAdd->coef = L1->coef;
			LAdd->exp = L1->exp;
			L1 = L1->next;
		} else if ( L1->exp < L2->exp ){
			LAdd->coef = L2->coef;
			LAdd->exp = L2->exp;
			L2 = L2->next;
		} else {
			LAdd->coef = L1->coef + L2->coef;
			LAdd->exp = L1->exp;
			// if( LAdd->coef == 0 )
			L1 = L1->next;
			L2 = L2->next;
		}
	}
	p = LAdd;
	while( L1 && L2 ){
		temp = (List)malloc(sizeof(struct LNode));
		temp->next = NULL;
		if( L1->exp > L2->exp ){
			temp->coef = L1->coef;
			temp->exp = L1->exp;
			L1 = L1->next;
		} else if ( L1->exp < L2->exp ){
			temp->coef = L2->coef;
			temp->exp = L2->exp;
			L2 = L2->next;
		} else {
			temp->coef = L1->coef + L2->coef;
			temp->exp = L1->exp;
			L1 = L1->next;
			L2 = L2->next;
			if( temp->coef == 0 ){
				free(temp);
				continue;
			}
		}
		p->next = temp;
		p = p->next;
	}
	while( L1 )
	{
		temp = (List)malloc(sizeof(struct LNode));
		temp->coef = L1->coef;
		temp->exp = L1->exp;
		temp->next = NULL;
		L1 = L1->next;
		p->next = temp;
		p = p->next;
	}
	while( L2 )
	{
		temp = (List)malloc(sizeof(struct LNode));
		temp->coef = L2->coef;
		temp->exp = L2->exp;
		temp->next = NULL;
		L2 = L2->next;
		p->next = temp;
		p = p->next;
	}
	if( LAdd->coef == 0 ){
		temp = LAdd;
		LAdd = LAdd->next;
		free(temp);
	}
	return LAdd;
}

List MultiplyList( List L1, List L2 )
{
	List LMul = NULL, LTmp, p, temp, q;
	if( L1 == NULL || L2 == NULL )
		return NULL;
	LTmp = (List)malloc(sizeof(struct LNode));
	LTmp->next = NULL;
	// LMul = (List)malloc(sizeof(struct LNode));
	// LMul->coef = L1->coef * L2->coef;
	// LMul->exp = L1->exp + L2->exp;
	// LMul->next = NULL;

	// p = LMul; 
	// q = L2->next;
	// while( q )
	// {
	// 	temp = (List)malloc(sizeof(struct LNode));
	// 	temp->coef = L1->coef * q->coef;
	// 	temp->exp = L1->exp + q->exp;
	// 	temp->next = NULL;
	// 	p->next = temp;
	// 	p = p->next;
	// 	q = q->next;
	// }
	// L1 = L1->next;
	while( L1 )
	{
		p = LTmp;
		q = L2;
		p->coef = L1->coef * L2->coef;
		p->exp = L1->exp + L2->exp;
		q = q->next;
		while( q )
		{
			temp = (List)malloc(sizeof(struct LNode));
			temp->coef = L1->coef * q->coef;
			temp->exp = L1->exp + q->exp;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
			q = q->next;
		}
		LMul = AddList(LMul, LTmp);
		// printf("LTmp = ");print(LTmp);
		// printf("LMul = ");print(LMul);
		L1 = L1->next;
	}
	return LMul;
}
// List f( List L )
// {
// 	List L3 = NULL;
// 	int i;
// 	for( i = 0; i < 3; i++){
// 		L3 = AddList(L3, L);
// 		print(L3);
// 	}
// 	return L3;
// }
int main()
{
	List L1, L2;
	L1 = CreateList();
	// print(L1);
	L2 = CreateList();
	// print(L2);

	print(MultiplyList(L1,L2));
	print(AddList(L1,L2));

	return 0;
}