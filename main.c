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


#include"structure.h"
#include"swap.h"
#include"project_publish.h"
#include"athlete_checkin.h"
#include"orderbook_generation.h"
#include"grade_input.h"
#include"seting.h"
#include"data_backup.h"


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
					case 5:{sportsmeet_card(list);break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{sign=0;break;}
					default:printf("δ�ҵ����%d�����������������룡\n\n",input); 
				} 
		}

 } 
 
//�������̫�����ˣ�Ӧ����ȫ�ֱ��� 
