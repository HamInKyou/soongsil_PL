#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//version_4
//소수를 배열에 넣고 그 소수로 소수를 찾기 위한 비교를 함
int main(void)
{
	clock_t start, end;
	float res;
	int *p;
	int n, i, x, k, Prim = 0;
	printf("소수(prime number) 몇 개를 구할까요? : ");
	scanf("%d" , &n);
	p = (int *) calloc(n, sizeof(int));

	start = clock();
	
	x = 1; 
	for(i = 1; i <= n; i++){
		do{
			if(i == 1) //맨 처음의 경우
				x = 2;
			else //맨 처음이 아닐 경우
				x += 2;
			
			Prim = 1; //x를 일단 Prim이라 하고

			for(k = 1; k < i-1; k++){ //소수들이 들어있는 배열을 검사하며 반복
				if(x % p[k] == 0){ //반복문 내에서 Prim 걸러졌을 경우
					Prim = 0; //Prim 아니라고 하고
					break; //반복 그만
				}
			}
		}while(!Prim); //소수면 그만
		printf("%d : %d\n", i, x);
		p[i]=x;
		if(i == 1) //맨 처음의 경우 출력해주고 x를 다시 1로 초기화
			x -= 1;
	}
	
	end = clock();
	res = (float)(end - start)/CLOCKS_PER_SEC;
	printf("%f s\n", res);

	return 0;
}
