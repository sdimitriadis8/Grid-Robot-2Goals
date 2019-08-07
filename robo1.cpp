//����������� �������� �.�.:359
//
//
#include <iostream>
#include <vector>
#include <random>														// ���������� ��� C++ ��� �� random
//																		// ����� http://www.cplusplus.com/reference/random
//																		// ��� ���������� http://www.cplusplus.com/reference/random/discrete_distribution/
//																		// ��� ��� ������� ��� ���������������� �������� [1]
using namespace std;

class Komvos 
{
   	public:
		
		int a;  // 1� ������������ ��� ������
   		int b;  // 2� ������������ ��� ������
   		double h; // ���������� ������ ��������� ���������� h(n)
   		double g; // ������ ��������� ���� ���� n, g(n)
   		string path; // �������� ��� ��� �����
	
		// �������� ������ ������ f(n)=h(n)+g(n)
		double f()
		{
			return g+h;
		}
};

vector<class Komvos> Lista;


double heur(class Komvos,class Komvos);

int main()
{
	int reps=0;
	int flag=0;
	int check=0;
	int pos=-1;
	string fullpath="";
	int firstgoal=0;
	int N; 																		//������ ��� �������� � ��� �� ����� � ������� ��� �� ������-���� �������
	cout<<"Dwste to mege8os tou xwrou kinhshs tou mobile"<<endl;				// ��� �~10-20 ���
	cin>>N;																		// p~0.05-0.1 ������� "����" 
	cout<<endl;																	// �������� ��� ��������
	double p;																	// ������ ��� ����������� ��� �� ����� � �������
	cout<<"Dwste thn pi8anothta uparkshs empodiou sto plegma kinhshs"<<endl; 	// ��� ��� ������ ��������
	cin>>p;
	
	int A[N][N];
	vector<class Komvos> Lista;	// ����� ������-������� ���� ����������/�������
	vector<class Komvos> Passed;	// ����� ������ ��� �����������
	
	random_device rd;													// }   ������� ��� �� ���������� random
	mt19937 gen(rd());													// }-> [1](����� ������� ���������� ��������)
	discrete_distribution<int>distribution{1-p, p};						// }
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			A[i][j]=distribution(gen);
			cout<<A[i][j];
			
		}
		cout<<"\n";
	}
	
	int x=N+1; //������������ ��-������� ������������� ��� 
	int y=N+1; //������� ������� ��� �������� ��������
	// ��� �������� ����������������:
	// ������� ������������� ����������� ������� ��� ��� ������ ��� ������� �����,
	// ����� �� ��������� ������� ����� (����� ������/����� �������)
	while(x<0 || y<0 || x>=N || y>=N || A[x][y]==1)
	{
		cout<<"Dwste (mia pros mia)tis suntetagmenes tou shmeiou enarkshs tou mobile"<<endl;
		cin>>x;
		cin>>y;
		if(x<0 || y<0 || x>=N || y>=N || A[x][y]==1)
		{
			cout<<"Oi suntetagmenes tou shmeiou enarkshs, den einai egkures,"<<endl;
			cout<<"eite giati einai ektos tou xwrou kinhshs, eite giati uparxei"<<endl;
			cout<<"empodio sth sugkekrimenh 8esh. Elegkste thn eisodo sas!!"<<endl;
		}
		else
		{
			cout<<"Oi suntetagmenes kataxwrh8hkan. Ws shmeio enarkshs orisate to ("<<x<<", "<<y<<")"<<endl;
		}
		
	}
	
	int x1=N+1; // ������������ ��-������� ������������� 
	int y1=N+1; // ��� ������ ������ ��� �������� ��������
	// ��� �������� ����������������:
	// ������� ������������� ��� ������ ������ ��� ��� ������ ��� ������� �����,
	// ����� �� ��������� ������� ����� (����� ������/����� �������)
	while(x1<0 || y1<0 || x1>=N || y1>=N || A[x1][y1]==1)
	{
		cout<<"Dwste (mia pros mia)tis suntetagmenes tou prwtou stoxou gia to mobile"<<endl;
		cin>>x1;
		cin>>y1;
		if(x1<0 || y1<0 || x1>=N || y1>=N || A[x1][y1]==1)
		{
			cout<<"Oi suntetagmenes tou prwtou stoxou den einai egkures,"<<endl;
			cout<<"eite giati einai ektos tou xwrou kinhshs, eite giati uparxei"<<endl;
			cout<<"empodio sth sugkekrimenh 8esh. Elegkste thn eisodo sas!!"<<endl;
		}
		else
		{
			cout<<"Oi suntetagmenes kataxwrh8hkan. Ws prwto stoxo orisate to shmeio ("<<x1<<", "<<y1<<")"<<endl;
		}
	}
	
	int x2=N+1; // ������������ ��-������� ������������� 
	int y2=N+1; // ��� �������� ������ ��� �������� ��������
	// ��� �������� ����������������:
	// ������� ������������� ��� �������� ������ ��� ��� ������ ��� ������� �����,
	// ����� �� ��������� ������� ����� (����� ������/����� �������)
	while(x2<0 || y2<0 || x2>=N || y2>=N || A[x2][y2]==1)
	{
		cout<<"Dwste (mia pros mia)tis suntetagmenes tou deuterou stoxou gia to mobile"<<endl;
		cin>>x2;
		cin>>y2;
		if(x2<0 || y2<0 || x2>=N || y2>=N || A[x2][y2]==1)
		{
			cout<<"Oi suntetagmenes tou deuterou stoxou den einai egkures,"<<endl;
			cout<<"eite giati einai ektos tou xwrou kinhshs, eite giati uparxei"<<endl;
			cout<<"empodio sth sugkekrimenh 8esh. Elegkste thn eisodo sas!!"<<endl;
		}
		else
		{
			cout<<"Oi suntetagmenes kataxwrh8hkan. Ws deutero stoxo orisate to shmeio ("<<x2<<", "<<y2<<")"<<endl;
		}
	}
	
	// ������������ ��� ������ ��� �� ������ �������
	class Komvos S;
	S.a=x;
	S.b=y;
	S.g=0;
	S.path="(" + to_string(x) + "," + to_string(y) + ")";
	
	// ������������ ��� ������ ��� ��� ����� �����
	class Komvos G1;
	G1.a=x1;
	G1.b=y1;
	G1.h=0;
	G1.g=heur(S,G1);
	
	// ������������ ��� ������ ��� ��� ������� �����
	class Komvos G2;
	G2.a=x2;
	G2.b=y2;
	G2.h=0;
	G2.g=heur(S,G2);
	class Komvos GTemp;
	GTemp = G1;
	S.h=G1.g; //������������ ��� ������ ������ ���� G1 ��� ��� ��������
			 // ������� ��� ����������.
	if(G2.g<S.h)
	{
		S.h=G2.g;
		cout<<"O enarkthrios komvos apexei apo ton plhsiestero stoxo (G2): "<<S.h<<endl;
		GTemp = G2;
	}
	else
	{
		cout<<"O enarkthrios komvos apexei apo ton plhsiestero stoxo (G1): "<<S.h<<endl;
	}
	
	// ����� �������������� ��� ������� ����� �������...
    // .
	// .
	// .
	// ������ ����������� ��� ������������ ����������� ��
	// ����� ��� ���������� �*
	Lista.push_back(S);
	double hl=-1;
	double hr=-1;
	double hu=-1;
	double hd=-1;
	
	class Komvos cur;

	do
	{
		if(pos!=-1)
		{
			Lista.erase(Lista.begin()+pos);
		}
		if(Lista.empty())
		{
			cout<<"Den uparxoun alles dunates metavaseis"<<endl;
			cout<<"Den uparxei monopati pros teliko stoxo"<<endl;
			break;
		}
		cur=Lista.at(0); //������������ ��� ������ �� �� �������� ������
		//������ �� ����� ������ ��� �� ��� ����� �� �� ��������� ������...
		for(int i=0; i<Lista.size(); i++)
		{
			class Komvos temp = Lista.at(i); //Lista[i]
			if(temp.f()<=cur.f())
			{
				cur = temp;
				pos=i;
			}
		}
		// ����� � ������ cur ����� � ������������ ������ (minimum heuristic)
		
		Passed.push_back(cur);
		
		
		if(cur.a==GTemp.a && cur.b==GTemp.b)
		{
			cout<<"To mobile eftase ston stoxo"<<endl;
			cout<<"pou vrisketai sth 8esh ("<<cur.a<<","<<cur.b<<")"<<endl;
			flag++;
			if(GTemp.a==x1 && GTemp.b==y1)
			{
				cout<<"Vre8hke o stoxos G1"<<endl;
				firstgoal=1;				
			}
			else if(GTemp.a==x2 && GTemp.b==y2)
			{
				cout<<"Vre8hke o stoxos G2"<<endl;
				firstgoal=2;
			}
			cur.g=0;
			cur.h=heur(cur,GTemp);
			Lista.clear(); //������� �� ����� ����������� ��� ������������ ���..
			Lista.push_back(cur); // �������� ��� ������ ��������� ��� ����� �����������
			Passed.clear(); // ������� ��� �� ����� ��� ��� ��������������� ����������� ���...
			Passed.push_back(cur);// �������� ��� �� ���� ��� ������ ���������
			cout<<"Lista twra"<<endl;
			for(int i=0; i<Lista.size(); i++)
			{
				class Komvos temp = Lista.at(i); //Lista[i]
				cout<<"("<<temp.a<<","<<temp.b<<")"<<endl;
			}	
		}
		
		
		if(flag==0)
		{
			G1.g=heur(cur,G1);
			G2.g=heur(cur,G2);
			class Komvos GTemp;
			if(G1.g<G2.g)
			{
				GTemp = G1;
			}
			else
			{
				GTemp = G2;
			}	
			cout<<"O twrinos komvos apexei apo ton G1: "<<G1.g<<" , enw apo ton G2: "<<G2.g<<endl;
		}
		else if(flag==1)
		{
			if(firstgoal==1)
			{
				G2.g=heur(cur,G2);
				GTemp=G2;
			}
			else if(firstgoal==2)
			{
				G1.g=heur(cur,G1);
				GTemp=G1;
			}
			else
			{
				cout<<"O twrinos komvos apexei apo ton teliko stoxo: "<<GTemp.g<<endl;
			}
			for(int i=0; i<Lista.size(); i++)
			{
				class Komvos temp = Lista.at(i); //Lista[i]
				temp.h=heur(temp,GTemp);
				Lista[i] = temp;
			}
		}
		
		if((cur.b)-1>=0 && A[cur.a][(cur.b)-1]==0 && flag<2)//left
		{
			class Komvos left;
			left.a=cur.a;
			left.b=(cur.b)-1;
			hl=heur(left,GTemp);
			left.h=hl;
			left.g=cur.g+0.5;
			left.path=cur.path + "->(" + to_string(left.a) + "," + to_string(left.b) + ")";
			cout<<"To kostos gia ton left einai: "<<left.f()<<endl<<endl;
			for (int i=0; i<Passed.size(); i++)
			{
				class Komvos temp=Passed.at(i);
				if(temp.a==left.a && temp.b==left.b)
				{
					i=Passed.size();
					check=1;
				}
			}
			if(check==0)
			{
				Lista.push_back(left);
			}
			check=0;
		}
		if((cur.b)+1<N && A[cur.a][(cur.b)+1]==0 && flag<2)//right
		{
			class Komvos right;  
			right.a=cur.a;
			right.b=(cur.b)+1;
			hr=heur(right,GTemp);
			right.h=hr;
			right.g=cur.g+0.5;
			right.path=cur.path + "->(" + to_string(right.a) + "," + to_string(right.b) + ")";
			cout<<"To kostos gia ton right einai: "<<right.f()<<endl<<endl;
			for (int i=0; i<Passed.size(); i++)
			{
				class Komvos temp=Passed.at(i);
				if(temp.a==right.a && temp.b==right.b)
				{
					i=Passed.size();
					check=1;
				}
			}
			if(check==0)
			{
				Lista.push_back(right);
			}
			check=0;
		}
		if((cur.a)-1>=0 && A[(cur.a)-1][cur.b]==0 && flag<2)//up
		{
			class Komvos up;
			up.a=(cur.a)-1;
			up.b=cur.b;
			hu=heur(up,GTemp);
			up.h=hu;
			up.g=cur.g+1;
			up.path=cur.path + "->(" + to_string(up.a) + "," + to_string(up.b) + ")";
			cout<<"To kostos gia ton up einai: "<<up.f()<<endl<<endl;
			for (int i=0; i<Passed.size(); i++)
			{
				class Komvos temp=Passed.at(i);
				if(temp.a==up.a && temp.b==up.b)
				{
					i=Passed.size();
					check=1;
				}
			}
			if(check==0)
			{
				Lista.push_back(up);
			}
			check=0;
		}
		if((cur.a)+1<N && A[(cur.a)+1][cur.b]==0 && flag<2)//down
		{
			class Komvos down;
			down.a=(cur.a)+1;
			down.b=cur.b;
			hd=heur(down,GTemp);
			down.h=hd;
			down.g=cur.g+1;
			down.path=cur.path + "->(" + to_string(down.a) + "," + to_string(down.b) + ")";
			cout<<"To kostos gia ton down einai: "<<down.f()<<endl<<endl;
			for (int i=0; i<Passed.size(); i++)
			{
				class Komvos temp=Passed.at(i);
				if(temp.a==down.a && temp.b==down.b)
				{
					i=Passed.size();
					check=1;
				}
			}
			if(check==0)
			{
				Lista.push_back(down);				
			}
			check=0;
		}
		cout<<cur.path;	
		system("PAUSE");
	}
	while(flag<2);
	
	if(flag==2)
	{
		cout<<"To robot eftase epituxws kai stous duo stoxous"<<endl;
		cout<<"kai to monopati einai to ekshs:"<<endl;
		cout<<cur.path;
	}
	else if(flag==1)
	{
		cout<<"To robot eftase mono ston enan apo tous duo stoxous"<<endl;
		cout<<cur.path;
	}
	
	system("PAUSE");
}

double heur(class Komvos Start,class Komvos Goal)
{
	double mandist=abs(Start.b-Goal.b)*0.5+abs(Start.a-Goal.a);
	cout<<"To ("<<Start.a<<", "<<Start.b<<")"<<" apexei"<<endl;
	cout<<"apo to ("<<Goal.a<<", "<<Goal.b<<")"<<" apostash "<<mandist<<endl;
	return(mandist);
}

