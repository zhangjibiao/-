void orderbook_generation(struct Project *p[])
{
	//复制一份项目指针数组
	struct Project *order[100];//开辟内存 
	memcpy(order,p,sizeof(struct Project *)*100);
	
	//获取项目数量
	int project_num=0;
	while(p[project_num])
		project_num += 1;
	
	//对项目按时间顺序排序, 冒泡排序 
	int i,j;
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
	
	//输出秩序册 
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
		}
	printf("\n");	
}
