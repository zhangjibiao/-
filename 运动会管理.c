/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/10/20 00:55
	Description: 
*/

//try
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
		//p[i] = &project;
		printf("\np[%d]:%x",i,p[i]);
	
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
			 
			// ����������̫�࣬��������� 
//			scanf("%s%s%d%d%d%d%d%s%d%d",
//			project.name,
//			project.site,
//			&project.month,
//			&project.day,
//			&project.hour,
//			&project.minute, 
//			&project.second,
//			project.unit,
//			&project.down,
//			&project.up);
			
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
						
//			printf("\n��Ŀ1\
//			\n��Ŀ���ƣ�%s\
//			\n��Ŀ���أ�%s\
//			\n�����·ݣ�%d\
//			\n���ڣ�%d\
//			\nСʱ��%d\
//			\n���ӣ�%d\
//			\n�룺%d\
//			\n�ɼ���λ��%s\
//			\n�����������ޣ�%d\
//			\n�����������ޣ�%d",
//			project.name,
//			project.site,
//			project.month,
//			project.day,
//			project.hour,
//			project.minute, 
//			project.second,
//			project.unit,
//			project.down,
//			project.up);
			
			printf("\n��Ŀ1\
			\n��Ŀ���ƣ�%s\
			\n��Ŀ���أ�%s\
			\n�����·ݣ�%d\
			\n���ڣ�%d\
			\nСʱ��%d\
			\n���ӣ�%d\
			\n�룺%d\
			\n�ɼ���λ��%s\
			\n�����������ޣ�%d\
			\n�����������ޣ�%d",
			p[i]->name,
			p[i]->site,
			p[i]->month,
			p[i]->day,
			p[i]->hour,
			p[i]->minute, 
			p[i]->second,
			p[i]->unit,
			p[i]->down,
			p[i]->up);
			
		struct Athlete athlete1;
		strcpy(athlete1.name,"��ҹ�ô������");
		
		struct Athlete athlete2;
		strcpy(athlete2.name,"��һ��");
		
		struct Athlete athlete3;
		strcpy(athlete3.name,"������");
		
		struct Athlete athlete4;
		strcpy(athlete4.name,".");
				
//		project.athlete[0] = &athlete1; // ��ָ��ָ���˶�Ա
//		project.athlete[1] = &athlete2;
//		project.athlete[2] = &athlete3;
//		project.athlete[3] = &athlete4;
		
		p[i]->athlete[0] = &athlete1; // ��ָ��ָ���˶�Ա
		p[i]->athlete[1] = &athlete2;
		p[i]->athlete[2] = &athlete3;
		p[i]->athlete[3] = &athlete4;
		
//		printf("\n\n���Բ�ѯ�˶�Ա��\
//		\n1:%s\
//		\n2:%s\
//		\n3:%s\
//		\n4:%s\n\n",
//		project.athlete[0]->name,
//		project.athlete[1]->name,
//		project.athlete[2]->name,
//		project.athlete[3]->name);
		
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
		if (i==1)
		{
			printf("\n��Ŀһ���ƣ�%s",p[i]->name);
			printf("\n��Ŀ�����ƣ�%s",p[i-1]->name);
		}
				
			
		
	}
	
	
		
}

void athlete_checkin()
{
	
}

void orderbook_generation(struct Project *p[])
{
	//����һ����Ŀָ������
	struct Project *order[100];
	printf("\n1:%x",p[0]);
	printf("\n2:%x",p[1]);
	memcpy(order,p,sizeof(struct Project)*100);
	
	printf("\n1:%x",p[0]);
	printf("\n2:%x",p[1]);
	
	printf("\ncopy1:%x",order[0]);
	printf("\ncopy2:%x",order[1]);
	
	//��ȡ��Ŀ����
	int project_qua=0;
	while(!p[project_qua])
		//order[project_qua] = p[project_qua]
		printf("\nlist:%x",p[project_qua]);

		printf("\noder:%x",order[project_qua]);
		
		project_qua += 1;
	
	printf("\nproject_qua:%d",project_qua) ;	
//	//��˳��ָ�����鸳ֵ
//	int i=0;
//	while(!)
//	//����Ŀ��ʱ��˳������, ð������ 
//	int i=0,j=0;
//	if (p[i]->month > p[i+1]->month)
//		order[i] = p[i+1];
		
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
