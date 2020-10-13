void grade_input(struct Project *p[])
{
	int i=0;
	int input;
	int project_num=0;
	
	printf("\n�ѷ�������Ŀ��\n"); 
	while(p[i])
		{
			printf("%d:%10s\t",i+1,p[i]->name); 
	    	project_num += 1;
	    	i += 1; 
	    	if (i%5==0) printf("\n");
		}
		
	printf("\n����Ҫ¼�����Ŀ��ţ�");
	scanf("%d",&input);
	if (0<input && input<=project_num)
		{
			printf("�����%d����Ŀ<%s>�ĳɼ���\
			\n�������˶�Ա�У�\n",input,p[input-1]->name);
			i = 0;
			while(p[input-1]->athlete[i])
				{
					printf("%d:%8s\t",i+1,p[input-1]->athlete[i]->name);
					i += 1;
					if (i%5==0) printf("\n");
				}
			i=0;
			printf("\n����˶�Ա�Կո��س��ָ���\n");
			while(project_num)
				{
					//�˶�Ա�ɼ��������Ŀ��Ŷ�Ӧ 
					scanf("%d",&(p[input-1]->athlete[i]->score[input-1]));
					project_num -= 1;
				}
			printf("����ɹ���\n\n");
				
		}
	else printf("�������Ŷ�Ӧ����Ŀ�����ڣ�\n");
}

void sportsmeet_card(struct Project *p[])
{
	int sign=1;
	int i,j,k=0;
	int athlete_num=0;
	struct Athlete *athlete_list[3000]={0}; 
	struct Athlete *ath_order[3000]={0};
	struct Athlete *temp;

	struct Project *order[100]={0};  //�ź����ָ����Ŀ�ṹ���ָ������ 
	int athlete_list_len=0;	
	int add_athlete_sign=1;				  //�����˶�Ա���� 
	 
	//��ȡ��Ŀ����
	int project_num=0;
	while(p[project_num])
		project_num += 1;
	
	//��ȡ�˶�Ա���� �������⣬ʱ�临�Ӷ�̫�� 
	for(i=0;i<project_num;i++)
		for(j=0;p[i]->athlete[j];j++)
		{
			for(k=0;k<athlete_list_len;k++)
				if (p[i]->athlete[j]->name == athlete_list[k]->name)//��Ӧ�ý�ͬ��������λ��ͬ����Ϊͬһ�˶�Ա
					{sign = 0; break;} 	
			if (sign)
				{
					athlete_list[k]=p[i]->athlete[j];
					athlete_list_len += 1;
				}
		}
	
	//����Ŀ��ʱ��˳������, ð������ 
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
			
			
				
	//�����ж�				
	i = project_num;
	while(i)
	{
		i -= 1;
		if (!(p[i]->athlete[0]->score[i])) // �����һ���˶�Ա�ĳɼ��Ǽ������Ҫȷ��
			{sign=0;break;}						   // �ɼ����뺯���������벿���˶�Ա�ɼ� 
	}	
	
	//������� 
	if (sign)
	{
		printf("\n�����˶���˳������������Ϊ�˶��ᱨ��");
		printf("\n������<%d>��������Ŀ������<%d>���˶�Ա������",project_num,athlete_list_len);
		for(i=0;i<project_num;i++)  
		{
			printf("\n��<%d>��:%s %s %2d��%2d��%.2d:",
			i+1,
			order[i]->name,
			order[i]->site,
			order[i]->month,
			order[i]->day,
			order[i]->hour);
			
			printf("%.2d:%.2d ��<%s>Ϊ�ɼ���λ ����%d�� ���%d��\n",
			order[i]->minute, 
			order[i]->second,
			order[i]->unit,
			order[i]->down,
			order[i]->up);
						
			//�Ե�ǰ��Ŀ�ڵ��˶�Ա�ɼ����� ��ð�� 
			for(j=0;order[i]->athlete[j];j++) 
				for(k=j+1;order[i]->athlete[k];k++)
					{
						if (order[i]->athlete[j]->score[i] > order[i]->athlete[k]->score[i])
							temp = order[i]->athlete[j];
							order[i]->athlete[j] = order[i]->athlete[k];
							order[i]->athlete[k] = temp;
							
					}
					
			printf("\n<����>:");
			for(j=0;order[i]->athlete[j];j++)
				{
					printf("<%d>%8s",j+1,order[i]->athlete[j]->name);
					if ((j+1)%5 == 0) printf("\n");
				}
		}
		
	}
	else printf("�˶���δ�ܽ���������δ����ɼ�����Ŀ��\n\n");
}
