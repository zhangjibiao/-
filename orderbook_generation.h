void orderbook_generation(struct Project *p[])
{
	//����һ����Ŀָ������
	struct Project *order[100];//�����ڴ� 
	memcpy(order,p,sizeof(struct Project *)*100);
	
	//��ȡ��Ŀ����
	int project_num=0;
	while(p[project_num])
		project_num += 1;
	
	//����Ŀ��ʱ��˳������, ð������ 
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
	
	//�������� 
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
		}
	printf("\n");	
}
