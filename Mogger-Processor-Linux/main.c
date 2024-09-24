#include <stdio.h>
#include <stdlib.h>
#include "os1.h"
#include "command_interpreter.h"

int main() {
    init_os();
    command_interpreter();
    printf("Mogger shutting down.\n");
    return 0;
}
