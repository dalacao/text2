#include"student.h"
/*
����
*/
struct student * create()          //����������ѧ����Ϣ��  ���ļ��н�ѧ����Ϣ��ȡ����
{
	char title[100];
	FILE *fp;
	struct student *head, *p , *q;
    	p = q = (struct student *)malloc(LEN);
	if( ( fp = fopen("data00.txt","r") ) == NULL )
	{
		printf( "can't open file\n" );
		exit(1);
	}
	fgets( title, 100, fp );
	head = p;
	fscanf( fp , "%ld%s%f%f%f\n",&q->num, p->name, &p->s1,&p->s2,&p->s3 );
	p->sum = p->s1 + p->s2 + p->s3;
	while(!feof(fp))
	{
		q = (struct student *)malloc(LEN);
		fscanf( fp,"%ld%s%f%f%f%\n", &q->num,q->name, &q->s1,&q->s2,&q->s3 );
		q->sum = q->s1 + q->s2 + q->s3;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(fp);
	return head;
}

void sort(struct student *head) //���� 
{
    	struct student *p , *q ;
	p = head;
	while( p ) //��̨����������
   	{
		p->sum = p->s1 + p->s2 + p->s3;
		p->rank = 1;
		q = head;
		while(q!=p)
		{
			if((q->sum) > (p->sum))
			{
				p->rank +=1;
			}
			else if((q->sum)< (p->sum))
			{
				q->rank +=1;
			}
			q = q->next;
		}
		p = p->next;
	}	
}

void locatename(struct student *head)   //��ѯ��Ϣ
{
	struct student *p , *q;
	char name[20];
    	printf("\n������Ҫ��ѯѧ��������:");
    	scanf("%s",name); 
    	p = head;
    	q = p->next;
	if(strcmp(name,p->name)==0)
	{
		printf("\nѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num,p->name, p->s1, p->s2, p->s3 , p->sum ,p->rank );
	}
	else
	{
		while(q && (strcmp(q->name,name)!=0))
		{
			q = q->next;
		}
		if(q)
		{
			printf("��ѯ����ϢΪ:\n");
			printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
			printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,q->num,q->name, q->s1, q->s2, q->s3 , q->sum ,q->rank );
		}
		else
		{
			printf("û��%sѧ��\n",name);
		}
	}
}

void locatenum(struct student *head)   //��ѯ��Ϣ
{
	struct student *p , *q;
	long num;
    	printf("\n������Ҫ��ѯѧ����ѧ��:");
    	scanf("%d",&num); 
	fflush(stdin);
    	p = head;
    	q = p->next;
	if( p->num == num )
	{
		printf("\nѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num,p->name, p->s1, p->s2, p->s3 , p->sum ,p->rank );
	}
	else
	{
		while(q && q->num != num )
		{
			q = q->next;
		}
		if(q)
		{
			printf("��ѯ����ϢΪ:\n");
			printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
			printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,q->num,q->name, q->s1, q->s2, q->s3 , q->sum ,q->rank );
		}
		else
		{
			printf("û�и�ѧ��������������\n");
		}
	}
}
struct student * delname(struct student *head)  //ͨ������ɾ��ѧ����Ϣ 
{
	char name[20];
	struct student  *p , *q;
	printf("����������Ҫɾ��������\n");
	scanf("%s",name);
    	if( head==NULL )
    	{
        	printf("\nlist null!\n");
		return head;
    	}
    	p  = head;
    	while( strcmp(p->name,name)!=0 && p->next!=NULL)
    	{
        	q = p ;
		p = p->next;
    	}  //ֱ���ҵ�Ϊֹ
    	if(strcmp(p->name,name)==0 )  //����ƥ��
    	{
		if( p == head )    //������ѧ���ǵ�һ��ѧ���Ļ�
        	{
			head = p->next;
			printf("��ɾ����ѧ����ϢΪ:\n");
			printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" , p->num,p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("ѧ��%sɾ���ɹ�\n",name);
		}//ͷheadҪ�� ��Ȼ�Ҳ�����
        	else
        	{
			q->next=p->next;
            		printf("��ɾ����ѧ����ϢΪ:\n");
			printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("ѧ��%sɾ���ɹ�\n",name);
        	}
	}
	if(strcmp(p->name,name)!=0 )
	{
		printf("û��%sѧ��\n",name);
	}
	return head;
}

struct student * delnum(struct student *head)  //ͨ��ѧ��ɾ��ѧ����Ϣ 
{
	long num;
	struct student  *p , *q;
	printf("����������Ҫɾ����ѧ��\n");
	scanf("%ld",&num);
	fflush(stdin);
    	if( head==NULL )
    	{
        	printf("\nlist null!\n");
		return head;
    	}
    	p  = head;
    	while( p->num != num && p->next!=NULL)
    	{
        	q = p ;
		p = p->next;
    	}  //ֱ���ҵ�Ϊֹ
    	if(p->num == num )  //����ƥ��
    	{
		if( p == head )    //������ѧ���ǵ�һ��ѧ���Ļ�
        	{
			head = p->next;
			printf("��ɾ����ѧ����ϢΪ:\n");
			printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" , p->num,p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("ѧ��Ϊ%ld��ѧ��ɾ���ɹ�\n",num);
		}//ͷheadҪ�� ��Ȼ�Ҳ�����
        	else
        	{
			q->next=p->next;
            		printf("��ɾ����ѧ����ϢΪ:\n");
			printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("ѧ��Ϊ%ld��ѧ��ɾ���ɹ�\n",num);
        	}
	}
	if(p->num != num )
	{
		printf("û�и�ѧ��������������\n");
	}
	return head;
}

struct student * changename(struct student *head) //ͨ������ȥ�޸�ѧ������
{
	struct student *p ,*q;
	char name[20];
	printf("�����������޸ĵ�����\n");
	scanf("%s",name);
	fflush(stdin);
    	p = head;
	while( strcmp(p->name,name)!=0 && p->next!=NULL)
    	{
        	q = p ;
		p = p->next;
    }  //ֱ���ҵ�Ϊֹ
    	if(strcmp(p->name,name)==0)
    	{
		printf("ѧ��%s����\n",p->name);
		printf("��Ҫ�޸ĵ�ѧ����ϢΪ:\n");
		printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
        	printf("���޸��ں����ķ���:\n");
		scanf("%f",&p->s1);
		printf("���޸ķ��յķ���:\n");
		scanf("%f",&p->s2);
		printf("���޸�ȥ�������ķ���:\n");
		scanf("%f",&p->s3);
		p->sum = p->s1 + p->s2 + p->s3;
		sort(head);
		printf("�����Ѿ���ɸ���\n");
		printf("���º��ѧ����ϢΪ:\n");
		printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum,p->rank );
    }
	else if(strcmp(q->name,name)==0)
	{
		printf("ѧ��%s����\n",p->name);
        	printf("���޸��ں����ķ���:\n");
		scanf("%f",&p->s1);
		printf("���޸ķ��յķ���:\n");
		scanf("%f",&p->s2);
		printf("���޸�ȥ�������ķ���:\n");
		scanf("%f",&p->s3);
		printf("�����Ѿ���ɸ���\n");
		p->sum = p->s1 + p->s2 + p->s3;
	}
	else
	{
		printf("û��%sѧ��\n",name);
		
	}
	return head;
}

