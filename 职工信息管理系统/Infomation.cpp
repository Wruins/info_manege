#include"Infomation.h"
#include<iostream>
#include <string>
using namespace std;

void WorkList::ScreenShow()
{
	int m;
	char c;
	size_t i=0;
	cout<<"职工信息管理系统主菜单"<<endl;
	cout<<"1.职工信息添加"<<endl;
	cout<<"2.职工信息修改"<<endl;
	cout<<"3.职工信息删除"<<endl;
	cout<<"4.职工信息排序"<<endl;
	cout<<"5.职工信息查找"<<endl;
	cout<<"6.职工信息显示"<<endl;
	cout<<"7.职工信息保存"<<endl;
	cout<<"0.退出"<<endl;
	cout<<"请选择数字编号0~7："<<endl;
	do
	{
		while (1)
		{
			cin >> m;
			if (cin.good() == 1)
			{
				if (m > 7 || m < 0)
				{
					cout << "选择有误，重新输入" << endl;
					continue;
				}
				else break;
				
			}
			if (cin.fail() == 1)
			{
				cin.clear();
				cin.ignore();
				cout << "类型有误，重新输入" << endl;
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
	
	cout << "是否继续(Y/N)" << endl;
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
			cout << "输入有误！" << endl;
		}
	}
}

void WorkList::AddWorker()
{
	int m;
	cout<<"要输入信息组数有："<<endl;
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
	cout << "一共存入" << workerArray.size() << "个数据" << endl;
	for(size_t i = 0; i < workerArray.size(); i++)
	{
		workerArray[i].Show();
		cout << endl;
	}
}

void Worker::InputData()
{	 
	cout<<"请输入要添加员工的工号："<<endl;
	cin>>num;
	cout<<"请输入职工信息："<<endl;
	cout<<"工号："<<num<<endl;
	cout<<"姓名：";cin>>name;
	cout<<"性别(M/F)：";cin>>sex;
	cout<<"学历：";cin>>education;
	cout<<"年龄：";cin>>age;
	cout<<"工资：";cin>>wage;
	cout<<"地址：";cin>>address;
	cout<<"电话：";cin>>telephone;

}

void Worker::Show()
{
	cout<<"工号："<<num<<endl;
	cout<<"姓名："<<name<<endl;
	cout<<"性别(M/F)："<<sex<<endl;
	cout<<"学历："<<education<<endl;
	cout<<"年龄："<<age<<endl;
	cout<<"工资："<<wage<<endl;
	cout<<"地址："<<address<<endl;
	cout<<"电话："<<telephone<<endl;

}

void WorkList::FindWorker(size_t i)//查找单个
{
	int m;
	size_t findlen=0;
	cout << "请输入要查找的方式：" << endl;
	cout << "1.根据工号查找" << endl;
	cout << "2.根据姓名查找" << endl;
	cin >> m;
	if (m == 1)
	{
		char num[10];
		cout << "请输入查找的工号：" << endl;
		cin >> num;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (strcmp(workerArray[i].GetNumber() , num)==0)
				break;
		}
		if (i == workerArray.size())
		{
			cout << "查找失败！\n没有找到查找工号为" << num << "的人" << endl;
			return ;
		}
		cout << "查找成功" << endl;
		workerArray[i].Show();

	}
	else if (m == 2)
	{
		char nam[30];
		cout << "请输入查找的姓名：" << endl;
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
		cout<<"找到匹配的"<<findlen<<"组数据"<<endl;
		if (findlen==0)
		{
			cout << "查找失败！\n没有找到查找姓名为" << nam << "的人" << endl;
			return ;
		}
		
		cout << "查找成功" << endl;
	}
}

