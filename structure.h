//�˶�Ա���� 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
	int score[10];
};


//�˶���Ŀ����
struct Project
{
	char name[20];
	char site[20];
	int month;	// ʱ��Ҳ������Сʱ���� 
	int day;
	int hour;
	int minute;
	int second;
	char unit[10];	//�ɼ���λ 
	int  up; // ��������
	int down; // ��������
	int score[100]; // ��Ŀ������÷֣�score[0]��ֵ��ʾ��һ�������ٷ� ,
					// �ṹ���ڲ��ܳ�ʼ������Ҫ������ʱ��ȫ����0 
	struct Athlete *athlete[100]; //ָ������Ϊchar���˶�Աָ������  
};
