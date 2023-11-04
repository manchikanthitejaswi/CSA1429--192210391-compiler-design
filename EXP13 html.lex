%{
#include<stdio.h>
%}
%%
\<[^>]*\> fprintf(yyout,"%s\n",yytext);
.|\n;
%%
int yywrap()
{
return 1;
}
int main()
{
yyin=fopen("sample.html","r");
yyout=fopen("output.txt","W");
yylex();
return 0;
}
