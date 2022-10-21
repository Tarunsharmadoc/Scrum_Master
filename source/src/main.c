#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <stdlib.h>
int main()
{
	FILE *feature_file=fopen("../external/features.csv","r");
    if (feature_file==NULL){
        printf("Feature File not found");
        exit(0);
    }
	else{
		char featureFileData[500];
		fgets(featureFileData,500,feature_file);
		char* data;
		feature *f1=(feature*) malloc(sizeof(feature));
		data=strtok(featureFileData,",");
		if ( data != NULL )
    	{
			f1->featureId=atoi(data);
    	}
		data=strtok(NULL,",");
		if ( data != NULL )
    	{
			f1->completionStatus=atoi(data);
    	}
		data=strtok(NULL,",");
		if ( data != NULL )
    	{
			strcpy(f1->featureName,data);
    	}
		data=strtok(NULL,",");
		if ( data != NULL )
    	{
			strcpy(f1->featureDesc,data);
    	}
		printf("%d",f1->featureId);
		printf("%d",f1->completionStatus);
		printf("%s",f1->featureName);
		printf("%s",f1->featureDesc);
	}
	fclose(feature_file);
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
