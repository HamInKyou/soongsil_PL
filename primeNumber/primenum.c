#include <stdio.h>
#include <time.h>

int main(void)
{
	clock_t start, end;
	float res;
	int n, i, x, k, Prim = 0;
	printf("소수(prime number) 몇 개를 구할까요? : ");
	scanf("%d" , &n);

	start = clock();
	
	x = 1; 
	for( i = 1; i <= n; i++){
		do{
			x++;
			Prim = 1; //x를 일단 Prim이라 하고

			for(k = 2; k <= x/2; k++){
				if(x % k == 0){ //반복문 내에서 Prim 걸러졌을 경우
					Prim = 0; //Prim 아니라고 하고
					break; //반복 그만
				}
			}
		}while(!Prim);
		printf("%d : %d\n", i, x);
	}
	
	end = clock();
	res = (float)(end - start)/CLOCKS_PER_SEC;
	printf("%f s\n", res);

	return 0;
}
