    #ifndef FILE_OPERATIONS_H
    #define FILE_OPERATIONS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>

    #define MAX_FILENAME_LENGTH 256
    #define MAX_BUFFER_SIZE 1024

    // Function prototypes
    int create_file(const char *filename);
    int delete_file(const char *filename);
    int rename_file(const char *old_filename, const char *new_filename);
    int copy_file(const char *source_filename, const char *destination_filename);
    int move_file(const char *source_filename, const char *destination_filename);
    int read_file(const char *filename);
    int write_file(const char *filename, const char *content);
    int append_to_file(const char *filename, const char *content);
    int get_file_size(const char *filename);
    int list_directory_contents(const char *directory_path);

    #endif // FILE_OPERATIONS_H

    // Function implementations

    int create_file(const char *filename) {
        int fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, 0644);
        if (fd == -1) {
            perror("Error creating file");
            return -1;
        }
        close(fd);
        printf("File '%s' created successfully.\n", filename);
        return 0;
    }

    int delete_file(const char *filename) {
        if (unlink(filename) == -1) {
            perror("Error deleting file");
            return -1;
        }
        printf("File '%s' deleted successfully.\n", filename);
        return 0;
    }

    int rename_file(const char *old_filename, const char *new_filename) {
        if (rename(old_filename, new_filename) == -1) {
            perror("Error renaming file");
            return -1;
        }
        printf("File renamed from '%s' to '%s' successfully.\n", old_filename, new_filename);
        return 0;
    }

    int copy_file(const char *source_filename, const char *destination_filename) {
        int source_fd, dest_fd;
        ssize_t bytes_read, bytes_written;
        char buffer[MAX_BUFFER_SIZE];

        source_fd = open(source_filename, O_RDONLY);
        if (source_fd == -1) {
            perror("Error opening source file");
            return -1;
        }

        dest_fd = open(destination_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dest_fd == -1) {
            perror("Error creating destination file");
            close(source_fd);
            return -1;
        }

        while ((bytes_read = read(source_fd, buffer, MAX_BUFFER_SIZE)) > 0) {
            bytes_written = write(dest_fd, buffer, bytes_read);
            if (bytes_written != bytes_read) {
                perror("Error writing to destination file");
                close(source_fd);
                close(dest_fd);
                return -1;
            }
        }

        if (bytes_read == -1) {
            perror("Error reading from source file");
            close(source_fd);
            close(dest_fd);
            return -1;
        }

        close(source_fd);
        close(dest_fd);
        printf("File '%s' copied to '%s' successfully.\n", source_filename, destination_filename);
        return 0;
    }

    int move_file(const char *source_filename, const char *destination_filename) {
        if (rename(source_filename, destination_filename) == -1) {
            perror("Error moving file");
            return -1;
        }
        printf("File moved from '%s' to '%s' successfully.\n", source_filename, destination_filename);
        return 0;
    }

    int read_file(const char *filename) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("Error opening file for reading");
            return -1;
        }

        char buffer[MAX_BUFFER_SIZE];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
        return 0;
    }

    int write_file(const char *filename, const char *content) {
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            perror("Error opening file for writing");
            return -1;
        }

        if (fputs(content, file) == EOF) {
            perror("Error writing to file");
            fclose(file);
            return -1;
        }

        fclose(file);
        printf("Content written to file '%s' successfully.\n", filename);
        return 0;
    }

    int append_to_file(const char *filename, const char *content) {
        FILE *file = fopen(filename, "a");
        if (file == NULL) {
            perror("Error opening file for appending");
            return -1;
        }

        if (fputs(content, file) == EOF) {
            perror("Error appending to file");
            fclose(file);
            return -1;
        }

        fclose(file);
        printf("Content appended to file '%s' successfully.\n", filename);
        return 0;
    }

    int get_file_size(const char *filename) {
        struct stat st;
        if (stat(filename, &st) == -1) {
            perror("Error getting file size");
            return -1;
        }
        printf("Size of file '%s': %ld bytes\n", filename, st.st_size);
        return st.st_size;
    }

    int list_directory_contents(const char *directory_path) {
        DIR *dir;
        struct dirent *entry;

        dir = opendir(directory_path);
        if (dir == NULL) {
            perror("Error opening directory");
            return -1;
        }

        printf("Contents of directory '%s':\n", directory_path);
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }

        closedir(dir);
        return 0;
    }
