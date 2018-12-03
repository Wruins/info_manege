#include"Infomation.h"
#include<iostream>
#include <string>
using namespace std;

void WorkList::ScreenShow()
{
	int m;
	char c;
	size_t i=0;
	cout<<"ְ����Ϣ����ϵͳ���˵�"<<endl;
	cout<<"1.ְ����Ϣ���"<<endl;
	cout<<"2.ְ����Ϣ�޸�"<<endl;
	cout<<"3.ְ����Ϣɾ��"<<endl;
	cout<<"4.ְ����Ϣ����"<<endl;
	cout<<"5.ְ����Ϣ����"<<endl;
	cout<<"6.ְ����Ϣ��ʾ"<<endl;
	cout<<"7.ְ����Ϣ����"<<endl;
	cout<<"0.�˳�"<<endl;
	cout<<"��ѡ�����ֱ��0~7��"<<endl;
	do
	{
		while (1)
		{
			cin >> m;
			if (cin.good() == 1)
			{
				if (m > 7 || m < 0)
				{
					cout << "ѡ��������������" << endl;
					continue;
				}
				else break;
				
			}
			if (cin.fail() == 1)
			{
				cin.clear();
				cin.ignore();
				cout << "����������������" << endl;
				continue;
			}
		}
		switch (m)
		{
		case 1:AddWorker(); break;
		case 2:Modification(); break;
		case 3:DeleteWorker(); break;
		case 4:SortWorker(); break;
		case 5:FindWorker(i); break;
		case 6:ShowWorker(); break;
		case 7:SaveInfoFile(); break;
		case 0:exit(0); break;
		}
	} while (m<=0&&m>=7);
	
	cout << "�Ƿ����(Y/N)" << endl;
	//cin >> c;
	while (1)
	{
		cin >> c;
		if (c == 'y' || c == 'Y')
			ScreenShow();
		else if (c == 'n' || c == 'N')
			exit(0);
		else
		{
			cin.clear();
			//cin.sync();
			cout << "��������" << endl;
		}
	}
}

void WorkList::AddWorker()
{
	int m;
	cout<<"Ҫ������Ϣ�����У�"<<endl;
	cin>>m;
	for(int i=0;i<m;i++)
	{
	m_TmpWorker.InputData();
	workerArray.push_back(m_TmpWorker);
	cout<<endl;
	}
}

void WorkList::ShowWorker()
{
	cout << "һ������" << workerArray.size() << "������" << endl;
	for(size_t i = 0; i < workerArray.size(); i++)
	{
		workerArray[i].Show();
		cout << endl;
	}
}

void Worker::InputData()
{	 
	cout<<"������Ҫ���Ա���Ĺ��ţ�"<<endl;
	cin>>num;
	cout<<"������ְ����Ϣ��"<<endl;
	cout<<"���ţ�"<<num<<endl;
	cout<<"������";cin>>name;
	cout<<"�Ա�(M/F)��";cin>>sex;
	cout<<"ѧ����";cin>>education;
	cout<<"���䣺";cin>>age;
	cout<<"���ʣ�";cin>>wage;
	cout<<"��ַ��";cin>>address;
	cout<<"�绰��";cin>>telephone;

}

void Worker::Show()
{
	cout<<"���ţ�"<<num<<endl;
	cout<<"������"<<name<<endl;
	cout<<"�Ա�(M/F)��"<<sex<<endl;
	cout<<"ѧ����"<<education<<endl;
	cout<<"���䣺"<<age<<endl;
	cout<<"���ʣ�"<<wage<<endl;
	cout<<"��ַ��"<<address<<endl;
	cout<<"�绰��"<<telephone<<endl;

}

void WorkList::FindWorker(size_t i)//���ҵ���
{
	int m;
	size_t findlen=0;
	cout << "������Ҫ���ҵķ�ʽ��" << endl;
	cout << "1.���ݹ��Ų���" << endl;
	cout << "2.������������" << endl;
	cin >> m;
	if (m == 1)
	{
		char num[10];
		cout << "��������ҵĹ��ţ�" << endl;
		cin >> num;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (strcmp(workerArray[i].GetNumber() , num)==0)
				break;
		}
		if (i == workerArray.size())
		{
			cout << "����ʧ�ܣ�\nû���ҵ����ҹ���Ϊ" << num << "����" << endl;
			return ;
		}
		cout << "���ҳɹ�" << endl;
		workerArray[i].Show();

	}
	else if (m == 2)
	{
		char nam[30];
		cout << "��������ҵ�������" << endl;
		cin >> nam;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (strcmp(workerArray[i].GetName() , nam) == 0)
			{
				workerArray[i].Show();
				cout<<endl;
				findlen++;
			}
		}
		cout<<"�ҵ�ƥ���"<<findlen<<"������"<<endl;
		if (findlen==0)
		{
			cout << "����ʧ�ܣ�\nû���ҵ���������Ϊ" << nam << "����" << endl;
			return ;
		}
		
		cout << "���ҳɹ�" << endl;
	}
}

