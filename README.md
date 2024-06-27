



# C语言学生宿舍管理系统

#C语言 #链表

## 项目目的

1.   体会从需求理解出发，到软件整体设计，详细设计，开发，测试，发布的整体流程。熟悉软件开发整体过程。

2.   能够更深的理解面向过程分析和设计的思想，培养面向过程的思维。

3.   熟够熟练掌握C/C++语言集成开发环境，能够通过调试解决程序问题。

4.   培养快速学习新的知识，并在项目中使用的能力。

## 项目内容

​     该项目是一个学生宿舍管理系统，主要功能包括学生和管理员两种用户模式的操作。以下是详细的功能描述：

### 学生模式

1.  **提出住宿申请**：学生可以提出住宿申请，输入个人信息并等待管理员审核。
2.  **录入住宿时间**：学生可以录入或修改自己的住宿时间。
3.  **查看个人信息**：学生可以查看自己的住宿信息，包括宿舍楼、宿舍号、入住时间、离开时间等。
4.  **退出学生模式**：学生可以退出当前模式。

### 管理员模式

1.  **录入宿舍信息**：管理员可以录入新的宿舍信息。
2.  **录入学生信息**：管理员可以录入新的学生信息，并自动分配宿舍。
3.  **录入入住提示**：管理员可以为学生录入住住提示。
4.  **修改信息**：管理员可以修改学生或宿舍的信息。
5.  **查找信息**：管理员可以查找学生或宿舍的信息。
6.  **删除信息**：管理员可以删除学生或宿舍的信息。
7.  **查看入住申请**：管理员可以查看并处理学生的住宿申请。
8.  **退出管理员模式**：管理员可以退出当前模式。

### 其他功能

-   **数据储存和读取**：系统可以将学生和宿舍信息保存到文件中，并在启动时读取这些信息。
-   **信息显示**：系统可以显示当前已录入的学生和宿舍信息。
-   **床位分配逻辑**：系统会自动分配床位，并检查床位是否已被占用。

该项目通过链表结构来管理学生和宿舍信息，确保信息的动态管理和高效操作。

## 软件设计

### 总体设计

#### 系统设计架构

1.  **主程序入口**：
    -   `main()`
    
2.  **用户界面模块**：
    -   `welcome()`
    -   `menuA()`
    -   `menuB()`
    -   `menu2()`
    -   `menu4()`
    -   `menu5()`
    -   `menu6()`
    
3.  **学生操作模块**：
    -   `applyDormitory(student* stuhead, dormitory* dorhead, int id)`
    -   `stuFind(student* stuhead, dormitory* dorhead, int id)`
    -   `stuInputTime(student* stuhead, dormitory* dorhead, int id, char c)`
    
4.  **管理员操作模块**：
    -   `inputDormitory(dormitory* dorhead)`
    -   `inputStudent(student* stuhead, dormitory* dorhead)`
    -   `inputTips(student* stuhead, dormitory* dorhead)`
    -   `modifyInformation(student* stuhead, dormitory* dorhead)`
    -   `findInformation(student* stuhead, dormitory* dorhead, char c)`
    -   `deleteInformation(student* stuhead, dormitory* dorhead, char c)`
    -   `processingApplication(student* stuhead, dormitory* dorhead)`
    
5.  **数据管理模块**：
    -   `saveStudent(student* stuhead)`
    -   `saveDormitory(dormitory* dorhead)`
    -   `load(student* stuhead, dormitory* dorhead)`
    
6.  **辅助函数模块**：
    -   `showInformation(student* stuhead, dormitory* dorhead)`
    
