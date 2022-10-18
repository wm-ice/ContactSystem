//通讯录系统
/*
系统实现功能：
1、增删改查联系人：最多1000人，信息包括姓名，年龄，性别，电话，地址
2、显示所有联系人
3、清空联系人
4、退出通讯录
*/
#include<bits/stdc++.h>
using namespace std;

//设置为1000可能出现堆栈问题
#define MAX 100 //最大人数

struct Person
{
	string p_name;
	int p_age=-1;
	int p_gender=0;//1代表男，2代表女
	string p_telephone;
	string p_address;
};

struct ContactBook
{
	struct Person personArray[MAX];
	//通讯录人员个数
	int iSize=-1;  
};

void showMenu()
{
	cout << "*********************************" << endl;
	cout << "通讯录菜单：" << endl;
	cout << "*********************************" << endl;
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "输入数字执行操作，输入0退出系统。" << endl;
	cout << "*********************************" << endl;
}

//添加联系人
void addPerson(ContactBook* book)
{
	if (book->iSize == MAX)
	{
		cout << "通讯录已满，不能再添加联系人！" << endl;
		return;
	}
	cout << "请输入联系人信息：" << endl;
	cout << "请输入联系人姓名:" ;
	cin >> book->personArray[book->iSize].p_name;
	cout << "请输入联系人年龄:";
	cin >> book->personArray[book->iSize].p_age;
	cout << "请输入联系人性别：1代表男，2代表女 :" ;
	int iGender = 0;
	while (true)
	{
		cin >> iGender;
		if (iGender != 1 && iGender != 2)
		{
			cout << "输入有误，请重新输入" << endl;
			cout << "请输入联系人性别：1代表男，2代表女 :" ;
		}
		else
		{
			break;
		}
	}
	book->personArray[book->iSize].p_gender=iGender;
	cout << "请输入联系人电话:";
	cin >> book->personArray[book->iSize].p_telephone;
	cout << "请输入联系人地址:";
	cin >> book->personArray[book->iSize].p_address;
	book->iSize++;
	cout << "已成功添加联系人操作！" << endl << endl;
}
//显示所有联系人
void showBook(ContactBook* book)
{
	if (book->iSize == 0)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	cout << "通讯录" << endl;
	for (int i = 0; i < book->iSize; i++)
	{
		cout << "联系人姓名："<<book->personArray[i].p_name
			<<" 年龄："<< book->personArray[i].p_age
			<< " 性别：" << (book->personArray[i].p_gender==1?"男":"女")
			<< " 电话：" << book->personArray[i].p_telephone
			<< " 地址：" << book->personArray[i].p_address
			<< endl;
	}
}
//查找联系人
int iExistPerson(ContactBook* book,string searchName)
{
	int iNum = -1;
	for (int i = 0; i < book->iSize; i++)
	{
		if (book->personArray[i].p_name == searchName)
		{
			iNum = i;
			break;
		}
	}
	return iNum;
}

//删除联系人
void deletePerson(ContactBook* book)
{
	showBook(book);
	if (book->iSize == 0)
	{
		cout << "不能进行删除！" << endl;
		return;
	}
	cout << endl;
	cout << "请输入以上联系人的姓名进行删除操作！" << endl;
	string deleteName;
	cin >> deleteName;
	int iSearch= iExistPerson(book, deleteName);
	if (iSearch < 0)
	{
		cout << "该用户不存在，无法进行删除操作！" << endl;
	}
	else
	{
		for (int i = iSearch; i < book->iSize; i++)
		{
			book->personArray[i] = book->personArray[i + 1];
		}
		book->iSize--;
		cout << "删除成功";
	}
}
//查找联系人
void searchPerson(ContactBook* book)
{
	if (book->iSize == 0)
	{
		cout << "通讯录为空，不能进行查找！" << endl;
		return;
	}
	string searchName;
	cout << "请输入联系人的姓名：" ;
	cin >> searchName;
	int iSearch = iExistPerson(book, searchName);
	if (iSearch < 0)
	{
		cout << "该用户不存在！" << endl;
	}
	else
	{
		cout << "联系人姓名：" << book->personArray[iSearch].p_name
			<< " 年龄：" << book->personArray[iSearch].p_age
			<< " 性别：" << (book->personArray[iSearch].p_gender == 1 ? "男" : "女")
			<< " 电话：" << book->personArray[iSearch].p_telephone
			<< " 地址：" << book->personArray[iSearch].p_address
			<< endl;
	}
}
//修改联系人
void modifyPerson(ContactBook* book)
{
	showBook(book);
	if (book->iSize == 0)
	{
		cout << "不能进行修改！" << endl;
		return;
	}
	cout << endl;
	string searchName;
	cout << "请输入以上想要修改的联系人姓名：";
	cin >> searchName;
	int iSearch = iExistPerson(book, searchName);
	if (iSearch < 0)
	{
		cout << "该用户不存在，不能进行修改！" << endl;
	}
	else
	{
		cout << "请输入联系人信息进行修改：" << endl;
		cout << "请输入联系人年龄:";
		cin >> book->personArray[iSearch].p_age;
		cout << "请输入联系人性别：1代表男，2代表女 :";
		int iGender = 0;
		while (true)
		{
			cin >> iGender;
			if (iGender != 1 && iGender != 2)
			{
				cout << "输入有误，请重新输入" << endl;
				cout << "请输入联系人性别：1代表男，2代表女 :";
			}
			else
			{
				break;
			}
		}
		book->personArray[iSearch].p_gender = iGender;
		cout << "请输入联系人电话:";
		cin >> book->personArray[iSearch].p_telephone;
		cout << "请输入联系人地址:";
		cin >> book->personArray[iSearch].p_address;
		cout << "已成功修改联系人操作！" << endl;
		cout<<"更新后的信息如下" << endl;
		cout << "联系人姓名：" << book->personArray[iSearch].p_name
			<< " 年龄：" << book->personArray[iSearch].p_age
			<< " 性别：" << (book->personArray[iSearch].p_gender == 1 ? "男" : "女")
			<< " 电话：" << book->personArray[iSearch].p_telephone
			<< " 地址：" << book->personArray[iSearch].p_address
			<< endl;
		cout << endl;
	}
}
//清空通讯录
void cleanBook(ContactBook* book)
{
	cout << "请再次确认是否要清空通讯录？" <<endl ;
	cout << "输入1为确认清空，否则不清空。" << endl;
	int iFlag = 0;
	cin >> iFlag;
	if (iFlag == 1)
	{
		book->iSize = 0;
		cout << "通讯录已清空" << endl;
	}
	else
	{
		return;
	}
}

int main()
{
	ContactBook book;
	book.iSize = 0;
	int iSelect = 0;
	while (true)
	{
		showMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 0:
			cout << "退出系统" << endl;
			return 0;
		case 1:
			//添加联系人
			addPerson(&book);
			cout << endl;
			break;
		case 2:
			//显示联系人
			showBook(&book);
			cout << endl;
			break;
		case 3:
			//删除联系人
			deletePerson(&book);
			cout << endl;
			break;
		case 4:
			//查找联系人
			searchPerson(&book);
			cout << endl;
			break;
		case 5:
			//修改联系人
			modifyPerson(&book);
			cout << endl;
			break;
		case 6:
			//清空联系人
			cleanBook(&book);
			cout << endl;
			break;
		}
		//请按任意键操作
		system("pause");
		//清屏
		system("cls");
	}
	return 0;
}