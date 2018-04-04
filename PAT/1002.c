// #include <stdio.h>
// #include <stdlib.h>

// typedef struct LNode *PolyList
// struct LNode{
// 	int exp;
// 	double coef;
// 	PolyList next;
// };

// PolyList CreatList()
// {
// 	PolyList L = (PolyList)malloc(sizeof( struct LNode ));
// 	L->next = NULL;
// 	PolyList p, tmp;
// 	int K;
// 	scanf("%d", &K);

// 	p = L;
// 	while( K-- ){
// 		tmp = (PolyList)malloc(sizeof( struct LNode ));
// 		scanf("%d%lf", &tmp->exp, &tmp->coef);
// 	}
// }
// int main()
// {
// 	PolyList L1, L2;
// 	L1 = CreatList();
// 	L2 = CreatList();
// 	PrintList(AddList(L1, L2));

// 	return 0;
// }

#include <stdio.h>

int main()
{
	double poly[1001] = {0};
	int i, k, N = 2;
	int exp;
	double coef;
	int cnt = 0;
	while(N--){
		scanf("%d", &k);
		while(k--){
			scanf("%d%lf", &exp, &coef);
			poly[exp] += coef;
		}
	}
	
	for( i = 0; i < 1001; i++ ){
		if(poly[i] != 0)
			cnt++;
	}
	printf("%d", cnt);
	for( i = 1000; i >= 0; i-- ){
		if( poly[i] != 0 ){
			printf(" %d %.1f", i, poly[i]);
		}
	}
}