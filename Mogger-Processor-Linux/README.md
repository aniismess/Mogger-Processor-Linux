# Mogger Processor v2.0

## Overview
Mogger Processor v2.0 is a lightweight, user-friendly operating system tailored for efficient process management and file handling. With its intuitive command-line interface, it is designed to cater to both novice users and experienced developers.

## Features
- **Process Management**: Effortlessly create, list, start, and stop processes.
- **File Handling**: Create and list files while effectively managing their sizes.
- **System Information**: Display current system statistics, including memory usage and active process counts.
- **Colored Output**: Enjoy a visually engaging terminal experience with colored text.
- **Customizable Commands**: Extend functionality with user-friendly commands.

## Installation
1. Download the source code.
2. Compile the code using a C compiler (e.g., `gcc`):
   ```bash
   gcc -o MoggerProcessor os.c -std=c99
   ```
3. Run the executable:
   ```bash
   ./MoggerProcessor
   ```

## Commands
Here’s a list of available commands:
- `create [name] [priority] [memory]`: Create a new process.
- `list`: List all current processes.
- `start [id]`: Start a specified process by ID.
- `stop [id]`: Stop a specified process by ID.
- `createfile [name] [size]`: Create a new file.
- `listfiles`: List all created files.
- `sysinfo`: Display system information.
- `exit`: Exit the OS.

## Contribution
Contributions are welcome! If you would like to suggest features, report bugs, or enhance documentation, please submit a pull request or open an issue on the project repository.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## Acknowledgments
- Inspired by traditional operating systems and user feedback.
- Special thanks to the open-source community for their ongoing support and resources.

## Contact
For more information, please contact:
- Email: mradulnatani0@gmail.com
- GitHub: mradulnatani
