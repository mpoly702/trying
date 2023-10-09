#include <stdio.h>
#include <stdarg.h>

// Define a variadic function
// int sum(int num, ...) {
//     int total = 0;
//
//         va_list args;
//             va_start(args, num); // Initialize the argument list
//
//                 for (int i = 0; i < num; ++i) {
//                         int value = va_arg(args, int); // Get the next argument
//                                 total += value;
//                                     }
//
//                                         va_end(args); // Clean up the argument list
//
//                                             return total;
//                                             }
//
//                                             int main() {
//                                                 int result = sum(5, 1, 2, 3, 4, 5);
//                                                     printf("Sum: %d\n", result);
//
//                                                         return 0;
//                                                         }
//
