#include <stdio.h>
#include <string.h>


int main()
{
	printf("\n\t#######################################################");
    printf("\n\t## Welcome to Scrum Sprint Management ###");
    printf("\n\t#######################################################");
	int ch=1;
	while(ch!=0)
	{
		printf("\n1 to Login as Team Lead:");
		printf("\n2 to Login as Team Member:\n");
		scanf("%d",&ch);
		if (ch==1)
		{
			int userId;
			char userPassword[50];
			printf("\nEnter User ID:");
			scanf("%d",&userId);
			printf("\nEnter User Password:");
			scanf("%s",userPassword);
			int userBelonging;
			userBelonging=checkLogin(userId,userPassword);
			if (userBelonging==0){
				printf("\nCheck your Login Credentials again!");
			}
			else{
				printf("Login Success!");
			}

		}
		if (ch==2)
		{
			int userId;
			char userPassword[50];
			printf("\nEnter User ID:");
			scanf("%d",&userId);
			printf("\nEnter User Password:");
			scanf("%s",userPassword);
			int userBelonging=checkLogin(userId,userPassword);
			if (userBelonging==0){
				printf("\nCheck your Login Credentials again!");
			}
			else{
				printf("Login Success!");
			}
		}
		
	}
	printf("Exiting...!");
}