struct student * changenum(struct student *head) //ͨ��ѧ��ȥ�޸�ѧ������
{
	struct student *p ,*q;
	long num;
	printf("�����������޸ĵ�ѧ��\n");
	scanf( "%ld",&num );
	fflush(stdin);
    	p = head;
	while( p->num != num && p->next!=NULL)
    	{
        	q = p ;
		p = p->next;
    	}  //ֱ���ҵ�Ϊֹ
    	if( p->num == num )
    	{
		printf("ѧ��Ϊ%ld��ѧ������\n",p->num);
		printf("��Ҫ�޸ĵ�ѧ����ϢΪ:\n");
		printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
        	printf("���޸��ں����ķ���:\n");
		scanf("%f",&p->s1);
		printf("���޸ķ��յķ���:\n");
		scanf("%f",&p->s2);
		printf("���޸�ȥ�������ķ���:\n");
		scanf("%f",&p->s3);
		p->sum = p->s1 + p->s2 + p->s3;
		sort(head);
		printf("�����Ѿ���ɸ���\n");
		printf("���º��ѧ����ϢΪ:\n");
		printf("ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum,p->rank );
    	}
	else if( p->num == num )
	{
		printf("ѧ��Ϊ%ld��ѧ������\n",p->num);
        	printf("���޸��ں����ķ���:\n");
		scanf("%f",&p->s1);
		printf("���޸ķ��յķ���:\n");
		scanf("%f",&p->s2);
		printf("���޸�ȥ�������ķ���:\n");
		scanf("%f",&p->s3);
		printf("�����Ѿ���ɸ���\n");
		p->sum = p->s1 + p->s2 + p->s3;
	}
	else
	{
		printf("\nû�и�ѧ��������������\n");
	}
	return head;
}

void filein(struct student *head)//���浽�ļ��� 
{
	char title[50];
    	FILE *fp;
    	struct student *p;
    	if((fp=fopen("data11.txt","w"))==NULL)//���ļ� 
    	{
        	printf("can't open.\n");
        	exit(-1);
    	}
    	p = head;
	fprintf(fp,"ѧ��\t����\t�ں���\t����\tȥ������\t����ָ��\t����\t\n");
	while(p)
	{
		p->sum = p->s1 + p->s2 + p->s3;
        	fprintf(fp , "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%2d\n",p->num,p->name, p->s1, p->s2, p->s3 , p->sum , p->rank );
        	p = p->next;
	}
	fclose(fp);
}

