#include "get_next_line.h"

// Function to read from the file descriptor and update the buffer
char *read_file(int fd, char *buffer) {
    char temp_buffer[BUFFER_SIZE + 1]; // Temporary buffer for reading
    int bytes_read;

    bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
    if (bytes_read <= 0) {
        return NULL; // Return NULL if no bytes were read or an error occurred
    }
    temp_buffer[bytes_read] = '\0'; // Null-terminate the temporary buffer
    buffer = ft_strjoin(buffer, temp_buffer); // Concatenate the buffer with the new data
    return buffer; // Return the updated buffer
}

// Function to extract the next line from the buffer
char *extract_line(char **buffer) {
    char *line;
    int i = 0;

    // Find the position of the newline character
    while ((*buffer)[i] && (*buffer)[i] != '\n') {
        i++;
    }

    // If no characters were found, return NULL
    if (i == 0 && !(*buffer)[i]) {
        free(*buffer);
        return NULL;
    }

    // Allocate memory for the line including the newline if present
    line = ft_calloc(i + 2, sizeof(char)); // +2 for newline and null terminator
    if (!line) {
        return NULL; // Check for allocation failure
    }

    // Copy characters from buffer to line
    for (int j = 0; j < i; j++) {
        line[j] = (*buffer)[j];
    }
    if ((*buffer)[i] == '\n') {
        line[i++] = '\n'; // Add newline if present
    }
    line[i] = '\0'; // Null-terminate the line

    // Update the buffer to remove the extracted line
    char *new_buffer = ft_strchr(*buffer, '\n');
    if (new_buffer) {
        new_buffer++; // Move past the newline character
        char *temp = *buffer; // Store the old buffer
        *buffer = ft_strjoin("", new_buffer); // Update buffer with the remaining data
        free(temp); // Free the old buffer
    } else {
        free(*buffer); // Free the buffer if no newline was found
        *buffer = NULL; // Set buffer to NULL
    }

    return line; // Return the extracted line
}

// Main function to get the next line
char *get_next_line(int fd) {
    static char *buffer = NULL; // Static buffer to hold data between calls

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL; // Check for valid file descriptor and buffer size
    }

    // Read data from the file into the buffer
    buffer = read_file(fd, buffer);
    if (!buffer) {
        return NULL; // Return NULL if reading fails
    }

    // Extract the next line from the buffer
    return extract_line(&buffer);
}

