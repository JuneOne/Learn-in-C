#include <stdio.h>
#include <stdlib.h>

int find[10001];

struct node{
	char ID[8];
	char title[81];
	char author[81];
	char word[5][11];
	int key;
	char publish[81];
	char year[5];
}Book[10000];

int cmp( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	return strcmp(aa->ID, bb->ID);
}

int main()
{
	int k;
	int N, M;
	scanf("%d", &N);
	getchar();
	for( k = 0; k < N; k++ )
	{
		int i = 0, j = 0, cnt = 0;
		char c;
		gets(Book[k].ID);
		gets(Book[k].title);
		gets(Book[k].author);
		while( (c=getchar()) != '\n' )
		{
			if( c != ' ' ){
				Book[k].word[i][j++] = c;
			} else {
				Book[k].word[i][j] = '\0';
				j = 0;
				i++; Book[k].key++;
			}
		}
		gets(Book[k].publish);
		gets(Book[k].year);
	}
	qsort(Book, N, sizeof(Book[0]), cmp);
	// for( k = 0; k < N; k++ )
	// {
	// 	int i;
	// 	printf("%s\n%s\n%s\n", Book[k].ID, Book[k].title, Book[k].author);
	// 	for( i = 0; i < Book[k].key+1; i++ )
	// 	{
	// 		printf("%s ", Book[k].word[i]);
	// 	}
	// 	putchar('\n');
	// 	printf("%s\n%s\n", Book[k].publish, Book[k].year);
	// }

	scanf("%d", &M);
	getchar();
	while(M--)
	{
		int i, j, index, flag = 0;
		char search[100];
		scanf("%d: ", &index);
		gets(search);
		switch(index)
		{
			case 1:
				for( i = 0; i < N; i++ )
					if( strcmp(Book[i].title, search) == 0 )
						find[i] = 1;
				break;
			case 2:
				for( i = 0; i < N; i++ )
					if( strcmp(Book[i].author, search) == 0 )
						find[i] = 1;
				break;
			case 3:
				for( i = 0; i < N; i++ )
					for( j = 0; j <= Book[i].key; j++ )
						if( strcmp(Book[i].word[j], search) == 0 ){
							find[i] = 1;
							break;
						}
				break;
			case 4:
				for( i = 0; i < N; i++ )
					if( strcmp(Book[i].publish, search) == 0 )
						find[i] = 1;
				break;
			case 5:
				for( i = 0; i < N; i++ )
					if( strcmp(Book[i].year, search) == 0 )
						find[i] = 1;
				break;
		}
		printf("%d: %s\n", index, search);
		for( i = 0; i < N; i++ )
			if( find[i] == 1 ){
				printf("%s\n",Book[i].ID);
				flag = 1;
				find[i] = 0;
			}
		if( flag == 0 )
			printf("Not Found\n");
	}

	return 0;
}

