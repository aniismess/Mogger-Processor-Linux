#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int id;
    char name[50];
    int status;
    int priority;
} Process;

void create_process(const char* name, int priority);
void list_processes();
void start_process(int id);
void stop_process(int id);
void terminate_process(int id);
void update_process_priority(int id, int priority);
void find_process_by_name(const char* name);
void save_processes(int append);
void load_processes();

#endif