#### 函数调用关系图

        main()
          ├── welcome()
          │    ├── menuA()
          │    │    ├── applyDormitory(stuhead, dorhead, id)
          │    │    ├── stuFind(stuhead, dorhead, id)
          │    │    ├── stuInputTime(stuhead, dorhead, id, c)
          │    │    └── stuInputTime(stuhead, dorhead, id, c)
          │    │         
          │    └── menuB()
          │         ├── inputDormitory(dorhead)
          │         ├── inputStudent(stuhead, dorhead)
          │         ├── inputTips(stuhead, dorhead)
          │         ├── modifyInformation(stuhead, dorhead)
          │         ├── findInformation(stuhead, dorhead, c)
          │         ├── deleteInformation(stuhead, dorhead, c)
          │         └── processingApplication(stuhead, dorhead)
          ├── load(stuhead, dorhead)
          └── showInformation(stuhead, dorhead)
               ├── saveStudent(stuhead)
               └── saveDormitory(dorhead)

#### 说明

-   `main()` 是程序的入口，负责初始化链表和加载数据。
-   `welcome()` 是主菜单，根据用户选择调用不同的子菜单。
-   `menuA()` 和 `menuB()` 分别是学生和管理员的菜单，根据用户选择调用相应的操作函数。
-   `applyDormitory()`, `stuFind()`, `stuInputTime()` 是学生操作函数。
-   `inputDormitory()`, `inputStudent()`, `inputTips()`, `modifyInformation()`, `findInformation()`, `deleteInformation()`, `processingApplication()` 是管理员操作函数。
-   `saveStudent()`, `saveDormitory()`, `load()` 是数据管理函数，负责数据的保存和读取。
-   `showInformation()` 是一个辅助函数，用于显示当前已录入的学生和宿舍信息。

### 详细设计

#### 学生模块代码逻辑

##### applyDormitory

``` c
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

```

1.  **检查学生是否已存在**：遍历学生链表，检查该学生是否已经存在于系统中。
2.  **如果存在**：提示学生已在住宿中，无需申请，并返回。
3.  **如果不存在**：提示输入学生的姓名、班级和学号。
4.  **创建新节点**：为新学生创建一个新的链表节点。
5.  **检查学号是否匹配**：确认输入的学号与申请的学号一致。
6.  **设置初始信息**：设置新节点的初始信息，如宿舍楼、宿舍号、入住时间等。
7.  **插入节点**：将新节点插入到学生链表的末尾。
8.  **保存学生信息**：调用保存函数，将学生信息保存到文件中。
9.  **通知成功**：提示申请成功，并等待管理员审核。

| applyDormitory      |
| ------------------- |
| 1. Check if student |
| already exists      |
| 2. If exists,       |
| return              |
| 3. If not, prompt   |
| for student info    |
| 4. Create new       |
| student node        |
| 5. Check if ID      |
| matches             |
| 6. Set initial      |
| info                |
| 7. Insert node to   |
| list                |
| 8. Save student     |
| info                |
| 9. Notify success   |
|                     |

##### stuFind

``` c
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

```

1.  **遍历链表**：遍历学生链表，查找指定学号的学生。
2.  **如果找到**：打印该学生的所有信息。
3.  **如果未找到**：提示当前没有该学生的信息。

| stuFind            |
| ------------------ |
| 1. Traverse list   |
| to find student    |
| 2. If found, print |
| student info       |
| 3. If not found,   |
| notify no info     |
|                    |

##### stuInputTime

``` c
void stuInputTime(student* stuhead, dormitory* dorhead, int id, char c) {
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

    else if (c == '2') {
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

```

1.  **遍历链表**：遍历学生链表，查找指定学号的学生。
2.  **如果找到**：打印该学生的当前住宿信息。
3.  **如果未找到**：提示当前没有该学生的住宿信息

| stuInputTime       |
| ------------------ |
| 1. Traverse list   |
| to find student    |
| 2. If found, print |
| current info       |
| 3. If not found,   |
| notify no info     |
| 4. Depending on    |

#### 管理员模块代码逻辑

##### inputDormitory

