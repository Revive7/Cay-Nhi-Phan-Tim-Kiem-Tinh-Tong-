#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
 //Vo Nguyen Xuan Quynh
 //1751060480
 //thptso1pm@gmail.com
struct node
{
	int data; 
	struct node *pLeft; 
	struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;
void Create(TREE &t)
{
	t = NULL;
}


void InsertNODE(TREE &t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x < t->data)
		{
			InsertNODE(t->pLeft, x);
		}
		else if (x > t->data)
		{
			InsertNODE(t->pRight, x);
		}
	}
}

void LNR(TREE t)
{
	if (t != NULL)
	{
	
		LNR(t->pLeft);	
		cout << t->data << "  ";
		LNR(t->pRight);
	}
}
int CountNODE2(TREE t)
{
	if (t == NULL)
	{
	int a = CountNODE2(t->pLeft);
        int b = CountNODE2(t->pRight);
        if (t->pLeft != NULL && t->pRight != NULL)
            return 1 + a + b;
        return a + b;
    }
}

int TotalNODEChan(TREE t)
{
    if (t!=NULL)
    {
        int a = TotalNODEChan(t->pLeft);
        int b = TotalNODEChan(t->pRight);
        if (t->data % 2 == 0)
            return t->data + a + b;
        return a + b;
    }
}
int TotalNODELe(TREE t)
{
    if (t!=NULL)
    {
        int a = TotalNODELe(t->pLeft);
        int b = TotalNODELe(t->pRight);
        if (t->data % 2 != 0)
            return t->data + a + b;
        return a + b;
    }
}
bool SoNguyenTo(int n)
{
    if (n<=1)
        return false;
    for (int i=2; i<n; i++)
        if(n%i==0)
            return false;
    return true;
}
int TotalNODENgto(TREE t)
{
    if (t!=NULL)
    {
        int a = TotalNODENgto(t->pLeft);
        int b = TotalNODENgto(t->pRight);
        if (SoNguyenTo(t->data))
                return t->data + a + b;
        return a + b;
    }
}
void Menu(TREE &t)
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =================== MENU ==================";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Xuat cay ra man hinh";
		cout << "\n3. Dem so nut co 2 con cua cay";
		cout << "\n4. Tinh tong cac so chan trong cay";
		cout << "\n5. Tinh tong cac so le trong cay";
		cout << "\n6. Tinh tong cac so nguyen to trong cay";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t ===================  END  ==================";

		cout << "\nNhap lua chon: ";
		cin >> choose;

		if (choose == 1)
		{
			int x;
			cout << "\nNhap gia tri: ";
			cin >> x;
			InsertNODE(t, x);
		}
		else if (choose == 2)
		{
			cout << "\n\t Cay nhi phan tim kiem:\n";
			LNR(t);
			system("pause");
		}
		else if (choose == 3)
		{
			cout<<"\n\t So nut co 2 con trong cay:\n";
			CountNODE2(t);
			system("pause");			
		}
			else if (choose == 4)
		{
			cout<<"\n\t Tong cac so chan trong cay:\n";
			TotalNODEChan(t);
			system("pause");			
		}
			else if (choose == 5)
		{
			cout<<"\n\t Tong cac so le trong cay:\n";
			TotalNODELe(t);	
			system("pause");		
		}
			else if (choose == 6)
		{
			cout<<"\n\t Tong cac so nguyen to trong cay:\n";
			TotalNODENgto(t);	
			system("pause");		
		}
		else
		{
			break;
		}
	}
}


int main()
{
	TREE t;
	Create(t);
	Menu(t);

	system("pause");
	return 0;
}
