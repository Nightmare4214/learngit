%{
int wordCount = 0;
int numcount = 0;
#define N 100000 
char stack[N];
int top=0;
%}
chars [A-Za-z\_]
numbers ([0-9])+
delim [" "\n\r\t]
whitespace {delim}+
words {chars}({chars}|{numbers})*
kexuejishu  -?((([0-9]+)((\.[0-9]+)*[Ee](\+|\-)?([0-9]+))*)|(\.([0-9]+)[Ee](\+|\-)?[0-9]+))
%%
"#".* {printf("%s\n",yytext);}
"//".* {}
"/*" {
	int c1=0,c2=input(),flag=0;
	while(1){
		if(c2==EOF)break;
		if(c1=='*'&c2=='/'){
			flag=1;
			break;
		}
		c1=c2;
		c2=input();
	}
	if(flag==0)printf("/**/≤ª∆•≈‰\n");
}
\" {
	char s[10000];
	s[0]='"';
	int len=1,flag=0;
	s[len]=input();
	while(1){
		if(s[len]==EOF)break;
		if(s[len]=='"'&&s[len-1]!='\\'){
			flag=1;
			break;
		}
		++len;
		s[len]=input();
	}
	if(flag==1){
		printf("(%d,\"%s\")\n",4,s);
	}
	else{
		printf("\"\"≤ª∆•≈‰\n");
		return;
	}
}
"'" {
	char s[10000];
	s[0]='\'';
	int len=1,flag=0;
	s[len]=input();
	while(1){
		if(s[len]==EOF)break;
		if(s[len]=='\''&&s[len-1]!='\\'){
			flag=1;
			break;
		}
		++len;
		s[len]=input();
	}
	if(flag==1){
		printf("(%d,\"%s\")\n",4,s);
	}
	else{
		printf("''≤ª∆•≈‰\n");
		return;
	}
}
[({\[] {stack[top++]=yytext[0];printf("(%d,\"%s\")\n",5,yytext);}
[)}\]] {
	if(top>0){
		char c=stack[top-1],d=yytext[0];
		if(c=='('&&d==')'||c=='['&&d==']'||c=='{'&&d=='}'){
			--top;
			printf("(%d,\"%s\")\n",5,yytext);
		}
		else {
			printf("¿®∫≈≤ª∆•≈‰\n");
			return;
		}
	}
	else {
		printf("¿®∫≈≤ª∆•≈‰\n");
		return;
	}
	
}
try|catch|class|signed|unsigned|char|int|short|long|bool|longlong|size_t|enum|false|true|float|double|longdouble|string|typedef|void|struct|define|const|delete|dynamic_cast|static|static_cast|switch|case|break|default|for|while|do|continue|if|else|goto|explicit|export|extern|new|operator|private|public|protected|register|return|sizeof|throw|template|this|typeid|friend|inline|using|namespace|union|virtual|reinterpret_cast|typename|volatile|wchar_t|main {printf("(%d,\"%s\")\n",1,yytext);}
{words} { wordCount++; printf("(%d,\"%s\")\n",2,yytext); }
{whitespace} {}
0[xX][0-9a-fA-F]+ {printf("(%d,\"%s\")\n",3,yytext);}
{kexuejishu} {printf("(%d,\"%s\")\n",3,yytext);}
:|::|\.|->|\+\+|\-\-|~|!|\-|&|\+|\*|"/"|%|<<|>>|<|<=|>|>=|==|!=|\^|"|"|&&|"||"|=|\+=|\-=|\*=|"/="|%=|<<=|>>=|&=|"|="|^=|, {printf("(%d,\"%s\")\n",4,yytext);}
[,;`] {printf("(%d,\"%s\")\n",5,yytext);}
%%

int main()
{
printf("ok1\n");

yylex(); /* start the  analysis*/

printf("ok2\n");
if(top!=0)printf("¿®∫≈≤ª∆•≈‰\n");
printf(" No of words: %d\n  number: %d\n", wordCount, numcount);
return 0;

}

int yywrap()
{
return 1;
}
