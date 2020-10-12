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

//运动员定义 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
//	struct Project *project_pointer[10];
	int score[10];
};


//运动项目定义
struct Project
{
	char name[10];
	char site[10];
	int month;	// 时间也分月日小时分秒 
	int day;
	int hour;
	int minute;
	int second;
	char unit[10];	//成绩单位 
	int  up; // 人数上限
	int down; // 人数下限
	int score[100]; // 项目名次与得分，score[0]的值表示第一名积多少分 ,
					// 结构体内不能初始化，需要在输入时先全部赋0 
	struct Athlete *athlete[100]; //指向类型为char的运动员指针数组  
};



// 功能模块 
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

		printf("1.运动会项目发布\
    		\n您正在输入第%d个项目，请依次输入(以空格或回车分隔):\
			\n* 项目名称\
			\n* 项目场地\
			\n* 比赛月份\
			\n* 日期\
			\n* 小时\
			\n* 分钟\
			\n* 秒\
			\n* 成绩单位\
			\n* 参数人数下限（人数不足项目将被取消)\
			\n* 参数人数上限\n", i+1);
			
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
									
			// 增加检测输入正确性代码 
			
		struct Athlete athlete1;
		strcpy(athlete1.name,"熬夜敲代码的我");
		
		struct Athlete athlete2;
		strcpy(athlete2.name,"方一帆");
		
		struct Athlete athlete3;
		strcpy(athlete3.name,"武勇涛");
		
		struct Athlete athlete4;
		strcpy(athlete4.name,".");
		
		p[i]->athlete[0] = &athlete1; // 将指针指向运动员
		p[i]->athlete[1] = &athlete2;
		p[i]->athlete[2] = &athlete3;
		p[i]->athlete[3] = &athlete4;
		
		printf("\n\n尝试查询运动员：\
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

//重构下面的orderbook_generation函数需要使用的交换两个指针的功能 
void swap(struct Project **a, struct Project **b)
{
	struct Project *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void orderbook_generation(struct Project *p[])
{
	//复制一份项目指针数组
	struct Project *order[100];
	memcpy(order,p,sizeof(struct Project *)*100);
	
	//获取项目数量
	int project_qua=0;
	while(p[project_qua])
		project_qua += 1;
	
	//对项目按时间顺序排序, 冒泡排序 
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
	
	for(i=0;i<project_qua;i++) // 待规划输出样式 ，尽量变横 
		{
			printf("\n第%d场比赛\
			\n项目名称：%10s\
			\n项目场地：%10s\
			\n比赛月份：%10d\
			\n日期：%14d\
			\n小时：%14d\
			\n分钟：%14d\
			\n秒：%16d\
			\n成绩单位：%10s\
			\n参数人数下限：%6d\
			\n参数人数上限：%6d\n",
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

// 主函数：作为主界面，实现获取用户输入并导航至相应功能。 
int main()
{
	int sign=1; //循环标志 
	int input; //用户输入的序号 
	int i=0;
	
	struct Project *list[100]={0};	
	
	while(sign)
		{
			printf("<<学校运动会管理系统>>\n"); 
			printf("1. 参数项目发布\n"
					"2. 运动员报名登记\n"
					"3. 秩序册生成\n"
					"4. 成绩录入\n"
					"5. 运动会成绩册\n"
					"6. 系统设置\n"
					"7. 数据备份\n"
					"8. 退出系统\n");
			printf("\n输入序号以使用相应功能:"); 
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
					default:printf("未找到序号%d，输入有误，重新输入！\n\n",input); 
				} 
		}

 } 
