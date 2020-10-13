void athlete_checkin(struct Project *p[])
{
	int sign=1;
	int i=0;
	int j=0;
	int project_num=0; //已存在的项目数量 
	int num; // 欲参加的项目数量 
	int input; // 用户输入的序号 
	 
	
	printf("\n<运动员报名登记>"); 
	//获取项目数量,并输出项目名称 
	while(p[i])
		{
	    	project_num += 1;
	    	i += 1; 
		}
	    
	
	while(sign)
	{
		struct Athlete *athlete_p;
		athlete_p = (struct Athlete *)malloc(sizeof(struct Athlete));
		for(;i<10;i++)
			athlete_p->score[i] = 0; 
			

		printf("\n输入运动员姓名、性别、单位，以空格或回车分隔：");
									
		// 增加检测输入正确性代码 ，能否报名成功 
		
		scanf("%s%s%s", athlete_p->name, athlete_p->gender, athlete_p->organization);
		
		printf("<%s> 参加的项目数量：",athlete_p->name);
		scanf("%d",&num);
		
		printf("输入项目对应序号：\n");
		for(i=0;i<project_num;i++)
		{
			printf("%d:%10s\t",i+1,p[i]->name); 
			if (i%5==0) printf("\n");
			
		}			
			
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
		
		printf("\n");
		sign=0;	

	}
	
}
