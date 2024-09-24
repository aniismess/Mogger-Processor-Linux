
#include "os1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "file_operations.h"

void init_os() {
    printf("\033[1;34mSimple OS initializing...\033[0m\n");
    print_welcome_message();
    load_processes();
}

void print_welcome_message() {
    printf("\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*             W E L C O M E            *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf(" *  ¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦   *\n");
    printf(" * ¦¦  ¦¦ ¦¦    ¦¦ ¦¦    ¦¦ ¦¦    ¦¦  *\n");
    printf(" * ¦¦      ¦¦    ¦¦ ¦¦    ¦¦ ¦¦    ¦¦  *\n");
    printf(" * ¦¦  ¦¦ ¦¦    ¦¦ ¦¦    ¦¦ ¦¦    ¦¦  *\n");
    printf(" *  ¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦   *\n");
    printf("*                                       *\n");
    printf("*              M O G G E R              *\n");
    printf("*                                       *\n");
    printf("*      Get Ready for an Exciting       *\n");
    printf("*               Adventure!              *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("\n");
}

void print_help() {
    printf("\033[1;34mAvailable commands:\033[0m\n");
    printf("  create <name> [priority]  - Create a new process with the given name and optional priority (default is 1).\n");
    printf("  list                       - List all processes.\n");
    printf("  start <id>                - Start the process with the given ID.\n");
    printf("  stop <id>                 - Stop the process with the given ID.\n");
    printf("  terminate <id>            - Terminate the process with the given ID.\n");
    printf("  update <id> <priority>    - Update the priority of the process with the given ID.\n");
    printf("  find <name>               - Find and display details of a process by name.\n");
    printf("  save                       - Save all processes to file (overwrites).\n");
    printf("  append                     - Append all processes to the file.\n");
    printf("  load                       - Load processes from file.\n");
    printf("  exit                       - Exit the program.\n");
}
