import java.util.Scanner;
public class Gauss {

    public static int n;
    public static double [][] matrix;

    public static void main(String args[]) {
        matrix = new double[3][4]; //식을 저장할 수 있게 이차원 배열 생성
        n = 3; //삼원연립 방정식으로 풀기 위함

        System.out.println("삼원연립일차방정식 프로그램입니다.");
        InputMatrix();
        PrintMatrix();
        GaussElimination();
        JordanElimination();
        PrintResult();

    }

    public static void GaussElimination(){
        for(int i = 0; i < n; i++) { //모든 행에 대해서
            double temp = matrix[i][i]; //i행의 모든 원소를 피봇으로 나누어주기 위함
            double temp2;

            for(int j = 0; j < n+1; j++){
                matrix[i][j] = matrix[i][j]/temp; //i행의 원소들 피봇으로 나누어 피봇을 1로 만들기
            }
            if(i < n-1) { //현재 행이 마지막 행이 아닐 경우
                for(int x = 1; x+i < n; x++){ //그 다음 행들에 대해서
                    temp2 = matrix[i+x][i]; //그 다음 행들의 피봇과 동일한 열에 위치한 값을 임시저장
                    for(int j = 0; j < n+1; j++){ //그 행의 값들에 현재 행의 값들과 임시저장 값을 곱하여 빼준다.
                        matrix[i+x][j] -= temp2*matrix[i][j]; //0을 만들기 위하여
                    }
                }
            }
            PrintMatrix();
        }
    }

    public static void JordanElimination(){
        for(int i = n-1; i > 0; i--){ //맨 끝 열부터 시작(상수열 빼고)
            double temp = matrix[i][n]; //상수값을 임시로 저장한다.
            for(int j = 0; j < i; j++){ //첫행부터 피봇행 전까지
                double temp2 = matrix[j][i]; //현재 값을 임시 저장
                matrix[j][i] = 0; //현재 값을 0으로 저장해준다.
                matrix[j][n] = matrix[j][n] - temp*temp2; //0으로 바꾸기 위해 뺀 값을 상수도 빼준다.
            }
            PrintMatrix();
        }
    }

    public static void InputMatrix(){
        Scanner scanner = new Scanner(System.in);

        System.out.println("[x1] [x2] [x3] [상수] 순으로 계수를 입력해주세요.");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n+1; j++){
                matrix[i][j] = (double)scanner.nextInt();
            }
        }
    }

    public static void PrintMatrix(){
        System.out.println();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n+1; j++){
                System.out.print(String.format("%.3f",matrix[i][j])+"  ");
            }
            System.out.println();
        }
    }

    public static void PrintResult(){
        System.out.println("\n삼원연립일차방정식의 결과입니다.");
        for (int i = 0; i < n; i++){
            System.out.println("[x" + (i+1) + "] = " + String.format("%.3f",matrix[i][n]));
        }
    }
}
