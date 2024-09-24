
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdbool.h>

// File operation functions
bool create_file(const char* filename);
bool delete_file(const char* filename);
bool rename_file(const char* old_filename, const char* new_filename);
bool copy_file(const char* source_filename, const char* destination_filename);
bool move_file(const char* source_filename, const char* destination_filename);

// Directory operation functions
bool create_directory(const char* dirname);
bool delete_directory(const char* dirname);
bool rename_directory(const char* old_dirname, const char* new_dirname);

// File/directory information functions
bool file_exists(const char* filename);
bool is_directory(const char* path);
long get_file_size(const char* filename);
char* get_file_permissions(const char* filename);

// File content operations
char* read_file_content(const char* filename);
bool write_file_content(const char* filename, const char* content);
bool append_file_content(const char* filename, const char* content);

#endif // FILE_OPERATIONS_H