void WorkList::Modification()//�޸�
{
	size_t i=0;
	int c, Age;//j
	//char n;
	char nam, addr, numb, edu, tel;
	double Wage;
	char Sex;
	FindWorker(i);
/*	cout << "������Ҫ�޸ĵķ�ʽ��" << endl;
	cout << "1.���ݹ��Ų���" << endl;
	cout << "2.������������" << endl;
	cin >> j;
	if (j == 1)
	{
		cout << "��������ҵĹ��ţ�" << endl;
		cin >> n;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (workerArray[i].GetNumber() == n)
				break;
		}
		if (i == workerArray.size())
		{
			cout << "����ʧ�ܣ�\nû���ҵ����ҹ���Ϊ" << n << "����" << endl;
			return ;
		}
		cout << "���ҳɹ�" << endl;

	}
	else if (j == 2)
	{
		cout << "��������ҵ�������" << endl;
		cin >> n;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (workerArray[i].GetName() == n)
				break;
		}
		if (i == workerArray.size())
		{
			cout << "����ʧ�ܣ�\nû���ҵ���������Ϊ" << n << "����" << endl;
			return ;
		}
		cout << "���ҳɹ�" << endl;
	
	}
*/
	cout << "Ա����Ϣ��" << endl;
	cout << "1-------------����" << endl;
	cout << "2-------------����" << endl;
	cout << "3---------�Ա�(M/F)" << endl;
	cout << "4-------------ѧ��" << endl;
	cout << "5-------------����" << endl;
	cout << "6-------------����" << endl;
	cout << "7-------------��ַ" << endl;
	cout << "8-------------�绰" << endl;
	cout << "�������޸ĵ�ѡ���" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		cout << "����Ҫ�޸ĵĹ���" << endl;
		cin >> numb;
		workerArray[i].SetNumber(numb);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 2:
		cout << "����Ҫ�޸ĵ�����" << endl;
		cin >> nam;
		workerArray[i].SetName(nam);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 3:
		cout << "����Ҫ�޸ĵ��Ա�(M/F)" << endl;
		cin >> Sex;
		workerArray[i].SetSex(Sex);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 4:
		cout << "����Ҫ�޸ĵ�ѧ��" << endl;
		cin >> edu;
		workerArray[i].SetEducation(edu);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 5:
		cout << "����Ҫ�޸ĵ�����" << endl;
		cin >> Age;
		workerArray[i].SetAge(Age);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 6:
		cout << "����Ҫ�޸ĵĹ���" << endl;
		cin >> Wage;
		workerArray[i].SetWage(Wage);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 7:
		cout << "����Ҫ�޸ĵĵ�ַ" << endl;
		cin >> addr;
		workerArray[i].SetAddress(addr);
		cout << "�޸ĳɹ�" << endl;
		break;
	case 8:
		cout << "����Ҫ�޸ĵĵ绰" << endl;
		cin >> tel;
		workerArray[i].SetTelephone(tel);
		break;
		cout << "�޸ĳɹ�" << endl;
	default:
		cout << "���������!\n" << endl;
		break;
	}
}

void WorkList::DeleteWorker()
{
	size_t i=0;
	FindWorker(i);	
	workerArray.erase(workerArray.begin() + i);//ɾ��i���Ǹ�����
	cout << "�����ɹ�" << endl;
}

void WorkList::SortWorker()
{
	int choice;
	cout << "��ѡ������ķ�ʽ��" << endl;
	cout << "1��������������" << endl;
	cout << "2�����ս�������" << endl;
	cin >> choice;
	switch(choice)
	{
		case 1:UpSort();break;
		case 2:DownSort();break;
	}
}

