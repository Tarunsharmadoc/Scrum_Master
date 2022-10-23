#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <userStory.h>
#include <task.h>
#define LINE_SIZE 500
// void create();
// void display();
// void insert_end();

struct node *head=NULL;

void create(int info,int info1,int info2,char name[],char desc[])
{
        userStory *temp,*ptr;
        temp=(userStory *)malloc(sizeof(userStory));
        temp->storyId=info;
        temp->featureId=info1;
        temp->completionStatus=info2;
        strcpy(temp->storyName,name);
        strcpy(temp->storyDesc,desc);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
}
void display()
{
        userStory *ptr;
        if(head==NULL)
        {
            printf("nList is empty:n");
            return;
        }
        else
        {
            ptr=head;
            printf("\n------------------------------User Stories----------------------------------------\n");
                printf("\n Story ID:\tFeature ID:\tCompletion Status:\tStory Name:\t\t\tStory Info\n");
            while(ptr!=NULL)
            {
                printf("\t%d\t\t",ptr->storyId);
                printf("%d\t\t",ptr->featureId);
                printf("%d\t",ptr->completionStatus);
                printf("\t%s",ptr->storyName);
                printf("\t\t%s\n",ptr->storyDesc);
                ptr=ptr->next ;
            }
            printf("\n-----------------------------END of User Stories----------------------------------\n");
        }
}
void insert_end(int a,int b,int c,char name[],char desc[])
{
        userStory *temp,*ptr;
        temp=(userStory *)malloc(sizeof(userStory));
        if(temp==NULL)
        {
            printf("nOut of Memory Space:n");
            return;
        }
        
        temp->storyId=a;
        temp->featureId=b;
        temp->completionStatus=c;
        strcpy(temp->storyName,name);
        strcpy(temp->storyDesc,desc);
        temp->next =NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next !=NULL)
            {
            ptr=ptr->next ;
            }
            ptr->next =temp;
        }
}
void createUserStoryLL(){
    FILE *userStoryFile=fopen("../external/userStories.csv","r");
    if (userStoryFile==NULL){
        printf("User Story File not found");
        exit(0);
    }
    else{
		char userStoryFileData[LINE_SIZE];
        char *data;
		while(1){
            if (fgets(userStoryFileData, LINE_SIZE, userStoryFile) == NULL){
                break;
            }
            else{
                // userStory *newStory = (userStory*)malloc (sizeof(userStory));
                data=strtok(userStoryFileData,",");
                int a=atoi(data);
                data=strtok(NULL,",");
                int b=atoi(data);
                data=strtok(NULL,",");
                int c=atoi(data);
                char name[100];
                char desc[300];
                data=strtok(NULL,",");
                strcpy(name,data);
                data=strtok(NULL,",");
                strcpy(desc,data);
                // newStory->storyId=atoi(data);
                // data=strtok(NULL,",");
                // newStory->completionStatus=atoi(data);
                // data=strtok(NULL,",");
                // newStory->featureId=atoi(data);
                // data=strtok(NULL,",");
                // strcpy(newStory->storyName,data);
                // data=strtok(NULL,",");
                // strcpy(newStory->storyDesc,data);
                // newStory->next=NULL;
                insert_end(a,b,c,name,desc);
                
            }
        }
    }
    fclose(userStoryFile);
}