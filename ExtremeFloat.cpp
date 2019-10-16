#include<iostream>
using namespace std;
#include<conio.h>
#include<stdlib.h>

template<class T>
struct node{
	char data;
	node* prev;
	node* next;
};

struct list{
	node<char>* front;
	node<char>* back;
};

list temp; 

void createList(list &l)
{
	l.front=l.back=NULL;
}

int isEmpty(list l)
{
	return((l.front==NULL)||(l.back==NULL));
}

void insertionSlot(list num, int n, node<char>* &prevNum)
{
	prevNum = num.back;
	for(int i=0;i<n;i++)
	{
		prevNum=prevNum->prev;
	}
}

void insertFront(list &num, char ch)
{
	node<char>*p = new (nothrow) node<char>;//get new node from OS
	p->data=ch;
	p->next=p->prev=NULL;
	if(isEmpty(num))//the list is empty
		num.front= num.back= p;
	else
	{
		p->next=num.front;
		num.front->prev=p;
		num.front=p;
	}
}

void insertMiddle(list &num, int n, char ch)
{
	node<char>*p=new (nothrow) node<char>;
	node<char>*prevNum;
	p->next=p->prev=prevNum->next=prevNum->prev=NULL;
	insertionSlot(num,n,prevNum);//prevNum is sent into the function by reference
	p->data=ch;
	p->prev=prevNum;
	p->next=prevNum->next;
	prevNum->next=p;
	p=p->next;
	prevNum=prevNum->next;
	p->prev=prevNum;
	
}

void insertBack(list &num, char ch)
{
	node<char>*p = new (nothrow) node<char>;//get new node from OS
	p->data=ch;
	p->next=p->prev=NULL;
	if(isEmpty(num))//the list is empty
		num.front= num.back= p;
	else
	{
		num.back->next=p;
		p->prev=num.back;
		num.back=p;
		//cout<<p->prev<<endl;
		
	}
}

void nodeToDelete(list num, int n, node<char>* &p)
{
	p=num.back;
	for(int i=0;i<n;i++)
	{
		p=p->prev;
	}
}

void deleteFront(list &num)
{
	node<char>*p;
	p=num.front;// make the pointer p point to the first element
	if(p==NULL)
		cout<<"ERROR: Deletion Failed, the list is empty";
	num.front=p->next;
	p->next=NULL;
	num.front->prev=NULL;
	delete p;
}

void deleteMiddle(list &num, int n)
{
	node<char>*p;
	node<char>*prevNum;
	node<char>*nextNum;
	nodeToDelete(num,n,p);
	if(p==NULL)
		cout<<"ERROR: Deletion Failed, the list is empty";
	prevNum=p->prev;
	prevNum->next=p->next;
	p->prev=NULL;
	nextNum=p->next;
	p->next=NULL;
	nextNum->prev=prevNum;
}

void deleteBack(list &num)
{
	node<char>*p;
	p=num.back;
	if(p==NULL)
		cout<<"ERROR: Deletion Failed, the list is empty";
	num.back=p->prev;
	num.back->next=NULL;
	p->prev=NULL;
}


void topPart()
{
	cout<<"\n			%%%%%%%%\n"
		<<"			%%\n"
		<<"			%%%%%%\n"
		<<"			%%\n"
		<<"			%%%%%%%% xtreme	%%%%%%%%\n"
		<<"			              	%%\n"
		<<"			               	%%%%%%\n"
		<<"			              	%%\n"
		<<"			              	%%      loat\n"
		<<"_______________________________________________________________________________\n";
}

void welcome()
{
	cout<<"\n\n\n\n\n\n\n\n\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<<"\t\t%%            Welcome                 %%\n"
		<<"\t\t%%                To                  %%\n"
		<<"\t\t%%         Etreme Float               %%\n"
		<<"\t\tt%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<<"\t\t A program that allows any value of\n"
		<<"\t number to be used for the purpose of adding, subtracting,\n"
		<<"  multiplying and dividing with as much precision of insignificant digits\n"
		<<"\t\t\tas you like.  \n";
}
char menu()
{
	char ch;
	cout<<"\n"
		<<"\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<<"\t\t%%                    Menu                     %%\n"
		<<"\t\t%%    Addition => a     Multiplication => m    %%\n"
		<<"\t\t%%    Subtraction => s  Division => d          %%\n"
		<<"\t\t%%    Comparison => c                          %%\n"
		<<"\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<<"\n\tChoos an operation from the above menu : ";
	cin>>ch;
	return ch;
}

void promptUser(int n, list &num)
{
	char ch;
	createList(num);
	if(n==1)
		cout<<"\n\tEnter the first number : ";
	else
		cout<<"\n\tEnter the second number : ";
		cin.ignore();
	while(cin.get(ch)&&ch!='\n')
	{
			insertBack(num,ch);
			
			
	}
}

