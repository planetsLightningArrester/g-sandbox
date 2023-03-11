#ifndef SUM_H
#define SUM_H

#include <iostream>
#include <stdlib.h>
#include <cstdio>

/** Called when missing arguments happened */
class MissingArgument : public std::exception {
  private:
    /* The error message */
    char* message;

  public:
    MissingArgument(char* msg) : message(msg) {}
    char * what ();
};

/** Called when one of the arguments isn't a number */
class ArgumentIsNotANumber : public std::exception {
  private:
    /* The error message */
    char* message;

  public:
    ArgumentIsNotANumber(char* msg) : message(msg) {}
    char * what ();
};

/**
 * Check if a given string is a number
 * @param number the incoming string
 * @return `true` if the incoming string is a valid number,
 * and `false` otherwise
*/
bool isNumber(char *number);

/**
 * Sum two or more numbers formatted as string
*/
double sum (int argc, char const *argv[]);

#endif