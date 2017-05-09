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

		string question = p.generateExpression();		//用于生成题目 
		cout << question;
		p.writefile(p1, &question[0],0);
		float answer = p.calculateResult(question);		//用于计算结果 
		//	cout << answer << endl;
		sum += p.scan(answer,p1);							//用于用户输入并计算做对题目的数目 
		i++;												//	cout << sum << endl;
//		if (p.end() == 1)                               //用于结束应用 
//		{
//			break;
//		}
	}
	p.print(sum,p1);                                //用于输出结果 
	return 0;
}
