#include<stdio.h>
#include<stdlib.h>

//�˶���Ŀ����
struct Project
{
	char name[10];
	char site[10];
	int month;	// ʱ��Ҳ������Сʱ���� 
	int day;
	int hour;
	int minute;
	int second;
	int unit;	//�ɼ���λ 
	int  up; // ��������
	int down; // ��������
	int score[100]; // ��Ŀ������÷֣�score[0]��ֵ��ʾ��һ�������ٷ� ,
					// �ṹ���ڲ��ܳ�ʼ������Ҫ������ʱ��ȫ����0 
	char *athlete[100]; //ָ������Ϊchar���˶�Աָ������ ���� 
};


//�˶�Ա���� 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
	struct Project *project_pointer[10];
	int score[10];
};

// ����ģ�� 
void project_publish()
{
	
}

void athlete_checkin()
{
	
}

void orderbook_generation()
{
	
}

void grade_input()
{
	
}

void sportsmeet_card()
{
	
}

void seting()
{
	
}

void data_backup()
{
	
}

void quit()
{
	
}

// ����������Ϊ�����棬ʵ�ֻ�ȡ�û����벢��������Ӧ���ܡ� 
int main()
{
	int sign=1;
	int input;
	
	while(sign)
		{
			printf("<<ѧУ�˶������ϵͳ>>\n"); 
			printf("1. ������Ŀ����\n"
					"2. �˶�Ա�����Ǽ�\n"
					"3. ���������\n"
					"4. �ɼ�¼��\n"
					"5. �˶���ɼ���\n"
					"6. ϵͳ����\n"
					"7. ���ݱ���\n"
					"8. �˳�ϵͳ\n");
			printf("\n���������ʹ����Ӧ����:"); 
			scanf("%d",&input);
			switch(input)
				{
					case 1:{project_publish();break;}
					case 2:{athlete_checkin();break;}
					case 3:{orderbook_generation();break;}
					case 4:{grade_input();break; }
					case 5:{sportsmeet_card();break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{quit();break;}
					default:printf("\n    �������"); 
				} 
		}
		
		

 } 
