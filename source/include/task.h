#define TASK_NAME_LEN 100
#define TASK_DESC_LEN 100

typedef struct _task_
{
    int taskId;     /* primary key */
    int storyId;    /* foreign key */ 
    int completionStatus;  /* 0 initialized maximum 100 */

    char taskName[TASK_NAME_LEN];
    char taskDesc[TASK_DESC_LEN];

    struct _task_ *next;
} task;