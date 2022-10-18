//ͨѶ¼ϵͳ
/*
ϵͳʵ�ֹ��ܣ�
1����ɾ�Ĳ���ϵ�ˣ����1000�ˣ���Ϣ�������������䣬�Ա𣬵绰����ַ
2����ʾ������ϵ��
3�������ϵ��
4���˳�ͨѶ¼
*/
#include<bits/stdc++.h>
using namespace std;

//����Ϊ1000���ܳ��ֶ�ջ����
#define MAX 100 //�������

struct Person
{
	string p_name;
	int p_age=-1;
	int p_gender=0;//1�����У�2����Ů
	string p_telephone;
	string p_address;
};

struct ContactBook
{
	struct Person personArray[MAX];
	//ͨѶ¼��Ա����
	int iSize=-1;  
};

void showMenu()
{
	cout << "*********************************" << endl;
	cout << "ͨѶ¼�˵���" << endl;
	cout << "*********************************" << endl;
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "��������ִ�в���������0�˳�ϵͳ��" << endl;
	cout << "*********************************" << endl;
}

//�����ϵ��
void addPerson(ContactBook* book)
{
	if (book->iSize == MAX)
	{
		cout << "ͨѶ¼�����������������ϵ�ˣ�" << endl;
		return;
	}
	cout << "��������ϵ����Ϣ��" << endl;
	cout << "��������ϵ������:" ;
	cin >> book->personArray[book->iSize].p_name;
	cout << "��������ϵ������:";
	cin >> book->personArray[book->iSize].p_age;
	cout << "��������ϵ���Ա�1�����У�2����Ů :" ;
	int iGender = 0;
	while (true)
	{
		cin >> iGender;
		if (iGender != 1 && iGender != 2)
		{
			cout << "������������������" << endl;
			cout << "��������ϵ���Ա�1�����У�2����Ů :" ;
		}
		else
		{
			break;
		}
	}
	book->personArray[book->iSize].p_gender=iGender;
	cout << "��������ϵ�˵绰:";
	cin >> book->personArray[book->iSize].p_telephone;
	cout << "��������ϵ�˵�ַ:";
	cin >> book->personArray[book->iSize].p_address;
	book->iSize++;
	cout << "�ѳɹ������ϵ�˲�����" << endl << endl;
}
//��ʾ������ϵ��
void showBook(ContactBook* book)
{
	if (book->iSize == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	cout << "ͨѶ¼" << endl;
	for (int i = 0; i < book->iSize; i++)
	{
		cout << "��ϵ��������"<<book->personArray[i].p_name
			<<" ���䣺"<< book->personArray[i].p_age
			<< " �Ա�" << (book->personArray[i].p_gender==1?"��":"Ů")
			<< " �绰��" << book->personArray[i].p_telephone
			<< " ��ַ��" << book->personArray[i].p_address
			<< endl;
	}
}
//������ϵ��
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

//ɾ����ϵ��
void deletePerson(ContactBook* book)
{
	showBook(book);
	if (book->iSize == 0)
	{
		cout << "���ܽ���ɾ����" << endl;
		return;
	}
	cout << endl;
	cout << "������������ϵ�˵���������ɾ��������" << endl;
	string deleteName;
	cin >> deleteName;
	int iSearch= iExistPerson(book, deleteName);
	if (iSearch < 0)
	{
		cout << "���û������ڣ��޷�����ɾ��������" << endl;
	}
	else
	{
		for (int i = iSearch; i < book->iSize; i++)
		{
			book->personArray[i] = book->personArray[i + 1];
		}
		book->iSize--;
		cout << "ɾ���ɹ�";
	}
}
//������ϵ��
void searchPerson(ContactBook* book)
{
	if (book->iSize == 0)
	{
		cout << "ͨѶ¼Ϊ�գ����ܽ��в��ң�" << endl;
		return;
	}
	string searchName;
	cout << "��������ϵ�˵�������" ;
	cin >> searchName;
	int iSearch = iExistPerson(book, searchName);
	if (iSearch < 0)
	{
		cout << "���û������ڣ�" << endl;
	}
	else
	{
		cout << "��ϵ��������" << book->personArray[iSearch].p_name
			<< " ���䣺" << book->personArray[iSearch].p_age
			<< " �Ա�" << (book->personArray[iSearch].p_gender == 1 ? "��" : "Ů")
			<< " �绰��" << book->personArray[iSearch].p_telephone
			<< " ��ַ��" << book->personArray[iSearch].p_address
			<< endl;
	}
}
//�޸���ϵ��
void modifyPerson(ContactBook* book)
{
	showBook(book);
	if (book->iSize == 0)
	{
		cout << "���ܽ����޸ģ�" << endl;
		return;
	}
	cout << endl;
	string searchName;
	cout << "������������Ҫ�޸ĵ���ϵ��������";
	cin >> searchName;
	int iSearch = iExistPerson(book, searchName);
	if (iSearch < 0)
	{
		cout << "���û������ڣ����ܽ����޸ģ�" << endl;
	}
	else
	{
		cout << "��������ϵ����Ϣ�����޸ģ�" << endl;
		cout << "��������ϵ������:";
		cin >> book->personArray[iSearch].p_age;
		cout << "��������ϵ���Ա�1�����У�2����Ů :";
		int iGender = 0;
		while (true)
		{
			cin >> iGender;
			if (iGender != 1 && iGender != 2)
			{
				cout << "������������������" << endl;
				cout << "��������ϵ���Ա�1�����У�2����Ů :";
			}
			else
			{
				break;
			}
		}
		book->personArray[iSearch].p_gender = iGender;
		cout << "��������ϵ�˵绰:";
		cin >> book->personArray[iSearch].p_telephone;
		cout << "��������ϵ�˵�ַ:";
		cin >> book->personArray[iSearch].p_address;
		cout << "�ѳɹ��޸���ϵ�˲�����" << endl;
		cout<<"���º����Ϣ����" << endl;
		cout << "��ϵ��������" << book->personArray[iSearch].p_name
			<< " ���䣺" << book->personArray[iSearch].p_age
			<< " �Ա�" << (book->personArray[iSearch].p_gender == 1 ? "��" : "Ů")
			<< " �绰��" << book->personArray[iSearch].p_telephone
			<< " ��ַ��" << book->personArray[iSearch].p_address
			<< endl;
		cout << endl;
	}
}
//���ͨѶ¼
void cleanBook(ContactBook* book)
{
	cout << "���ٴ�ȷ���Ƿ�Ҫ���ͨѶ¼��" <<endl ;
	cout << "����1Ϊȷ����գ�������ա�" << endl;
	int iFlag = 0;
	cin >> iFlag;
	if (iFlag == 1)
	{
		book->iSize = 0;
		cout << "ͨѶ¼�����" << endl;
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
			cout << "�˳�ϵͳ" << endl;
			return 0;
		case 1:
			//�����ϵ��
			addPerson(&book);
			cout << endl;
			break;
		case 2:
			//��ʾ��ϵ��
			showBook(&book);
			cout << endl;
			break;
		case 3:
			//ɾ����ϵ��
			deletePerson(&book);
			cout << endl;
			break;
		case 4:
			//������ϵ��
			searchPerson(&book);
			cout << endl;
			break;
		case 5:
			//�޸���ϵ��
			modifyPerson(&book);
			cout << endl;
			break;
		case 6:
			//�����ϵ��
			cleanBook(&book);
			cout << endl;
			break;
		}
		//�밴���������
		system("pause");
		//����
		system("cls");
	}
	return 0;
}