#define _CRT_SECURE_NO_WARNINGS //보안 문제로 인한 오류를 방지하기 위함
#include <stdio.h>
#include <string.h> //문자열에 관한 헤더파일
#define SIZE 5  //추후에 필요시 변경이 용이하도록 사이즈로 지정, 우선 5로 지정함

typedef struct _Student
{
	char name[20];  //이름
	int number;     //학번
	double grade;   //학점
}Student; //구조체에 별칭을 지정, 전역변수

void print_student_data(Student* student, char name[20]); //함수의 원형 선언

int main()
{
	Student student[SIZE] = {           //구조체 배열의 초기화
		{"Kim", 2022001, 4.1},
		{"Lee", 2022002, 3.8},
		{"Park",2022003, 3.2},
		{"Choi", 2022004, 4.0},
		{"Jeong", 2022005, 4.5},
	};
	
	while(1)
	{
		printf("찾을 학생의 이름을 입력하세요 : ");//학생 정보를 출력하기 전 이름을 입력받기 위함
		char name[20];
		scanf("%s", name);                     //이름 입력 받음
		print_student_data(student, name);     //학생 정보를 출력하는 함수 호출
	}
}

void print_student_data(Student* student, char name[20]) //학생 정보를 출력하는 함수
{
	printf("--------(%s)학생의 정보 출력--------\n", name);
	for (int i = 0; i < SIZE; i++) 
	{
		if (strcmp(name, student[i].name) == 0) //입력 받은 name과 구조체 배열의 name이
			                                    //같은지 비교, 같으면 (이름, 학번, 학점)출력
		{
			printf("이름:%s  학번:%d  학점:%.1lf \n\n",     
				student[i].name, student[i].number, student[i].grade);
			return;
		}
	}
	printf("찾는 학생이 존재하지 않습니다.\n");  
}