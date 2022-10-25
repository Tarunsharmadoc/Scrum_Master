#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <userStory.h>
#include <task.h>
#define LINE_SIZE 500

task *taskHead=NULL;
void createTaskLL(int info,int info1,int info2,int info3,char name[],char desc[])
{
        task *temp,*ptr;
        temp=(task *)malloc(sizeof(task));
        temp->taskId=info;
        temp->storyId=info1;
        temp->completionStatus=info2;
        temp->userid=info3;
        strcpy(temp->taskName,name);
        strcpy(temp->taskDesc,desc);
        temp->next=NULL;
        if(taskHead==NULL)
        {
            taskHead=temp;
        }
        else
        {
            ptr=taskHead;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
}
void displayTaskLL()
{
        task *ptr;
        if(taskHead==NULL)
        {
            printf("nList is empty:n");
            return;
        }
        else
        {
            ptr=taskHead;
            printf("\n------------------------------Tasks----------------------------------------\n");
                printf("\n Task ID:\tStory ID:\tCompletion Status:\tUser ID: \tTask Name:\t\t\tTask Info\n");
            while(ptr!=NULL)
            {
                printf("\t%d\t\t",ptr->taskId);
                printf("%d\t\t",ptr->storyId);
                printf("%d\t",ptr->completionStatus);
                printf("\t%d\t",ptr->userid);
                printf("\t%s",ptr->taskName);
                printf("\t\t%s\n",ptr->taskDesc);
                ptr=ptr->next ;
            }
            printf("\n-----------------------------END of Tasks----------------------------------\n");
        }
}
void appendTaskLL(int a,int b,int c,int d,char name[],char desc[])
{
    task *temp,*ptr;
    temp=(task *)malloc(sizeof(task));
    if(temp==NULL)
    {
        printf("nOut of Memory Space:n");
        return;
    }
        
    temp->taskId=a;
    temp->storyId=b;
    temp->completionStatus=c;
    temp->userid=d;
    strcpy(temp->taskName,name);
    strcpy(temp->taskDesc,desc);
    temp->next =NULL;
    if(taskHead==NULL)
    {
        taskHead=temp;
    }
    else
    {
        ptr=taskHead;
        while(ptr->next !=NULL)
        {
            ptr=ptr->next ;
        }
        ptr->next =temp;
    }
    
}
void createTaskLLFromCSV(){
    FILE *taskFile=fopen("../external/tasks.csv","r");
    if (taskFile==NULL){
        printf("User Story File not found");
        exit(0);
    }
    else{
		char taskFileData[LINE_SIZE];
        char *data;
		while(1){
            if (fgets(taskFileData, LINE_SIZE, taskFile) == NULL){
                break;
            }
            else{
                data=strtok(taskFileData,",");
                int a=atoi(data);
                data=strtok(NULL,",");
                int b=atoi(data);
                data=strtok(NULL,",");
                int c=atoi(data);
                data=strtok(NULL,",");
                int d=atoi(data);
                char name[100];
                char desc[300];
                data=strtok(NULL,",");
                strcpy(name,data);
                data=strtok(NULL,",");
                strcpy(desc,data);
                appendTaskLL(a,b,c,d,name,desc);
                
            }
        }
    }
    fclose(taskFile);
}
void appendTasksCSV(int a,int b,int c,int d,char name[],char desc[]){
    FILE *taskFile=fopen("../external/tasks.csv","a");
    if (taskFile==NULL){
        printf("User Story File not found");
        exit(0);
    }
    else{
        fprintf(taskFile,"%c",'\n');
        fprintf(taskFile,"%d",a);
        fprintf(taskFile,"%c",',');
        fprintf(taskFile,"%d",b);
        fprintf(taskFile,"%c",',');
        fprintf(taskFile,"%d",c);
        fprintf(taskFile,"%c",',');
        fprintf(taskFile,"%d",d);
        fprintf(taskFile,"%c",',');
        fprintf(taskFile,"%s",name);
        fprintf(taskFile,"%c",',');
        fprintf(taskFile,"%s",desc);
    }   
    fclose(taskFile);
}

