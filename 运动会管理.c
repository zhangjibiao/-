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

//运动员定义 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
	int score[10];
};


//运动项目定义
struct Project
{
	char name[20];
	char site[20];
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
	int j=0; 
	
	//获取项目数量
	while(p[i])
	    i += 1;
	    
	while(sign)
	{
		//申请一片指向结构体的内存空间，并负责给指针，结构体的指针数组初始化。 
		p[i] = (struct Project *)malloc(sizeof(struct Project));		
		for(;j<100;j++)
			p[i]->athlete[j] = 0; 
			
		printf("\n<项目发布>\
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
		
		sign=0;	

	}
}


//运动员报名登记 
void athlete_checkin(struct Project *p[])
{
	int sign=1;
	int i=0;
	int j=0;
	int project_num=0; //已存在的项目数量 
	int num; // 欲参加的项目数量 
	int input; // 用户输入的序号 
	 
	//获取项目数量,并输出项目名称 
	printf("\n已发布的项目：\n"); 
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

		printf("\n输入运动员姓名、性别、单位，以空格或回车分隔：");
									
		// 增加检测输入正确性代码 ，能否报名成功 
		
		scanf("%s%s%s", athlete_p->name, athlete_p->gender, athlete_p->organization);
		
		printf("输入运动员<%s>要参加的下项目数量：",athlete_p->name);
		scanf("%d",&num);
		printf("输入项目序号");
		for(i=0;i<num;i++)
		{
			scanf("%d",&input);
			if (0<input && input<=project_num)
				{
					//获取当前项目已存在运动员的数量 
					while((p[input-1]->athlete[j]))
						j += 1;
					//将运动员添加到当前项目 
					p[input-1]->athlete[j]=athlete_p;
					j =0;
				}
			else printf("\n输入序号对应的项目不存在！"); 
		}
		
//		printf("\n\n尝试查询运动员：\
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
	int project_num=0;
	while(p[project_num])
		project_num += 1;
	
	//对项目按时间顺序排序, 冒泡排序 
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
	
	for(i=0;i<project_num;i++) // 待规划输出样式 ，尽量变横 
		{
			printf("\n第<%d>场:%s %s %2d月%2d日%.2d:",
			i+1,
			order[i]->name,
			order[i]->site,
			order[i]->month,
			order[i]->day,
			order[i]->hour);
			
			printf("%.2d:%.2d 以<%s>为成绩单位 最少%d人 最多%d人\n",
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
	
	printf("\n已发布的项目：\n"); 
	while(p[i])
		{
			printf("%d:%10s\t",i+1,p[i]->name); 
	    	project_num += 1;
	    	i += 1; 
	    	if (i%5==0) printf("\n");
		}
		
	printf("\n输入要录入的项目序号：");
	scanf("%d",&input);
	if (0<input && input<=project_num)
		{
			printf("输入第%d个项目<%s>的成绩：\
			\n参赛的运动员有：\n",input,p[input-1]->name);
			i = 0;
			while(p[input-1]->athlete[i])
				{
					printf("%d:%8s\t",i+1,p[input-1]->athlete[i]->name);
					i += 1;
					if (i%5==0) printf("\n");
				}
			i=0;
			printf("\n多个运动员以空格或回车分隔：\n");
			while(project_num)
				{
					//运动员成绩数组和项目序号对应 
					scanf("%d",&(p[input-1]->athlete[i]->score[input-1]));
					project_num -= 1;
				}
			printf("输入成功。\n");
				
		}
	else printf("输入的序号对应的项目不存在！\n");
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

// 主函数：作为主界面，实现获取用户输入并导航至相应功能。 
int main()
{
	int sign=1; //循环标志 
	int input; //用户输入的序号 
	int i=0;
	
	//定义指向项目的指针数组 
	struct Project *list[100]={0}; 
	
	while(sign)
		{
			printf("<<学校运动会管理系统>>\n"); 
			printf( "1. 项目发布\n"
					"2. 运动员报名登记\n"
					"3. 秩序册生成\n"
					"4. 成绩录入\n"
					"5. 运动会成绩册\n"
					"6. 系统设置\n"
					"7. 数据备份\n"
					"8. 退出系统");
			printf("\n输入序号:"); 
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
					default:printf("未找到序号%d，输入有误，重新输入！\n\n",input); 
				} 
		}

 } 
