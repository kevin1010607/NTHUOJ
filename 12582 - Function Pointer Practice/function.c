#include"function.h"

void job1(void* argument){
    Data *data = (Data*)argument;
    int left = data->lower;
    int right = data->upper;
    while(left < right){
        int tmp = data->arr[left];
        data->arr[left] = data->arr[right];
        data->arr[right] = tmp;
        left++, right--;
    }
}
void job2(void* argument){
    Data *data = (Data*)argument;
    for(int i = data->lower; i <= data->upper; i++)
        data->arr[i] = -(data->arr[i]);
}
void job3(void* argument){
    Data *data = (Data*)argument;
    for(int i = data->lower; i <= data->upper; i++)
        data->arr[i] = 2*(data->arr[i]);
}
void initTask(Task* task, void(*func)(void*),void* argument){
    task->argument = argument;
    task->func = func;
}
void executeTasks(Task_List *task_list){
    for(int i = 0; i < task_list->size; i++)
        (task_list->tasks[i]->func)(task_list->tasks[i]->argument);
}