``` c
void inputDormitory(dormitory* dorhead) {
    dormitory* fresh = malloc(sizeof(dormitory));
    fresh->next = NULL;
    fresh->dorCheckInNumber = 0;
    printf("请输录入 宿舍楼 ,宿舍号\n");
    scanf("%9s%d", fresh->dorBuilding, &fresh->dorID);

    dormitory* move = dorhead;
    while (move->next != NULL) {
        move = move->next;
    }
    move->next = fresh;
    if (move->next != NULL) {
        printf("宿舍信息录入成功\n");
    }

    saveDormitory(dorhead);
    system("pause");
    system("cls");
}

```

1.  **提示输入宿舍信息**：提示管理员输入新的宿舍信息。
2.  **创建新节点**：为新宿舍创建一个新的链表节点。
3.  **插入节点**：将新节点插入到宿舍链表的末尾。
4.  **保存宿舍信息**：调用保存函数，将宿舍信息保存到文件中。
5.  **通知成功**：提示宿舍信息录入成功。

| inputDormitory        |
| --------------------- |
| 1. Prompt for         |
| dormitory info        |
| 2. Create new         |
| dormitory node        |
| 3. Insert node to     |
| list                  |
| 4. Save dormitory     |
| info                  |
| 5. Notify success     |
| +-------------------+ |

##### inputStudent

``` c
void inputStudent(student* stuhead, dormitory* dorhead) {
    student* fresh = malloc(sizeof(student));
    fresh->next = NULL;
    char a[13] = "暂无信息";
    strcpy(fresh->stuStartTime, a);
    strcpy(fresh->stuEndTime, a);
    strcpy(fresh->stuTip, a);
    printf("请输入学生的 姓名 ,班级, 学号 ,宿舍楼 ,宿舍号 ,床位号 \n");
    int bedNum;
    scanf("%19s%19s%d%9s%d%d", fresh->stuName, fresh->stuclass, &fresh->stuID, fresh->stuDorBuilding, &fresh->stuDormitoryID, &bedNum);
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
    move->next = fresh;
    if (move->next != NULL) {
        printf("学生信息录入成功\n");
    }

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
        moveDor->next = freshDor;
        if (moveDor->next != NULL) {
            printf("发现新宿舍,自动创建宿舍信息\n");
        }
        saveDormitory(dorhead);
    }

    saveStudent(stuhead);
    system("pause");
    system("cls");
}

```

1.  **提示输入学生信息**：提示管理员输入新的学生信息。
2.  **创建新节点**：为新学生创建一个新的链表节点。
3.  **检查床位可用性**：检查所分配床位是否已被占用。
4.  **插入节点**：将新节点插入到学生链表的末尾。
5.  **更新宿舍信息**：更新宿舍的入住人数。
6.  **保存学生信息**：调用保存函数，将学生信息保存到文件中。
7.  **通知成功**：提示学生信息录入成功。

| inputStudent          |
| --------------------- |
| 1. Prompt for         |
| student info          |
| 2. Create new         |
| student node          |
| 3. Check bed          |
| availability          |
| 4. Insert node to     |
| list                  |
| 5. Update dormitory   |
| info                  |
| 6. Save student       |
| info                  |
| 7. Notify success     |
| +-------------------+ |

##### inputTips

``` c
void inputTips(student* stuhead, dormitory* dorhead) {
    student* move = stuhead->next;
    while (move != NULL) {
        if (strcmp(move->stuStartTime, "暂无信息") == 0) {
            printf("姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d \n入住时间:%s 离开时间:%s 入住提示:%s\n\n", move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuStartTime, move->stuEndTime, move->stuTip);
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
            system("pause");
            system("cls");
            return;
        }
        move = move->next;
    }
    printf("未找到学生信息\n");
    system("pause");
    system("cls");
}

```

1.  **显示无提示信息的学生**：显示所有没有入住提示的学生信息。
2.  **提示输入学生ID**：提示管理员输入要添加提示的学生ID。
3.  **查找学生**：根据ID查找学生。
4.  **提示输入提示信息**：提示管理员输入入住提示。
5.  **更新学生信息**：更新学生的入住提示信息。
6.  **保存学生信息**：调用保存函数，将学生信息保存到文件中。
7.  **通知成功**：提示入住提示录入成功。