 //���ѧ����Ϣ  �˺����Ѿ����
 void print(struct student *head)
 {
    	struct student *p;
	p = head;
	while(p)
	{
		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n",p->num,p->name , p->s1 , p->s2 , p->s3 , p->sum , p->rank );
		p = p->next;
    	}
}



void ABCD(struct student *head)
{
    	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int n7 = 0;
	int n8 = 0;
	int n9 = 0;
	int n10 = 0;
	int n11 = 0;
	int n12 = 0;
	//ͳ�Ʒ����ε�����
    	struct student *p;
	FILE *fp;
    	p = head;
	printf("A�ȼ�Ϊ90--100\nB�ȼ�Ϊ60--89\nC�ȼ�Ϊ30--59\nD�ȼ�Ϊ<30\n");
    	while(p!=NULL)
    	{
		if( p->s1 >= 90  )
		{
			n1 ++;
		}
		if( (p->s1 >= 60 ) && ( p->s1 < 90 ) )
		{
			n2 ++;
		}
		if( (p->s1 >= 30 ) && ( p->s1 < 60 ) )
		{
			n3 ++;
		}
		if( p->s1 < 30  )
		{
			n4 ++;
		}
		if( p->s2 >= 90  )
		{
			n5 ++;
		}
		if( (p->s2 >= 60 ) && ( p->s2 < 90 ) )
		{
			n6 ++;
		}
		if( (p->s2 >= 30 ) && ( p->s2 < 60 ) )
		{
			n7 ++;
		}
		if( p->s2 < 30  )
		{
			n8 ++;
		}
		if( p->s3 >= 90  )
		{
			n9 ++;
		}
		if( (p->s3 >= 60 ) && ( p->s3 < 90 ) )
		{
			n10 ++;
		}
		if( (p->s3 >= 30 ) && ( p->s3 < 60  ) )
		{
			n11 ++;
		}
		if( p->s3 < 30  )
		{
			n12 ++;
		}
		
		p = p->next;
    }
	printf("\n���������Ѿ����ɱ��\n");
	printf("\n�ȼ�\tA\tB\tC\tD\t����\n�ں���\t%d\t%d\t%d\t%d\t%3d\n",n1,n2,n3,n4,n1+n2+n3+n4);
    	printf("����\t%d\t%d\t%d\t%d\t%3d\n",n5,n6,n7,n8,n5+n6+n7+n8);
	printf("ȥ������\t%d\t%d\t%d\t%d\t%3d\n",n9,n10,n11,n12,n9+n10+n11+n12);
	printf("����\t%d\t%d\t%d\t%d\t%3d\n",n1+n5+n9,n2+n6+n10,n3+n7+n11,n4+n8+n12,n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12);
	if((fp=fopen("abcd.txt","w"))==NULL)//���ļ� 
    	{
        	printf("can't open.\n");
        	exit(-1);
    	}
	fprintf(fp,"���������Ѿ����ɱ��\n");
	fprintf(fp,"A�ȼ�Ϊ90--100\nB�ȼ�Ϊ60--89\nC�ȼ�Ϊ30--59\nD�ȼ�Ϊ<30\n");
	fprintf(fp,"\n�ȼ�\tA\tB\tC\tD\t����\n�ں���\t%d\t%d\t%d\t%d\t%3d\n",n1,n2,n3,n4,n1+n2+n3+n4);
    	fprintf(fp,"����\t%d\t%d\t%d\t%d\t%3d\n",n5,n6,n7,n8,n5+n6+n7+n8);
	fprintf(fp,"ȥ������\t%d\t%d\t%d\t%d\t%3d\n",n9,n10,n11,n12,n9+n10+n11+n12);
	fprintf(fp,"����\t%d\t%d\t%d\t%d\t%3d\n",n1+n5+n9,n2+n6+n10,n3+n7+n11,n4+n8+n12,n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12);
	fclose(fp);
}

void max(struct student * head)
{
	struct student *p,*p1,*p2,*p3,*p4,*p5,*p6,*p7,*summax,*summin,*s1max,*s2max,*s3max,*s1min,*s2min,*s3min;
	FILE *fp;
	p = head;
	p1 = head;
	p2 = head;
	p3 = head;
	p4 = head;
	p5 = head;
	p6 = head;
	p7 = head;
	summax = p;
	s1max = p1;
	s2max = p2;
	s3max = p3;
	summin = p4;
	s1min = p5;
	s2min = p6;
	s3min = p7;
	summax->sum = summax->s1+summax->s2+summax->s3;
	summin->sum = summin->s1+summin->s2+summin->s3;
	while(p!=NULL)
	{
		if(p->sum > summax->sum)
		{
			summax = p;
		}
		p = p->next;
	}
	while(p1!=NULL)
	{
		if(p1->sum > s1max->sum)
		{
			s1max = p1;
		}
		p1 = p1->next;
	}
	while(p2!=NULL)
	{
		if(p2->sum > s2max->sum)
		{
			s2max = p2;
		}
		p2 = p2->next;
	}
	while(p3!=NULL)
	{
		if(p3->sum > s3max->sum)
		{
			s3max = p3;
		}
		p3 = p3->next;
	}
	while(p4!=NULL)
	{
		if(p4->sum < summin->sum)
		{
			summin = p4;
		}
		p4 = p4->next;
	}
	while(p5!=NULL)
	{
		if(p5->s1 < s1min->s1)
		{
			s1min = p5;
		}
		p5= p5->next;
	}
	while(p6!=NULL)
	{
		if(p6->s2 < s2min->s2)
		{
			s2min = p6;
		}
		p6 = p6->next;
	}
	while(p7!=NULL)
	{
		if(p7->s2 < s3min->s3)
		{
			s3min = p7;
		}
		p7 = p7->next;
	}
	printf("\t����\t\t�ں���\t\t\t����\t\t\tȥ������\n");
	printf("��߷�\t%.2f(%s)\t%.2f(%s)\t\t%.2f(%s)\t\t%.2f(%s)\n",summax->sum,summax->name,s1max->s1,s1max->name,s2max->s2,s2max->name,s3max->s3,s3max->name);
	printf("��ͷ�\t%.2f(%s)\t%.2f(%s)\t\t%.2f(%s)\t\t%.2f(%s)\n",summin->sum,summin->name,s1min->s1,s1min->name,s2min->s2,s2min->name,s3min->s3,s3min->name);
	if((fp=fopen("max.txt","w"))==NULL)//���ļ� 
    	{
        	printf("can't open.\n");
        	exit(-1);
    	}
	fprintf(fp,"\t\t����\t\t\t�ں���\t\t\t����\t\t\tȥ������\n");
	fprintf(fp,"��߷�\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\n",summax->sum,summax->name,s1max->s1,s1max->name,s2max->s2,s2max->name,s3max->s3,s3max->name);
	fprintf(fp,"��ͷ�\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\n",summin->sum,summin->name,s1min->s1,s1min->name,s2min->s2,s2min->name,s3min->s3,s3min->name);
	fclose(fp);
}

