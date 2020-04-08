#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPR_SIZE 100

typedef enum{PLUS,STAR,NUMBER,LP,RP,END} tokens;
tokens token;
char exprbuf[MAX_EXPR_SIZE];
char tokenbuf[10];
int num;
int j = 0;

void get_next_token();
int expr();
int term();
int factor();
void error();

int main(void)
{
	int result;
	printf("식을 입력해주세요 (공백없이)  > ");
	scanf("%[^\n]", exprbuf);
	get_next_token();
	result = expr();
	printf("이 식은 맞는 문법입니다.\n");
	printf("계산의 결과 : %d\n", result);
}

void get_next_token(){ //다음 토큰 읽기
	int i=0;
	tokenbuf[i++] = exprbuf[j++];
	if(tokenbuf[0] == '+'){
		token = PLUS;
	}
	else if(tokenbuf[0] == '*'){
		token = STAR;
	}
	else if(tokenbuf[0] == '('){
		token = LP;
	}
	else if(tokenbuf[0] == ')'){
		token = RP;
	}
	else if(tokenbuf[0] >= '0' && tokenbuf[0] <= '9'){ //숫자일경우 연속된 숫자 다 읽기
		while(exprbuf[i] >= '0' && exprbuf[i] <= '9'){
			tokenbuf[i++] = exprbuf[j++];
		}
		num = atoi(tokenbuf); //읽은 숫자들은 문자열이므로 int 형으로 변환
		token = NUMBER;
	}
	else if(tokenbuf[0] == 0){
		token = END;
	}
}

int expr(){
	int r = term();
	while (token == PLUS) {
		get_next_token();
		r = r + term();
	}
	return r;
}

int term(){
	int r = factor();
	while(token == STAR) {
		get_next_token();
		r = r * factor();
	}
	return r;
}

int factor(){
	int r;
	if(token == NUMBER){
		get_next_token();
		r = num;
	}
	else if (token == LP) {
		get_next_token();
		r = expr();
		if(token==RP)
			get_next_token();
		else
			error();
	}
	else
		error();
	return r;
}

void error(){
	fprintf(stderr,"error!\n");
	exit(1);
}

