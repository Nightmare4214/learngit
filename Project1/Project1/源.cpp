#include<iostream>
#include<set>
#include<fstream>
#include<string>
using namespace std;
//1���������֡�2��ʶ����3������4�������5�ָ���

//������
string reserved[] = { "try","catch","class","signed","unsigned","char","int","short","long","bool","long long","size_t",
"enum","false","true","float","double","long double","string","typedef","void","struct","define","const","delete","dynamic_cast",
"static","static_cast","switch","case","break","default","for","while","do","continue","if","else","goto","explicit",
"export","extern","new","operator","private","public","protected","register","return","sizeof","throw","template","this","typeid",
"friend","inline","using","namespace","union","virtual","reinterpret_cast","typename","volatile","wchar_t" ,"main"};
//������/�ؼ��ֵļ���
set<string> keyword(reserved, reserved + 65);
//��ʶ��
set<string> identifier;
//������
set<string> constant;
char character;
string token;
ifstream fin;
//��character�е��ַ�Ϊ�գ���������ַ���ֱ���ǿ�
void getbe() {
	while (character == ' ' || character == '\r' || character == '\n'||character=='\t') {
		character = fin.get();
	}
}
//��token���ַ�����character�е��ַ�������Ϊtoken�е����ַ���
void concatenation() {
	token += character;
}
//�ж�character�е��ַ��Ƿ�Ϊ��ĸ
bool letter() {
	return character >= 'a'&&character <= 'z' || character >= 'A'&&character <= 'Z';
}
//�ж�character�е��ַ��Ƿ�Ϊ����
bool digit() {
	return character >= '0'&&character <= '9';
}
//�ж�token�е��ַ����Ƿ��ڱ����ֱ���
bool reserve() {
	return keyword.find(token)==keyword.end();
}
//ɨ��ָ�����һ���ַ���ͬʱ��character��Ϊ�հ�
void retract() {
	fin.seekg(-1, ios::cur);
	character = ' ';
}
//����ʶ���Ǽǵ����ű���(id=2),�������Ǽǵ�������(id=3)
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
//�ʷ�����
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
		cout << "�ļ���ʧ��" << endl;
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