void WorkList::UpSort()
{
	size_t i,j;
	int choice;
	cout << "��ѡ������ķ�ʽ��" << endl;
	cout << "1.���չ�������" << endl;
	cout << "2.���չ�������" << endl;
	cout << "3.������������" << endl;
	cin >> choice;
	switch(choice)//ð�ݷ�����
	{
		case 1:
			for(i=0;i<workerArray.size();i++)
			{
				for(j=0;j<workerArray.size()-1-i;j++)
				{
					if(workerArray[j].GetNumber() > workerArray[j+1].GetNumber())
					{
						Worker woker = workerArray[j];
						workerArray[j] = workerArray[j+1];
						workerArray[j+1] = woker;
					}
				}
			}
			ShowWorker();
			break;
		case 2:
			for(i=0;i<workerArray.size();i++)
			{
				for(j=0;j<workerArray.size()-1-i;j++)
				{
					if(workerArray[j].GetWage() > workerArray[j+1].GetWage())
					{
						Worker woker = workerArray[j];
						workerArray[j] = workerArray[j+1];
						workerArray[j+1] = woker;
					}
				}
			}
			ShowWorker();
			break;
		case 3:
			for(i=0;i<workerArray.size();i++)
			{
				for(j=0;j<workerArray.size()-1-i;j++)
				{
					if(workerArray[j].GetName() > workerArray[j+1].GetName())
					{
						Worker woker = workerArray[j];
						workerArray[j] = workerArray[j+1];
						workerArray[j+1] = woker;
					}
				}
			}
			ShowWorker();
			break;
	}
}

void WorkList::DownSort()
{
	size_t i,j;
	int choice;
	cout << "��ѡ������ķ�ʽ��" << endl;
	cout << "1.���չ�������" << endl;
	cout << "2.���չ�������" << endl;
	cout << "3.������������" << endl;
	cin >> choice;
	switch(choice)//ð�ݷ�����
	{
		case 1:
			for(i=0;i<workerArray.size();i++)
			{
				for(j=0;j<workerArray.size()-1-i;j++)
				{
					if(workerArray[j].GetNumber() < workerArray[j+1].GetNumber())
					{
						Worker woker = workerArray[j];
						workerArray[j] = workerArray[j+1];
						workerArray[j+1] = woker;
					}
				}
			}
			ShowWorker();
			break;
		case 2:
			for(i=0;i<workerArray.size();i++)
			{
				for(j=0;j<workerArray.size()-1-i;j++)
				{
					if(workerArray[j].GetWage() < workerArray[j+1].GetWage())
					{
						Worker woker = workerArray[j];
						workerArray[j] = workerArray[j+1];
						workerArray[j+1] = woker;
					}
				}
			}
			ShowWorker();
			break;
		case 3:
			for(i=0;i<workerArray.size();i++)
			{
				for(j=0;j<workerArray.size()-1-i;j++)
				{
					if(workerArray[j].GetName() < workerArray[j+1].GetName())
					{
						Worker woker = workerArray[j];
						workerArray[j] = workerArray[j+1];
						workerArray[j+1] = woker;
					}
				}
			}
			ShowWorker();
			break;
		default:
			cout << "��������" << endl;
	}
}

void WorkList::SaveInfoFile()
{
	fstream ioFile("workerInfo.dat", ios::in | ios::out | ios::binary);
	if (!ioFile)
	{
		cerr << "open workerInfo.dat error!" << endl;
		abort();
	}
	vector<Worker>::iterator iter = workerArray.begin();
	while(iter != workerArray.end())
	{
		Worker tmpWorker = *iter;
		ioFile.write((char*)&tmpWorker, sizeof(Worker));
		++iter;
	}
	ioFile.close();

}

void WorkList::ReadInfoFile()
{
	fstream ioFile("workerInfo.dat", ios::in | ios::out | ios::binary);
	if (!ioFile)
	{
		cerr << "open workerInfo.dat error!" << endl;
		abort();
	}
	ioFile.seekg(0,ios::end);
	streampos spEnd = ioFile.tellg();
	ioFile.seekg(0, ios::beg);
	streampos spBeg = ioFile.tellg();
	size_t dataLength = spEnd - spBeg;
	size_t dataSize = dataLength / sizeof(Worker);
	
	for(size_t i=0; i < dataSize; ++i)
	{
		//Worker tmpWorker;
		ioFile.read((char*)&m_TmpWorker, sizeof(Worker));
		workerArray.push_back(m_TmpWorker);
	}
	ioFile.close();

}