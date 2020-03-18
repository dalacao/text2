#include"student.h"
/*
函数
*/
struct student * create()          //建立基础的学生信息库  从文件中将学生信息读取出来
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

void sort(struct student *head) //排序 
{
    	struct student *p , *q ;
	p = head;
	while( p ) //擂台法进行排序
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

void locatename(struct student *head)   //查询信息
{
	struct student *p , *q;
	char name[20];
    	printf("\n请输入要查询学生的姓名:");
    	scanf("%s",name); 
    	p = head;
    	q = p->next;
	if(strcmp(name,p->name)==0)
	{
		printf("\n学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
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
			printf("查询的信息为:\n");
			printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
			printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,q->num,q->name, q->s1, q->s2, q->s3 , q->sum ,q->rank );
		}
		else
		{
			printf("没有%s学生\n",name);
		}
	}
}

void locatenum(struct student *head)   //查询信息
{
	struct student *p , *q;
	long num;
    	printf("\n请输入要查询学生的学号:");
    	scanf("%d",&num); 
	fflush(stdin);
    	p = head;
    	q = p->next;
	if( p->num == num )
	{
		printf("\n学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
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
			printf("查询的信息为:\n");
			printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
			printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,q->num,q->name, q->s1, q->s2, q->s3 , q->sum ,q->rank );
		}
		else
		{
			printf("没有该学生，请重新输入\n");
		}
	}
}
struct student * delname(struct student *head)  //通过姓名删除学生信息 
{
	char name[20];
	struct student  *p , *q;
	printf("请输如你想要删除的姓名\n");
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
    	}  //直到找到为止
    	if(strcmp(p->name,name)==0 )  //姓名匹配
    	{
		if( p == head )    //如果这个学生是第一个学生的话
        	{
			head = p->next;
			printf("你删除的学生信息为:\n");
			printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" , p->num,p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("学生%s删除成功\n",name);
		}//头head要换 不然找不到了
        	else
        	{
			q->next=p->next;
            		printf("你删除的学生信息为:\n");
			printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("学生%s删除成功\n",name);
        	}
	}
	if(strcmp(p->name,name)!=0 )
	{
		printf("没有%s学生\n",name);
	}
	return head;
}

struct student * delnum(struct student *head)  //通过学号删除学生信息 
{
	long num;
	struct student  *p , *q;
	printf("请输如你想要删除的学号\n");
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
    	}  //直到找到为止
    	if(p->num == num )  //姓名匹配
    	{
		if( p == head )    //如果这个学生是第一个学生的话
        	{
			head = p->next;
			printf("你删除的学生信息为:\n");
			printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" , p->num,p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("学号为%ld的学生删除成功\n",num);
		}//头head要换 不然找不到了
        	else
        	{
			q->next=p->next;
            		printf("你删除的学生信息为:\n");
			printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
            		printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
			printf("学号为%ld的学生删除成功\n",num);
        	}
	}
	if(p->num != num )
	{
		printf("没有该学生，请重新输入\n");
	}
	return head;
}

struct student * changename(struct student *head) //通过姓名去修改学生数据
{
	struct student *p ,*q;
	char name[20];
	printf("请输入你想修改的姓名\n");
	scanf("%s",name);
	fflush(stdin);
    	p = head;
	while( strcmp(p->name,name)!=0 && p->next!=NULL)
    	{
        	q = p ;
		p = p->next;
    }  //直到找到为止
    	if(strcmp(p->name,name)==0)
    	{
		printf("学生%s存在\n",p->name);
		printf("你要修改的学生信息为:\n");
		printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
        	printf("请修改在湖北的分数:\n");
		scanf("%f",&p->s1);
		printf("请修改发烧的分数:\n");
		scanf("%f",&p->s2);
		printf("请修改去过湖北的分数:\n");
		scanf("%f",&p->s3);
		p->sum = p->s1 + p->s2 + p->s3;
		sort(head);
		printf("分数已经完成更新\n");
		printf("更新后的学生信息为:\n");
		printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum,p->rank );
    }
	else if(strcmp(q->name,name)==0)
	{
		printf("学生%s存在\n",p->name);
        	printf("请修改在湖北的分数:\n");
		scanf("%f",&p->s1);
		printf("请修改发烧的分数:\n");
		scanf("%f",&p->s2);
		printf("请修改去过湖北的分数:\n");
		scanf("%f",&p->s3);
		printf("分数已经完成更新\n");
		p->sum = p->s1 + p->s2 + p->s3;
	}
	else
	{
		printf("没有%s学生\n",name);
		
	}
	return head;
}

