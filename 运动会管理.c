/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/10/20 00:55
	Description: 
*/

#define DEBUG  

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//�˶�Ա���� 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
//	struct Project *project_pointer[10];
	int score[10];
};


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
	char unit[10];	//�ɼ���λ 
	int  up; // ��������
	int down; // ��������
	int score[100]; // ��Ŀ������÷֣�score[0]��ֵ��ʾ��һ�������ٷ� ,
					// �ṹ���ڲ��ܳ�ʼ������Ҫ������ʱ��ȫ����0 
	struct Athlete *athlete[100]; //ָ������Ϊchar���˶�Աָ������  
};



// ����ģ�� 
void project_publish(struct Project *p[])
{
	int sign=1;
	int i=0;

	while(p[i])
	    i += 1;
	    
	while(sign)
	{
		struct Project project;
		p[i] = (struct Project *)malloc(sizeof(struct Project));	

		printf("1.�˶�����Ŀ����\
    		\n�����������%d����Ŀ������������(�Կո��س��ָ�):\
			\n* ��Ŀ����\
			\n* ��Ŀ����\
			\n* �����·�\
			\n* ����\
			\n* Сʱ\
			\n* ����\
			\n* ��\
			\n* �ɼ���λ\
			\n* �����������ޣ�����������Ŀ����ȡ��)\
			\n* ������������\n", i+1);
			
			scanf("%s%s%d%d%d%d%d%s%d%d",
			p[i]->name,
			p[i]->site,
			&(p[i]->month),
			&(p[i]->day),
			&(p[i]->hour),
			&(p[i]->minute), 
			&(p[i]->second),
			p[i]->unit,
			&(p[i]->down),
			&(p[i]->up));
									
			// ���Ӽ��������ȷ�Դ��� 
			
		struct Athlete athlete1;
		strcpy(athlete1.name,"��ҹ�ô������");
		
		struct Athlete athlete2;
		strcpy(athlete2.name,"��һ��");
		
		struct Athlete athlete3;
		strcpy(athlete3.name,"������");
		
		struct Athlete athlete4;
		strcpy(athlete4.name,".");
		
		p[i]->athlete[0] = &athlete1; // ��ָ��ָ���˶�Ա
		p[i]->athlete[1] = &athlete2;
		p[i]->athlete[2] = &athlete3;
		p[i]->athlete[3] = &athlete4;
		
		printf("\n\n���Բ�ѯ�˶�Ա��\
		\n1:%s\
		\n2:%s\
		\n3:%s\
		\n4:%s\n\n",
		p[i]->athlete[0]->name,
		p[i]->athlete[1]->name,
		p[i]->athlete[2]->name,
		p[i]->athlete[3]->name);
		
		sign=0;	

	}
}

void athlete_checkin()
{
	
}

//�ع������orderbook_generation������Ҫʹ�õĽ�������ָ��Ĺ��� 
void swap(struct Project **a, struct Project **b)
{
	struct Project *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void orderbook_generation(struct Project *p[])
{
	//����һ����Ŀָ������
	struct Project *order[100];
	memcpy(order,p,sizeof(struct Project *)*100);
	
	//��ȡ��Ŀ����
	int project_qua=0;
	while(p[project_qua])
		project_qua += 1;
	
	//����Ŀ��ʱ��˳������, ð������ 
	int i,j;
	for(i=0;i<project_qua-1;i++)
	{
		order[i];
		order[j];
		for(j=i+1;j<project_qua;j++)
			{
				if (order[i]->month > order[j]->month)
					swap(&order[i],&order[j]);
				else if  (order[i]->month = order[j]->month)
						if (order[i]->day > order[j]->day)
							swap(&order[i],&order[j]);
						else if (order[i]->day = order[j]->day)
							if (order[i]->hour > order[j]->hour)
								swap(&order[i],&order[j]);
							else if (order[i]->hour = order[j]->hour)
								if (order[i]->minute > order[j]->minute)
									swap(&order[i],&order[j]);
								else if (order[i]->minute = order[j]->minute)
									if (order[i]->second > order[j]->second)
										swap(&order[i],&order[j]);					
			}
	}
	
	for(i=0;i<project_qua;i++) // ���滮�����ʽ ��������� 
		{
			printf("\n��%d������\
			\n��Ŀ���ƣ�%10s\
			\n��Ŀ���أ�%10s\
			\n�����·ݣ�%10d\
			\n���ڣ�%14d\
			\nСʱ��%14d\
			\n���ӣ�%14d\
			\n�룺%16d\
			\n�ɼ���λ��%10s\
			\n�����������ޣ�%6d\
			\n�����������ޣ�%6d\n",
			i+1,
			order[i]->name,
			order[i]->site,
			order[i]->month,
			order[i]->day,
			order[i]->hour,
			order[i]->minute, 
			order[i]->second,
			order[i]->unit,
			order[i]->down,
			order[i]->up);
		}
		
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
	int sign=1; //ѭ����־ 
	int input; //�û��������� 
	int i=0;
	
	struct Project *list[100]={0};	
	
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
					case 1:{project_publish(list);break;}
					case 2:{athlete_checkin();break;}
					case 3:{orderbook_generation(list);break;}
					case 4:{grade_input();break; }
					case 5:{sportsmeet_card();break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{quit();break;}
					default:printf("δ�ҵ����%d�����������������룡\n\n",input); 
				} 
		}

 } 
