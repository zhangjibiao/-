/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/10/20 00:55
	Description: 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//�˶�Ա���� 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
	int score[10];
};


//�˶���Ŀ����
struct Project
{
	char name[20];
	char site[20];
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
	int j=0; 
	
	//��ȡ��Ŀ����
	while(p[i])
	    i += 1;
	    
	while(sign)
	{
		//����һƬָ��ṹ����ڴ�ռ䣬�������ָ�룬�ṹ���ָ�������ʼ���� 
		p[i] = (struct Project *)malloc(sizeof(struct Project));		
		for(;j<100;j++)
			p[i]->athlete[j] = 0; 
			
		printf("\n<��Ŀ����>\
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
		
		sign=0;	

	}
}


//�˶�Ա�����Ǽ� 
void athlete_checkin(struct Project *p[])
{
	int sign=1;
	int i=0;
	int j=0;
	int project_num=0; //�Ѵ��ڵ���Ŀ���� 
	int num; // ���μӵ���Ŀ���� 
	int input; // �û��������� 
	 
	//��ȡ��Ŀ����,�������Ŀ���� 
	printf("\n�ѷ�������Ŀ��\n"); 
	while(p[i])
		{
			printf("%d:%10s\t",i+1,p[i]->name); 
	    	project_num += 1;
	    	i += 1; 
	    	if (i%5==0) printf("\n");
		}
	    
	
	while(sign)
	{
		struct Athlete *athlete_p;
		athlete_p = (struct Athlete *)malloc(sizeof(struct Athlete));	

		printf("\n�����˶�Ա�������Ա𡢵�λ���Կո��س��ָ���");
									
		// ���Ӽ��������ȷ�Դ��� ���ܷ����ɹ� 
		
		scanf("%s%s%s", athlete_p->name, athlete_p->gender, athlete_p->organization);
		
		printf("�����˶�Ա<%s>Ҫ�μӵ�����Ŀ������",athlete_p->name);
		scanf("%d",&num);
		printf("������Ŀ���");
		for(i=0;i<num;i++)
		{
			scanf("%d",&input);
			if (0<input && input<=project_num)
				{
					//��ȡ��ǰ��Ŀ�Ѵ����˶�Ա������ 
					while((p[input-1]->athlete[j]))
						j += 1;
					//���˶�Ա��ӵ���ǰ��Ŀ 
					p[input-1]->athlete[j]=athlete_p;
					j =0;
				}
			else printf("\n������Ŷ�Ӧ����Ŀ�����ڣ�"); 
		}
		
//		printf("\n\n���Բ�ѯ�˶�Ա��\
//		\n1:%s\
//		\n2:%s\
//		\n3:%s\
//		\n4:%s\n\n",
//		p[input-1]->athlete[0]->name,
//		p[input-1]->athlete[1]->name,
//		p[input-1]->athlete[2]->name,
//		p[input-1]->athlete[3]->name);
		
		sign=0;	

	}
	
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
	int project_num=0;
	while(p[project_num])
		project_num += 1;
	
	//����Ŀ��ʱ��˳������, ð������ 
	int i,j;
	for(i=0;i<project_num-1;i++)
	{
		order[i];
		order[j];
		for(j=i+1;j<project_num;j++)
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
	
	for(i=0;i<project_num;i++) // ���滮�����ʽ ��������� 
		{
			printf("\n��<%d>��:%s %s %2d��%2d��%.2d:",
			i+1,
			order[i]->name,
			order[i]->site,
			order[i]->month,
			order[i]->day,
			order[i]->hour);
			
			printf("%.2d:%.2d ��<%s>Ϊ�ɼ���λ ����%d�� ���%d��\n",
			order[i]->minute, 
			order[i]->second,
			order[i]->unit,
			order[i]->down,
			order[i]->up);
		}		
}

void grade_input(struct Project *p[])
{
	int i=0;
	int input;
	int project_num=0;
	
	printf("\n�ѷ�������Ŀ��\n"); 
	while(p[i])
		{
			printf("%d:%10s\t",i+1,p[i]->name); 
	    	project_num += 1;
	    	i += 1; 
	    	if (i%5==0) printf("\n");
		}
		
	printf("\n����Ҫ¼�����Ŀ��ţ�");
	scanf("%d",&input);
	if (0<input && input<=project_num)
		{
			printf("�����%d����Ŀ<%s>�ĳɼ���\
			\n�������˶�Ա�У�\n",input,p[input-1]->name);
			i = 0;
			while(p[input-1]->athlete[i])
				{
					printf("%d:%8s\t",i+1,p[input-1]->athlete[i]->name);
					i += 1;
					if (i%5==0) printf("\n");
				}
			i=0;
			printf("\n����˶�Ա�Կո��س��ָ���\n");
			while(project_num)
				{
					//�˶�Ա�ɼ��������Ŀ��Ŷ�Ӧ 
					scanf("%d",&(p[input-1]->athlete[i]->score[input-1]));
					project_num -= 1;
				}
			printf("����ɹ���\n");
				
		}
	else printf("�������Ŷ�Ӧ����Ŀ�����ڣ�\n");
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

// ����������Ϊ�����棬ʵ�ֻ�ȡ�û����벢��������Ӧ���ܡ� 
int main()
{
	int sign=1; //ѭ����־ 
	int input; //�û��������� 
	int i=0;
	
	//����ָ����Ŀ��ָ������ 
	struct Project *list[100]={0}; 
	
	while(sign)
		{
			printf("<<ѧУ�˶������ϵͳ>>\n"); 
			printf( "1. ��Ŀ����\n"
					"2. �˶�Ա�����Ǽ�\n"
					"3. ���������\n"
					"4. �ɼ�¼��\n"
					"5. �˶���ɼ���\n"
					"6. ϵͳ����\n"
					"7. ���ݱ���\n"
					"8. �˳�ϵͳ");
			printf("\n�������:"); 
			scanf("%d",&input);
			switch(input)
				{
					case 1:{project_publish(list);break;}
					case 2:{athlete_checkin(list);break;}
					case 3:{orderbook_generation(list);break;}
					case 4:{grade_input(list);break; }
					case 5:{sportsmeet_card();break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{sign=0;break;}
					default:printf("δ�ҵ����%d�����������������룡\n\n",input); 
				} 
		}

 } 
