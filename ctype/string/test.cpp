#include<stdio.h>
#include<ctype.h>
int main() {
	char arr[] = "I Am a Student";
	int i = 0;
	while (arr[i]!='\0')
	{
		if (islower(arr[i]))
		{
			arr[i] -= 32;
		}
		i++;

	}
	printf("%s\n", arr);
	return 0;
}