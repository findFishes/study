#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h> 
using namespace std;

void help();
void run(int ch[25][12],int level);
int menu();
int put(int a[25][12]);
int getnew(int a[8] ,int flag);
int getold(int tu[25][12],int a[8],int q);
int check(int ch[25][12] ,int score);
int newnum(int t);
void reset(int ch[25][12]);
void choose(int ch[25][12],int level);
int main( )
{  
	int kuang[25][12];
	int flag,level;
	level=1;
	
	reset(kuang);
    flag=menu();
	system("cls");
	do
	{
		switch(flag)
		{
		case 1:
			{
				run(kuang,level);
				break ;
			}
		case 2:
			{
				help();
				break;
			}
		case 3:
			{
				choose(kuang,level);
				break;
			}
		case 4:
			{
				system("cls");
				cout << "�Ѿ��˳�......." << endl;
				exit(0);
				break;
			}
		default:
			{
				system("cls");
				cout << "�������������ѡ��" << endl;
				flag=menu();
			}
		}
	} while (1);
}

void choose(int ch[25][12],int level)
{

	cout << "������ѡ��ȼ�(1-6)��" << endl;
	cout << "���س�����ʼ��Ϸ��" << endl;
	cout << "�������˵��밴0��" << endl;
	cin >> level;	
	switch(level)
	{
	case 0:
		{
			system("cls");
			main();
			break;
		}
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		{
			run(ch,level);
			break;
		}
	}
}

void reset(int ch[25][12])
{  
	int i,j;
	for(i=0;i<25;i++)
	{	
		ch[i][0]=1;
		ch[i][11]=1;
		for(j=1;j<11;j++)
		{
			ch[i][j]=0;
			ch[24][j]=1;
		}
	}
}

int newnum(int t)
{
	while(1)
	{
		if(t==0)
		{
			break ;
		}
		if(t==1)
		{
			t=2;break ;
		}
		if(t==2)
		{
			t=1;break ;
		}
		if(t==3)
		{
			t=4;break ;
		}
		if(t==4)
		{
			t=3;break ;
		}
		if(t==5)
		{
			t=6;break ;
		}
		if(t==6)
		{
			t=5;break ;
		}
		if(t>6&&t<11)
		{
			if(t==10)
			{
				t=7;break ;
			}
			else
			{
				t++;break ;
			}
		}
		if(t>10&&t<15)
		{
			if(t==14)
			{
				t=11;break;
			}
			else
			{
				t++;break;
			}
		}
		if(t>14&&t<19)
		{
			if(t==18)
			{
				t=15;break;
			}
			else
			{
				t++;break;
			}
		}
	   }
	   return t;
}

int menu()
{
    int i;
	system("Color f8"); // ������ɫ
    cout << endl << endl << endl;
	cout << '\t' << "1. ��ʼ��Ϸ   " << endl;
	cout << '\t' << "2. ����       " << endl;
	cout << '\t' << "3. ѡ��ȼ�   " << endl;
	cout << '\t' << "4. �˳���Ϸ   " << endl;
    cout << endl;
	cout << "��ѡ��";
	cin >> i;	
	return i;
}

int put(int a[25][12])
{    	
	int i,j;
	for(i=4;i<25;i++)
	{
		for(j=0;j<12;j++)
		{
			if(a[i][j]==0)
			{
				cout << "  ";
			}
			else
				if(a[i][j]==1)
				{
					cout << "��";
				}
				else
					if(a[i][j]==2||a[i][j]==3)
					{
						cout << "��";
					}
		}
		cout << endl;		
	}
	return 0;
}

