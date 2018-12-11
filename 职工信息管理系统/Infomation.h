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
	char name[30];  // ����
	char address[50]; // ��ַ
	int age;    // ����
	double wage; // ����
	char num[10]; // ����
	char sex; //�Ա�
	char education[20];  // ѧ��
	char telephone[20];  // �绰

};

class WorkList
{
public:
	WorkList() {};
	~WorkList(){};
	void ScreenShow();   // ������ʾ
	void ReadInfoFile();//��ȡ�ļ���Ϣ���ڴ���
	
private:
	void DeleteWorker(); // ɾ��Ա����Ϣ**
	void Modification(); // �޸�Ա����Ϣ**
	void SortWorker();   // ����
	void UpSort();       // ����������
	void DownSort();     // �Խ�������
	void SaveInfoFile(); // �����ڴ���Ϣ���ļ�
	//void ReadInfoFile(); // ��ȡ�ļ���Ϣ���ڴ���   
	void ShowWorker();   // ��ʾ����Ա����Ϣ**
	void FindWorker(size_t);   // �鿴�뿴��Ա����Ϣ**
	void AddWorker();    // ���Ա����Ϣ**
	size_t fdi;
	vector<Worker> workerArray;
	Worker m_TmpWorker;
};
