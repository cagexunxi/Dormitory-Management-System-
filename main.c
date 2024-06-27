/*
*  项目名称：学生宿舍管理系统
* 
*  C语言、链表
* 
* ps: 每个人的学号唯一
*       默认每个寝室6个床位
*       在输入信息的时候没有纠错机制, 请注意输入格式
* 
* 
* 6.19上 确定项目需求
* 6.19下 完成链表的创建、插入
* 6.20    打印链表成员时程序崩溃
* 6.21    破案了, scanf的时候在存字符串时不需要在 fresh->dorBuilding 前加上 &，因为数组名本身就是其首元素的地址。
* 6.21晚 完成数据储存、读取(注意&的用法)
* 6.22下 管理员录入学生信息时若无宿舍信息则自动分配宿舍
* 6.22晚 信息删除和修改, 完善细节
* 6.23    完善管理员模式的功能, 优化床位分配逻辑
* 6.24     完善学生模式的功能
* 6.25     项目完结
*/
#include"myHead.h"

int main() {
	//创建头结点
	student* stuhead = malloc(sizeof(student));
	stuhead->next = NULL;
	dormitory* dorhead = malloc(sizeof(dormitory));
	dorhead->next = NULL;
	//加载学生信息
	load(stuhead, dorhead);


	while (1) {

		welcome();

		char c = _getch();

		if (c == '1') {
			int id;
			printf("请输入您的学号:");
			scanf("%d", &id);
			system("cls");
			while (1) {
				menuA();//打印菜单
				c = _getch();
				switch (c) {

				case '1':  //录入住宿申请
					system("cls");
					applyDormitory(stuhead, dorhead, id);					
					break;
				case '2':  //录入住宿记录
					system("cls");
					menu2();
					c = _getch();
					stuInputTime(stuhead, dorhead, id, c);
					break;
				case '3':  //查看信息
					system("cls");
					stuFind(stuhead, dorhead, id);
					break;
				case '4':  //退出学生模式
					break;
				default:
					printf("请重新输入\n");
					break;
				}
				if (c == '4') {
					system("cls");
					break;
				}
			}
		}

		else if (c == '2') {
			while (1) {
				system("cls");
				menuB();
				c = _getch();
				switch (c) {//管理员模式

				case '1':  //录入宿舍信息
					inputDormitory(dorhead);
					break;
				case '2':  //录入学生信息
					inputStudent(stuhead, dorhead);
					break;
				case '3':  //录入入住提示
					system("cls");
					inputTips(stuhead, dorhead);
					break;
				case '4':  //修改信息(学生,宿舍)
					system("cls");
					showInformation(stuhead, dorhead);
					modifyInformation(stuhead, dorhead);
					break;
				case '5':  //查找信息(学生,宿舍)
					system("cls");
					showInformation(stuhead, dorhead);
					menu5();
					c = _getch();
					findInformation(stuhead, dorhead, c);
					break;
				case '6':  //删除信息(学生,宿舍)
					while (1) {
						system("cls");
						showInformation(stuhead, dorhead);
						menu6();
						c = _getch();
						deleteInformation(stuhead, dorhead, c);
						if(c=='3') break;
					}
					break;
				case '7':  //查看入住申请
					system("cls");
					processingApplication(stuhead, dorhead);
					break;
				case '8':  //退出管理员模式
					break;
				default:
					printf("请重新输入\n");
					break;
				}
				if (c == '8') {
					system("cls");
					break;
				}
			}
		}

		else if (c == '3') {
			system("cls");
			printf("感谢使用, 再见!\n");
			exit(0);
		}

		else {
			printf("请重新输入\n");
		}
	}
	return 0;
}

	void welcome() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t请选用户身份\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.学生模式\t\t*\n");
		printf("*\t2.管理员模式\t\t*\n");
		printf("*\t3.退出系统\t\t*\n");
		printf("*********************************\n");
	}

	//学生模式的函数
	void menuA() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t当前是学生模式\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.提出住宿申请\t\t*\n");
		printf("*\t2.录入住宿时间\t\t*\n");
		printf("*\t3.查看个人信息\t\t*\n");
		printf("*\t4.退出学生模式\t\t*\n");
		printf("*********************************\n");
	}
	void menu2() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t学生住宿时间\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.录入住宿时间\t\t*\n");
		printf("*\t2.修改住宿时间\t\t*\n");
		printf("*********************************\n");
	}

	void applyDormitory(student* stuhead, dormitory* dorhead, int id) {
		student* stumove = stuhead->next;
		while (stumove != NULL) {
			if (stumove->stuID == id) {
				printf("您已在住宿中, 无需申请住宿!\n");
				system("pause");
				system("cls");
				return;
			}
			stumove = stumove->next;
		}

		stumove = stuhead;
		printf("您当前的学号为:%d\n", id);
		printf("请输入您的姓名, 班别, 并再次输入你的学号\n");
		char stuName[30];
		char stuclass[30];
		int a;
		scanf("%s %s %d", stuName, stuclass, &a);
		student* fresh = malloc(sizeof(student));
		strcpy(fresh->stuName, stuName);
		strcpy(fresh->stuclass, stuclass);
		if (a != id) {
			printf("学号输入错误, 请重新输入!\n");
			system("pause");
			system("cls");
			free(fresh);
			return;
		}
		fresh->stuID = id;
		strcpy(fresh->stuDorBuilding, "暂未分配");
		fresh->stuDormitoryID = 0;
		strcpy(fresh->stuStartTime, "暂无信息");
		strcpy(fresh->stuEndTime, "暂无信息");
		strcpy(fresh->stuTip, "暂无信息");
		while (stumove->next != NULL) {
			stumove = stumove->next;
		}
		stumove->next = fresh;
		fresh->next = NULL;
		saveStudent(stuhead);
		printf("申请成功, 请耐心等待管理员审核!\n");
		system("pause");
		system("cls");
	}
	
	void stuFind(student* stuhead, dormitory* dorhead, int id) {
		student* stumove = stuhead->next;
		while (stumove != NULL) {
			if (stumove->stuID == id) {
				printf("姓名:%s\n", stumove->stuName);
				printf("班别:%s\n", stumove->stuclass);
				printf("学号:%d\n", stumove->stuID);
				printf("宿舍楼:%s\n", stumove->stuDorBuilding);
				printf("宿舍号:%d\n", stumove->stuDormitoryID);
				printf("入住时间:%s\n", stumove->stuStartTime);
				printf("离开时间:%s\n", stumove->stuEndTime);
				printf("入住提示:%s\n\n", stumove->stuTip);
				system("pause");
				system("cls");
				return;
			}
			stumove = stumove->next;
		}
		printf("\n当前没有您的信息, 赶快去申请住宿吧!\n");
		system("pause");
		system("cls");
	}

	void stuInputTime(student* stuhead, dormitory* dorhead, int id, char c) {
		//打印当前学生入住信息
		student* stumove = stuhead->next;

		while (stumove != NULL) {
			if (stumove->stuID == id) {
				printf("姓名:%s, 班别:%s, 学号:%d, 宿舍楼:%s, 宿舍号:%d, \n入住时间:%s, 离开时间:%s, 入住提示:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuStartTime, stumove->stuEndTime, stumove->stuTip);
				break;
			}
			stumove = stumove->next;
		}
		if (stumove == NULL) {
			printf("当前还没有您的住宿信息, 请去申请住宿吧!\n");
			system("pause");
			system("cls");
			return;
		}

		//录入学生入住信息
		if (c == '1') {
			char stuStartTime[30];
			char stuEndTime[30];
			printf("请输入入住时间(格式:2024.6.23) ");
			scanf("%s", stuStartTime);
			printf("请输入离开时间(格式:2024.6.28) ");
			scanf("%s", stuEndTime);
			strcpy(stumove->stuStartTime, stuStartTime);
			strcpy(stumove->stuEndTime, stuEndTime);
			saveStudent(stuhead);
			printf("姓名:%s, 班别:%s, 学号:%d, 宿舍楼:%s, 宿舍号:%d, \n入住时间:%s, 离开时间:%s, 入住提示:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuStartTime, stumove->stuEndTime, stumove->stuTip);
			printf("住宿时间录入成功!\n");
			system("pause");
			system("cls");
			return;
		}

		else if (c == '2') {//修改入住时间
			char stuStartTime[30];
			char stuEndTime[30];
			printf("请输入新的入住时间(格式:2024.6.23) ");
			scanf("%s", stuStartTime);
			printf("请输入新的离开时间(格式:2024.6.28) ");
			scanf("%s", stuEndTime);
			strcpy(stumove->stuStartTime, stuStartTime);
			strcpy(stumove->stuEndTime, stuEndTime);
			printf("姓名:%s, 班别:%s, 学号:%d, 宿舍楼:%s, 宿舍号:%d, \n入住时间:%s, 离开时间:%s, 入住提示:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuStartTime, stumove->stuEndTime, stumove->stuTip);
			saveStudent(stuhead);
			printf("住宿时间修改成功!\n");
			system("pause");
			system("cls");
			return;
		}
	}

	
	

//以下为管理员模式的函数
	void menuB() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t当前是管理员模式\t\t\n");
		printf("*********************************\n");
		printf("*\t1.录入宿舍信息\t\t*\n");
		printf("*\t2.录入学生信息\t\t*\n");
		printf("*\t3.录入入住提示\t\t*\n");
		printf("*\t4.修改信息(学生,宿舍)\t*\n");
		printf("*\t5.查找信息(学生,宿舍)\t*\n");
		printf("*\t6.删除信息(学生,宿舍)\t*\n");
		printf("*\t7.查看入住申请\t\t*\n");
		printf("*\t8.退出管理员模式\t\t\n");
		printf("*********************************\n");
	}
	void menu5() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t   信息查看\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.以学号查找学生信息\t*\t\n");
		printf("*\t2.以宿舍号查看住宿信息\t*\t\n");
		printf("*********************************\n");
	}
	void menu6() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t   信息删除\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.删除学生信息\t*\t\n");
		printf("*\t2.删除宿舍信息\t*\t\n");
		printf("*\t3.退出信息删除\t*\t\n");
		printf("*********************************\n");
		printf("*\t按1或2选择删除对象\t\t\n");
	}
	void menu4() {
		printf("*********************************\n");
		printf("*\t学生宿舍管理系统\t*\n");
		printf("*********************************\n");
		printf("*\t   信息修改\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.修改学生信息\t*\t\n");
		printf("*\t2.修改宿舍信息\t*\t\n");
		printf("*********************************\n");
		printf("*\t按1或2选择修改对象\t\t\n");
	}

	void saveStudent(student* stuhead) {
		FILE* file = fopen("./student.data", "wb");//覆盖模式, 二进制
		student* stumove = stuhead->next;
		while (stumove != NULL) {
			if (fwrite(stumove, sizeof(student), 1, file) != 1) {//先执行写入操作，再判断是否成功, 所以文件写入在经过if时就已经成功了
				printf("写入失败\n");
				return;
			}
			stumove = stumove->next;
		}
		fclose(file);
	}

	void saveDormitory(dormitory* dorhead) {
		FILE* file = fopen("./dormitory.data", "wb");//覆盖模式
		dormitory* dormove = dorhead->next;
		while (dormove != NULL) {
			if (fwrite(dormove, sizeof(dormitory), 1, file) != 1) {//先执行写入操作，再判断是否成功, 所以文件写入在经过if时就已经成功了
				printf("写入失败\n");
				return;
			}
			dormove = dormove->next;
		}
		fclose(file);
	}

	void load(student* stuhead, dormitory* dorhead) {//读取数据再重构链表
		FILE* stufile = fopen("./student.data", "rb");//只读模式
		if (!stufile) {
			printf("没有学生文件,跳过读取\n");
			return;
		}
		student* stufresh = malloc(sizeof(student));
		stufresh->next = NULL;
		student* stumove = stuhead;
		while (fread(stufresh, sizeof(student), 1, stufile) == 1) {
			stumove->next = stufresh;
			stumove = stufresh;
			stufresh = malloc(sizeof(student));//为读取下一个学生分配空间
			stufresh->next = NULL;
		}
		free(stufresh);//由于循环到最后会多一次分配操作，所以释放最后一个学生的空间
		fclose(stufile);
		printf("学生信息读取成功\n");

		FILE* dorfile = fopen("./dormitory.data", "rb");//只读模式
		if (!dorfile) {
			printf("没有宿舍文件,跳过读取\n");
			return;
		}
		dormitory* dorfresh = malloc(sizeof(dormitory));
		dorfresh->next = NULL;
		dormitory* dormove = dorhead;
		while (fread(dorfresh, sizeof(dormitory), 1, dorfile) == 1) {
			dormove->next = dorfresh;
			dormove = dorfresh;
			dorfresh = malloc(sizeof(dormitory));//为读取下一个宿舍分配空间
			dorfresh->next = NULL;
		}
		free(dorfresh);//由于循环到最后会多一次分配操作，所以释放最后一个宿舍的空间
		fclose(dorfile);
		printf("宿舍信息读取成功\n");
	}

	void inputDormitory(dormitory* dorhead) {//管理员录入宿舍信息

		dormitory* fresh =malloc(sizeof(dormitory));
		fresh->next = NULL;
		fresh->dorCheckInNumber = 0;
		printf("请输录入 宿舍楼 ,宿舍号\n");
		scanf("%9s%d", fresh->dorBuilding, &fresh->dorID);

		dormitory* move = dorhead;
		while (move->next != NULL) {
			move = move->next;
		}
		//将宿舍插入到尾部
		move->next = fresh;
		if (move->next != NULL) {
			printf("宿舍信息录入成功\n");
		}

		//保存信息
		saveDormitory(dorhead);
		
		//暂停程序
		system("pause");
		//清空控制台
		system("cls");
	}

	void inputStudent(student* stuhead, dormitory* dorhead) {//管理员录入学生信息

		student* fresh = malloc(sizeof(student));
		fresh->next = NULL;
		char a[13] = "暂无信息";
		strcpy(fresh->stuStartTime, a);
		strcpy(fresh->stuEndTime, a);
		strcpy(fresh->stuTip, a);
		printf("请输入学生的 姓名 ,班级, 学号 ,宿舍楼 ,宿舍号 ,床位号 \n");
		int bedNum;
		scanf("%19s%19s%d%9s%d%d", fresh->stuName, fresh->stuclass ,&fresh->stuID, fresh->stuDorBuilding,&fresh->stuDormitoryID,&bedNum);
		//如果该宿舍床位号已被占用则直接返回
		student* bedcheck = stuhead->next;
		while (bedcheck != NULL) {
			if (strcmp(fresh->stuDorBuilding, bedcheck->stuDorBuilding) == 0 && fresh->stuDormitoryID == bedcheck->stuDormitoryID && bedNum == bedcheck->stuBedID) {
				printf("该床位号已被占用,请重新输入\n");
				system("pause");
				system("cls");
				return;
			}
			bedcheck = bedcheck->next;
		}
		fresh->stuBedID = bedNum;

		student* move = stuhead;
		while (move->next != NULL) {
			move = move->next;
		}
		//将学生插入到尾部
		move->next = fresh;
		if (move->next != NULL) {
			printf("学生信息录入成功\n");
		}
		//如果学生宿舍楼和宿舍号不存在则自动新增宿舍信息,若存在则宿舍人数+1
		dormitory* check = dorhead->next;
		while (check != NULL) {
			if (strcmp(fresh->stuDorBuilding, check->dorBuilding) == 0 && fresh->stuDormitoryID == check->dorID) {
				check->dorCheckInNumber++;
				saveDormitory(dorhead);
				break;
			}
			check = check->next;
		}
		if (check == NULL) {
			dormitory* freshDor = malloc(sizeof(dormitory));
			freshDor->next = NULL;
			freshDor->dorCheckInNumber = 1;
			strcpy(freshDor->dorBuilding, fresh->stuDorBuilding);
			freshDor->dorID = fresh->stuDormitoryID;
			dormitory* moveDor = dorhead;
			while (moveDor->next != NULL) {
				moveDor = moveDor->next;
			}
			//将宿舍插入到尾部
			moveDor->next = freshDor;
			if (moveDor->next != NULL) {
				printf("发现新宿舍,自动创建宿舍信息\n");
			}
			saveDormitory(dorhead);		
		}
		//保存信息
		saveStudent(stuhead);
		
		//暂停程序
		system("pause");
		//清空控制台
		system("cls");
	}

	void showInformation(student* stuhead, dormitory* dorhead) {
		system("cls");

		printf("当前已录入: \n\n");

		printf("宿舍情况: \n");
		dormitory* dormove = dorhead->next;
		int people = 0;
		int allCount = 0;
		int count = 0;
		int a = 1;
		while (dormove != NULL) {
			printf("%d. 宿舍楼: %s 宿舍号:%d 宿舍人数:%d/6\n", a, dormove->dorBuilding, dormove->dorID, dormove->dorCheckInNumber);//宿舍人数
			a++;
			people += dormove->dorCheckInNumber;
			count += dormove->dorCheckInNumber;
			allCount += 6;
			dormove = dormove->next;
		}
		printf(" 当前总入住人数:%d 当前总床位剩余%d\n\n", people, allCount - count);

		printf("学生情况: \n");
		student* stumove = stuhead->next;
		int b = 1;
		while (stumove != NULL) {
			if (stumove->stuDormitoryID != 0) {
				printf("%d. 姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d 床位号:%d 入住提示:%s\n", b, stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuBedID, stumove->stuTip);
				b++;
			}
			stumove = stumove->next;
		}
	}
	

	void findInformation(student* stuhead, dormitory* dorhead, char c) {
		if (c == '1') {
			printf("请输入学生的 学号 ");
			int stuNum;
			scanf("%d", &stuNum);
			student* move = stuhead->next;
			while (move != NULL) {
				if (stuNum == move->stuID&&move->stuDormitoryID!=0) {
					printf("姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d 床位号:%d\n", move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuBedID);
					//暂停程序
					system("pause");
					//清空控制台
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("未找到学生信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
		}
		if (c == '2') {
			printf("请输入宿舍的 宿舍楼 和 宿舍号 ");//查找宿舍信息和该宿舍的学生信息
			char building[10];
			int dormitoryNum;
			scanf("%9s%d", building, &dormitoryNum);
			dormitory* move = dorhead->next;
			while (move != NULL) {
				if (strcmp(building, move->dorBuilding) == 0 && dormitoryNum == move->dorID) {
					printf("宿舍楼:%s 宿舍号:%d 宿舍人数:%d/6\n", move->dorBuilding, move->dorID, move->dorCheckInNumber);
					printf("当前入住学生: \n");
					student* stumove = stuhead->next;
					while (stumove != NULL) {
						if (strcmp(building, stumove->stuDorBuilding) == 0 && dormitoryNum == stumove->stuDormitoryID) {
							printf("姓名:%s 班级:%s 学号:%d 床位号:%d\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuBedID);
						}
						stumove = stumove->next;
					}
					//暂停程序
					system("pause");
					//清空控制台
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("未找到宿舍信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");

		}
	}

	void deleteInformation(student* stuhead, dormitory* dorhead, char c) {

		if (c == '1') {
			printf("请输入要删除的学生的 学号 ");
			int num;
			getchar();
			scanf("%d", &num);
			student* move = stuhead->next;
			student* pre = stuhead;
			while (move != NULL) {
				if (num == move->stuID) {
					//学生所在宿舍人数-1
					dormitory* dormove = dorhead->next;
					while (dormove != NULL) {
						if (strcmp(move->stuDorBuilding, dormove->dorBuilding) == 0 && move->stuDormitoryID == dormove->dorID) {
							dormove->dorCheckInNumber--;
							saveDormitory(dorhead);
							break;
						}
						dormove = dormove->next;
					}
					pre->next = move->next;
					free(move);
					saveStudent(stuhead);
					showInformation(stuhead, dorhead);
					printf("删除成功\n");
					//暂停程序
					system("pause");
					//清空控制台
					system("cls");
					return;
				}
				pre = move;
				move = move->next;
			}
			printf("未找到学生信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
		}
		if (c == '2') {

			printf("请输入宿舍的 宿舍楼 和 宿舍号 ");
			char building[10];
			int num;
			scanf("%9s%d", building, &num);
			//如果当前宿舍有人则不能删除
			dormitory* move = dorhead->next;
			while (move != NULL) {
				if (strcmp(building, move->dorBuilding) == 0 && num == move->dorID) {
					if (move->dorCheckInNumber != 0) {
						printf("当前宿舍有人居住,不能删除\n");
						//暂停程序
						system("pause");
						//清空控制台
						system("cls");
						return;
					}
					//删除宿舍信息
					dormitory* pre = dorhead;
					while (pre->next != move) {
						pre = pre->next;
					}
					pre->next = move->next;
					free(move);
					saveDormitory(dorhead);
					showInformation(stuhead, dorhead);
					printf("删除成功\n");
					//暂停程序
					system("pause");
					//清空控制台
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("未找到宿舍信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");

		}
	}

	void modifyInformation(student* stuhead, dormitory* dorhead) {
			printf("请输入要修改的学生的 学号 ");
			int num;
			scanf("%d", &num);
			student* move = stuhead->next;
			while (move != NULL) {
				if (num == move->stuID) {
					//原来宿舍人数-1
					dormitory* dormove = dorhead->next;
					while (dormove != NULL) {
						if (strcmp(move->stuDorBuilding, dormove->dorBuilding) == 0 && move->stuDormitoryID == dormove->dorID) {
							dormove->dorCheckInNumber--;
							saveDormitory(dorhead);
							break;
						}
						dormove = dormove->next;
					}
					//储存原来的指针
					student* pre = move;
					printf("请输入修改后的 姓名 ,班级, 宿舍楼 ,宿舍号 ,床位号 \n");
					scanf("%19s%19s%9s%d%d", move->stuName, move->stuclass, move->stuDorBuilding, &move->stuDormitoryID, &move->stuBedID);
					//如果同一宿舍的该床位号已被占用则报错
					student* bedcheck = stuhead->next;
					while (bedcheck != NULL) {
						if (strcmp(move->stuDorBuilding, bedcheck->stuDorBuilding) == 0 && move->stuDormitoryID == bedcheck->stuDormitoryID && move->stuBedID == bedcheck->stuBedID && move->stuID != bedcheck->stuID) {
							printf("该宿舍的该床位号已被占用,请重新输入\n");
							//恢复原来信息
							move = pre;
							dormove->dorCheckInNumber++;
							saveDormitory(dorhead);
							saveStudent(stuhead);
							system("pause");
							system("cls");
							return;
						}
						bedcheck = bedcheck->next;
					}
					//如果学生宿舍楼和宿舍号不存在则自动新增宿舍信息
					dormitory* check = dorhead->next;
					while (check != NULL) {
						if (strcmp(move->stuDorBuilding, check->dorBuilding) == 0 && move->stuDormitoryID == check->dorID) {						
								check->dorCheckInNumber++;
								saveDormitory(dorhead);						
							break;
						}
						check = check->next;
					}
					if (check == NULL) {
						dormitory* freshDor = malloc(sizeof(dormitory));
						freshDor->next = NULL;
						freshDor->dorCheckInNumber = 1;
						strcpy(freshDor->dorBuilding, move->stuDorBuilding);
						freshDor->dorID = move->stuDormitoryID;
						dormitory* moveDor = dorhead;
						while (moveDor->next != NULL) {
							moveDor = moveDor->next;
						}
						//将宿舍插入到尾部
						moveDor->next = freshDor;
						if (moveDor->next != NULL) {
							printf("发现新宿舍,已更新宿舍信息\n");
						}
						saveDormitory(dorhead);		
					}
					saveStudent(stuhead);
					showInformation(stuhead, dorhead);
					printf("修改成功\n");
					//暂停程序
					system("pause");
					//清空控制台
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("未找到学生信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");	
	}

	void inputTips(student* stuhead, dormitory* dorhead) {
		student* move = stuhead->next;
		while (move != NULL) {//先打印无信息的学生, 再打印有信息的学生
			if (strcmp(move->stuStartTime, "暂无信息") == 0) {
				printf("姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d \n入住时间:%s 离开时间:%s 入住提示:%s\n\n", move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
			}
			move = move->next;
		}
		move = stuhead->next;

		while (move != NULL) {
			if (strcmp(move->stuStartTime, "暂无信息") != 0) {
				printf("姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d \n入住时间:%s 离开时间:%s 入住提示:%s\n\n",move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
			}
			move = move->next;
		}
		move = stuhead->next;

		printf("请输入学生的学号\n");
		int stuID;
		scanf("%d", &stuID);
		while (move != NULL) {
			if (stuID == move->stuID) {
				printf("姓名:%s 班级:%s宿舍楼:%s 宿舍号:%d \n开始入住:%s 结束入住:%s 入住提示:%s\n", move->stuName, move->stuclass, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
				printf("请输入该学生的入住提示(30字以内)\n");
				char tips[100];
				scanf("%99s", tips);
				strcpy(move->stuTip, tips);
				saveStudent(stuhead);
				printf("姓名:%s 班级:%s宿舍楼:%s 宿舍号:%d \n开始入住:%s 结束入住:%s 入住提示:%s\n", move->stuName, move->stuclass, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
				printf("修改成功\n");
				//暂停程序
				system("pause");
				//清空控制台
				system("cls");
				return;
			}
			move = move->next;
		}
		printf("未找到学生信息\n");
		//暂停程序
		system("pause");
		//清空控制台
		system("cls");

	}

	void processingApplication(student* stuhead, dormitory* dorhead) {
		//显示待处理学生信息
		printf("待处理学生信息: \n\n");
		student* stumove = stuhead->next;
		int stucount = 0;
		while (stumove != NULL) {
			if (stumove->stuDormitoryID == 0) {
				stucount++;
				printf("姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d 入住提示:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuTip);
			}
			stumove = stumove->next;
		}
		stumove = stuhead->next;
		if (stucount == 0) {
			printf("暂无待处理学生信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}

		//显示空闲宿舍信息
		printf("空闲宿舍信息: \n\n");
		dormitory* dormove = dorhead->next;
		int dorcount = 0;
		while (dormove != NULL) {
			if (dormove->dorCheckInNumber <= 6) {
				dorcount++;
				printf("宿舍楼:%s 宿舍号:%d 已入住:%d/6\n", dormove->dorBuilding, dormove->dorID, dormove->dorCheckInNumber);
			}
			dormove = dormove->next;
		}
		dormove = dorhead->next;
		if (dorcount == 0) {
			printf("暂无空闲宿舍信息\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}

		//开始分配宿舍
		printf("请输入要处理学生的学号\n");
		int stuID=0;
		scanf("%d", &stuID);
		while (stumove != NULL) {
			if (stuID == stumove->stuID && stumove->stuDormitoryID == 0) {
				break;
			}
			if (stumove->next == NULL) {
				printf("未找到该学生信息\n");
				//暂停程序
				system("pause");
				//清空控制台
				system("cls");
				return;
			}
			stumove = stumove->next;
		}
		printf("请为该学生分配宿舍楼和宿舍号\n");
		char building[10];
		int dormitoryNum;
		scanf("%9s%d", building, &dormitoryNum);
		strcpy(stumove->stuDorBuilding, building);
		stumove->stuDormitoryID = dormitoryNum;
		//记录此宿舍已占的床位号,并随即分配除此之外床位号
		student* bedcheck = stuhead->next;
		int bedArray[6] = {0};
		while (bedcheck != NULL) {
			if (strcmp(bedcheck->stuDorBuilding, building) == 0 && bedcheck->stuDormitoryID == dormitoryNum&& bedcheck->stuBedID<=6&& bedcheck->stuBedID>0) {
				bedArray[bedcheck->stuBedID]=1;//1表示此床位已被占用
			}
			bedcheck = bedcheck->next;
		}
		int bedNum = 0;
		for (int i = 1; i <= 6; i++) {
			if (bedArray[i] == 0) {
				bedNum = i;
				break;
			}
		}
		if (bedNum == 0) {
			printf("当前宿舍已满, 请选择其他宿舍\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}
		stumove->stuBedID = bedNum;
		saveStudent(stuhead);
		//更新宿舍信息
		dormitory* dormitoryMove = dorhead->next;
		while (dormitoryMove != NULL) {
			if (strcmp(dormitoryMove->dorBuilding, building) == 0 && dormitoryMove->dorID == dormitoryNum) {
				dormitoryMove->dorCheckInNumber++;
				saveDormitory(dorhead);
				break;
			}
			dormitoryMove = dormitoryMove->next;
		}
		printf("分配宿舍成功\n");
		//暂停程序
		system("pause");
		//清空控制台
		system("cls");
		}
	

	
		