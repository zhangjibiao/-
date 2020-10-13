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
		printf("\n\n"); 
									
			// 增加检测输入正确性代码 	
		
		sign=0;	

	}
}
