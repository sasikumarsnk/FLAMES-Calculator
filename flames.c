#include<stdio.h>
#include<string.h>

void update(char *name_1,char *name_2)
{
	int index=0;
	for(int i=0;name_1[i];i++)
	{
		for(int j=0;name_2[j];j++)
		{
			if(name_1[i]==name_2[j])
		        {
				for(int p=i;name_1[p];p++)
					name_1[p]=name_1[p+1];
				for(int q=j;q<name_2[q];q++)
					name_2[q]=name_2[q+1];
				--i;--j;
				break;
			}
		}
	}
	strcat(name_1,name_2);
	return;
}

char flames(int len)
{
	char arr[6]={'f','l','a','m','e','s'};
	int index=0;
	int temp=0;
	int size = 6;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<len;j++)
		{
			++temp;
			if(temp>=size+1)
				temp=1;
		}
		size--;
		int del = temp-1;
		for(int p=del;p<size;p++)
			arr[p]=arr[p+1];
	}
	return arr[0];
	
}

int main()
{
	char your_name[20];
	char partner_name[20];
	int len;
	printf("Enter your name:\n");
	scanf("%[^\n]",your_name);
	printf("Enter your Partner name:\n");
	scanf(" %[^\n]",partner_name);
	update(your_name,partner_name);
	len = strlen(your_name);
	switch(flames(len))
	{
		case'f':
			printf("Friends\n");break;
		case'l':
			printf("Lovers\n");break;
		case'a':
			printf("Affection/Admirers\n");break;
		case'm':
			printf("Marriage\n");break;
		case'e':
			printf("Enemies\n");break;
		case's':
			printf("Siblings\n");break;
	}
}
