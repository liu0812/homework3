
#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>


#define random() (rand()%100000)

class problem
{
public:
	string combine(string str1, string str2, char k);
	string int_string(int number);
	int scan(float answer,char *p);
	//int end();
	char randomOperation();
	void print(int right,char *pp);
	string generateExpression();
	float calculateResult(string str);
	float caculate(float Operand1, float Operand2, char Operator);
	void showTip(char *ptr);
//	void SelectLanguage();
	void InitPriorities();
	int readfile(char *p0);
	int randomNunber();
	void writefile(char *p0, char *p,int w);
private:
	unordered_map< char, unordered_map < char, char > > Priorities;

	char _tip[102];
	char _whether_to_exit[102];
	char _correctNum[102];
	char _thanks[102];
}; 