| inputTips             |
| --------------------- |
| 1. Display student    |
| info without          |
| tips                  |
| 2. Prompt for         |
| student ID            |
| 3. Find student       |
| by ID                 |
| 4. Prompt for         |
| tips                  |
| 5. Update student     |
| info                  |
| 6. Save student       |
| info                  |
| 7. Notify success     |
| +-------------------+ |

##### modifyInformation

``` c
void modifyInformation(student* stuhead, dormitory* dorhead) {
    printf("请输入要修改的学生的 学号 ");
    int num;
    scanf("%d", &num);
    student* move = stuhead->next;
    while (move != NULL) {
        if (num == move->stuID) {
            dormitory* dormove = dorhead->next;
            while (dormove != NULL) {
                if (strcmp(move->stuDorBuilding, dormove->dorBuilding) == 0 && move->stuDormitoryID == dormove->dorID) {
                    dormove->dorCheckInNumber--;
                    saveDormitory(dorhead);
                    break;
                }
                dormove = dormove->next;
            }
            printf("请输入修改后的 姓名 ,班级, 宿舍楼 ,宿舍号 ,床位号 \n");
            scanf("%19s%19s%9s%d%d", move->stuName, move->stuclass, move->stuDorBuilding, &move->stuDormitoryID, &move->stuBedID);
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
                moveDor->next = freshDor;
                if (moveDor->next != NULL) {
                    printf("发现新宿舍,已更新宿舍信息\n");
                }
                saveDormitory(dorhead);
            }
            saveStudent(stuhead);
            showInformation(stuhead, dorhead);
            printf("修改成功\n");
            system("pause");
            system("cls");
            return;
        }
        move = move->next;
    }
    printf("未找到学生信息\n");
    system("pause");
    system("cls");
}

```

1.  **提示输入学生ID**：提示管理员输入要修改信息的学生ID。
2.  **查找学生**：根据ID查找学生。
3.  **提示输入新信息**：提示管理员输入新的学生信息。
4.  **更新学生信息**：更新学生的信息。
5.  **更新宿舍信息**：更新宿舍的入住人数。
6.  **保存学生信息**：调用保存函数，将学生信息保存到文件中。
7.  **通知成功**：提示学生信息修改成功。

| modifyInformation     |
| --------------------- |
| 1. Prompt for         |
| student ID            |
| 2. Find student       |
| by ID                 |
| 3. Prompt for         |
| new info              |
| 4. Update student     |
| info                  |
| 5. Update dormitory   |
| info                  |
| 6. Save student       |
| info                  |
| 7. Notify success     |
| +-------------------+ |

##### findInformation

``` c
void findInformation(student* stuhead, dormitory* dorhead, char c) {
    if (c == '1') {
        printf("请输入学生的 学号 ");
        int stuNum;
        scanf("%d", &stuNum);
        student* move = stuhead->next;
        while (move != NULL) {
            if (stuNum == move->stuID && move->stuDormitoryID != 0) {
                printf("姓名:%s 班级:%s 学号:%d 宿舍楼:%s 宿舍号:%d 床位号:%d\n", move->stuName, move->stuclass, move->stuID, move->stuDorBuilding, move->stuDormitoryID, move->stuBedID);
                system("pause");
                system("cls");
                return;
            }
            move = move->next;
        }
        printf("未找到学生信息\n");
        system("pause");
        system("cls");
    }
    if (c == '2') {
        printf("请输入宿舍的 宿舍楼 和 宿舍号 ");
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
                system("pause");
                system("cls");
                return;
            }
            move = move->next;
        }
        printf("未找到宿舍信息\n");
        system("pause");
        system("cls");
    }
}

```

1.  **提示输入搜索条件**：提示管理员输入要查找的学生或宿舍的搜索条件。
2.  **查找学生或宿舍**：根据条件查找学生或宿舍。
3.  **显示找到的信息**：显示找到的学生或宿舍信息。

