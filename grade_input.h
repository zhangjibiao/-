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
			printf("输入成功。\n\n");
				
		}
	else printf("输入的序号对应的项目不存在！\n");
}

void sportsmeet_card(struct Project *p[])
{
	int sign=1;
	int i,j,k=0;
	int athlete_num=0;
	struct Athlete *athlete_list[3000]={0}; 
	struct Athlete *ath_order[3000]={0};
	struct Athlete *temp;

	struct Project *order[100]={0};  //排好序的指向项目结构体的指针数组 
	int athlete_list_len=0;	
	int add_athlete_sign=1;				  //以求运动员数量 
	 
	//获取项目数量
	int project_num=0;
	while(p[project_num])
		project_num += 1;
	
	//获取运动员数量 存在问题，时间复杂度太大 
	for(i=0;i<project_num;i++)
		for(j=0;p[i]->athlete[j];j++)
		{
			for(k=0;k<athlete_list_len;k++)
				if (p[i]->athlete[j]->name == athlete_list[k]->name)//不应该将同姓名但单位不同的视为同一运动员
					{sign = 0; break;} 	
			if (sign)
				{
					athlete_list[k]=p[i]->athlete[j];
					athlete_list_len += 1;
				}
		}
	
	//对项目按时间顺序排序, 冒泡排序 
	for(i=0;i<project_num-1;i++)
	{
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
			
			
				
	//结束判断				
	i = project_num;
	while(i)
	{
		i -= 1;
		if (!(p[i]->athlete[0]->score[i])) // 仅检查一个运动员的成绩登记与否，需要确保
			{sign=0;break;}						   // 成绩登入函数不能输入部分运动员成绩 
	}	
	
	//输出报表 
	if (sign)
	{
		printf("\n本次运动会顺利结束，以下为运动会报表：");
		printf("\n共举行<%d>个比赛项目，共有<%d>名运动员参赛。",project_num,athlete_list_len);
		for(i=0;i<project_num;i++)  
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
						
			//对当前项目内的运动员成绩排序 ，冒泡 
			for(j=0;order[i]->athlete[j];j++) 
				for(k=j+1;order[i]->athlete[k];k++)
					{
						if (order[i]->athlete[j]->score[i] > order[i]->athlete[k]->score[i])
							temp = order[i]->athlete[j];
							order[i]->athlete[j] = order[i]->athlete[k];
							order[i]->athlete[k] = temp;
							
					}
					
			printf("\n<排名>:");
			for(j=0;order[i]->athlete[j];j++)
				{
					printf("<%d>%8s",j+1,order[i]->athlete[j]->name);
					if ((j+1)%5 == 0) printf("\n");
				}
		}
		
	}
	else printf("运动会未能结束，存在未登入成绩的项目。\n\n");
}
