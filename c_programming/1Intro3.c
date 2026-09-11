//"argument count" and "argument vector"
//The main() function takes two parameters: argc, an integer representing the number of command-line arguments, and argv, an array of strings containing the command-line arguments. 

#include <stdio.h>

int main(int argc, char *argv[]) 
{
    printf(“Computer Science!\n");
    return 0;
}

#include <stdio.h>

int main(int argc, char **argv) 
{
    printf(" Computer Science!\n");
    return 0;
}

