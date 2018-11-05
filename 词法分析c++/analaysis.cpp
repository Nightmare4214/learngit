#include<iostream>
#include<stack>
#include<set>
#include<fstream>
#include<string>
using namespace std;
//1基本保留字、2标识符、3常量、4运算符、5分隔符
//保留字
string reserved[] = { "try", "catch", "class", "signed", "unsigned", "char", "int", "short", "long", "bool", "long long", "size_t",
"enum", "false", "true", "float", "double", "long double", "string", "typedef", "void", "struct", "define", "const", "delete", "dynamic_cast",
"static", "static_cast", "switch", "case", "break", "default", "for", "while", "do", "continue", "if", "else", "goto", "explicit",
"export", "extern", "new", "operator", "private", "public", "protected", "register", "return", "sizeof", "throw", "template", "this", "typeid",
"friend", "inline", "using", "namespace", "union", "virtual", "reinterpret_cast", "typename", "volatile", "wchar_t", "main" };
//保留字/关键字的集合
set<string> keyword(reserved, reserved + 65);
//标识符
set<string> identifier;
//常数表
set<string> constant;
//检测括号是否匹配
stack<char> match;
char character;
string token;
ifstream fin;
//是否终止程序;
bool jumpEnd;
//是否终止匹配括号
bool endMatch;
//若character中的字符为空，则继续读字符，直到非空
void getbe() {
	while (character == ' ' || character == '\r' || character == '\n' || character == '\t') {
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
	return keyword.find(token) == keyword.end();
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
//错误处理
void error() {
	cout << "error:" << token << endl;
}
bool isEnd() {
	return character == ' ' || character == '\r' || character == '\n' || character == '\t' || character == '(' || character == ')' || character == '{' || character == '}' || character == '[' || character == ']' || character == ';' || character == ',' || character == EOF;
}
bool isOp(char getOp) {
	return getOp == '+' || getOp == '-' || getOp == '*' || getOp == '/';
}
//判断科学记数法，返回：3代表数字，4代表运算符，-1代表错误
int isUnsignNum()
{
	//开头小数点判断
	if (character == '.')
	{
		concatenation();
		character = fin.get();
		if (character == '_' || letter()) {
			retract();

			return 4;
		}
	}
	//读取整数不带E部分
	while (!fin.eof() && digit()) {
		concatenation();
		character = fin.get();
	}
	if (character == '.')//出现小数点，进入小数部分
	{
		do {
			concatenation();
			character = fin.get();
		} while (!fin.eof() && digit());//读取小数部分的数字
		if (character == 'E' || character == 'e')//如果出现E
		{
			concatenation();
			character = fin.get();
			if (character == '+' || character == '-')//E后面只能跟+或-
			{
				concatenation();
				character = fin.get();
				//读取E,E+,E-后面的数字部分
				while (!fin.eof() && digit()) {
					concatenation();
					character = fin.get();
				}
			}
			else if (!fin.eof() && digit())
			{
				//读取E,E+,E-后面的数字部分
				while (!fin.eof() && digit()) {
					concatenation();
					character = fin.get();
				}
			}
			else
			{
				while (!isEnd() && !isOp(character))//还没结束，匹配失败，error()
				{
					concatenation();
					character = fin.get();
				}
				retract();
				return -1;
			}
		}
	}
	else if (character == 'E' || character == 'e')//没有出现小数点,读取整数部分的E
	{
		concatenation();
		character = fin.get();
		if (character == '+' || character == '-')//E后面只能跟+或-
		{
			concatenation();
			character = fin.get();
			//读取E,E+,E-后面的数字部分
			while (!fin.eof() && digit()) {
				concatenation();
				character = fin.get();
			}
		}
		else if (!fin.eof() && digit())
		{
			//读取E,E+,E-后面的数字部分
			while (!fin.eof() && digit()) {
				concatenation();
				character = fin.get();
			}
		}
		else
		{
			while (!isEnd() && !isOp(character))//还没结束，匹配失败，error()
			{
				concatenation();
				character = fin.get();
			}
			retract();
			return -1;
		}
	}
	else if (character == 'x' || character == 'X') {
		concatenation();
		character = fin.get();
		while (!fin.eof() && (digit()||character>='a'&&character<='f'||character>='A'&&character<='Z')) {
			concatenation();
			character = fin.get();
		}
	}
	//匹配结束，判断该无符号读取是否结束
	if (isEnd() || isOp(character))
	{
		retract();
		buildlist(3);
		return 3;
	}
	else
	{
		while (!isEnd() && !isOp(character))//还没结束，匹配失败，error()
		{
			concatenation();
			character = fin.get();
		}
		retract();
		return -1;
	}
}
//词法分析
void analysis() {
	token = "";
	character = fin.get();
	getbe();
	bool finded;
	bool changed;
	if (character == EOF)
		return;
	if (letter() || character == '_') {
		while (letter() || digit() || character == '_') {
			concatenation();
			character = fin.get();
		}
		if (reserve()) {
			//标识符
			buildlist(2);
			cout << "(2,\"" + token + "\")" << endl;
		}
		else {
			//保留字
			cout << "(1,\"" + token + "\")" << endl;
		}
		if (character == '.')
			cout << "(4,\".\")" << endl;
		else
			retract();
	}
	else if (digit() || character == '.') {
		int t = isUnsignNum();
		if (t == 3) {
			//常数
			cout << "(3,\"" << token << "\")" << endl;
		}
		else if (t == -1) {
			//错误
			error();
		}
		else if (t == 4) {
			//以对象方式访问成员.
			cout << "(4,\"" + token + "\")" << endl;
		}
	}
	else
	{
		switch (character)
		{
		case '+':
			concatenation();
			character = fin.get();
			if (character == '+') {
				//自增++
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '=') {
				//以和赋值+=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//加号+
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '-':
			concatenation();
			character = fin.get();
			if (character == '-') {
				//自减--
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '>') {
				//以指针方式访问成员->
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '=') {
				//以差赋值-=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (digit())
			{
				char getOp = ' ';
				if (fin.tellg() >= 3) {
					fin.seekg(-3, ios::cur);
					getOp = fin.get();
					fin.seekg(2, ios::cur);
				}
				//如果往前读俩个字符，发现是等号或者运算符或者空格，则识别为负数;
				if (isOp(getOp) || getOp == '=' || getOp == '\n' || getOp == '\t' || getOp == ' ')
				{
					int t = isUnsignNum();
					if (t == 3) {
						//常数
						cout << "(3,\"" << token << "\")" << endl;
					}
					else if (t == -1) {
						//错误
						error();
					}
					else if (t == 4) {
						//以对象方式访问成员
						cout << "(4,\"" + token + "\")" << endl;
					}
				}
			}
			else {
				//减号-
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '*':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//以积赋值*=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//乘号/取指针指向的值*
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '%':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//以取余数赋值%=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//取余%
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '/':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//以商赋值/=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '/') {
				//单行注释
				character = fin.get();
				while (!fin.eof() && character != '\n') {
					character = fin.get();
				}
			}
			else if (character == '*') {
				//多行注释
				character = fin.get();
				bool finded = false;
				while (!fin.eof()) {
					if (character == '*') {
						finded = true;
					}
					else if (character == '/'&&finded) {
						break;
					}
					else {
						finded = false;
					}
					character = fin.get();
				}
				// /**/不匹配
				if (!finded) {
					cout << "/**/不匹配" << endl;
				}
				break;
			}
			else {
				//除号/
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '<':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//小于等于关系<=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '<') {
				concatenation();
				character = fin.get();
				if (character == '=') {
					//以比特左移赋值<<=
					concatenation();
					cout << "(4,\"" << token << "\")" << endl;
				}
				else {
					//比特左移<<
					retract();
					cout << "(4,\"" << token << "\")" << endl;
				}
			}
			else {
				//小于关系<
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '>':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//大于等于关系>=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '>') {
				concatenation();
				character = fin.get();
				if (character == '=') {
					//以比特右移赋值>>=
					concatenation();
					cout << "(4,\"" << token << "\")" << endl;
				}
				else {
					//比特右移>>
					retract();
					cout << "(4,\"" << token << "\")" << endl;
				}
			}
			else {
				//大于关系>
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '=':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//等于关系==
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//直接赋值=
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '&':
			concatenation();
			character = fin.get();
			if (character == '&') {
				//逻辑AND &&
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '=') {
				//以比特AND赋值 &=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//比特AND/取变量的地址 &
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '|':
			concatenation();
			character = fin.get();
			if (character == '|') {
				//逻辑OR ||
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else if (character == '=') {
				//以比特OR赋值 |=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//比特OR |
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '^':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//以比特XOR赋值 ^=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//比特XOR ^
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '!':
			concatenation();
			character = fin.get();
			if (character == '=') {
				//不等于关系!=
				concatenation();
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				//逻辑非!
				retract();
				cout << "(4,\"" << token << "\")" << endl;
			}
			break;
		case '~':
			//按位取反~
			cout << "(4,\"" << token << "\")" << endl;
			break;
		case '.':
			//以对象方式访问成员
			cout << "(4,\"" << token << "\")" << endl;
			break;
		case '#':
			concatenation();
			character = fin.get();
			while (!fin.eof() && character != '\n') {
				concatenation();
				character = fin.get();
			}
			//预处理指令
			cout << "预处理指令" + token << endl;
			break;
		case '[':
		case '(':
		case '{':
			if (!endMatch) {
				match.push(character);
			}
			cout << "(5,\"" << character << "\")" << endl;
			break;
		case ')':
			if (endMatch) {
				cout << "(5,\"" << character << "\")" << endl;
			}
			else if (!match.empty() && match.top() == '(') {
				match.pop();
				cout << "(5,\"" << character << "\")" << endl;
			}
			else {
				cout << "()不匹配" << endl;
				jumpEnd = true;
				endMatch = true;
			}
			break;
		case '}':
			if (endMatch) {
				cout << "(5,\"" << character << "\")" << endl;
			}
			else if (!match.empty() && match.top() == '{') {
				match.pop();
				cout << "(5,\"" << character << "\")" << endl;
			}
			else {
				cout << "{}不匹配" << endl;
				jumpEnd = true;
				endMatch = true;
			}
			break;
		case ']':
			if (endMatch) {
				cout << "(5,\"" << character << "\")" << endl;
			}
			else if (!match.empty() && match.top() == '[') {
				match.pop();
				cout << "(5,\"" << character << "\")" << endl;
			}
			else {
				cout << "[]不匹配" << endl;
				jumpEnd = true;
				endMatch = true;
			}
			break;
		case '\'':
			//找到'
			finded = false;
			//转义
			changed = false;
			concatenation();
			character = fin.get();
			while (!fin.eof()) {
				if (changed) {
					changed = false;
					concatenation();
					character = fin.get();
				}
				else if (character == '\n') {
					cout << "字符中不能有换行" << endl;
					return;
				}
				else if (character == '\'') {
					finded = true;
					concatenation();
					buildlist(3);
					//字符常量
					cout << "(4,\"" << token << "\")" << endl;
					break;
				}
				else if (character == '\\') {
					changed = true;
					concatenation();
					character = fin.get();
					if (!fin.eof() && character == '\r') {
						character = fin.get();
						if (!fin.eof() && character == '\n') {
							token = token.substr(0, token.length() - 1);
							changed = false;
							character = fin.get();
						}
						else {
							retract();
							retract();
						}
					}
				}
				else {
					concatenation();
					character = fin.get();
				}

			}
			if (!finded) {
				cout << "''不匹配" << endl;
			}
			break;
		case '"':
			//找到'
			finded = false;
			//转义
			changed = false;
			concatenation();
			character = fin.get();
			while (!fin.eof()) {
				if (changed) {
					changed = false;
					concatenation();
					character = fin.get();
				}
				else if (character == '\n') {
					cout << "字符串中不能有换行" << endl;
					return;
				}
				else if (character == '"') {
					finded = true;
					concatenation();
					buildlist(3);
					//字符串常量
					cout << "(4,\"" << token << "\")" << endl;
					break;
				}
				else if (character == '\\') {
					changed = true;
					concatenation();
					character = fin.get();
					if (!fin.eof() && character == '\r') {
						character = fin.get();
						if (!fin.eof() && character == '\n') {
							token = token.substr(0, token.length() - 1);
							changed = false;
							character = fin.get();
						}
						else {
							retract();
							retract();
						}
					}
				}
				else {
					concatenation();
					character = fin.get();
				}

			}
			if (!finded) {
				cout << "\"\"不匹配" << endl;
			}
			break;
		case ':':
			concatenation();
			character = fin.get();
			if (character == ':') {
				//作用域解析::
				cout << "(4,\"" << token << "\")" << endl;
			}
			else {
				retract();
				// :
				cout << "(4,\"" << token << "\")" << endl;
			}
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
	endMatch = false;
	jumpEnd = false;
	fin.open("test.txt", ios::binary | ios::in);
	if (!fin)
	{
		cout << "文件打开失败" << endl;
	}
	else
	{
		while (fin.peek() != EOF)
		{
			if (jumpEnd) {
				break;
			}
			analysis();
		}
		if (!match.empty()) {
			cout << "括号不匹配" << endl;
		}
	}
	return 0;
}