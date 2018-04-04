#include <stdio.h>
#include <stdlib.h>

typedef struct record Record;
struct record{
	char ID_number[15];
	// char Sign_in_time[10];
	// char Sign_out_time[10];
	int Sign_in_time;
	int Sign_out_time;
};

int main()
{
	int i, M;
	char in[10];
	char out[10];
	int min_in = 0;
	int max_out = 0;
	Record* R;

	scanf("%d", &M);
	R = (Record*)malloc(sizeof(struct record)*M);
	for( i = 0; i < M; i++ ){
		// scanf("%s%s%s", R[i].ID_number, R[i].Sign_in_time, R[i].Sign_out_time);
		scanf("%s%s%s", R[i].ID_number, in, out);
		R[i].Sign_in_time = ((in[0]-'0')*10+in[1]-'0')*3600 + ((in[3]-'0')*10+in[4]-'0')*60 + ((in[6]-'0')*10+in[7]-'0');	
		R[i].Sign_out_time = ((out[0]-'0')*10+out[1]-'0')*3600 + ((out[3]-'0')*10+out[4]-'0')*60 + ((out[6]-'0')*10+out[7]-'0');
	}
	// for( i = 0; i < M; i++ ){
	// 	printf("%s %s %s\n", R[i].ID_number, R[i].Sign_in_time, R[i].Sign_out_time);
	// }
	for( i = 0; i < M; i++ ){
		if( R[i].Sign_in_time < R[min_in].Sign_in_time )
			min_in = i;
		if( R[i].Sign_out_time > R[max_out].Sign_out_time )
			max_out = i;
	}
	printf("%s %s", R[min_in].ID_number, R[max_out].ID_number);
}