#include "sum.h"

/** Called when missing arguments happened */
char* MissingArgument::what() {
  return message;
}

/** Called when one of the arguments isn't a number */
char* ArgumentIsNotANumber::what() {
  return message;
}

/**
 * Check if a given string is a number
 * @param number the incoming string
 * @return `true` if the incoming string is a valid number,
 * and `false` otherwise
*/
bool isNumber(char *number) {  
  bool decimalDelimiterFound = false;
  for (int i = 0; number[i] != '\0'; i++) {
    switch (number[i]) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        break;
      case '-':
        if (i != 0) return false;
        break;
      case '.':
        if (decimalDelimiterFound) return false;
        else if (i == 0) return false;
        else if (number[i + 1] == '\0') return false;
        decimalDelimiterFound = true;
        break;
      default:
        return false;
    }
  }
  return true;
}

/**
 * Sum two or more numbers formatted as string
 * @param argc the number of elements to be summed up
 * @param argv the elements to be summed up
 * @returns the sum of all elements inside argv
*/
double sum (int argc, char const *argv[]) {
  
  // Check if enough arguments were passed
  if (argc < 2) throw MissingArgument((char*)"At least one number should be passed as argument");
  
  /* The resulting double */
  double result = 0;

  // Iterate over the elements
  for (int i = 1; i < argc; i++) {

    // If the element is a number
    if (isNumber((char*) argv[i])) result += atof(argv[i]);
    // If the element isn't a number, throw na error
    else {
      
      /* The error message placeholder */
      char messagePlaceholder[] = "The argument %i: '%s' is not a valid number";
      /* The error message placeholder string length */
      int messagePlaceholderLength;
      /* The argument string length */
      int argumentLength;
      /* The i counter as string */
      auto s = std::to_string(i);
      /* The i counter as string length */
      int counterSize;

      // Get the size of the string to be displayed
      for (counterSize = 0; s[counterSize] != '\0'; counterSize++);
      for (argumentLength = 0; argv[i][argumentLength] != '\0'; argumentLength++);
      for (messagePlaceholderLength = 0; messagePlaceholder[messagePlaceholderLength] != '\0'; messagePlaceholderLength++);

      // The error message to be displayed with allocated memory
      char *message = (char*) malloc((messagePlaceholderLength + argumentLength + counterSize) * sizeof(*message));
      sprintf(message, messagePlaceholder, i, argv[i]);

      throw ArgumentIsNotANumber(message);
    }
  }

  return result;

}
