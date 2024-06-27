#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

//学生链表
typedef struct _Student
{
	char stuName[20];//学生姓名
	char stuclass[20];//学生班级
	int stuID;//学生学号
	int stuBedID;//学生床位号
	int stuDormitoryID;//宿舍号
	char stuDorBuilding[10];//宿舍楼号
	char stuStartTime[30];//入住时间
	char stuEndTime[30];//离开时间
	char stuTip[100];//入住提示
	bool stuCheckIn;//是否申请住宿

	struct _Student* next;//下一个学生信息
}student;

//宿舍链表
typedef struct _Dormitory
{
	char dorBuilding[10]; //宿舍楼号
	int dorID; //宿舍号
	int dorCheckInNumber; //宿舍入住量

	//student* dorStudent; //指向该宿舍的学生链表
	struct _Dormitory* next; //下一个宿舍信息
}dormitory;




void welcome();

//学生
void menuA();
void menu1();
void menu2();
void menu3();
void stuFind(student* stuhead, dormitory* dorhead,int id);
void stuInputTime(student* stuhead, dormitory* dorhead, int id,char c);
void applyDormitory(student* stuhead, dormitory* dorhead, int id);




//管理员
void menuB();
void menu4();
void menu5();
void menu6();
void inputDormitory(dormitory* dorhead);
void inputStudent(student* stuhead);
void showInformation(student* stuhead, dormitory* dorhead);
void findInformation(student* stuhead, dormitory* dorhead);
void saveStudent(student* stuhead);
void saveDormitory(dormitory* dorhead);
void load(student* stuhead, dormitory* dorhead);
void deleteInformation(student* stuhead, dormitory* dorhead);
void modifyInformation(student* stuhead, dormitory* dorhead);
void inputTips(student* stuhead);
void processingApplication(student* stuhead, dormitory* dorhead);
