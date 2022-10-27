#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <stdlib.h>
feature *f1=NULL;
void printFeatures(){
	printf("\n----------------------------------Feature Details----------------------------------------------\n");
	printf("\nFeature ID:\tCompletion Status:\tFeature Name:\tFeature Info:");
	printf("\n\t%d",f1->featureId);
	printf("\t\t%d",f1->completionStatus);
	printf("\t\t%s",f1->featureName);
	printf("\t%s\n",f1->featureDesc);
	printf("\n--------------------------------END of Feature Details-------------------------------------\n");

}

void loadFeature(){
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
}