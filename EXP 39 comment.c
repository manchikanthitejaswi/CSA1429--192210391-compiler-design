#include<stdio.h>
#include<string.h>
int main()
{
    char text[100];
    int i,len;
    printf("\nEnter Text: ");
    gets(text);
    len=strlen(text);
    for(i=0;i<len;i++)
    {
      if(text[i]=='/' && text[i+1]=='/')
	     printf("\nIt is a Comment.");
      else if(text[i]=='/' && text[i+1]=='' && text[len-1]=='/' && text[len-2]=='')
	     printf("\nit is a comment");
	  else
	    printf("\n it is not a comment");
	    break;
    }
    return 0;
}
