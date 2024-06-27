#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

//ѧ������
typedef struct _Student
{
	char stuName[20];//ѧ������
	char stuclass[20];//ѧ���༶
	int stuID;//ѧ��ѧ��
	int stuBedID;//ѧ����λ��
	int stuDormitoryID;//�����
	char stuDorBuilding[10];//����¥��
	char stuStartTime[30];//��סʱ��
	char stuEndTime[30];//�뿪ʱ��
	char stuTip[100];//��ס��ʾ
	bool stuCheckIn;//�Ƿ�����ס��

	struct _Student* next;//��һ��ѧ����Ϣ
}student;

//��������
typedef struct _Dormitory
{
	char dorBuilding[10]; //����¥��
	int dorID; //�����
	int dorCheckInNumber; //������ס��

	//student* dorStudent; //ָ��������ѧ������
	struct _Dormitory* next; //��һ��������Ϣ
}dormitory;




void welcome();

//ѧ��
void menuA();
void menu1();
void menu2();
void menu3();
void stuFind(student* stuhead, dormitory* dorhead,int id);
void stuInputTime(student* stuhead, dormitory* dorhead, int id,char c);
void applyDormitory(student* stuhead, dormitory* dorhead, int id);




//����Ա
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
