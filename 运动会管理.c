#include<stdio.h>
#include<stdlib.h>

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
	int unit;	//成绩单位 
	int  up; // 人数上限
	int down; // 人数下限
	int score[100]; // 项目名次与得分，score[0]的值表示第一名积多少分 ,
					// 结构体内不能初始化，需要在输入时先全部赋0 
	char *athlete[100]; //指向类型为char的运动员指针数组 ？？ 
};


//运动员定义 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
	struct Project *project_pointer[10];
	int score[10];
};

// 功能模块 
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

// 主函数：作为主界面，实现获取用户输入并导航至相应功能。 
int main()
{
	int sign=1;
	int input;
	
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
					case 1:{project_publish();break;}
					case 2:{athlete_checkin();break;}
					case 3:{orderbook_generation();break;}
					case 4:{grade_input();break; }
					case 5:{sportsmeet_card();break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{quit();break;}
					default:printf("\n    输入错误！"); 
				} 
		}
		
		

 } 
