%{
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

%}

letter [a-zA-Z]  
digit[0-9]  
%%  
{digit}+("E"("+"|"-")?{digit}+)? printf("\n%s\this is real number",yytext);  

{digit}+"."{digit}+("E"("+"|"-")?{digit}+)? printf("\n%s\t is floating pt no ",yytext); 
 
"if"|"else"|"int"|"char"|"scanf"|"printf"|"switch"|"return"|"struct"|"do"|"while"|"void"|"for"|"float" printf("\n%s\t is keywords",yytext);  

"\a"|"\\n"|"\\b"|"\t"|"\\t"|"\b"|"\\a" printf("\n%s\tis Escape sequences",yytext);  

{letter}({letter}|{digit})* printf("\n%s\tis identifier",yytext);  

"&&"|"<"|">"|"<="|">="|"="|"+"|"-"|"?"|"*"|"/"|"%"|"&"|"||" printf("\n%s\toperator ",yytext);  

"{"|"}"|"["|"]"|"("|")"|"#"|"'"|"."|"\""|"\\"|";"|"," printf("\n%s\t is a special character",yytext);  

"%d"|"%s"|"%c"|"%f"|"%e" printf("\n%s\tis a format specifier",yytext);  

%%  
int yywrap()  
{  
return 1;  
}  
int main(int argc,char *argv[])  
{  
yyin=fopen(argv[1],"r");  
yylex();
fclose(yyin);  
return 0;  
}