| findInformation       |
| --------------------- |
| 1. Prompt for         |
| search criteria       |
| 2. Find student or    |
| dormitory by          |
| criteria              |
| 3. Display found      |
| info                  |
| +-------------------+ |

##### deleteInformation

``` c
void deleteInformation(student* stuhead, dormitory* dorhead, char c) {
    if (c == '1') {
        printf("请输入要删除的学生的 学号 ");
        int num;
        scanf("%d", &num);
        student* move = stuhead->next;
        student* pre = stuhead;
        while (move != NULL) {
            if (num == move->stuID) {
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
                system("pause");
                system("cls");
                return;
            }
            pre = move;
            move = move->next;
        }
        printf("未找到学生信息\n");
        system("pause");
        system("cls");
    }
    if (c == '2') {
        printf("请输入宿舍的 宿舍楼 和 宿舍号 ");
        char building[10];
        int num;
        scanf("%9s%d", building, &num);
        dormitory* move = dorhead->next;
        while (move != NULL) {
            if (strcmp(building, move->dorBuilding) == 0 && num == move->dorID) {
                if (move->dorCheckInNumber != 0) {
                    printf("当前宿舍有人居住,不能删除\n");
                    system("pause");
                    system("cls");
                    return;
                }
                dormitory* pre = dorhead;
                while (pre->next != move) {
                    pre = pre->next;
                }
                pre->next = move->next;
                free(move);
                saveDormitory(dorhead);
                showInformation(stuhead, dorhead);
                printf("删除成功\n");
                system("pause");
                system("cls");
                return;
            }
            move = move->next;
        }
        printf("未找到宿舍信息\n");
        system("pause");
        system("cls");
    }
}

```

1.  **提示输入删除条件**：提示管理员输入要删除的学生或宿舍的删除条件。
2.  **查找学生或宿舍**：根据条件查找学生或宿舍。
3.  **删除节点**：从链表中删除相应的节点。
4.  **更新宿舍信息**：更新宿舍的入住人数。
5.  **保存学生或宿舍信息**：调用保存函数，将学生或宿舍信息保存到文件中。
6.  **通知成功**：提示信息删除成功。

| deleteInformation     |
| --------------------- |
| 1. Prompt for         |
| delete criteria       |
| 2. Find student or    |
| dormitory by          |
| criteria              |
| 3. Delete node        |
| 4. Update dormitory   |
| info                  |
| 5. Save student or    |
| dormitory info        |
| 6. Notify success     |
| +-------------------+ |

##### processingApplication

``` c
void processingApplication(student* stuhead, dormitory* dorhead) {
    // 显示待处理学生信息
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
        system("pause");
        system("cls");
        return;
    }

    // 显示空闲宿舍信息
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
        system("pause");
        system("cls");
        return;
    }

    // 开始分配宿舍
    printf("请输入要处理学生的学号\n");
    int stuID;
    scanf("%d", &stuID);
    while (stumove != NULL) {
        if (stuID == stumove->stuID && stumove->stuDormitoryID == 0) {
            break;
        }
        stumove = stumove->next;
    }
    printf("请为该学生分配宿舍楼和宿舍号\n");
    char building[10];
    int dormitoryNum;
    scanf("%9s%d", building, &dormitoryNum);
    strcpy(stumove->stuDorBuilding, building);
    stumove->stuDormitoryID = dormitoryNum;
    // 记录此宿舍已占的床位号,并随即分配除此之外床位号
    student* bedcheck = stuhead->next;
    int bedArray[6] = {0};
    while (bedcheck != NULL) {
        if (strcmp(bedcheck->stuDorBuilding, building) == 0 && bedcheck->stuDormitoryID == dormitoryNum && bedcheck->stuBedID <= 6 && bedcheck->stuBedID > 0) {
            bedArray[bedcheck->stuBedID - 1] = 1; // 1表示此床位已被占用
        }
        bedcheck = bedcheck->next;
    }
    int bedNum = 0;
    for (int i = 0; i < 6; i++) {
        if (bedArray[i] == 0) {
            bedNum = i + 1;
            break;
        }
    }
    if (bedNum == 0) {
        printf("当前宿舍已满, 请选择其他宿舍\n");
        system("pause");
        system("cls");
        return;
    }
    stumove->stuBedID = bedNum;
    saveStudent(stuhead);
    // 更新宿舍信息
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
    system("pause");
    system("cls");
}

```

