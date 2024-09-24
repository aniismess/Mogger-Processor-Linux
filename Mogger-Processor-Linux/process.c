#include "process.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define PROCESS_FILE "/home/ani/Mogger-Processor/PROCESS_FILE.txt"

#define MAX_PROCESSES 10
Process processes[MAX_PROCESSES];
int process_count = 0;

void create_process(const char* name, int priority) {
    if (process_count < MAX_PROCESSES) {
        printf("\033[1;32mCreating process...\033[0m\n");
        Process new_process;
        new_process.id = process_count; 
        strcpy(new_process.name, name);
        new_process.status = 0;
        new_process.priority = priority;
        processes[process_count++] = new_process;
        printf("Process '%s' created with ID %d and priority %d\n", name, process_count - 1, priority);
    } else {
        printf("\033[1;31mError: Maximum number of processes reached.\033[0m\n");
    }
}

void list_processes() {
    int i;
    printf("\033[1;33mCurrent processes:\033[0m\n");
    for (i = 0; i < process_count; i++) {
        printf("ID: %d, Name: %s, Status: %s, Priority: %d\n",
               processes[i].id,
               processes[i].name,
               processes[i].status ? "Running" : "Stopped",
               processes[i].priority);
    }
}

void start_process(int id) {
    if (id >= 0 && id < process_count) {
        processes[id].status = 1;
        printf("\033[1;32mStarting process '%s' (ID: %d)...\033[0m\n", processes[id].name, id);
        printf("Process '%s' (ID: %d) started.\n", processes[id].name, id);
    } else {
        printf("\033[1;31mError: Invalid process ID.\033[0m\n");
    }
}

void stop_process(int id) {
    if (id >= 0 && id < process_count) {
        processes[id].status = 0;
        printf("\033[1;32mStopping process '%s' (ID: %d)...\033[0m\n", processes[id].name, id);
        printf("Process '%s' (ID: %d) stopped.\n", processes[id].name, id);
    } else {
        printf("\033[1;31mError: Invalid process ID.\033[0m\n");
    }
}

void terminate_process(int id) {
    int i;
    if (id >= 0 && id < process_count) {
        printf("\033[1;32mTerminating process '%s' (ID: %d)...\033[0m\n", processes[id].name, id);
        for (i = id; i < process_count - 1; i++) {
            processes[i] = processes[i + 1];
        }
        process_count--;
        printf("Process '%s' (ID: %d) terminated.\n", processes[id].name, id);
    } else {
        printf("\033[1;31mError: Invalid process ID.\033[0m\n");
    }
}

void update_process_priority(int id, int priority) {
    if (id >= 0 && id < process_count) {
        processes[id].priority = priority;
        printf("Updated priority of process '%s' (ID: %d) to %d.\n", processes[id].name, id, priority);
    } else {
        printf("\033[1;31mError: Invalid process ID.\033[0m\n");
    }
}

void find_process_by_name(const char* name) {
    int i;
    int found = 0;
    for (i = 0; i < process_count; i++) {
        if (strcmp(processes[i].name, name) == 0) {
            printf("Found process: ID: %d, Name: %s, Status: %s, Priority: %d\n",
                   processes[i].id, processes[i].name,
                   processes[i].status ? "Running" : "Stopped",
                   processes[i].priority);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\033[1;31mNo process found with name '%s'.\033[0m\n", name);
    }
}
void save_processes(int append) {
    int i;
    FILE *file = fopen(PROCESS_FILE, append ? "a" : "w");
    if (!file) {
        printf("\033[1;31mError: Unable to open file for writing.\033[0m\n");
        return;
    }
    for (i = 0; i < process_count; i++) {
        fprintf(file, "%d %s %d %d\n", processes[i].id, processes[i].name, processes[i].status, processes[i].priority);
    }
    fclose(file);
    printf("Processes %s to '%s'.\n", append ? "appended" : "saved", PROCESS_FILE);
}

void load_processes() {
    printf("\033[1;33mLoading processes...\033[0m\n");
    usleep(500000); 
    FILE *file = fopen(PROCESS_FILE, "r");
    if (!file) {
        printf("No process file found. Starting with an empty process list.\n");
        return;
    }
    while (fscanf(file, "%d %49s %d %d", &processes[process_count].id, processes[process_count].name, &processes[process_count].status, &processes[process_count].priority) == 4) {
        process_count++;
        if (process_count >= MAX_PROCESSES) {
            break; 
        }
    
    }
}