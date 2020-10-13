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
					case 5:{sportsmeet_card(list);break;} 
					case 6:{seting();break;}
					case 7:{data_backup();break;}
					case 8:{sign=0;break;}
					default:printf("未找到序号%d，输入有误，重新输入！\n\n",input); 
				} 
		}

 } 
 
//整体设计太复杂了，应该用全局变量 
