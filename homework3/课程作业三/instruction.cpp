#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include<stdlib.h>
#include <string>
#include <vector>
#include<sstream>
#include <cstring>
#include <unordered_map>
#include <math.h>
#include"caluculate.h"


using namespace std;

void problem::writefile(char *p0,char *p,int w)
{
	FILE *f;
	if ((f = fopen(p0, "a") )== NULL)
	{
		cout << "can not write" << endl;
	}
	fputs(p,f);
	if(w==1)
	fputs("\n", f);

	
}
string problem::combine(string str1, string str2, char k)
{
	string combination;
	combination = str1 + k + str2;
	return combination;
}
string problem::int_string(int number)
{
	int temp = abs(number);
	char str[200];
	_itoa_s(temp, str, 10);
	return str;
}
int problem::scan(float answer,char *p)
{
	int flag1 = 0; int flag2 = 1;
	char chinese[10] = "��ȷ��";
	float user;
	cin >> user;
	ostringstream ss1;
	ss1 << user;
	string str1 = ss1.str();
	problem::writefile(p, &str1[0],flag2);
	answer = ((int)(((float)answer) * 100 + 0.5)) / 100.0;
	cout << "��ȷ�� " << answer << endl;
	problem::writefile(p, chinese,flag1);
	ostringstream ss2;
	ss2 << answer;
	string str2 = ss2.str();
	problem::writefile(p, &str2[0],flag2);
	if (user == answer)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*int problem::end()
{
	cout << _whether_to_exit << " ";
	char choose;
	cin >> choose;
	if (choose == 'Y' || choose == 'y')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}*/
char problem::randomOperation()
{
	int j;
	char symbol[1];
	j = random() % 4;
	switch (j) {
	case 0:
		symbol[0] = '+';
		break;
	case 1:
		symbol[0] = '-';
		break;
	case 2:
		symbol[0] = '*';
		break;
	case 3:
		symbol[0] = '/';
		break;
	}
	return symbol[0];
}
int problem::randomNunber()
{
	int a = random() % 10 + 1;
	return a;
}
void problem::print(int right,char *pp)
{
	int flag1 = 0;
	char right1[20] = { 0 };
	char chinese1[10] = "��������", chinese2[20] = "���⣬��л����ʹ��";
	cout << "��������" << right << "���⣬��л����ʹ��" << endl;
	problem::writefile(pp, chinese1,flag1);
	right1[0] = right + '0';
	problem::writefile(pp, &right1[0],flag1);
	problem::writefile(pp, chinese2,flag1);
//	cout << _thanks << endl;
}
string problem::generateExpression()
{
	int num1, num2, change, count;
	char symbol;
	string str_num1, str_num2, Equation, t;
	num1 = randomNunber();
	num2 = randomNunber();
	count = random() % 6 + 2;
	symbol = randomOperation();
	str_num1 = int_string(num1);
	str_num2 = int_string(num2);
	Equation = combine(str_num1, str_num2, symbol);          //�����������ķ��Ž�� 
	for (count; count>2; count--) {
		symbol = randomOperation();
		str_num1 = Equation;
		change = random() % 2;
		if (change == 0) {
			str_num1 = '(' + str_num1 + ')';
		}
		num2 = random() % 10 + 1;
		str_num2 = int_string(num2);
		change = random() % 2;
		if (change == 0) {
			t = str_num1;
			str_num1 = str_num2;
			str_num2 = t;
		}
		Equation = combine(str_num1, str_num2, symbol);
	}
	//		cout << Equation << "=" << endl;
	string Equation2 = Equation + '=';
	return Equation2;
}
float problem::calculateResult(string str)
{
	InitPriorities();                                      //�������ȼ��Ƚϱ� 
	vector< float > Operands;                              //������ջ 
	vector< char > Operators;                              //�����ջ 
	float OperandTemp = 0;
	char LastOperator = 0;                                 //��¼��һ���������ķ��� 
	for (int i = 0; i < str.size(); i++) {                 //��ѭ������ȥ���� 
		char ch = str[i];
		if ('0' <= ch && ch <= '9') {
			OperandTemp = OperandTemp * 10 + ch - '0';
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
			if (ch != '(' && LastOperator != ')') {         //��ϱ��κ��ϴ��������ķ������ж��Ƿ���Ҫ����ǰ�洢��������ѹ��ջ 
				Operands.push_back(OperandTemp);
				OperandTemp = 0;
			}
			char Opt2 = ch;
			for (; Operators.size() > 0;) {
				char Opt1 = Operators.back();
				char CompareRet = Priorities[Opt1][Opt2];   //�õ�ǰ������ջ������������ʽ�� 
				if (CompareRet == '>') {                    //��ǰ�ķ��ŵ����ȼ�С��ջ������ʱ�Ϳ��Խ�ջ�����ż�����������ѹ��ջ  
					float Operand2 = Operands.back();
					Operands.pop_back();
					float Operand1 = Operands.back();
					Operands.pop_back();
					Operators.pop_back();
					float Ret = caculate(Operand1, Operand2, Opt1);
					Operands.push_back(Ret);
				}
				else if (CompareRet == '<') {                //��ǰ�ķ������ȼ�����ջ�����Ų��ܽ���������������ѭ�����洢��ǰ���� 
					break;
				}
				else if (CompareRet == '=') {                //����ǡ����������� ����ϵ���� �����Ƴ����������˳�ѭ�� 
					Operators.pop_back();
					break;
				}
			}
			if (Opt2 != ')') {
				Operators.push_back(Opt2);
			}
			LastOperator = Opt2;
		}
	}
	if (LastOperator != ')') {                               //���������Ǽ���һ���������ŵ���ʽ�� 
		Operands.push_back(OperandTemp);
	}
	for (; Operators.size() > 0;) {
		float Operand2 = Operands.back();
		Operands.pop_back();
		float Operand1 = Operands.back();
		Operands.pop_back();
		char Opt = Operators.back();
		Operators.pop_back();
		float Ret = caculate(Operand1, Operand2, Opt);
		Operands.push_back(Ret);
	}
	return Operands.back();
}
float problem::caculate(float Operand1, float Operand2, char Operator)
{
	float result = 0;
	if (Operator == '+') {
		result = Operand1 + Operand2;
	}
	if (Operator == '-') {
		result = Operand1 - Operand2;
	}
	if (Operator == '*') {
		result = Operand1*Operand2;
	}
	if (Operator == '/') {
		result = Operand1 / Operand2;
	}
	return result;
}
void problem::showTip(char *ptr)
{
	char chinese1[60] = "��ӭʹ�ñ�����,�Ѿ���������Ҫ����г��⡣С���뱣����λ";
	cout << "��ӭʹ�ñ�����,�Ѿ���������Ҫ����г��⣬С���뱣����λ��" << endl;
	problem::writefile(ptr, chinese1,1);
	//cout << _tip << endl;
}
/*void problem::SelectLanguage()
{
	char str[1000][55] = { 0 };
	ifstream is("LanguageList.txt");
	int fnum = 0;
	char buf[49];
	for (int i = 0; !is.eof(); i++)
	{
		is.getline(buf, 49);
		if (strlen(buf) > 1)
		{
			strcpy_s(str[fnum], buf);
			fnum++;
		}
	}
	cout << "��ѡ�����ԣ�" << endl;
	for (int i = 0; i < fnum; i++)
	{
		cout << i + 1 << "\t";
		cout << str[i] << endl;
	}
	cout << "��ѡ��";
	is.close();

	int choose;
	cin >> choose;
	choose--;
	strcat_s(str[choose], ".txt");
	is.open(str[choose]);
	if (is.is_open())
	{
		is.getline(_tip, 100);
		is.getline(_whether_to_exit, 100);
		is.getline(_correctNum, 100);
		is.getline(_thanks, 100);
	}
	is.close();
	system("cls");
}*/
void problem::InitPriorities()
{
	Priorities['+']['-'] = '>';
	Priorities['+']['+'] = '>';
	Priorities['+']['*'] = '<';
	Priorities['+']['/'] = '<';
	Priorities['+']['('] = '<';
	Priorities['+'][')'] = '>';

	Priorities['-']['-'] = '>';
	Priorities['-']['+'] = '>';
	Priorities['-']['*'] = '<';
	Priorities['-']['/'] = '<';
	Priorities['-']['('] = '<';
	Priorities['-'][')'] = '>';

	Priorities['*']['-'] = '>';
	Priorities['*']['+'] = '>';
	Priorities['*']['*'] = '>';
	Priorities['*']['/'] = '>';
	Priorities['*']['('] = '<';
	Priorities['*'][')'] = '>';

	Priorities['/']['-'] = '>';
	Priorities['/']['+'] = '>';
	Priorities['/']['*'] = '>';
	Priorities['/']['/'] = '>';
	Priorities['/']['('] = '<';
	Priorities['/'][')'] = '>';

	Priorities['(']['+'] = '<';
	Priorities['(']['-'] = '<';
	Priorities['(']['*'] = '<';
	Priorities['(']['/'] = '<';
	Priorities['(']['('] = '<';
	Priorities['('][')'] = '=';

	Priorities[')']['+'] = '?';
	Priorities[')']['-'] = '?';
	Priorities[')']['*'] = '?';
	Priorities[')']['/'] = '?';
	Priorities[')']['('] = '?';
	Priorities[')'][')'] = '?';
}
int problem::readfile(char *p0)
{
	FILE *f;
	char ch[2];
	if ((f = fopen(p0, "r")) == NULL)
	{
		cout << "Can not open!" << endl;
	}

	fgets(ch, 2, f);
	return ch[0] - '0';
}