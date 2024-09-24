# Mogger Processor

Mogger Processor is a system designed for Linux that allows users to create, list, manage, and retrieve information about processes. This project aims to provide an efficient and user-friendly interface for process management.

## Features

- **Create Processes**: Easily create new processes with specified names and priorities.
- **List Processes**: View all currently running or stopped processes along with their details.
- **Manage Processes**: Start, stop, or terminate processes as needed.
- **Update Process Priority**: Change the priority of existing processes.
- **Find Processes**: Search for processes by name.
- **Persistent Storage**: Load and save processes to a file.

## Getting Started

### Prerequisites

Make sure you have the following installed on your Linux machine:

- GCC (GNU Compiler Collection)
- Make (optional for easier builds)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/aniismess/Mogger-Processor-Linux.git
   cd Mogger-Processor-Linux
   ```

2. Compile the project:

   ```bash
   gcc main.c process.c file_operation.c os1.c command_interpreter.c -o mogger_processor
   ```

### Usage

To run the Mogger Processor, execute the following command in your terminal:

```bash
./mogger_processor
```

### Functionality

- **Creating a Process**: You can create a process by entering its name and priority when prompted.
- **Listing Processes**: Use the provided commands to list all active processes.
- **Managing Processes**: Start, stop, or terminate processes using their IDs.

## Contributing

If you would like to contribute to this project, please feel free to fork the repository and submit a pull request.

## Contact

For any inquiries, please contact me at [animesh.mishra818@gmail.com](mailto:animesh.mishra818@gmail.com).
