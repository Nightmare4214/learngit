#include<iostream>
#include<set>
#include<fstream>
#include<string>
using namespace std;
//1基本保留字、2标识符、3常量、4运算符、5分隔符

//保留字
string reserved[] = { "try","catch","class","signed","unsigned","char","int","short","long","bool","long long","size_t",
"enum","false","true","float","double","long double","string","typedef","void","struct","define","const","delete","dynamic_cast",
"static","static_cast","switch","case","break","default","for","while","do","continue","if","else","goto","explicit",
"export","extern","new","operator","private","public","protected","register","return","sizeof","throw","template","this","typeid",
"friend","inline","using","namespace","union","virtual","reinterpret_cast","typename","volatile","wchar_t" ,"main"};
//保留字/关键字的集合
set<string> keyword(reserved, reserved + 65);
//标识符
set<string> identifier;
//常数表
set<string> constant;
char character;
string token;
ifstream fin;
//若character中的字符为空，则继续读字符，直到非空
void getbe() {
	while (character == ' ' || character == '\r' || character == '\n'||character=='\t') {
		character = fin.get();
	}
}
//将token中字符串与character中的字符连接作为token中的新字符串
void concatenation() {
	token += character;
}
//判断character中的字符是否为字母
bool letter() {
	return character >= 'a'&&character <= 'z' || character >= 'A'&&character <= 'Z';
}
//判断character中的字符是否为数字
bool digit() {
	return character >= '0'&&character <= '9';
}
//判断token中的字符串是否在保留字表中
bool reserve() {
	return keyword.find(token)==keyword.end();
}
//扫描指针回退一个字符，同时将character置为空白
void retract() {
	fin.seekg(-1, ios::cur);
	character = ' ';
}
//将标识符登记到符号表中(id=2),将常数登记到常数表(id=3)
void buildlist(int id) {
	if (id == 2) {
		identifier.insert(token);
	}
	else {
		constant.insert(token);
	}
}
void error() {
	cout << "error:" << character << endl;
}
//词法分析
void analysis() {

	token = "";
	character = fin.get();
	getbe();
	if (character == EOF)
		return;
	if ('a' <= character && character <= 'z' || 'A' <= character && character <= 'Z') {
		while (letter() || digit()) {
			concatenation();
			character = fin.get();
		}
		retract();
		if (reserve()) {
			buildlist(2);
			cout << "(2,\"" + token + "\")" << endl;
		}
		else {
			cout << "(1,\"" + token + "\")" << endl;
		}
	}
	else if ('0' <= character && character <= '9') {
		while (digit()) {
			concatenation();
			character = fin.get();
		}
		retract();
		buildlist(3);
		cout << "(3,\"" << token << "\")" << endl;
	}
	else
	{
		switch (character)
		{

		case '+':
			cout << "(4,\"" << character << "\")" << endl;
			break;
		case '-':
			cout << "(4,\"" << character << "\")" << endl;
			break;
		case '*':
			cout << "(4,\"" << character << "\")" << endl;
			break;
		case '<':
			concatenation();
			character = fin.get();
			if (character == '=') {
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '=':
			concatenation();
			character = fin.get();
			if (character == '=') {
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '(':
		case ')':
		case '{':
		case '}':
		case ',':
		case ';':
		case '`':
			cout << "(5,\"" << character << "\")" << endl;
			break;
		default:
			error();
			break;
		}
	}
}
int main()
{
	fin.open("test.txt", ios::binary | ios::in);
	if (!fin)
	{
		cout << "文件打开失败" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			analysis();
		}
	}
	return 0;
}