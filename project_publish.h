void project_publish(struct Project *p[])
{
	int sign=1;
	int i=0;
	int j=0; 
	
	//��ȡ��Ŀ����
	while(p[i])
	    i += 1;
	    
	while(sign)
	{
		//����һƬָ��ṹ����ڴ�ռ䣬�������ָ�룬�ṹ���ָ�������ʼ���� 
		p[i] = (struct Project *)malloc(sizeof(struct Project));		
		for(;j<100;j++)
			p[i]->athlete[j] = 0; 
			
		printf("\n<��Ŀ����>\
    		\n�����������%d����Ŀ������������(�Կո��س��ָ�):\
			\n* ��Ŀ����\
			\n* ��Ŀ����\
			\n* �����·�\
			\n* ����\
			\n* Сʱ\
			\n* ����\
			\n* ��\
			\n* �ɼ���λ\
			\n* �����������ޣ�����������Ŀ����ȡ��)\
			\n* ������������\n", i+1);
			
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
									
			// ���Ӽ��������ȷ�Դ��� 	
		
		sign=0;	

	}
}