void WorkList::Modification()//修改
{
	size_t i=0;
	int c, Age;//j
	//char n;
	char nam, addr, numb, edu, tel;
	double Wage;
	char Sex;
	FindWorker(i);
/*	cout << "请输入要修改的方式：" << endl;
	cout << "1.根据工号查找" << endl;
	cout << "2.根据姓名查找" << endl;
	cin >> j;
	if (j == 1)
	{
		cout << "请输入查找的工号：" << endl;
		cin >> n;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (workerArray[i].GetNumber() == n)
				break;
		}
		if (i == workerArray.size())
		{
			cout << "查找失败！\n没有找到查找工号为" << n << "的人" << endl;
			return ;
		}
		cout << "查找成功" << endl;

	}
	else if (j == 2)
	{
		cout << "请输入查找的姓名：" << endl;
		cin >> n;
		for (i = 0; i < workerArray.size(); i++)
		{
			if (workerArray[i].GetName() == n)
				break;
		}
		if (i == workerArray.size())
		{
			cout << "查找失败！\n没有找到查找姓名为" << n << "的人" << endl;
			return ;
		}
		cout << "查找成功" << endl;
	
	}
*/
	cout << "员工信息：" << endl;
	cout << "1-------------工号" << endl;
	cout << "2-------------姓名" << endl;
	cout << "3---------性别(M/F)" << endl;
	cout << "4-------------学历" << endl;
	cout << "5-------------年龄" << endl;
	cout << "6-------------工资" << endl;
	cout << "7-------------地址" << endl;
	cout << "8-------------电话" << endl;
	cout << "请输入修改的选项的" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		cout << "输入要修改的工号" << endl;
		cin >> numb;
		workerArray[i].SetNumber(numb);
		cout << "修改成功" << endl;
		break;
	case 2:
		cout << "输入要修改的姓名" << endl;
		cin >> nam;
		workerArray[i].SetName(nam);
		cout << "修改成功" << endl;
		break;
	case 3:
		cout << "输入要修改的性别(M/F)" << endl;
		cin >> Sex;
		workerArray[i].SetSex(Sex);
		cout << "修改成功" << endl;
		break;
	case 4:
		cout << "输入要修改的学历" << endl;
		cin >> edu;
		workerArray[i].SetEducation(edu);
		cout << "修改成功" << endl;
		break;
	case 5:
		cout << "输入要修改的年龄" << endl;
		cin >> Age;
		workerArray[i].SetAge(Age);
		cout << "修改成功" << endl;
		break;
	case 6:
		cout << "输入要修改的工资" << endl;
		cin >> Wage;
		workerArray[i].SetWage(Wage);
		cout << "修改成功" << endl;
		break;
	case 7:
		cout << "输入要修改的地址" << endl;
		cin >> addr;
		workerArray[i].SetAddress(addr);
		cout << "修改成功" << endl;
		break;
	case 8:
		cout << "输入要修改的电话" << endl;
		cin >> tel;
		workerArray[i].SetTelephone(tel);
		break;
		cout << "修改成功" << endl;
	default:
		cout << "错误的输入!\n" << endl;
		break;
	}
}

void WorkList::DeleteWorker()
{
	size_t i=0;
	FindWorker(i);	
	workerArray.erase(workerArray.begin() + i);//删掉i的那个数组
	cout << "操作成功" << endl;
}

void WorkList::SortWorker()
{
	int choice;
	cout << "请选择排序的方式：" << endl;
	cout << "1、按照升序排序" << endl;
	cout << "2、按照降序排序" << endl;
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
	cout << "请选择排序的方式：" << endl;
	cout << "1.按照工号排序" << endl;
	cout << "2.按照工资排序" << endl;
	cout << "3.按照姓名排序" << endl;
	cin >> choice;
	switch(choice)//冒泡法排序
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
	cout << "请选择排序的方式：" << endl;
	cout << "1.按照工号排序" << endl;
	cout << "2.按照工资排序" << endl;
	cout << "3.按照姓名排序" << endl;
	cin >> choice;
	switch(choice)//冒泡法排序
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
			cout << "输入有误" << endl;
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