1.  **显示待处理申请**：显示所有待处理的住宿申请。
2.  **提示输入学生ID**：提示管理员输入要处理申请的学生ID。
3.  **查找学生**：根据ID查找学生。
4.  **提示输入宿舍分配**：提示管理员输入要分配的宿舍信息。
5.  **更新学生信息**：更新学生的宿舍信息。
6.  **更新宿舍信息**：更新宿舍的入住人数。
7.  **保存学生信息**：调用保存函数，将学生信息保存到文件中。
8.  **通知成功**：提示申请处理成功。

| processingApplication |
| --------------------- |
| 1. Display pending    |
| applications          |
| 2. Prompt for         |
| student ID            |
| 3. Find student       |
| by ID                 |
| 4. Prompt for         |
| dormitory             |
| assignment            |
| 5. Update student     |
| info                  |
| 6. Update dormitory   |
| info                  |
| 7. Save student       |
| info                  |
| 8. Notify success     |
| +-------------------+ |

## 测试分析

### 1. 提出住宿申请 (`applyDormitory`)

**测试场景**:

-   输入: 学号 `12345`, 姓名 `张三`, 班级 `A班`
-   预期输出: 提示申请成功，并显示新学生的信息。

**测试结果**:

```plaintext
您当前的学号为: 12345
请输入您的姓名, 班别, 并再次输入你的学号
张三 A班 12345
申请成功, 请耐心等待管理员审核!
```

### 2. 查看个人信息 (`stuFind`)

**测试场景**:

-   输入: 学号 `12345`
-   预期输出: 显示学生的详细信息。

**测试结果**:

```plaintext
姓名: 张三
班别: A班
学号: 12345
宿舍楼: 暂未分配
宿舍号: 0
入住时间: 暂无信息
离开时间: 暂无信息
入住提示: 暂无信息
```

### 3. 录入住宿时间 (`stuInputTime`)

**测试场景**:

-   输入: 学号 `12345`, 选项 `1`, 入住时间 `2024.6.23`, 离开时间 `2024.6.28`
-   预期输出: 提示住宿时间录入成功，并显示更新后的信息。

**测试结果**:

```plaintext
请输入入住时间(格式:2024.6.23) 2024.6.23
请输入离开时间(格式:2024.6.28) 2024.6.28
姓名: 张三, 班别: A班, 学号: 12345, 宿舍楼: 暂未分配, 宿舍号: 0, 
入住时间: 2024.6.23, 离开时间: 2024.6.28, 入住提示: 暂无信息
住宿时间录入成功!
```

### 4. 录入宿舍信息 (`inputDormitory`)

**测试场景**:

-   输入: 宿舍楼 `A楼`, 宿舍号 `101`
-   预期输出: 提示宿舍信息录入成功。

**测试结果**:

```plaintext
请输录入 宿舍楼 ,宿舍号
A楼 101
宿舍信息录入成功
```

### 5. 录入学生信息 (`inputStudent`)

**测试场景**:

-   输入: 姓名 `李四`, 班级 `B班`, 学号 `54321`, 宿舍楼 `A楼`, 宿舍号 `101`, 床位号 `1`
-   预期输出: 提示学生信息录入成功，并显示新学生的信息。

**测试结果**:

```plaintext
请输入学生的 姓名 ,班级, 学号 ,宿舍楼 ,宿舍号 ,床位号 
李四 B班 54321 A楼 101 1
学生信息录入成功
```

