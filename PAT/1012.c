#include <stdio.h>
#include <stdlib.h>

struct node{
	int ID;
	int score[4];
	int rank[4];
}Stu[2000];

int flag;

int cmp( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	return (aa->score[flag] < bb->score[flag]);
}

int main()
{
	int i, N, M;
	scanf("%d%d", &N, &M);
	for( i = 0; i < N; i++ )
	{
		scanf("%d%d%d%d", &Stu[i].ID, &Stu[i].score[1], &Stu[i].score[2], &Stu[i].score[3]);
		Stu[i].score[0] = (int)((Stu[i].score[1]+Stu[i].score[2]+Stu[i].score[3]) / 3.0 + 0.5);
	}

	for( flag = 0; flag < 4; flag++ )
	{
		qsort(Stu, N, sizeof(Stu[0]), cmp);
		Stu[0].rank[flag] = 1;
		for( i = 1; i < N; i++ )
		{
			Stu[i].rank[flag] = i + 1;
			if( Stu[i].score[flag] == Stu[i-1].score[flag] )
				Stu[i].rank[flag]--;
		}
		// for( i = 0; i < N; i++ )
		// {
		// 	printf("%d rank = %d %d %d %d\n", Stu[i].ID, Stu[i].rank[0], Stu[i].rank[1], Stu[i].rank[2], Stu[i].rank[3]);
		// }
	}
	char c[4] = {'A', 'C', 'M', 'E'};
	for( i = 0; i < M; i++ )
	{
		int j, k;
		int sid, flag = 0, best = 0;
		scanf("%d", &sid);
		for( j = 0; j < N; j++ )
		{
			if( Stu[j].ID == sid ){
				flag = 1;
				for( k = 1; k < 4; k++ ){
					if( Stu[j].rank[k] < Stu[j].rank[best] )
						best = k;
				}
				printf("%d %c\n", Stu[j].rank[best], c[best]);
				break;
			}
		}
		if( flag == 0 )
			printf("N/A\n");
	}

}

