#include "command_interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "file_operations.h"
#include "os1.h"

void command_interpreter() {
    char command[100];
    while (1) {
        printf("SimpleOS> ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0;
        char *token = strtok(command, " ");
        if (token == NULL) continue;
        if (strcasecmp(token, "exit") == 0) {
            save_processes(0);
            printf("Exiting...\n");
            break;
        } else if (strcasecmp(token, "create") == 0) {
            token = strtok(NULL, " ");
            if (token) {
                int priority = 1;
                char *priority_str = strtok(NULL, " ");
                if (priority_str) {
                    priority = atoi(priority_str);
                    if (priority < 1 || priority > 10) {
                        printf("\033[1;31mError: Invalid priority.\033[0m\n");
                        continue;
                    }
                }
                create_process(token, priority);
            }
        } else if (strcasecmp(token, "list") == 0) {
            list_processes();
        } else if (strcasecmp(token, "start") == 0) {
            token = strtok(NULL, " ");
            if (token) start_process(atoi(token));
        } else if (strcasecmp(token, "stop") == 0) {
            token = strtok(NULL, " ");
            if (token) stop_process(atoi(token));
        } else if (strcasecmp(token, "terminate") == 0) {
            token = strtok(NULL, " ");
            if (token) terminate_process(atoi(token));
        } else if (strcasecmp(token, "update") == 0) {
            int id, priority;
            token = strtok(NULL, " ");
            if (token) id = atoi(token);
            token = strtok(NULL, " ");
            if (token) priority = atoi(token);
            update_process_priority(id, priority);
        } else if (strcasecmp(token, "find") == 0) {
            token = strtok(NULL, " ");
            if (token) find_process_by_name(token);
        } else if (strcasecmp(token, "save") == 0) {
            save_processes(0);
        } else if (strcasecmp(token, "append") == 0) {
            save_processes(1);
        } else if (strcasecmp(token, "load") == 0) {
            load_processes();
        } else if (strcasecmp(token, "help") == 0) {
            print_help();
        } else {
            printf("\033[1;31mUnknown command. Type 'help' for a list of commands.\033[0m\n");
        }
    }
}
