//运动员定义 
struct Athlete
{
	char name[10];
	char organization[10];
	char gender[10];
	int score[10];
};


//运动项目定义
struct Project
{
	char name[20];
	char site[20];
	int month;	// 时间也分月日小时分秒 
	int day;
	int hour;
	int minute;
	int second;
	char unit[10];	//成绩单位 
	int  up; // 人数上限
	int down; // 人数下限
	int score[100]; // 项目名次与得分，score[0]的值表示第一名积多少分 ,
					// 结构体内不能初始化，需要在输入时先全部赋0 
	struct Athlete *athlete[100]; //指向类型为char的运动员指针数组  
};
