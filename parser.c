#include <stdio.h>
#include <string.h>

void parser(char str[])
{
	int in = 0;
	int index = 0;
	
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '<')
		{
			in = 1;
			continue;
		}
		else if(str[i] == '>')
		{
			in = 0;
			continue;
		}
		if(in == 0)
		{
			str[index] = str[i];
			index++;
		}
	}
	str[index] = '\0';
	
	//Removing spaces from the beginning
	while(str[0] == ' ')
	{
		for(int i = 0; i < strlen(str); i++)
		{
			str[i] = str[i+1];
		}
	}
	
	//Removing spaces from the end
	while(str[strlen(str) - 1] == ' ')
	{
		str[strlen(str) - 1] = '\0';
	}
}

int main()
{
	char str[200];
	
	printf("Enter html content to be parsed\n");
	gets(str);
	
	parser(str);
	
	printf("The content after parsing is ~~%s~~", str);
	return 0;
}