void run(int ch[25][12],int level)
{   
	int newtu[8];
	int time,c;
	int  flag=8,i,k=0,key,t,score=0;
	switch(level)
	{
	case 1:
		time=32,c=9;break;
	case 2:
		time=16,c=8;break;
	case 3:
		time=8,c=7;break;
	case 4:
		time=4,c=6;break;
	case 5:
		time=2,c=5;break;
    case 6:
		time=1,c=4;break;
	}
	while(1)
	{ 
		t=getnew(newtu,flag);
		while(1)
		{  
			ch[newtu[0]][newtu[4]]=0;
			ch[newtu[1]][newtu[5]]=0;
			ch[newtu[2]][newtu[6]]=0;
			ch[newtu[3]][newtu[7]]=0;
			ch[newtu[0]+1][newtu[4]]=3;
			ch[newtu[1]+1][newtu[5]]=3;
			ch[newtu[2]+1][newtu[6]]=3;
			ch[newtu[3]+1][newtu[7]]=3;
			newtu[0]++,newtu[1]++,newtu[2]++,newtu[3]++;
			for(i=0;i<c;i++)
			{   
				Sleep(time);
				system("cls");
				put(ch);
				cout << "�ȼ�--" << level << '\t';
				cout << "����--" << score << endl;
				if(kbhit())
				{
					key=getch();
					if((key=='a'||key=='A')&&ch[newtu[0]][newtu[4]-1]!=1&&
						ch[newtu[1]][newtu[5]-1]!=1&&ch[newtu[2]][newtu[6]-1]!=1&&
						ch[newtu[3]][newtu[7]-1]!=1&&ch[newtu[0]][newtu[4]-1]!=2&&
						ch[newtu[1]][newtu[5]-1]!=2&&ch[newtu[2]][newtu[6]-1]!=2&&
						ch[newtu[3]][newtu[7]-1]!=2)
					{
						ch[newtu[0]][newtu[4]]=0,ch[newtu[1]][newtu[5]]=0;
						ch[newtu[2]][newtu[6]]=0,ch[newtu[3]][newtu[7]]=0;
						ch[newtu[0]][newtu[4]-1]=3,ch[newtu[1]][newtu[5]-1]=3;
						ch[newtu[2]][newtu[6]-1]=3,ch[newtu[3]][newtu[7]-1]=3;
						newtu[4]--,newtu[5]--,newtu[6]--,newtu[7]--;
					}
					if((key=='d'||key=='D')&&ch[newtu[0]][newtu[4]+1]!=1&&
						ch[newtu[1]][newtu[5]+1]!=1&&ch[newtu[2]][newtu[6]+1]!=1&&
						ch[newtu[3]][newtu[7]+1]!=1&&ch[newtu[0]][newtu[4]+1]!=2&&
						ch[newtu[1]][newtu[5]+1]!=2&&ch[newtu[2]][newtu[6]+1]!=2&&
						ch[newtu[3]][newtu[7]+1]!=2)
					{
						ch[newtu[0]][newtu[4]]=0,ch[newtu[1]][newtu[5]]=0;
						ch[newtu[2]][newtu[6]]=0,ch[newtu[3]][newtu[7]]=0;
						ch[newtu[0]][newtu[4]+1]=3,ch[newtu[1]][newtu[5]+1]=3;
						ch[newtu[2]][newtu[6]+1]=3,ch[newtu[3]][newtu[7]+1]=3;
						newtu[4]++,newtu[5]++,newtu[6]++,newtu[7]++;
					}
					if((key=='s'||key=='S')&&ch[newtu[0]+1][newtu[4]]!=1&&
						ch[newtu[1]+1][newtu[5]]!=1&&ch[newtu[2]+1][newtu[6]]!=1&&
						ch[newtu[3]+1][newtu[7]]!=1&&ch[newtu[0]+1][newtu[4]]!=2&&
						ch[newtu[1]+1][newtu[5]]!=2&&ch[newtu[2]+1][newtu[6]]!=2&&
						ch[newtu[3]+1][newtu[7]]!=2)
					{
						ch[newtu[0]][newtu[4]]=0,ch[newtu[1]][newtu[5]]=0;
						ch[newtu[2]][newtu[6]]=0,ch[newtu[3]][newtu[7]]=0;
						ch[newtu[0]+1][newtu[4]]=3,ch[newtu[1]+1][newtu[5]]=3;
						ch[newtu[2]+1][newtu[6]]=3,ch[newtu[3]+1][newtu[7]]=3;
						newtu[0]++,newtu[1]++,newtu[2]++,newtu[3]++;
					}
					if(key=='w'||key=='W')
					{
						t=getold(ch,newtu,t);
					}
				}
			}
			if(ch[newtu[0]+1][newtu[4]]==2||
				ch[newtu[0]+1][newtu[4]]==1||
				ch[newtu[1]+1][newtu[5]]==2||
				ch[newtu[1]+1][newtu[5]]==1||
				ch[newtu[2]+1][newtu[6]]==2||
				ch[newtu[2]+1][newtu[6]]==1||
				ch[newtu[3]+1][newtu[7]]==2||
				ch[newtu[3]+1][newtu[7]]==1)
			{	
				ch[newtu[0]][newtu[4]]=2;
				ch[newtu[1]][newtu[5]]=2;
				ch[newtu[2]][newtu[6]]=2;
				ch[newtu[3]][newtu[7]]=2;
				score=check(ch,score);
				score=check(ch,score);
				score=check(ch,score);
				score=check(ch,score);
				if(score>300)
				{
					reset(ch);
					score=0;
					time=time/2;
					level++;
					c--;
				}
				for(i=1;i<11;i++)
				{
					if(ch[4][i]==2)
					{
						k=1;	
					}
				}
				if(k==1)
				{
					cout << "GAME OVER��" << endl;
					cout << "��������������˵���" << endl;
					getch();
                    system("cls");
					main();
				}
				else
				{
					k=0;
				}
				break ;
			}	
		}
	}
	
}
int  getold(int tu[25][12],int a[8],int q)
{
	int i,x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4,t;
	int ch[19][8]={
		{1,1,2,2,5,6,5,6},
		{2,2,2,2,4,5,6,7},
		{0,1,2,3,6,6,6,6},
		{0,1,1,2,5,5,6,6},
		{1,1,2,2,6,7,5,6},
		{0,1,1,2,6,5,6,5},
		{1,1,2,2,5,6,6,7},
		{1,2,2,2,6,5,6,7},
		{0,1,1,2,5,5,6,5},
		{1,1,1,2,5,6,7,6},
		{0,1,1,2,6,5,6,6},
		{0,0,1,2,5,6,5,5},
		{1,2,2,2,5,5,6,7},
		{0,1,2,2,6,6,5,6},
		{1,1,1,2,5,6,7,7},
		{0,0,1,2,5,6,6,6},
		{1,2,2,2,7,5,6,7},
		{0,1,2,2,5,5,5,6},
		{1,1,1,2,5,6,7,5}};
		x_1=a[0]-ch[q][0];
		x_2=a[1]-ch[q][1];
		x_3=a[2]-ch[q][2];
		x_4=a[3]-ch[q][3];
		y_1=a[4]-ch[q][4];
		y_2=a[5]-ch[q][5];
		y_3=a[6]-ch[q][6];
		y_4=a[7]-ch[q][7];
		t=newnum(q);
		if(tu[ch[t][0]+x_1][ch[t][4]+y_1]!=1&&
			tu[ch[t][0]+x_1][ch[t][4]+y_1]!=2&&
			tu[ch[t][1]+x_2][ch[t][5]+y_2]!=1&&
			tu[ch[t][1]+x_2][ch[t][5]+y_2]!=2&&
			tu[ch[t][2]+x_3][ch[t][6]+y_3]!=1&&
			tu[ch[t][2]+x_3][ch[t][6]+y_3]!=2&&
			tu[ch[t][3]+x_4][ch[t][7]+y_4]!=1&&
			tu[ch[t][3]+x_4][ch[t][7]+y_4]!=2)
		{
			for(i=0;i<4;i++)
			{
				tu[a[i]][a[i+4]]=0;
			}
			a[0]=ch[t][0]+x_1,a[1]=ch[t][1]+x_2;
			a[2]=ch[t][2]+x_3,a[3]=ch[t][3]+x_4;
			a[4]=ch[t][4]+y_1,a[5]=ch[t][5]+y_2;
			a[6]=ch[t][6]+y_3,a[7]=ch[t][7]+y_4;
			tu[a[0]][a[4]]=3,tu[a[1]][a[5]]=3;
			tu[a[2]][a[6]]=3,tu[a[3]][a[7]]=3;
			q=t;
		}
		return q;
}
void help()
{
	cout << "�����������Ϸ���ʼ��������������" << endl;
	cout << "�ҿ������Ĳ�����: ��90��Ϊ��λ��ת" << endl;
	cout << "����. �Ը���Ϊ��λ�����ƶ����鷽��" << endl;
	cout << "�Ƶ��������·������ŵص�����������" << endl;
	cout << "�޷��ƶ�ʱ���ͻ�̶��ڸô������µ�" << endl;
	cout << "��������������Ϸ���ʼ����. ������" << endl;
	cout << "��ĳһ�к������ȫ���ɷ����������" << endl;
	cout << "�л���ʧ����Ϊ��ҵĵ÷�ͬʱɾ����" << endl;
	cout << "����Խ��.�÷�ָ������.���̶��ķ���" << endl;
	cout << "�ѵ��������Ϸ����޷���������ʱ����" << endl;
	cout << "��Ϸ����.     ������������:       " << endl;
	cout << "w��W��תש�飬s��W��ש������½�  " << endl;
	cout << "a��Aʹש�����ƣ�d��Dʹש������" << endl << endl << endl;
    cout << "��������������˵�!" << endl;
	getch();
	system("cls");
	main();
}
int  getnew(int a[8] ,int flag)
{              
	int i,h;
    int tu[19][8]={
		{1,1,2,2,5,6,5,6},
		{2,2,2,2,4,5,6,7},
		{0,1,2,3,6,6,6,6},
		{0,1,1,2,5,5,6,6},
		{1,1,2,2,6,7,5,6},
		{0,1,1,2,6,5,6,5},
		{1,1,2,2,5,6,6,7},
		{1,2,2,2,6,5,6,7},
		{0,1,1,2,5,5,6,5},
		{1,1,1,2,5,6,7,6},
		{0,1,1,2,6,5,6,6},
		{0,0,1,2,5,6,5,5},
		{1,2,2,2,5,5,6,7},
		{0,1,2,2,6,6,5,6},
		{1,1,1,2,5,6,7,7},
		{0,0,1,2,5,6,6,6},
		{1,2,2,2,7,5,6,7},
		{0,1,2,2,5,5,5,6},
		{1,1,1,2,5,6,7,5}};
		srand((unsigned)time(NULL));
		h=rand()%19;
		for(i=0;i<8;i++)
		{
			a[i]=tu[h][i];
		}
		return h;
}
int  check(int ch[25][12],int score)
{
	int i,j,b,c;
	b=0,c=4;
	while(c<24)
	{
		if(ch[c][1]==2&&ch[c][2]==2&&ch[c][3]==2&&
			ch[c][4]==2&&ch[c][5]==2&&ch[c][6]==2&&
			ch[c][7]==2&&ch[c][8]==2&&ch[c][9]==2&&
			ch[c][10]==2)
		{
			b=c;break;
		}
		c++;
	}
	if(b!=0)
	{
		for(i=b;i>3;i--)
		{
			for(j=1;j<11;j++)
			{
				ch[i][j]=ch[i-1][j];
			}
		}
		score=score+10;
	}
	return score;
}
