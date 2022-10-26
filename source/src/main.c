#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <stdlib.h>
#define STORY_NAME_LEN 100
#define STORY_DESC_LEN 300
#define TASK_NAME_LEN 100
#define TASK_DESC_LEN 200
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
	feature *f1=(feature*) malloc(sizeof(feature));
	createUserStoryLL();
	createTaskLLFromCSV();
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
					printf("\n1. To Print all Features, User Stories and Tasks:");
					printf("\n2. To Add New User Story:");
					printf("\n3. To Add New Task:\n");
					scanf("%d",&tlChoice1);
					if (tlChoice1==1){
						printFeatures(f1);
						printf("\n");
						displayUserStoryLL();
						printf("\n");
						displayTaskLL();
						
					}
					else if(tlChoice1==2){
						int storyId,featureId,completionStatus;
						char storyName[STORY_NAME_LEN];
						char storyDesc[STORY_DESC_LEN];
						printf("\nEnter User Story Details:");
						printf("\nEnter Story ID:");
						scanf("%d",&storyId);
						printf("\nEnter Feature ID:");
						scanf("%d",&featureId);
						printf("\nEnter Completion Status:");
						scanf("%d",&completionStatus);
						printf("\nEnter Story Name:");
						scanf("%s",storyName);
						printf("\nEnter Story Desc:");
						scanf("%s",storyDesc);
						insert_end(storyId,featureId,completionStatus,storyName,storyDesc);
						appendUserStoryCSV(storyId,featureId,completionStatus,storyName,storyDesc);
						displayUserStoryLL();
					}
					else if(tlChoice1==3){
						int taskId,storyId,completionStatusTask,userId;
						char taskName[TASK_NAME_LEN];
						char taskDesc[TASK_DESC_LEN];
						printf("\nEnter Task Details:");
						printf("\nEnter Task ID:");
						scanf("%d",&taskId);
						printf("\nEnter Story ID:");
						scanf("%d",&storyId);
						printf("\nEnter Completion Status:");
						scanf("%d",&completionStatusTask);
						printf("\nEnter User ID:");
						scanf("%d",&userId);
						printf("\nEnter Story Name:");
						scanf("%s",taskName);
						printf("\nEnter Story Desc:");
						scanf("%s",taskDesc);
						appendTaskLL(taskId,storyId,completionStatusTask,userId,taskName,taskDesc);
						appendTasksCSV(taskId,storyId,completionStatusTask,userId,taskName,taskDesc);
						displayTaskLL();
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
				printf("\nLogged in as team Member!\n");
				int tlchoice2=1;
				while(tlchoice2!=0){
					printf("\n1. To print My Assigned Tasks:");
					printf("\n2. To Update Task:\n");
					scanf("%d",&tlchoice2);
					if (tlchoice2==1){
						displayUserTasks(userId);
					}
					else{
						int taskId,completionStatus;
						printf("\n Enter Task ID to Update:");
						scanf("%d",&taskId);
						printf("\n Enter New Completion Status:");
						scanf("%d",&completionStatus);
						updateCompletionStatus(taskId,completionStatus);
						continue;
					}
				}
				exit(0);
			}
			else{
				printf("\nYou cannot login as Team Lead from here!");
				exit(0);
			}
		}
		
	}
	printf("\nExiting...!");
}