struct student * changenum(struct student *head) //通过学号去修改学生数据
{
	struct student *p ,*q;
	long num;
	printf("请输入你想修改的学号\n");
	scanf( "%ld",&num );
	fflush(stdin);
    	p = head;
	while( p->num != num && p->next!=NULL)
    	{
        	q = p ;
		p = p->next;
    	}  //直到找到为止
    	if( p->num == num )
    	{
		printf("学号为%ld的学生存在\n",p->num);
		printf("你要修改的学生信息为:\n");
		printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum, p->rank );
        	printf("请修改在湖北的分数:\n");
		scanf("%f",&p->s1);
		printf("请修改发烧的分数:\n");
		scanf("%f",&p->s2);
		printf("请修改去过湖北的分数:\n");
		scanf("%f",&p->s3);
		p->sum = p->s1 + p->s2 + p->s3;
		sort(head);
		printf("分数已经完成更新\n");
		printf("更新后的学生信息为:\n");
		printf("学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\n");
        	printf( "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%3d\n" ,p->num, p->name, p->s1, p->s2, p->s3  ,p->sum,p->rank );
    	}
	else if( p->num == num )
	{
		printf("学号为%ld的学生存在\n",p->num);
        	printf("请修改在湖北的分数:\n");
		scanf("%f",&p->s1);
		printf("请修改发烧的分数:\n");
		scanf("%f",&p->s2);
		printf("请修改去过湖北的分数:\n");
		scanf("%f",&p->s3);
		printf("分数已经完成更新\n");
		p->sum = p->s1 + p->s2 + p->s3;
	}
	else
	{
		printf("\n没有该学生，请重新输入\n");
	}
	return head;
}

void filein(struct student *head)//保存到文件中 
{
	char title[50];
    	FILE *fp;
    	struct student *p;
    	if((fp=fopen("data11.txt","w"))==NULL)//打开文件 
    	{
        	printf("can't open.\n");
        	exit(-1);
    	}
    	p = head;
	fprintf(fp,"学号\t姓名\t在湖北\t发烧\t去过湖北\t健康指数\t排名\t\n");
	while(p)
	{
		p->sum = p->s1 + p->s2 + p->s3;
        	fprintf(fp , "%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%2d\n",p->num,p->name, p->s1, p->s2, p->s3 , p->sum , p->rank );
        	p = p->next;
	}
	fclose(fp);
}

 //输出学生信息  此函数已经完成
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
	//统计分数段的人数
    	struct student *p;
	FILE *fp;
    	p = head;
	printf("A等级为90--100\nB等级为60--89\nC等级为30--59\nD等级为<30\n");
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
	printf("\n分数分析已经生成表格\n");
	printf("\n等级\tA\tB\tC\tD\t总数\n在湖北\t%d\t%d\t%d\t%d\t%3d\n",n1,n2,n3,n4,n1+n2+n3+n4);
    	printf("发烧\t%d\t%d\t%d\t%d\t%3d\n",n5,n6,n7,n8,n5+n6+n7+n8);
	printf("去过湖北\t%d\t%d\t%d\t%d\t%3d\n",n9,n10,n11,n12,n9+n10+n11+n12);
	printf("总数\t%d\t%d\t%d\t%d\t%3d\n",n1+n5+n9,n2+n6+n10,n3+n7+n11,n4+n8+n12,n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12);
	if((fp=fopen("abcd.txt","w"))==NULL)//打开文件 
    	{
        	printf("can't open.\n");
        	exit(-1);
    	}
	fprintf(fp,"分数分析已经生成表格\n");
	fprintf(fp,"A等级为90--100\nB等级为60--89\nC等级为30--59\nD等级为<30\n");
	fprintf(fp,"\n等级\tA\tB\tC\tD\t总数\n在湖北\t%d\t%d\t%d\t%d\t%3d\n",n1,n2,n3,n4,n1+n2+n3+n4);
    	fprintf(fp,"发烧\t%d\t%d\t%d\t%d\t%3d\n",n5,n6,n7,n8,n5+n6+n7+n8);
	fprintf(fp,"去过湖北\t%d\t%d\t%d\t%d\t%3d\n",n9,n10,n11,n12,n9+n10+n11+n12);
	fprintf(fp,"总数\t%d\t%d\t%d\t%d\t%3d\n",n1+n5+n9,n2+n6+n10,n3+n7+n11,n4+n8+n12,n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12);
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
	printf("\t总数\t\t在湖北\t\t\t发烧\t\t\t去过湖北\n");
	printf("最高分\t%.2f(%s)\t%.2f(%s)\t\t%.2f(%s)\t\t%.2f(%s)\n",summax->sum,summax->name,s1max->s1,s1max->name,s2max->s2,s2max->name,s3max->s3,s3max->name);
	printf("最低分\t%.2f(%s)\t%.2f(%s)\t\t%.2f(%s)\t\t%.2f(%s)\n",summin->sum,summin->name,s1min->s1,s1min->name,s2min->s2,s2min->name,s3min->s3,s3min->name);
	if((fp=fopen("max.txt","w"))==NULL)//打开文件 
    	{
        	printf("can't open.\n");
        	exit(-1);
    	}
	fprintf(fp,"\t\t总数\t\t\t在湖北\t\t\t发烧\t\t\t去过湖北\n");
	fprintf(fp,"最高分\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\n",summax->sum,summax->name,s1max->s1,s1max->name,s2max->s2,s2max->name,s3max->s3,s3max->name);
	fprintf(fp,"最低分\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\t%.2f(%s)\n",summin->sum,summin->name,s1min->s1,s1min->name,s2min->s2,s2min->name,s3min->s3,s3min->name);
	fclose(fp);
}

