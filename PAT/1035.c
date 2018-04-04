#include <stdio.h>
#include <stdlib.h>

typedef struct infor Infor;
struct infor
{
	char name[11];
	char password[11];
	int ismodify;
};

int main(){
	int i, j, N;
	int cnt = 0;
	Infor *user;

	scanf("%d", &N);
	user = (Infor*)malloc(sizeof(struct infor) * N);
	for( i = 0; i < N; i++)
	{
		scanf("%s%s", user[i].name, user[i].password);
		// printf("i=%d", i);
		user[i].ismodify = 0;
	}
	for( i = 0; i < N; i++ ){
		// printf("%s %s", user[i].name, user[i].password);
		for( j = 0; user[i].password[j] != '\0'; j++ ){
			if( user[i].password[j] == '1' ){
				user[i].password[j] = '@';
				user[i].ismodify = 1;				
			}
			if( user[i].password[j] == '0' ){
				user[i].password[j] = '%';
				user[i].ismodify = 1;
			}
			if( user[i].password[j] == 'l' ){
				user[i].password[j] = 'L';
				user[i].ismodify = 1;
			}
			if( user[i].password[j] == 'O' ){
				user[i].password[j] = 'o';
				user[i].ismodify = 1;
			}
		}
		if( user[i].ismodify == 1 )
			cnt++;
	}

	if( cnt > 0 ){
		printf("%d\n", cnt);
		for( i = 0; i < N; i++ ){
			if( user[i].ismodify == 1 )
				printf("%s %s\n", user[i].name, user[i].password);
		}
	} else {
		if( N == 1 )
			printf("There is 1 account and no account is modified\n");
		if( N > 1 )
			printf("There are %d accounts and no account is modified\n", N);
	}

	return 0;
	
}