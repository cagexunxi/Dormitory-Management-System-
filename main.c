/*
*  ��Ŀ���ƣ�ѧ���������ϵͳ
* 
*  C���ԡ�����
* 
* ps: ÿ���˵�ѧ��Ψһ
*       Ĭ��ÿ������6����λ
*       ��������Ϣ��ʱ��û�о������, ��ע�������ʽ
* 
* 
* 6.19�� ȷ����Ŀ����
* 6.19�� �������Ĵ���������
* 6.20    ��ӡ�����Աʱ�������
* 6.21    �ư���, scanf��ʱ���ڴ��ַ���ʱ����Ҫ�� fresh->dorBuilding ǰ���� &����Ϊ�����������������Ԫ�صĵ�ַ��
* 6.21�� ������ݴ��桢��ȡ(ע��&���÷�)
* 6.22�� ����Ա¼��ѧ����Ϣʱ����������Ϣ���Զ���������
* 6.22�� ��Ϣɾ�����޸�, ����ϸ��
* 6.23    ���ƹ���Աģʽ�Ĺ���, �Ż���λ�����߼�
* 6.24     ����ѧ��ģʽ�Ĺ���
* 6.25     ��Ŀ���
*/
#include"myHead.h"

int main() {
	//����ͷ���
	student* stuhead = malloc(sizeof(student));
	stuhead->next = NULL;
	dormitory* dorhead = malloc(sizeof(dormitory));
	dorhead->next = NULL;
	//����ѧ����Ϣ
	load(stuhead, dorhead);


	while (1) {

		welcome();

		char c = _getch();

		if (c == '1') {
			int id;
			printf("����������ѧ��:");
			scanf("%d", &id);
			system("cls");
			while (1) {
				menuA();//��ӡ�˵�
				c = _getch();
				switch (c) {

				case '1':  //¼��ס������
					system("cls");
					applyDormitory(stuhead, dorhead, id);					
					break;
				case '2':  //¼��ס�޼�¼
					system("cls");
					menu2();
					c = _getch();
					stuInputTime(stuhead, dorhead, id, c);
					break;
				case '3':  //�鿴��Ϣ
					system("cls");
					stuFind(stuhead, dorhead, id);
					break;
				case '4':  //�˳�ѧ��ģʽ
					break;
				default:
					printf("����������\n");
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
				switch (c) {//����Աģʽ

				case '1':  //¼��������Ϣ
					inputDormitory(dorhead);
					break;
				case '2':  //¼��ѧ����Ϣ
					inputStudent(stuhead, dorhead);
					break;
				case '3':  //¼����ס��ʾ
					system("cls");
					inputTips(stuhead, dorhead);
					break;
				case '4':  //�޸���Ϣ(ѧ��,����)
					system("cls");
					showInformation(stuhead, dorhead);
					modifyInformation(stuhead, dorhead);
					break;
				case '5':  //������Ϣ(ѧ��,����)
					system("cls");
					showInformation(stuhead, dorhead);
					menu5();
					c = _getch();
					findInformation(stuhead, dorhead, c);
					break;
				case '6':  //ɾ����Ϣ(ѧ��,����)
					while (1) {
						system("cls");
						showInformation(stuhead, dorhead);
						menu6();
						c = _getch();
						deleteInformation(stuhead, dorhead, c);
						if(c=='3') break;
					}
					break;
				case '7':  //�鿴��ס����
					system("cls");
					processingApplication(stuhead, dorhead);
					break;
				case '8':  //�˳�����Աģʽ
					break;
				default:
					printf("����������\n");
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
			printf("��лʹ��, �ټ�!\n");
			exit(0);
		}

		else {
			printf("����������\n");
		}
	}
	return 0;
}

	void welcome() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\t��ѡ�û����\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.ѧ��ģʽ\t\t*\n");
		printf("*\t2.����Աģʽ\t\t*\n");
		printf("*\t3.�˳�ϵͳ\t\t*\n");
		printf("*********************************\n");
	}

	//ѧ��ģʽ�ĺ���
	void menuA() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\t��ǰ��ѧ��ģʽ\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.���ס������\t\t*\n");
		printf("*\t2.¼��ס��ʱ��\t\t*\n");
		printf("*\t3.�鿴������Ϣ\t\t*\n");
		printf("*\t4.�˳�ѧ��ģʽ\t\t*\n");
		printf("*********************************\n");
	}
	void menu2() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\tѧ��ס��ʱ��\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.¼��ס��ʱ��\t\t*\n");
		printf("*\t2.�޸�ס��ʱ��\t\t*\n");
		printf("*********************************\n");
	}

	void applyDormitory(student* stuhead, dormitory* dorhead, int id) {
		student* stumove = stuhead->next;
		while (stumove != NULL) {
			if (stumove->stuID == id) {
				printf("������ס����, ��������ס��!\n");
				system("pause");
				system("cls");
				return;
			}
			stumove = stumove->next;
		}

		stumove = stuhead;
		printf("����ǰ��ѧ��Ϊ:%d\n", id);
		printf("��������������, ���, ���ٴ��������ѧ��\n");
		char stuName[30];
		char stuclass[30];
		int a;
		scanf("%s %s %d", stuName, stuclass, &a);
		student* fresh = malloc(sizeof(student));
		strcpy(fresh->stuName, stuName);
		strcpy(fresh->stuclass, stuclass);
		if (a != id) {
			printf("ѧ���������, ����������!\n");
			system("pause");
			system("cls");
			free(fresh);
			return;
		}
		fresh->stuID = id;
		strcpy(fresh->stuDorBuilding, "��δ����");
		fresh->stuDormitoryID = 0;
		strcpy(fresh->stuStartTime, "������Ϣ");
		strcpy(fresh->stuEndTime, "������Ϣ");
		strcpy(fresh->stuTip, "������Ϣ");
		while (stumove->next != NULL) {
			stumove = stumove->next;
		}
		stumove->next = fresh;
		fresh->next = NULL;
		saveStudent(stuhead);
		printf("����ɹ�, �����ĵȴ�����Ա���!\n");
		system("pause");
		system("cls");
	}
	
	void stuFind(student* stuhead, dormitory* dorhead, int id) {
		student* stumove = stuhead->next;
		while (stumove != NULL) {
			if (stumove->stuID == id) {
				printf("����:%s\n", stumove->stuName);
				printf("���:%s\n", stumove->stuclass);
				printf("ѧ��:%d\n", stumove->stuID);
				printf("����¥:%s\n", stumove->stuDorBuilding);
				printf("�����:%d\n", stumove->stuDormitoryID);
				printf("��סʱ��:%s\n", stumove->stuStartTime);
				printf("�뿪ʱ��:%s\n", stumove->stuEndTime);
				printf("��ס��ʾ:%s\n\n", stumove->stuTip);
				system("pause");
				system("cls");
				return;
			}
			stumove = stumove->next;
		}
		printf("\n��ǰû��������Ϣ, �Ͽ�ȥ����ס�ް�!\n");
		system("pause");
		system("cls");
	}

	void stuInputTime(student* stuhead, dormitory* dorhead, int id, char c) {
		//��ӡ��ǰѧ����ס��Ϣ
		student* stumove = stuhead->next;

		while (stumove != NULL) {
			if (stumove->stuID == id) {
				printf("����:%s, ���:%s, ѧ��:%d, ����¥:%s, �����:%d, \n��סʱ��:%s, �뿪ʱ��:%s, ��ס��ʾ:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuStartTime, stumove->stuEndTime, stumove->stuTip);
				break;
			}
			stumove = stumove->next;
		}
		if (stumove == NULL) {
			printf("��ǰ��û������ס����Ϣ, ��ȥ����ס�ް�!\n");
			system("pause");
			system("cls");
			return;
		}

		//¼��ѧ����ס��Ϣ
		if (c == '1') {
			char stuStartTime[30];
			char stuEndTime[30];
			printf("��������סʱ��(��ʽ:2024.6.23) ");
			scanf("%s", stuStartTime);
			printf("�������뿪ʱ��(��ʽ:2024.6.28) ");
			scanf("%s", stuEndTime);
			strcpy(stumove->stuStartTime, stuStartTime);
			strcpy(stumove->stuEndTime, stuEndTime);
			saveStudent(stuhead);
			printf("����:%s, ���:%s, ѧ��:%d, ����¥:%s, �����:%d, \n��סʱ��:%s, �뿪ʱ��:%s, ��ס��ʾ:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuStartTime, stumove->stuEndTime, stumove->stuTip);
			printf("ס��ʱ��¼��ɹ�!\n");
			system("pause");
			system("cls");
			return;
		}

		else if (c == '2') {//�޸���סʱ��
			char stuStartTime[30];
			char stuEndTime[30];
			printf("�������µ���סʱ��(��ʽ:2024.6.23) ");
			scanf("%s", stuStartTime);
			printf("�������µ��뿪ʱ��(��ʽ:2024.6.28) ");
			scanf("%s", stuEndTime);
			strcpy(stumove->stuStartTime, stuStartTime);
			strcpy(stumove->stuEndTime, stuEndTime);
			printf("����:%s, ���:%s, ѧ��:%d, ����¥:%s, �����:%d, \n��סʱ��:%s, �뿪ʱ��:%s, ��ס��ʾ:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuStartTime, stumove->stuEndTime, stumove->stuTip);
			saveStudent(stuhead);
			printf("ס��ʱ���޸ĳɹ�!\n");
			system("pause");
			system("cls");
			return;
		}
	}

	
	

//����Ϊ����Աģʽ�ĺ���
	void menuB() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\t��ǰ�ǹ���Աģʽ\t\t\n");
		printf("*********************************\n");
		printf("*\t1.¼��������Ϣ\t\t*\n");
		printf("*\t2.¼��ѧ����Ϣ\t\t*\n");
		printf("*\t3.¼����ס��ʾ\t\t*\n");
		printf("*\t4.�޸���Ϣ(ѧ��,����)\t*\n");
		printf("*\t5.������Ϣ(ѧ��,����)\t*\n");
		printf("*\t6.ɾ����Ϣ(ѧ��,����)\t*\n");
		printf("*\t7.�鿴��ס����\t\t*\n");
		printf("*\t8.�˳�����Աģʽ\t\t\n");
		printf("*********************************\n");
	}
	void menu5() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\t   ��Ϣ�鿴\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.��ѧ�Ų���ѧ����Ϣ\t*\t\n");
		printf("*\t2.������Ų鿴ס����Ϣ\t*\t\n");
		printf("*********************************\n");
	}
	void menu6() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\t   ��Ϣɾ��\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.ɾ��ѧ����Ϣ\t*\t\n");
		printf("*\t2.ɾ��������Ϣ\t*\t\n");
		printf("*\t3.�˳���Ϣɾ��\t*\t\n");
		printf("*********************************\n");
		printf("*\t��1��2ѡ��ɾ������\t\t\n");
	}
	void menu4() {
		printf("*********************************\n");
		printf("*\tѧ���������ϵͳ\t*\n");
		printf("*********************************\n");
		printf("*\t   ��Ϣ�޸�\t\t*\n");
		printf("*********************************\n");
		printf("*\t1.�޸�ѧ����Ϣ\t*\t\n");
		printf("*\t2.�޸�������Ϣ\t*\t\n");
		printf("*********************************\n");
		printf("*\t��1��2ѡ���޸Ķ���\t\t\n");
	}

	void saveStudent(student* stuhead) {
		FILE* file = fopen("./student.data", "wb");//����ģʽ, ������
		student* stumove = stuhead->next;
		while (stumove != NULL) {
			if (fwrite(stumove, sizeof(student), 1, file) != 1) {//��ִ��д����������ж��Ƿ�ɹ�, �����ļ�д���ھ���ifʱ���Ѿ��ɹ���
				printf("д��ʧ��\n");
				return;
			}
			stumove = stumove->next;
		}
		fclose(file);
	}

	void saveDormitory(dormitory* dorhead) {
		FILE* file = fopen("./dormitory.data", "wb");//����ģʽ
		dormitory* dormove = dorhead->next;
		while (dormove != NULL) {
			if (fwrite(dormove, sizeof(dormitory), 1, file) != 1) {//��ִ��д����������ж��Ƿ�ɹ�, �����ļ�д���ھ���ifʱ���Ѿ��ɹ���
				printf("д��ʧ��\n");
				return;
			}
			dormove = dormove->next;
		}
		fclose(file);
	}

	void load(student* stuhead, dormitory* dorhead) {//��ȡ�������ع�����
		FILE* stufile = fopen("./student.data", "rb");//ֻ��ģʽ
		if (!stufile) {
			printf("û��ѧ���ļ�,������ȡ\n");
			return;
		}
		student* stufresh = malloc(sizeof(student));
		stufresh->next = NULL;
		student* stumove = stuhead;
		while (fread(stufresh, sizeof(student), 1, stufile) == 1) {
			stumove->next = stufresh;
			stumove = stufresh;
			stufresh = malloc(sizeof(student));//Ϊ��ȡ��һ��ѧ������ռ�
			stufresh->next = NULL;
		}
		free(stufresh);//����ѭ���������һ�η�������������ͷ����һ��ѧ���Ŀռ�
		fclose(stufile);
		printf("ѧ����Ϣ��ȡ�ɹ�\n");

		FILE* dorfile = fopen("./dormitory.data", "rb");//ֻ��ģʽ
		if (!dorfile) {
			printf("û�������ļ�,������ȡ\n");
			return;
		}
		dormitory* dorfresh = malloc(sizeof(dormitory));
		dorfresh->next = NULL;
		dormitory* dormove = dorhead;
		while (fread(dorfresh, sizeof(dormitory), 1, dorfile) == 1) {
			dormove->next = dorfresh;
			dormove = dorfresh;
			dorfresh = malloc(sizeof(dormitory));//Ϊ��ȡ��һ���������ռ�
			dorfresh->next = NULL;
		}
		free(dorfresh);//����ѭ���������һ�η�������������ͷ����һ������Ŀռ�
		fclose(dorfile);
		printf("������Ϣ��ȡ�ɹ�\n");
	}

	void inputDormitory(dormitory* dorhead) {//����Ա¼��������Ϣ

		dormitory* fresh =malloc(sizeof(dormitory));
		fresh->next = NULL;
		fresh->dorCheckInNumber = 0;
		printf("����¼�� ����¥ ,�����\n");
		scanf("%9s%d", fresh->dorBuilding, &fresh->dorID);

		dormitory* move = dorhead;
		while (move->next != NULL) {
			move = move->next;
		}
		//��������뵽β��
		move->next = fresh;
		if (move->next != NULL) {
			printf("������Ϣ¼��ɹ�\n");
		}

		//������Ϣ
		saveDormitory(dorhead);
		
		//��ͣ����
		system("pause");
		//��տ���̨
		system("cls");
	}

	void inputStudent(student* stuhead, dormitory* dorhead) {//����Ա¼��ѧ����Ϣ

		student* fresh = malloc(sizeof(student));
		fresh->next = NULL;
		char a[13] = "������Ϣ";
		strcpy(fresh->stuStartTime, a);
		strcpy(fresh->stuEndTime, a);
		strcpy(fresh->stuTip, a);
		printf("������ѧ���� ���� ,�༶, ѧ�� ,����¥ ,����� ,��λ�� \n");
		int bedNum;
		scanf("%19s%19s%d%9s%d%d", fresh->stuName, fresh->stuclass ,&fresh->stuID, fresh->stuDorBuilding,&fresh->stuDormitoryID,&bedNum);
		//��������ᴲλ���ѱ�ռ����ֱ�ӷ���
		student* bedcheck = stuhead->next;
		while (bedcheck != NULL) {
			if (strcmp(fresh->stuDorBuilding, bedcheck->stuDorBuilding) == 0 && fresh->stuDormitoryID == bedcheck->stuDormitoryID && bedNum == bedcheck->stuBedID) {
				printf("�ô�λ���ѱ�ռ��,����������\n");
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
		//��ѧ�����뵽β��
		move->next = fresh;
		if (move->next != NULL) {
			printf("ѧ����Ϣ¼��ɹ�\n");
		}
		//���ѧ������¥������Ų��������Զ�����������Ϣ,����������������+1
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
			//��������뵽β��
			moveDor->next = freshDor;
			if (moveDor->next != NULL) {
				printf("����������,�Զ�����������Ϣ\n");
			}
			saveDormitory(dorhead);		
		}
		//������Ϣ
		saveStudent(stuhead);
		
		//��ͣ����
		system("pause");
		//��տ���̨
		system("cls");
	}

	void showInformation(student* stuhead, dormitory* dorhead) {
		system("cls");

		printf("��ǰ��¼��: \n\n");

		printf("�������: \n");
		dormitory* dormove = dorhead->next;
		int people = 0;
		int allCount = 0;
		int count = 0;
		int a = 1;
		while (dormove != NULL) {
			printf("%d. ����¥: %s �����:%d ��������:%d/6\n", a, dormove->dorBuilding, dormove->dorID, dormove->dorCheckInNumber);//��������
			a++;
			people += dormove->dorCheckInNumber;
			count += dormove->dorCheckInNumber;
			allCount += 6;
			dormove = dormove->next;
		}
		printf(" ��ǰ����ס����:%d ��ǰ�ܴ�λʣ��%d\n\n", people, allCount - count);

		printf("ѧ�����: \n");
		student* stumove = stuhead->next;
		int b = 1;
		while (stumove != NULL) {
			if (stumove->stuDormitoryID != 0) {
				printf("%d. ����:%s �༶:%s ѧ��:%d ����¥:%s �����:%d ��λ��:%d ��ס��ʾ:%s\n", b, stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuBedID, stumove->stuTip);
				b++;
			}
			stumove = stumove->next;
		}
	}
	

	void findInformation(student* stuhead, dormitory* dorhead, char c) {
		if (c == '1') {
			printf("������ѧ���� ѧ�� ");
			int stuNum;
			scanf("%d", &stuNum);
			student* move = stuhead->next;
			while (move != NULL) {
				if (stuNum == move->stuID&&move->stuDormitoryID!=0) {
					printf("����:%s �༶:%s ѧ��:%d ����¥:%s �����:%d ��λ��:%d\n", move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuBedID);
					//��ͣ����
					system("pause");
					//��տ���̨
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("δ�ҵ�ѧ����Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
		}
		if (c == '2') {
			printf("����������� ����¥ �� ����� ");//����������Ϣ�͸������ѧ����Ϣ
			char building[10];
			int dormitoryNum;
			scanf("%9s%d", building, &dormitoryNum);
			dormitory* move = dorhead->next;
			while (move != NULL) {
				if (strcmp(building, move->dorBuilding) == 0 && dormitoryNum == move->dorID) {
					printf("����¥:%s �����:%d ��������:%d/6\n", move->dorBuilding, move->dorID, move->dorCheckInNumber);
					printf("��ǰ��סѧ��: \n");
					student* stumove = stuhead->next;
					while (stumove != NULL) {
						if (strcmp(building, stumove->stuDorBuilding) == 0 && dormitoryNum == stumove->stuDormitoryID) {
							printf("����:%s �༶:%s ѧ��:%d ��λ��:%d\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuBedID);
						}
						stumove = stumove->next;
					}
					//��ͣ����
					system("pause");
					//��տ���̨
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("δ�ҵ�������Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");

		}
	}

	void deleteInformation(student* stuhead, dormitory* dorhead, char c) {

		if (c == '1') {
			printf("������Ҫɾ����ѧ���� ѧ�� ");
			int num;
			getchar();
			scanf("%d", &num);
			student* move = stuhead->next;
			student* pre = stuhead;
			while (move != NULL) {
				if (num == move->stuID) {
					//ѧ��������������-1
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
					printf("ɾ���ɹ�\n");
					//��ͣ����
					system("pause");
					//��տ���̨
					system("cls");
					return;
				}
				pre = move;
				move = move->next;
			}
			printf("δ�ҵ�ѧ����Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
		}
		if (c == '2') {

			printf("����������� ����¥ �� ����� ");
			char building[10];
			int num;
			scanf("%9s%d", building, &num);
			//�����ǰ������������ɾ��
			dormitory* move = dorhead->next;
			while (move != NULL) {
				if (strcmp(building, move->dorBuilding) == 0 && num == move->dorID) {
					if (move->dorCheckInNumber != 0) {
						printf("��ǰ�������˾�ס,����ɾ��\n");
						//��ͣ����
						system("pause");
						//��տ���̨
						system("cls");
						return;
					}
					//ɾ��������Ϣ
					dormitory* pre = dorhead;
					while (pre->next != move) {
						pre = pre->next;
					}
					pre->next = move->next;
					free(move);
					saveDormitory(dorhead);
					showInformation(stuhead, dorhead);
					printf("ɾ���ɹ�\n");
					//��ͣ����
					system("pause");
					//��տ���̨
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("δ�ҵ�������Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");

		}
	}

	void modifyInformation(student* stuhead, dormitory* dorhead) {
			printf("������Ҫ�޸ĵ�ѧ���� ѧ�� ");
			int num;
			scanf("%d", &num);
			student* move = stuhead->next;
			while (move != NULL) {
				if (num == move->stuID) {
					//ԭ����������-1
					dormitory* dormove = dorhead->next;
					while (dormove != NULL) {
						if (strcmp(move->stuDorBuilding, dormove->dorBuilding) == 0 && move->stuDormitoryID == dormove->dorID) {
							dormove->dorCheckInNumber--;
							saveDormitory(dorhead);
							break;
						}
						dormove = dormove->next;
					}
					//����ԭ����ָ��
					student* pre = move;
					printf("�������޸ĺ�� ���� ,�༶, ����¥ ,����� ,��λ�� \n");
					scanf("%19s%19s%9s%d%d", move->stuName, move->stuclass, move->stuDorBuilding, &move->stuDormitoryID, &move->stuBedID);
					//���ͬһ����ĸô�λ���ѱ�ռ���򱨴�
					student* bedcheck = stuhead->next;
					while (bedcheck != NULL) {
						if (strcmp(move->stuDorBuilding, bedcheck->stuDorBuilding) == 0 && move->stuDormitoryID == bedcheck->stuDormitoryID && move->stuBedID == bedcheck->stuBedID && move->stuID != bedcheck->stuID) {
							printf("������ĸô�λ���ѱ�ռ��,����������\n");
							//�ָ�ԭ����Ϣ
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
					//���ѧ������¥������Ų��������Զ�����������Ϣ
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
						//��������뵽β��
						moveDor->next = freshDor;
						if (moveDor->next != NULL) {
							printf("����������,�Ѹ���������Ϣ\n");
						}
						saveDormitory(dorhead);		
					}
					saveStudent(stuhead);
					showInformation(stuhead, dorhead);
					printf("�޸ĳɹ�\n");
					//��ͣ����
					system("pause");
					//��տ���̨
					system("cls");
					return;
				}
				move = move->next;
			}
			printf("δ�ҵ�ѧ����Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");	
	}

	void inputTips(student* stuhead, dormitory* dorhead) {
		student* move = stuhead->next;
		while (move != NULL) {//�ȴ�ӡ����Ϣ��ѧ��, �ٴ�ӡ����Ϣ��ѧ��
			if (strcmp(move->stuStartTime, "������Ϣ") == 0) {
				printf("����:%s �༶:%s ѧ��:%d ����¥:%s �����:%d \n��סʱ��:%s �뿪ʱ��:%s ��ס��ʾ:%s\n\n", move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
			}
			move = move->next;
		}
		move = stuhead->next;

		while (move != NULL) {
			if (strcmp(move->stuStartTime, "������Ϣ") != 0) {
				printf("����:%s �༶:%s ѧ��:%d ����¥:%s �����:%d \n��סʱ��:%s �뿪ʱ��:%s ��ס��ʾ:%s\n\n",move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
			}
			move = move->next;
		}
		move = stuhead->next;

		printf("������ѧ����ѧ��\n");
		int stuID;
		scanf("%d", &stuID);
		while (move != NULL) {
			if (stuID == move->stuID) {
				printf("����:%s �༶:%s����¥:%s �����:%d \n��ʼ��ס:%s ������ס:%s ��ס��ʾ:%s\n", move->stuName, move->stuclass, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
				printf("�������ѧ������ס��ʾ(30������)\n");
				char tips[100];
				scanf("%99s", tips);
				strcpy(move->stuTip, tips);
				saveStudent(stuhead);
				printf("����:%s �༶:%s����¥:%s �����:%d \n��ʼ��ס:%s ������ס:%s ��ס��ʾ:%s\n", move->stuName, move->stuclass, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
				printf("�޸ĳɹ�\n");
				//��ͣ����
				system("pause");
				//��տ���̨
				system("cls");
				return;
			}
			move = move->next;
		}
		printf("δ�ҵ�ѧ����Ϣ\n");
		//��ͣ����
		system("pause");
		//��տ���̨
		system("cls");

	}

	void processingApplication(student* stuhead, dormitory* dorhead) {
		//��ʾ������ѧ����Ϣ
		printf("������ѧ����Ϣ: \n\n");
		student* stumove = stuhead->next;
		int stucount = 0;
		while (stumove != NULL) {
			if (stumove->stuDormitoryID == 0) {
				stucount++;
				printf("����:%s �༶:%s ѧ��:%d ����¥:%s �����:%d ��ס��ʾ:%s\n", stumove->stuName, stumove->stuclass, stumove->stuID, stumove->stuDorBuilding, stumove->stuDormitoryID, stumove->stuTip);
			}
			stumove = stumove->next;
		}
		stumove = stuhead->next;
		if (stucount == 0) {
			printf("���޴�����ѧ����Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}

		//��ʾ����������Ϣ
		printf("����������Ϣ: \n\n");
		dormitory* dormove = dorhead->next;
		int dorcount = 0;
		while (dormove != NULL) {
			if (dormove->dorCheckInNumber <= 6) {
				dorcount++;
				printf("����¥:%s �����:%d ����ס:%d/6\n", dormove->dorBuilding, dormove->dorID, dormove->dorCheckInNumber);
			}
			dormove = dormove->next;
		}
		dormove = dorhead->next;
		if (dorcount == 0) {
			printf("���޿���������Ϣ\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}

		//��ʼ��������
		printf("������Ҫ����ѧ����ѧ��\n");
		int stuID=0;
		scanf("%d", &stuID);
		while (stumove != NULL) {
			if (stuID == stumove->stuID && stumove->stuDormitoryID == 0) {
				break;
			}
			if (stumove->next == NULL) {
				printf("δ�ҵ���ѧ����Ϣ\n");
				//��ͣ����
				system("pause");
				//��տ���̨
				system("cls");
				return;
			}
			stumove = stumove->next;
		}
		printf("��Ϊ��ѧ����������¥�������\n");
		char building[10];
		int dormitoryNum;
		scanf("%9s%d", building, &dormitoryNum);
		strcpy(stumove->stuDorBuilding, building);
		stumove->stuDormitoryID = dormitoryNum;
		//��¼��������ռ�Ĵ�λ��,���漴�������֮�ⴲλ��
		student* bedcheck = stuhead->next;
		int bedArray[6] = {0};
		while (bedcheck != NULL) {
			if (strcmp(bedcheck->stuDorBuilding, building) == 0 && bedcheck->stuDormitoryID == dormitoryNum&& bedcheck->stuBedID<=6&& bedcheck->stuBedID>0) {
				bedArray[bedcheck->stuBedID]=1;//1��ʾ�˴�λ�ѱ�ռ��
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
			printf("��ǰ��������, ��ѡ����������\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		stumove->stuBedID = bedNum;
		saveStudent(stuhead);
		//����������Ϣ
		dormitory* dormitoryMove = dorhead->next;
		while (dormitoryMove != NULL) {
			if (strcmp(dormitoryMove->dorBuilding, building) == 0 && dormitoryMove->dorID == dormitoryNum) {
				dormitoryMove->dorCheckInNumber++;
				saveDormitory(dorhead);
				break;
			}
			dormitoryMove = dormitoryMove->next;
		}
		printf("��������ɹ�\n");
		//��ͣ����
		system("pause");
		//��տ���̨
		system("cls");
		}
	

	
		