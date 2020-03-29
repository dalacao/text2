#include"student.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    	char answer;
	int choice;
    	struct student *head ;
	head = create(); 
	sort(head);
	printf("\t\t西北师范大学学生疫情上报管理系统\n");
	printf("\n\t************    xitong  5.0      ***************\n");
	printf("\n\t************powered by 17网络狄慧***************\n");
	printf("\n\t\t\t按任意键登录系统\n");  
	getchar();
	system("cls");
	do
	{
		printf("欢迎你，管理员！\n");
		printf("|---------------------------------------|\n");
		printf("|\t请输入选项编号(0-6):\t\t|");
		printf("\n|---------------------------------------|\n");
		printf("|\t1--浏览学生信息:\t\t|\n");
		printf("|\t2--查询学生信息:\t\t|\n");
		printf("|\t3--修改学生信息:\t\t|\n");
		printf("|\t4--删除学生信息:\t\t|\n");
		printf("|\t5--各项得分:\t\t\t|\n");
		printf("|\t6--最高分:\t\t\t|\n");
		printf("|\t0--退出系统:\t\t\t|\n");
		printf("|---------------------------------------|\n");
		printf("请输入选项");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 0:
				{
					printf("********退出系统*********\n");
					filein(head);//将修改后的数据保存在data11.txt中
					printf("修改的数据已经保存在data11.txt中\n");
					printf("欢迎下次使用\n");
					exit(0);
					break;
				}
			case 1:
				{
					system("cls");
					printf("*************学生疫情上报信息一览表********************\n");
					printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
					print(head); //打印所有人的信息
					printf("\n按任意键继续回到菜单\n");
					getch();
					system("cls");
					break;
				}
			case 2:
				{
					
					while(1)
					{
						printf("请选择查询方式\n");
						printf("1.姓名\n2.学号\n");
						scanf("%s",&answer);
						if( answer == '1' )
						{
							locatename(head);//查询信息
						}
						if(answer == '2' )
						{
							locatenum(head);
						}
						if(answer != '1' && answer!= '2')
						{
							printf("输入错误\n");
						}
						printf("1.按任意键回车后继续查询\n0.退出\n");
						scanf("%s",&answer);
						fflush(stdin);
						if(answer == '0' )
						{
							break;
						}
						
					}
					printf("\n按任意键回到菜单");
					getch();
					system("cls");
					break;
				}
			case 3:
				{
					while(1)
					{
						printf("请选择修改分数的方式\n");
						printf("1.姓名\n2.学号\n");
						scanf("%s",&answer);
						if(answer == '1')
						{
							changename(head);
							sort(head); //修改分数后重新排序
						}
						if(answer == '2')
						{
							changenum(head);
							sort(head); //修改分数后重新排序
						}
						if(answer != '1' && answer!= '2')
						{
							printf("输入错误\n");
						}
						printf("是否继续\n");
						printf("1.按任意键回车后继续修改\n0.退出\n");
						scanf("%s",&answer);
						if(answer=='0')
						{
							break;
						}
					}
					printf("\n按任意键回到菜单\n");
					getch();
					system("cls");
					break;
				}
			case 4:
				{
					while(1)
					{
						printf("请选择删除学生的方式\n");
						printf("1.姓名\n2.学号\n");
						scanf("%s",&answer);
						if(answer=='1')
						{
							head= delname(head); //删除头时头要换
							sort(head); //删除学生后重新排序
						}
						if(answer=='2')
						{
							head= delnum(head); //删除头时头要换
							sort(head); //删除学生后重新排序
						}
						if(answer != '1' && answer!= '2')
						{
							printf("输入错误\n");
						}
						printf("是否继续\n");
						printf("1.继续删除\n0.退出\n");
						scanf("%s",&answer);
						if(answer=='0')
						{
							break;
						}
					}
					
					printf("\n按任意键继续执行你想要的操作");
					getch();
					system("cls");
					break;
				}
			case 5:
				{
					ABCD(head);//计算人数
					printf("\n按任意键继续执行你想要的操作");
					getch();
					system("cls");
					break;
				}
			case 6:
				{
					
					max(head);
					printf("\n按任意键继续执行你想要的操作");
					getch();
					system("cls");
					break;

				}
			default:
				{
					printf("********没有这个选项*********\n按任意键重新输入\n");
					getch();
					break;
				}
		} 
	}while(1);                           
    return 0;
 }


