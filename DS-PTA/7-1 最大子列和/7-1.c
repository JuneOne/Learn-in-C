#include <stdio.h>

// int main()
// {
// 	int data[100000];
// 	int i, j, k;
// 	int N;
// 	int sum, max;
// 	scanf("%d", &N);
// 	for( i = 0; i < N; i++ )
// 		scanf("%d", &data[i]);
// 	max = data[0];
// 	for( i = 0; i < N; i++ ){
// 		for( j = i; j < N; j++ ){
// 			sum = 0;
// 			for( k = i; k <= j; k++ ){
// 				sum += data[k];
// 			if( sum > max )// 			}

// 				max = sum;
// 		}
// 	}
// 	printf("%d\n", max);
// }

// int main()
// {
// 	int sum[100000];
// 	int i, j;
// 	int N;
// 	int temp, max;
// 	scanf("%d", &N);
// 	for( i = 0; i < N; i++ )
// 		scanf("%d", &sum[i]);
// 	for( i = 1; i < N; i++ )
// 		sum[i] = sum[i] + sum[i-1];
// 	max = sum[0];
// 	for( i = 0; i < N; i++ ){
// 		for( j = i; j < N; j++ ){
// 			if( i == 0 )
// 				temp = sum[j];
// 			else
// 				temp = sum[j] - sum[i-1];
// 			if( temp > max )
// 				max = temp;
// 		}
// 	}
// 	printf("%d", max);
// }



//N是数组长度，num是待计算的数组，放在全局区是因为可以开很大的数组
// int N, num[16777216];

// int solve(int left, int right)
// {
//     //数列长度为1时
//     int i;
//     if(left == right)
//         return num[left];
    
//     //划分为两个规模更小的问题
//     int mid = left + right >> 1;
//     int lans = solve(left, mid);
//     int rans = solve(mid + 1, right);
    
//     //横跨分割点的情况
//     int sum = 0, lmax = num[mid], rmax = num[mid + 1];
//     for( i = mid; i >= left; i--) {
//         sum += num[i];
//         if(sum > lmax) lmax = sum;
//     }
//     sum = 0;
//     for( i = mid + 1; i <= right; i++) {
//         sum += num[i];
//         if(sum > rmax) rmax = sum;
//     }

//     //答案是三种情况的最大值
//     int ans = lmax + rmax;
//     if(lans > ans) ans = lans;
//     if(rans > ans) ans = rans;

//     return ans;
// }

// int main()
// {
//     //输入数据
//     int i;
//     scanf("%d", &N);
//     for( i = 1; i <= N; i++)
//         scanf("%d", &num[i]);

//     printf("%d\n", solve(1, N));

//     return 0;
// }

// int data[100000];

// int f( int left, int right )
// {
// 	if( left == right )
// 		return data[left];
// 	int i;
// 	int mid = ( left + right ) / 2;
// 	int lmax = f(left, mid);
// 	int rmax = f(mid+1, right);
// 	int max;

// 	int l = data[mid], r = data[mid+1], sum = 0;
// 	for( i = mid; i >= left; i-- ){
// 		sum += data[i];
// 		if( sum > l )
// 			l = sum;
// 	}
// 	sum = 0;
// 	for( i = mid+1; i <= right; i++ ){
// 		sum += data[i];
// 		if( sum > r )
// 			r = sum;
// 	}

// 	max = l + r;
// 	if( lmax > max ) {
// 		// if( rmax > lmax )
// 		// 	max = rmax;
// 		// else
// 			max = lmax;
// 	}
// 	// else{
// 		if( rmax > max )
// 			max = rmax;
// 	// }

// 	return max;
// }

// int main()
// {
// 	int i, N;
// 	scanf("%d", &N);
// 	for( i = 0; i < N; i++ )
// 		scanf("%d", &data[i]);
// 	printf("%d\n", f(0, N-1));
// }

