#include <stdio.h>

char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
	int i;
	char c1, c2;
	int index;
	char s1[61];
	char s2[61];
	char s3[61];
	char s4[61];

	scanf("%s%s%s%s", s1, s2, s3, s4);

	for( i = 0; s1[i] != '\0' && s2[i] != '\0'; i++ ){
		if( s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' ){ // 注意是到'G'
			c1 = s1[i];
			break;
		}
	}
	for( i = i + 1; s1[i] != '\0' && s2[i] != '\0'; i++ ){
		if( s1[i] == s2[i] && ( s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' && s1[i] <= 'N') ){
			c2 = s1[i];
			break;
		}
	}
	for( i = 0; s3[i] != '\0' && s4[i] != '\0'; i++ ){
		if( s3[i] == s4[i] && ( s3[i] >= 'a' && s3[i] <= 'z' || s3[i] >= 'A' && s3[i] <= 'Z') ){
			index = i;
			break;
		}
	}

	// printf("c1=%c, c2=%c, index=%d, indexc=%c\n", c1, c2, index, s3[index]);
	printf("%s ", day[c1-'A']);
	if( c2 >= '0' && c2 <= '9' ){
		printf("0%d:", c2-'0');
	} else {
		printf("%d:", 10+c2-'A');
	}
	if( index < 10 ){
		printf("0%d", index);
	} else {
		printf("%d", index);
	}

	return 0;
}