void displayResult(list res)
{
	node<char>* p;
	p=res.front;
	while(p->next!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<p->data;
	char ch;
	cout<<"\n\twould you like this result to be saved as an input for the next\n\t operation \n\t\tA.Yes\tB.No";
	cin>>ch;
	if(ch=='a'||ch=='A')
		temp=res;
}

void checkTemp(list &num1, list &num2)
{
	//checks if there is an intentionally stored result from previous operations
	if(temp.front==NULL||temp.back==NULL)
		promptUser(1, num1);
	else{
		num1=temp;
	}
	promptUser(2, num2);
}

int searchFront(list num, int &count, char ch)
{
	node<char>*p;//curent node
	p->next=p->prev=NULL;
	int found=0;
	p= num.front;
	while(p->next!=NULL)
	{
		if(p->data==ch)
		{
			found=1;
			return 1;
		}
		else{
			p=p->next;
			count++;
		}
	}
	if(found==0)
		return 0;
}

int searchBack(list num, int &count, char ch)
{
	node<char>*p;//curent node
	p->next=NULL;
	p->prev=NULL;
	int found=0;
	p= num.back;
	while(p->prev!=NULL)
	{
		if(p->data==ch)
		{
			found=1;
			return 1;
		}
		else{
			p=p->prev;
			count++;
		}
	}
	if(found==0)
		return 0;
}

void matchPrecision(list &num1, list &num2)
{
	// Matches the decimal point by adding zeros at the back and front to make the two numbers corresponding
	int count1=0, count2=0, count3=0, count4=0, s1, s2, s3,s4, dif;
	s1=searchFront(num1,count1,'.');//searches for '.' starting from the front
	displayResult(num1);	
	s2=searchFront(num2,count2,'.');
	displayResult(num2);
	if(s1==1&&s2==0)//s1==1 means it has found'.'
		insertBack(num2,'.');
	else if(s1==0&&s2==1)
		insertBack(num1,'.');
	if(count1<count2)//the number of digits starting from the front to '.' for count1 is lesser than count2
	{
		dif=count2-count1;
		for(int i=0;i<dif;i++)
			insertFront(num1,'0');
			
	}
	else if(count1>count2)
	{
		dif=count1-count2;
		for(int i=0;i<dif;i++)
			insertFront(num2,'0');
	}
	s3=searchBack(num1, count3, '.');//searches for '.' starting from the back
	cout<<s3<<count3;
	s4=searchBack(num2, count4, '.');
	cout<<s4<<count4;
	if(s3==1&&s4==0)
		insertBack(num2,'.');
	else if(s3==0&&s4==1)
		insertBack(num1,'.');
	if(count3>count4)
	{
		dif=count3-count4;
		for(int i=0;i<dif;i++)
			insertBack(num2,'0');
	}
	else if(count3<count4)
	{
		dif=count4-count3;
		for(int i=0;i<dif;i++)
			insertBack(num1,'0');
	}
	//displayResult(num1);
}

void prepNum(list &num1, list &num2)
{
	createList(num1);
	createList(num2);
	checkTemp(num1, num2);//checks if there is an intentionally stored result from previous operations
}

list add(list num1, list num2)
{
	list result;
	createList(result);
	matchPrecision(num1, num2);// Matches the decimal point by adding zeros at the back and front to make the two numbers corresponding
	node<char>* p1;//current pointer to a node of list num1, num2 and result respectively
	node<char>* p2;
	node<char>* p3;
	p1=num1.back;
	p2=num2.back;
	p3= result.back;
	int sum;
	while((p1->prev!=NULL)&&(p2->prev!=NULL))
	{
		if(p1->data=='.')
			insertFront(result,'.');
		else
		{
			//This loop adds each data part of the two numbers by casting them to int and storing the result on result list
			sum=int(p1->data)+int(p2->data);
			if(sum<10)
			{
				insertFront(result,char(sum));
			}
			else{
				//if sum >=10, add one to the next digits's sum
				insertFront(result, char(sum-10));
				if(p1->prev==NULL)//if p1 points to the front most digit of num1
					insertFront(result, char(1));
				else{
					p1=p1->prev;
					int n=int(p1->data);
					n++;
					p1->data=char(n);
					p1=p1->next;
				}
			}
		}
		//Traverse backwards one node
		p1=p1->prev;
		p2=p2->prev;
		p3=p3->prev;
	}
	return result;
}

list subtract(list num1, list num2)
{
	list result;
	createList(result);
	matchPrecision(num1, num2);// Matches the decimal point by adding zeros at the back and front to make the two numbers corresponding
	node<char>* p1;//current pointer to a node of list num1, num2 and result respectively
	node<char>* p2;
	node<char>* p3;
	p1=num1.back;
	p2=num2.back;
	p3= result.back;
	int dif;
	while((p1->prev!=NULL)&&(p2->prev!=NULL))
	{
		if(p1->data=='.')
			insertFront(result,'.');
		else
		{
			//This loop subtracts each data part of the two numbers by casting them to int and storing the result on result list
			dif=int(p1->data)-int(p2->data);
			if(dif<0)
			{
				if(p1->prev==NULL)
				{
					dif=dif*(-1);
					insertFront(result, char(dif));
					insertFront(result,'-');
				}
				else{
					dif+=10;
					insertFront(result,char(dif));
					p1=p1->prev;
					int n;
					n=int(p1->data);
					n--;
					p1->data=char(n);
					p1=p1->next;
				}
			}
			else{
				//if dif >=0
				insertFront(result, char(dif));
			}
		}
		//Traverse backwards one node for each lists
		p1=p1->prev;
		p2=p2->prev;
		p3=p3->prev;
	}
	return result;
}

int deleteDecPoint (list &num1, list &num2)
{
	//removes decimal point from the two numbers to make multiplication or division simpler
	int count1=0,count2=0,totCount,s1,s2;
	s1=searchBack(num1, count1, '.');
	s2=searchBack(num2, count2, '.');
	if(s1!=0)
	{
		deleteMiddle(num1,count1);
		totCount+=count1;
	}
	if(s2!=0)
	{
		deleteMiddle(num2,count2);
		totCount+=count2;
	}
	return totCount;
	
}

list multiply(list num1, list num2)
{
	list tempRes, result;
	createList(result);
	createList(tempRes);
	int resDecpos= deleteDecPoint(num1,num2);//returns the position of the decimal point for the product of the two numbers
	node<char>*p1;
	node<char>*p2;
	node<char>*p3;
	p1=num1.back;
	p2=num2.back;
	p3=tempRes.back;
	int product,rem,quo, zeros;
	while(p2->prev!=NULL)
	{
		rem=0; quo=0;
		while(p1->prev!=NULL)
		{
			product=int(p1->data)*int(p2->data);
			if(product<10)
			{
				insertFront(tempRes,char(product));
			}
			else
			{
				quo+=product;
				if(quo>=10)
					rem=quo%10;
				else
					rem=product%10;
				insertFront(tempRes,char(rem));
			}
			p1=p1->prev;
		}
		insertFront(tempRes,char(quo));
		if(zeros!=0)
		{
			for(int i=0;i<zeros;i++)
				insertBack(tempRes,'0');
		}
		zeros++;
		if(isEmpty(result))
			result=tempRes;
		else
			result=add(result,tempRes);
		p2=p2->prev;
	}
}

int compare(list num1, list num2)
{
	matchPrecision(num1,num2);
	deleteDecPoint(num1,num2);  
	int flag=0;
	node<char>*p1;
	node<char>*p2;
	p1=num1.front;
	p2=num2.front;
	while(p1->next!=NULL){
		if(int(p1->data)>int(p2->data))
			return 2;
		else if(int(p1->data)<int(p2->data))
			return 3;
		p1=p1->next;
		p2=p2->next;
	}
	if(flag==0)
		return 1;
}


list divide(list num1, list num2)
{
	int s1,s2,count1=0,count2=0,totCount;
	s1=searchFront(num1,count1,'.');
	s2=searchFront(num2,count2,'.');
	totCount=count1+count2;
	deleteDecPoint(num1,num2);
	node<char>*p1;
	node<char>*p2;
	node<char>*p3;
	
}


int main()
{
	
	welcome();
	getch();
	system("cls");
	char exit;
	do{
		system("cls");
		topPart();
		char ch=menu();
		system("cls");
		topPart();
		int res=0;
		list num1,num2,result;
		prepNum(num1,num2);
		switch(ch)
		{
			case 'a': case 'A':
				result=add(num1,num2);
				break;
			case 's': case 'S':
				result=subtract(num1,num2);
				break;
			case 'm': case 'M':
				result=multiply(num1,num2);
				break;
			case 'd': case 'D':
				result=divide(num1,num2);
				break;
			case 'c': case 'C':
				res=compare(num1,num2);
				break;
		}
		if(res==0)
			displayResult(result);
		else if(res==1)
			cout<<"\n\tThe two numbers are equal.";
		else if(res==2)
			cout<<"\n\tThe first number is greater than the second number.";
		else
			cout<<"\n\tThe second number is greather than the first";
		cout<<"\n\tPress 'Q' or'q' to exit the program\n\tPress any key to return back to menu : ";
		cin>>exit;
	
	}while(exit !='Q'|| exit != 'q');
	getch();
	return 0;
}
