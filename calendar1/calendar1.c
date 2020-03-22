#include<stdio.h>

#define YES 1
#define NO 0

int isLeap(int year); //윤년의 여부를 확인하는 함수

int basicyear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void){
	int year;
	int month;
	int day;
	int mtw; //1일이 시작되는 요일
	int calendar_table[12][42] = {0}; //달력 정보를 저장할 배열
	int i, j, sum;

	printf("출력할 년도를 입력하세요 : ");
	scanf("%d", &year);

	if(isLeap(year)) //입력 년도가 윤년일 경우 2월 하루 늘리기
		basicyear[1]++;
	
	sum = 0;
	//입력 년도 전까지 1년 1월 1일부터 몇일이 지났는지
	for(i = 1; i < year; i++){
		if(isLeap(i))
			sum += 366;
		else
			sum += 365;
	}

	//매 첫달의 시작 요일을 정하기 위해 정의한 변수
	mtw = (sum % 7)+1;

	//1월부터 12월까지 현재 년도의 달력정보 저장
	for(i = 0; i < 12; i++){
		day = 1;
		for(j = 0; j <= sizeof(calendar_table[i]); j++){
			if(j < mtw){}
			else if(day <= basicyear[i]){
				calendar_table[i][j] = day++;
				sum += 1;
			}
			else
				break;
		}
		mtw = (sum % 7)+1;
		//시작요일이 7이 되면 다음행의 일요일로 넘어가기에 방지용
		if(mtw == 7){mtw = 0;}
	}


	//달력 출력
	for(i=0; i<12; i++){
		printf("===========%2d월 ===========\n", i+1);
		printf("SUN MON TUE WED THR FRO SAT\n");
		for(j=0; j<42; j++){
			if((j != 0) && !(j%7)){printf("\n");}

			if(calendar_table[i][j]==0)
				printf("    " );
			else
				printf("%3d ", calendar_table[i][j]);

		}
		printf("\n");
	}


}


int isLeap(int year){
	if((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
		return YES; //윤년일 경우
	else
		return NO; //윤년이 아닐 경우
}