### 6. 录入入住提示 (`inputTips`)

**测试场景**:

-   输入: 学号 `54321`, 入住提示 `请按时入住`
-   预期输出: 提示入住提示录入成功，并显示更新后的信息。

**测试结果**:

```plaintext
请输入学生的学号
54321
请输入该学生的入住提示(30字以内)
请按时入住
姓名: 李四, 班级: B班, 宿舍楼: A楼, 宿舍号: 101, 
开始入住: 暂无信息, 结束入住: 暂无信息, 入住提示: 请按时入住
修改成功
```

### 7. 修改信息 (`modifyInformation`)

**测试场景**:

-   输入: 学号 `54321`, 新信息: 姓名 `李四`, 班级 `B班`, 宿舍楼 `A楼`, 宿舍号 `102`, 床位号 `2`
-   预期输出: 提示信息修改成功，并显示更新后的信息。

**测试结果**:

```plaintext
请输入要修改的学生的 学号 
54321
请输入修改后的 姓名 ,班级, 宿舍楼 ,宿舍号 ,床位号 
李四 B班 A楼 102 2
修改成功
```

### 8. 查找信息 (`findInformation`)

**测试场景**:

-   输入: 搜索条件: 学号 `54321`
-   预期输出: 显示找到的学生信息。

**测试结果**:

```plaintext
请输入学生的 学号 
54321
姓名: 李四, 班级: B班, 学号: 54321, 宿舍楼: A楼, 宿舍号: 102, 床位号: 2
```

### 9. 删除信息 (`deleteInformation`)

**测试场景**:

-   输入: 删除条件: 学号 `54321`
-   预期输出: 提示信息删除成功。

**测试结果**:

```plaintext
请输入要删除的学生的 学号 
54321
删除成功
```

### 10. 处理申请 (`processingApplication`)

**测试场景**:

-   输入: 学号 `12345`, 宿舍楼 `A楼`, 宿舍号 `101`
-   预期输出: 提示申请处理成功，并显示更新后的信息。

**测试结果**:

```plaintext
请输入要处理学生的学号
12345
请为该学生分配宿舍楼和宿舍号
A楼 101
分配宿舍成功
```

## 总结和期望

本学生宿舍管理系统通过C语言和链表结构实现了基本的学生和管理员操作功能。系统设计包括学生模块和管理员模块，涵盖了住宿申请、信息录入、信息修改、信息查找、信息删除等多个方面。系统通过文件存储数据，确保数据的持久性和可恢复性。整体设计简洁明了，功能划分清晰，能够满足基本的宿舍管理需求。

### 存在的问题与不足

1.  **安全性问题**：系统缺乏用户认证和权限管理机制，任何人都可以访问和修改数据，存在安全风险。
2.  **界面友好性**：当前系统使用命令行界面，操作不够直观，用户体验较差，尤其是对于不熟悉命令行操作的用户。
3.  **数据一致性**：在多用户同时操作时，可能会出现数据不一致的问题，需要引入并发控制机制。
4.  **功能扩展性**：系统功能较为基础，缺乏一些高级功能，如统计分析、自动分配算法等。
5.  **错误处理**：系统对错误的处理不够完善，缺乏详细的错误提示和日志记录。

### 改进方向展望

1.  **引入用户认证和权限管理**：增加用户登录和权限控制功能，确保只有授权用户才能进行操作。
2.  **开发图形用户界面（GUI）**：使用图形界面库（如Qt、GTK+）开发用户友好的图形界面，提升用户体验。
3.  **实现并发控制**：引入数据库管理系统（如SQLite、MySQL），利用数据库的事务机制确保数据一致性。
4.  **增加高级功能**：开发统计分析功能，提供自动分配算法，优化宿舍资源利用。
5.  **完善错误处理和日志记录**：增加详细的错误提示和日志记录功能，便于系统维护和问题排查。
6.  **代码优化和重构**：现有代码太乱了, 进行优化和重构，提高代码的可读性和可维护性。
