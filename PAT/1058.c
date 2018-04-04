#include <stdio.h>

int main()
{
	int g1, g2, s1, s2, k1, k2;
	int g, s, k;
	g = s = 0;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	k = k1 + k2;
	if( k > 28 ){
		s++;
		k -= 29;
	}
	s += s1+s2;
	if( s > 16 ){
		g++;
		s -= 17;
	}
	g += g1+g2;
	printf("%d.%d.%d\n", g, s ,k);

	return 0;

}