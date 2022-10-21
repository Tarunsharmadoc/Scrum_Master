#define STORY_NAME_LEN 100
#define STORY_DESC_LEN 100

typedef struct _userStory_
{
    int storyId;     /* primary key */
    int featureId;   /* foreign key */
    int sprintId;
    int completionStatus;

    char storyName[STORY_NAME_LEN];
    char storyDesc[STORY_DESC_LEN];

    struct _story_ *next;

} userStory;
