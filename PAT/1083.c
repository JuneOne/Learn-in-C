#include <stdio.h>
#include <stdlib.h>

typedef struct list Grade;
struct list{
	char name[11];
	char ID[11];
	int grade;
};

int main()
{
	int i, j, N;
	Grade temp;
	Grade *record;
	int low, up;
	int cnt = 0;

	scanf("%d", &N);
	getchar();
	record = (Grade*)malloc(sizeof(Grade) * N);
	for( i = 0; i < N; i++ ){
		scanf("%s%s%d", record[i].name, record[i].ID, &record[i].grade);
	}
	scanf("%d%d", &low, &up);
	for( i = 0; i < N-1; i++ ){
		for( j = 0; j < N-1-i; j++ ){
			if( record[j].grade < record[j+1].grade ){
				temp = record[j];
				record[j] = record[j+1];
				record[j+1] = temp;
			}
		}
	}
	for( i = 0; i < N; i++ ){
		if( record[i].grade >= low && record[i].grade <= up ){
			printf("%s %s\n", record[i].name, record[i].ID);
			cnt++;
		}
	}

	if( cnt == 0 ){
		printf("NONE\n");
	}

}