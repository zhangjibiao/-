void athlete_checkin(struct Project *p[])
{
	int sign=1;
	int i=0;
	int j=0;
	int project_num=0; //�Ѵ��ڵ���Ŀ���� 
	int num; // ���μӵ���Ŀ���� 
	int input; // �û��������� 
	 
	
	printf("\n<�˶�Ա�����Ǽ�>"); 
	//��ȡ��Ŀ����,�������Ŀ���� 
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
			

		printf("\n�����˶�Ա�������Ա𡢵�λ���Կո��س��ָ���");
									
		// ���Ӽ��������ȷ�Դ��� ���ܷ����ɹ� 
		
		scanf("%s%s%s", athlete_p->name, athlete_p->gender, athlete_p->organization);
		
		printf("<%s> �μӵ���Ŀ������",athlete_p->name);
		scanf("%d",&num);
		
		printf("������Ŀ��Ӧ��ţ�\n");
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
					//��ȡ��ǰ��Ŀ�Ѵ����˶�Ա������ 
					while((p[input-1]->athlete[j]))
						j += 1;
					//���˶�Ա��ӵ���ǰ��Ŀ 
					p[input-1]->athlete[j]=athlete_p;
					j =0;
				}
			else printf("\n������Ŷ�Ӧ����Ŀ�����ڣ�"); 
		}
		
		printf("\n");
		sign=0;	

	}
	
}
