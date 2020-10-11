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
	
	printf("\n%x\n",p[0]);
	while(p[i])
	    i += 1;
	    
	while(sign)
	{
		struct Project project;
		p[i] = &project;

	printf("\n\np0：%x\n\n",p[0]);
	
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
			 
//			scanf("%s",project1.name);
//			printf("%s",project1.name);
			 
			// 不考虑输入太多，溢出的问题 
			scanf("%s%s%d%d%d%d%d%s%d%d",
			project.name,
			project.site,
			&project.month,
			&project.day,
			&project.hour,
			&project.minute, 
			&project.second,
			project.unit,
			&project.down,
			&project.up);
						
			printf("\n项目1\
			\n项目名称：%s\
			\n项目场地：%s\
			\n比赛月份：%d\
			\n日期：%d\
			\n小时：%d\
			\n分钟：%d\
			\n秒：%d\
			\n成绩单位：%s\
			\n参数人数下限：%d\
			\n参数人数上限：%d",
			project.name,
			project.site,
			project.month,
			project.day,
			project.hour,
			project.minute, 
			project.second,
			project.unit,
			project.down,
			project.up);
			
		struct Athlete athlete1;
		strcpy(athlete1.name,"熬夜敲代码的我");
		
		struct Athlete athlete2;
		strcpy(athlete2.name,"方一帆");
		
		struct Athlete athlete3;
		strcpy(athlete3.name,"武勇涛");
		
		struct Athlete athlete4;
		strcpy(athlete4.name,".");
				
		project.athlete[0] = &athlete1; // 将指针指向运动员
		project.athlete[1] = &athlete2;
		project.athlete[2] = &athlete3;
		project.athlete[3] = &athlete4;
		
		printf("\n\n尝试查询运动员：\
		\n1:%s\
		\n2:%s\
		\n3:%s\
		\n4:%s\n\n",
		project.athlete[0]->name,
		project.athlete[1]->name,
		project.athlete[2]->name,
		project.athlete[3]->name);
		
		sign=0;
		
	printf("\np0：%x\n",p[0]);
	}
	
	
		
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

// 主函数：作为主界面，实现获取用户输入并导航至相应功能。 
int main()
{
	int sign=1;
	int input;
	int i=0;
	
	struct Project *list[100]={0};
	printf("\n%x\n",list[0]);
	struct Project project;
	list[0]=&project;
    printf("\n%x\n",list[0]);
    printf("\n%x\n",list);
	
	
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
					case 3:{orderbook_generation();break;}
					case 4:{grade_input();break; }
					case 5:{sportsmeet_card();break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{quit();break;}
					default:printf("未找到序号%d，输入有误，重新输入！\n\n",input); 
				} 
		}
		

 } 