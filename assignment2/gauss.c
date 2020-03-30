#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

void GaussElimination(int n, double matrix[ROW][COL]);
void JordanElimination(int n, double matrix[ROW][COL]);
void InputMatrix(int n, double matrix[ROW][COL]);
void PrintMatrix(int n, double matrix[ROW][COL]);
void PrintResult(int n, double matrix[ROW][COL]);

int main(){
	double matrix[ROW][COL];
	int n = 3;

	printf("삼원연립일차방정식 프로그램입니다.\n");
	InputMatrix(n, matrix);
	PrintMatrix(n, matrix);
	GaussElimination(n, matrix);
	JordanElimination(n, matrix);
	PrintResult(n, matrix);

	return 0;
}



void GaussElimination(int n, double matrix[ROW][COL]){
	int i, j, x;

	for(i = 0; i < n; i++) //모든 행에 대해서
	{
		double temp = matrix[i][i]; //i행의 모든 원소를 피봇으로 나누어주기 위함
		double temp2; 
		
		for(j = 0; j < n+1; j++){
			matrix[i][j] = matrix[i][j]/temp; //i행의 원소들 피봇으로 나누어 피봇을 1로 만들기
		}
		if(i < n-1){ //현재 행이 마지막 행이 아닐 경우
			for(x = 1; x+i < n; x++) //그 다음 행들에 대해서
			{
				temp2 = matrix[i+x][i]; //그 다음 행들의 피봇과 동일한 열에 위치한 값을 임시저장
				for(j = 0; j < n+1; j++){ //그 행의 값들에 현재 행의 값들과 임시저장 값을 곱하여 빼준다.
					matrix[i+x][j] -= temp2*matrix[i][j]; //0을 만들기 위하여
				}
			}
		}
	
	PrintMatrix(n,matrix);
	}
}

void JordanElimination(int n, double matrix[ROW][COL]){
	int i, j;
	for(i= n-1; i > 0; i--){ //맨 끝 열부터 시작(상수열 빼고)
		double temp = matrix[i][n]; //상수값을 임시로 저장한다.
		for(j = 0; j < i; j++){ //첫행부터 피벗행 전까지
			double temp2 = matrix[j][i]; //현재 값을 임시 저장
			matrix[j][i] = 0; //현재 값을 0으로 저장해준다.
			matrix[j][n] = matrix[j][n] - temp*temp2; //0으로 바꾸기 위해 뺀 값을 상수도 빼준다.
		}
		PrintMatrix(n, matrix);
	}
}

void InputMatrix(int n, double matrix[ROW][COL]){
	int i, j, x;
	printf("[x1] [x2] [x3] [상수] 순으로 계수를 입력해주세요.\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n+1; j++){
			scanf("%d", &x);
			matrix[i][j] = x;
		}
	}
}

void PrintMatrix(int n, double matrix[ROW][COL]){
	int i, j;
	printf("\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n+1; j++){
			printf("%lf  ", matrix[i][j]);
		}
		printf("\n");
	}
}

void PrintResult(int n, double matrix[ROW][COL]){
	printf("\n삼원연립일차방정식의 결과입니다.\n");
	int i;
	for(i = 0; i < n; i++){
		printf("[x%d] = %lf\n", i+1, matrix[i][n]);
	}
}
