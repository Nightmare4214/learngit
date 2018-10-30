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
"friend","inline","using","namespace","union","virtual","reinterpret_cast","typename","volatile","wchar_t" };
//保留字/关键字的集合
set<string> keyword(reserved, reserved + 64);
//标识符
set<string> identifier;
//常数表
set<string> constant;
char character;
string token;
ifstream fin;
void getbe() {
	while (character == ' ' || character == '\r' || character == '\n') {
		character = fin.get();
	}
}
void concatenation() {
	token += character;
}
bool letter() {
	return character >= 'a'&&character <= 'z' || character >= 'A'&&character <= 'Z';
}
bool digit() {
	return character >= '0'&&character <= '9';
}
int reserve() {
	if (token == "while")
		return 1;
	else if (token == "if")
		return 2;
	else if (token == "else")
		return 3;
	else if (token == "switch")
		return 4;
	else if (token == "case")
		return 5;
	else if (token == "int")
		return 6;
	else if (token == "for")
		return 7;
	else if (token == "do")
		return 8;
	else if (token == "return")
		return 9;
	else if (token == "break")
		return 10;
	else if (token == "continue")
		return 11;
	else
		return 0;
}
void retract() {
	fin.seekg(-1, ios::cur);
	character = ' ';
}
void buildlist() {
	identifier.insert(token);
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
		if (reserve() == 0) {
			buildlist();
			cout << "(2," + token + ")" << endl;
		}
		else {
			cout << "(1," + token + ")" << endl;
		}
	}
	else if ('0' <= character && character <= '9') {
		while (digit()) {
			concatenation();
			character = fin.get();
		}
		retract();
		buildlist();
		cout << "(3," << token << ")" << endl;
	}
	else
	{
		switch (character)
		{

		case '+':
			cout << "(4," << character << ")" << endl;
			break;
		case '-':
			cout << "(4," << character << ")" << endl;
			break;
		case '*':
			cout << "(4," << character << ")" << endl;
			break;
		case '<':
			concatenation();
			character = fin.get();
			if (character == '=') {
				cout << "(4," << token << ")" << endl;
			}
			else {
				retract();
				cout << "(4," << token << ")" << endl;
			}
			break;
		case '=':
			concatenation();
			character = fin.get();
			if (character == '=') {
				concatenation();
				cout << "(4," << token << ")" << endl;
			}
			else {
				retract();
				cout << "(4," << token << ")" << endl;
			}
			break;
		case '(':
		case ')':
		case '{':
		case '}':
		case ',':
		case ';':
			cout << "(5," << character << ")" << endl;
			break;
		default:
			error();
			break;
		}
	}
}
int main()
{
	fin.open("D://test.txt", ios::binary | ios::in);
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