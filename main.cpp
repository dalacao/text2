#include"student.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    	char answer;
	int choice;
    	struct student *head ;
	head = create(); 
	sort(head);
	printf("\t\t����ʦ����ѧѧ�������ϱ�����ϵͳ\n");
	printf("\n\t************    xitong  5.0      ***************\n");
	printf("\n\t************powered by 17����һ�***************\n");
	printf("\n\t\t\t���������¼ϵͳ\n");  
	getchar();
	system("cls");
	do
	{
		printf("��ӭ�㣬����Ա��\n");
		printf("|---------------------------------------|\n");
		printf("|\t������ѡ����(0-6):\t\t|");
		printf("\n|---------------------------------------|\n");
		printf("|\t1--���ѧ����Ϣ:\t\t|\n");
		printf("|\t2--��ѯѧ����Ϣ:\t\t|\n");
		printf("|\t3--�޸�ѧ����Ϣ:\t\t|\n");
		printf("|\t4--ɾ��ѧ����Ϣ:\t\t|\n");
		printf("|\t5--����÷�:\t\t\t|\n");
		printf("|\t6--��߷�:\t\t\t|\n");
		printf("|\t0--�˳�ϵͳ:\t\t\t|\n");
		printf("|---------------------------------------|\n");
		printf("������ѡ��");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 0:
				{
					printf("********�˳�ϵͳ*********\n");
					filein(head);//���޸ĺ�����ݱ�����data11.txt��
					printf("�޸ĵ������Ѿ�������data11.txt��\n");
					printf("��ӭ�´�ʹ��\n");
					exit(0);
					break;
				}
			case 1:
				{
					system("cls");
					printf("*************ѧ�������ϱ���Ϣһ����********************\n");
					printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
					print(head); //��ӡ�����˵���Ϣ
					printf("\n������������ص��˵�\n");
					getch();
					system("cls");
					break;
				}
			case 2:
				{
					
					while(1)
					{
						printf("��ѡ���ѯ��ʽ\n");
						printf("1.����\n2.ѧ��\n");
						scanf("%s",&answer);
						if( answer == '1' )
						{
							locatename(head);//��ѯ��Ϣ
						}
						if(answer == '2' )
						{
							locatenum(head);
						}
						if(answer != '1' && answer!= '2')
						{
							printf("�������\n");
						}
						printf("1.��������س��������ѯ\n0.�˳�\n");
						scanf("%s",&answer);
						fflush(stdin);
						if(answer == '0' )
						{
							break;
						}
						
					}
					printf("\n��������ص��˵�");
					getch();
					system("cls");
					break;
				}
			case 3:
				{
					while(1)
					{
						printf("��ѡ���޸ķ����ķ�ʽ\n");
						printf("1.����\n2.ѧ��\n");
						scanf("%s",&answer);
						if(answer == '1')
						{
							changename(head);
							sort(head); //�޸ķ�������������
						}
						if(answer == '2')
						{
							changenum(head);
							sort(head); //�޸ķ�������������
						}
						if(answer != '1' && answer!= '2')
						{
							printf("�������\n");
						}
						printf("�Ƿ����\n");
						printf("1.��������س�������޸�\n0.�˳�\n");
						scanf("%s",&answer);
						if(answer=='0')
						{
							break;
						}
					}
					printf("\n��������ص��˵�\n");
					getch();
					system("cls");
					break;
				}
			case 4:
				{
					while(1)
					{
						printf("��ѡ��ɾ��ѧ���ķ�ʽ\n");
						printf("1.����\n2.ѧ��\n");
						scanf("%s",&answer);
						if(answer=='1')
						{
							head= delname(head); //ɾ��ͷʱͷҪ��
							sort(head); //ɾ��ѧ������������
						}
						if(answer=='2')
						{
							head= delnum(head); //ɾ��ͷʱͷҪ��
							sort(head); //ɾ��ѧ������������
						}
						if(answer != '1' && answer!= '2')
						{
							printf("�������\n");
						}
						printf("�Ƿ����\n");
						printf("1.����ɾ��\n0.�˳�\n");
						scanf("%s",&answer);
						if(answer=='0')
						{
							break;
						}
					}
					
					printf("\n�����������ִ������Ҫ�Ĳ���");
					getch();
					system("cls");
					break;
				}
			case 5:
				{
					ABCD(head);//��������
					printf("\n�����������ִ������Ҫ�Ĳ���");
					getch();
					system("cls");
					break;
				}
			case 6:
				{
					
					max(head);
					printf("\n�����������ִ������Ҫ�Ĳ���");
					getch();
					system("cls");
					break;

				}
			default:
				{
					printf("********û�����ѡ��*********\n���������������\n");
					getch();
					break;
				}
		} 
	}while(1);                           
    return 0;
 }


