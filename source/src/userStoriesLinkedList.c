#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <stdlib.h>
#define LINE_SIZE 500

int appendUserStoryLinkedList(userStory **head,userStory *newStoryvar){
    userStory* iter=*head;
    if(*head==NULL){
        *head=newStoryvar;
    }
    else{
        while(iter->next!=NULL){
            iter=iter->next;
        }
        iter->next=newStoryvar;
        newStoryvar->next=NULL;
    }
    return EXIT_SUCCESS;
}
// void printUserStoryLinkedList(userStory *head){
//     if(head==NULL){
//         printf("Linked List is empty\n");
//     }
//     else{
//         printf("---------------------------------------------------------------------------------------\n");
//         while (head!=NULL)
//         {
//             printf("%d\t\n",head->storyId);
//             printf("%d\t\n",head->featureId);
//             printf("%d\t\n",head->completionStatus);
//             printf("%s\t\n",head->storyName);
//             printf("%s\t\n",head->storyDesc);
//             head=head->next;
//         }
//         printf("---------------------------------------------------------------------------------------\n");
//     }
// }

void createUserStoryLinkedList(userStory *head){
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
                userStory *newStory = (userStory*)malloc (sizeof(userStory));
                data=strtok(userStoryFileData,",");
                newStory->storyId=atoi(data);
                data=strtok(NULL,",");
                newStory->completionStatus=atoi(data);
                data=strtok(NULL,",");
                newStory->featureId=atoi(data);
                data=strtok(NULL,",");
                strcpy(newStory->storyName,data);
                data=strtok(NULL,",");
                strcpy(newStory->storyDesc,data);
                // newStory->next=NULL;
                appendUserStoryLinkedList(&head,newStory);
                
            }
        }
    }
	fclose(userStoryFile);
}