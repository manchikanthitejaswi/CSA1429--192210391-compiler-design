%{
%}
%%
[A-Z]+ {printf("%s\n", yytext);}
.|\n {}

%%
int yywrap(){}
int main()
{
  printf("Enter a letter");
  yylex();
}
