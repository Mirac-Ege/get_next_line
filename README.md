
*This project has been created as part of the 42 curriculum by mkotan.*

## Description
The **Get Next Line** project is a fundamental exercise in C programming that involves creating a function to read text from a file descriptor line by line. The primary goal is to learn and implement the concept of **static variables**, which allow the function to preserve data and the reading state across multiple successive calls. This ensures that even when a large buffer is read, no data is lost between function calls.

## Instructions
### Compilation
The function must be compiled with the `-Wall -Wextra -Werror` flags, along with a buffer size defined at compile time using the `-D BUFFER_SIZE=n` flag.

**Example compilation command:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
Note: The project is designed to work with various buffer sizes, including 1, 9999, or 10,000,000.

### Usage
Repeated calls to get_next_line(fd) in a loop allow reading a text file one line at a time.

The function returns the read line, including the \n character (except at the end of a file that does not end with a newline).

It returns NULL when there is nothing left to read or if an error occurs.

The function supports reading from hem regular files hem de standard input.

## Resources
Static Variables in C (GeeksforGeeks)

File Descriptors and read()

AI Usage Disclosure: AI was utilized specifically to create a comprehensive testing environment (tester.sh and stres_testi.c) to verify memory safety (leaks) and edge cases such as empty files or extreme BUFFER_SIZE values. The core algorithm and utility functions were developed manually to ensure deep understanding.

### Algorithm Explanation
The algorithm is designed to read data as efficiently as possible while maintaining the state between calls using a static variable.

Static Buffer Management: A static variable acts as a persistent "storage" that keeps any leftover data read from the previous call that wasn't part of the returned line.

Reading Loop: The function reads from the file descriptor in chunks of BUFFER_SIZE until a newline character (\n) is detected in the accumulated string or the end of the file is reached.

Line Extraction: Once a newline is found, the function extracts everything up to that newline to be returned to the user.

State Preservation: Any data remaining after the newline is saved back into the static variable, ensuring it is ready for the next call to get_next_line.

Memory Safety: All heap-allocated memory is carefully managed to prevent leaks, especially when errors occur or the end of the file is reached.
