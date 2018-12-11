#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <vector>
using namespace std;

//const size_t maxNum = 100;

class Worker
{
public:
	Worker(){};
	~Worker(){};

	void InputData();
	void Show();
	char* GetName(){return name;};
	char* GetAddress(){return address;};
	int GetAge(){return age;};
	double GetWage(){return wage;};
	char* GetNumber(){return num;};
	char GetSex(){return sex;};
	char* GetEducation(){return education;};
	char* GetTelephone(){return telephone;};
	void SetName(char nam) {name[30] = nam; };
	void SetAddress(char addr){address[50]=addr;};
	void SetAge(int Age){age=Age;};
	void SetWage(double Wage){wage=Wage;};
	void SetNumber(char numb){num[10]=numb;};
	void SetSex(char Sex){sex=Sex;};
	void SetEducation(char edu){education[20]=edu;};
	void SetTelephone(char tel){telephone[20]=tel;};
	


private:
	char name[30];  // 姓名
	char address[50]; // 地址
	int age;    // 年龄
	double wage; // 工资
	char num[10]; // 工号
	char sex; //性别
	char education[20];  // 学历
	char telephone[20];  // 电话

};

class WorkList
{
public:
	WorkList() {};
	~WorkList(){};
	void ScreenShow();   // 界面显示
	void ReadInfoFile();//读取文件信息到内存中
	
private:
	void DeleteWorker(); // 删除员工信息**
	void Modification(); // 修改员工信息**
	void SortWorker();   // 排序
	void UpSort();       // 以升序排序
	void DownSort();     // 以降序排序
	void SaveInfoFile(); // 保存内存信息到文件
	//void ReadInfoFile(); // 读取文件信息到内存中   
	void ShowWorker();   // 显示所有员工信息**
	void FindWorker(size_t);   // 查看想看的员工信息**
	void AddWorker();    // 添加员工信息**
	size_t fdi;
	vector<Worker> workerArray;
	Worker m_TmpWorker;
};
