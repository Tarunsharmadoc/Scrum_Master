#define FEATURE_NAME_LEN 100

typedef struct _feature_
{
    int featureId;           /* primary key */
    int completionStatus;    /* 0 initialized maximum 100 */ 

    char featureName[FEATURE_NAME_LEN];
} feature;

