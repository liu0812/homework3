#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#include"caluculate.h"

int main(int argc,char *argv[])
{
	class problem p;

	char *p1 = argv[2];
	char *p0 = argv[1];
	//p.SelectLanguage();
	p.showTip(p1);
	int i=0,n;
	n = p.readfile(p0);
	srand(time(0));
	int sum = 0;
	while (i < n)
	{

		string question = p.generateExpression();		//����������Ŀ 
		cout << question;
		p.writefile(p1, &question[0],0);
		float answer = p.calculateResult(question);		//���ڼ����� 
		//	cout << answer << endl;
		sum += p.scan(answer,p1);							//�����û����벢����������Ŀ����Ŀ 
		i++;												//	cout << sum << endl;
//		if (p.end() == 1)                               //���ڽ���Ӧ�� 
//		{
//			break;
//		}
	}
	p.print(sum,p1);                                //���������� 
	return 0;
}
