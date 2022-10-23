#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <stdlib.h>

void printFeatures(feature *f){
	printf("\n----------------------------------Feature Details----------------------------------------------\n");
	printf("\nFeature ID:\tCompletion Status:\tFeature Name:\tFeature Info:");
	printf("\n\t%d",f->featureId);
	printf("\t\t%d",f->completionStatus);
	printf("\t\t%s",f->featureName);
	printf("\t%s\n",f->featureDesc);
	printf("\n--------------------------------END of Feature Details-------------------------------------\n");

}
int main()
{
	createUserStoryLL();
	feature *f1=(feature*) malloc(sizeof(feature));
	FILE *feature_file=fopen("../external/features.csv","r");
    if (feature_file==NULL){
        printf("Feature File not found");
        exit(0);
    }
	else{
		char featureFileData[500];
		fgets(featureFileData,500,feature_file);
		char* data;
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
			if (userBelonging==-1){
				printf("\nEither userid or password is incorrect!");
				exit(0);
			}
			else if(userBelonging==1){
				printf("\nLogged in as team Lead!\n");
				int tlChoice1=1;
				while(tlChoice1!=0){
					printf("1. To Print all Features, User Stories and Tasks:");
					printf("\n2. To Add New User Story:");
					printf("\n3. To Add New Task:\n");
					scanf("%d",&tlChoice1);
					if (tlChoice1==1){
						printFeatures(f1);
						printf("\n");
						display();
						
					}
					else if(tlChoice1==2){
						
					}
				}
				exit(0);
			}
			else{
				printf("\nYou cannot login as Team Lead from here!");
				exit(0);
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
			int userBelonging;
			userBelonging=checkLogin(userId,userPassword);
			if (userBelonging==-1){
				printf("\nEither userid or password is incorrect!");
				exit(0);
			}
			else if(userBelonging==0){
				printf("\nLogged in as team Member!");
				continue;
			}
			else{
				printf("\nYou cannot login as Team Lead from here!");
				exit(0);
			}
		}
		
	}
	printf("\nExiting...!");
}
