kip to content
geeksforgeeks
DSA
Tutorials
ML & Data Science
Web Development
Practice


M

M

 My Profile	 Edit Profile
 My Courses	 Go Premium
 Transactions	 Logout
Home
Saved Videos
Courses
GBlog
Puzzles
What's New ?
 Change Language

Trending Now
Data Structures
Algorithms
Topic-wise Practice
Python
Machine Learning
Data Science
JavaScript
Java
Web Development
Bootstrap
C
C++
ReactJS
Competitive Programming
Aptitude
Puzzles
Projects

▲
Related Articles
Write an Interview Experience
Share Your Campus Experience
dup() and dup2() Linux system call
C program that does not suspend when Ctrl+Z is pressed
How to bind to port number less than 1024 with non root access?
Fork() – Practice questions
getppid() and getpid() in Linux
Input-output system calls in C | Create, Open, Close, Read, Write
C vs BASH Fork bomb
pipe() System call
Working with Magic numbers in Linux
Reverse a string in C/C++ using Client Server model
Fork() Bomb
Wait System Call in C
fork() and memory shared b/w processes created using it
Splint — A C program verifier
Non-blocking I/O with pipes in C
Accept system call
TCP Server-Client implementation in C
Zombie Processes and their Prevention
Maximum number of threads that can be created within a process in C
Write an Interview Experience
Share Your Campus Experience
dup() and dup2() Linux system call
C program that does not suspend when Ctrl+Z is pressed
How to bind to port number less than 1024 with non root access?
Fork() – Practice questions
getppid() and getpid() in Linux
Input-output system calls in C | Create, Open, Close, Read, Write
C vs BASH Fork bomb
pipe() System call
Working with Magic numbers in Linux
Reverse a string in C/C++ using Client Server model
Fork() Bomb
Wait System Call in C
fork() and memory shared b/w processes created using it
Splint — A C program verifier
Non-blocking I/O with pipes in C
Accept system call
TCP Server-Client implementation in C
Zombie Processes and their Prevention
Maximum number of threads that can be created within a process in C
Making your own Linux Shell in C
Read
Discuss(20+)
Courses
Practice
To know more about what a shell is, click here.

We all use the built in terminal window in Linux distributions like Ubuntu, Fedora, etc. But how do they actually work? In this article, We are going to handle some under the hood features and algorithms what actually work inside a shell. All Linux operating systems have a terminal window to write in commands. But how are they executed properly after they are entered?
Also, how are extra features like keeping the history of commands and showing help handled? All of this can be understood by creating your own shell.



The Basics

After a command is entered, the following things are done:


Command is entered and if length is non-null, keep it in history.
Parsing : Parsing is the breaking up of commands into individual words and strings
Checking for special characters like pipes, etc is done
Checking if built-in commands are asked for.
If pipes are present, handling pipes.
Executing system commands and libraries by forking a child and calling execvp.
Printing current directory name and asking for next input.
For keeping history of commands, recovering history using arrow keys and handling autocomplete using the tab key, we will be using the readline library provided by GNU.

Implementation

To install the readline library, open the terminal window and write

sudo apt-get install libreadline-dev
It will ask for your password. Enter it. Press y in the next step.

Printing the directory can be done using getcwd.
Getting user name can be done by getenv(“USER”)
Parsing can be done by using strsep(“”). It will separate words based on spaces. Always skip words with zero length to avoid storing of extra spaces.
After parsing, check the list of built-in commands, and if present, execute it. If not, execute it as a system command. To check for built-in commands, store the commands in an array of character pointers, and compare all with strcmp().
Note: “cd” does not work natively using execvp, so it is a built-in command, executed with chdir().
For executing a system command, a new child will be created and then by using the execvp, execute the command, and wait until it is finished.
Detecting pipes can also be done by using strsep(“|”).To handle pipes, first separate the first part of the command from the second part. Then after parsing each part, call both parts in two separate new children, using execvp. Piping means passing the output of first command as the input of second command.
Declare an integer array of size 2 for storing file descriptors. File descriptor 0 is for reading and 1 is for writing.
Open a pipe using the pipe() function.
Create two children.
In child 1->
Here the output has to be taken into the pipe.
Copy file descriptor 1 to stdout.
Close  file descriptor 0.
Execute the first command using execvp()
In child 2->
Here the input has to be taken from the pipe.
Copy file descriptor 0 to stdin.
Close file descriptor 1.
Execute the second command using execvp()
Wait for the two children to finish in the parent.

// C Program to design a shell in Linux
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
  
#define MAXCOM 1000 // max number of letters to be supported
#define MAXLIST 100 // max number of commands to be supported
  
// Clearing the shell using escape sequences
#define clear() printf("\033[H\033[J")
  
// Greeting shell during startup
void init_shell()
{
    clear();
    printf("\n\n\n\n******************"
        "************************");
    printf("\n\n\n\t****MY SHELL****");
    printf("\n\n\t-USE AT YOUR OWN RISK-");
    printf("\n\n\n\n*******************"
        "***********************");
    char* username = getenv("USER");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n");
    sleep(1);
    clear();
}
  
// Function to take input
int takeInput(char* str)
{
    char* buf;
  
    buf = readline("\n>>> ");
    if (strlen(buf) != 0) {
        add_history(buf);
        strcpy(str, buf);
        return 0;
    } else {
        return 1;
    }
}
  
// Function to print Current Directory.
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nDir: %s", cwd);
}
  
// Function where the system command is executed
void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL); 
        return;
    }
}
  
// Function where the piped system commands is executed
void execArgsPiped(char** parsed, char** parsedpipe)
{
    // 0 is read end, 1 is write end
    int pipefd[2]; 
    pid_t p1, p2;
  
    if (pipe(pipefd) < 0) {
        printf("\nPipe could not be initialized");
        return;
    }
    p1 = fork();
    if (p1 < 0) {
        printf("\nCould not fork");
        return;
    }
  
    if (p1 == 0) {
        // Child 1 executing..
        // It only needs to write at the write end
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
  
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command 1..");
            exit(0);
        }
    } else {
        // Parent executing
        p2 = fork();
  
        if (p2 < 0) {
            printf("\nCould not fork");
            return;
        }
  
        // Child 2 executing..
        // It only needs to read at the read end
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
                printf("\nCould not execute command 2..");
                exit(0);
            }
        } else {
            // parent executing, waiting for two children
            wait(NULL);
            wait(NULL);
        }
    }
}
  
// Help command builtin
void openHelp()
{
    puts("\n***WELCOME TO MY SHELL HELP***"
        "\nCopyright @ Suprotik Dey"
        "\n-Use the shell at your own risk..."
        "\nList of Commands supported:"
        "\n>cd"
        "\n>ls"
        "\n>exit"
        "\n>all other general commands available in UNIX shell"
        "\n>pipe handling"
        "\n>improper space handling");
  
    return;
}
  
// Function to execute builtin commands
int ownCmdHandler(char** parsed)
{
    int NoOfOwnCmds = 4, i, switchOwnArg = 0;
    char* ListOfOwnCmds[NoOfOwnCmds];
    char* username;
  
    ListOfOwnCmds[0] = "exit";
    ListOfOwnCmds[1] = "cd";
    ListOfOwnCmds[2] = "help";
    ListOfOwnCmds[3] = "hello";
  
    for (i = 0; i < NoOfOwnCmds; i++) {
        if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
            switchOwnArg = i + 1;
            break;
        }
    }
  
    switch (switchOwnArg) {
    case 1:
        printf("\nGoodbye\n");
        exit(0);
    case 2:
        chdir(parsed[1]);
        return 1;
    case 3:
        openHelp();
        return 1;
    case 4:
        username = getenv("USER");
        printf("\nHello %s.\nMind that this is "
            "not a place to play around."
            "\nUse help to know more..\n",
            username);
        return 1;
    default:
        break;
    }
  
    return 0;
}
  
// function for finding pipe
int parsePipe(char* str, char** strpiped)
{
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL)
            break;
    }
  
    if (strpiped[1] == NULL)
        return 0; // returns zero if no pipe is found.
    else {
        return 1;
    }
}
  
// function for parsing command words
void parseSpace(char* str, char** parsed)
{
    int i;
  
    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");
  
        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}
  
int processString(char* str, char** parsed, char** parsedpipe)
{
  
    char* strpiped[2];
    int piped = 0;
  
    piped = parsePipe(str, strpiped);
  
    if (piped) {
        parseSpace(strpiped[0], parsed);
        parseSpace(strpiped[1], parsedpipe);
  
    } else {
  
        parseSpace(str, parsed);
    }
  
    if (ownCmdHandler(parsed))
        return 0;
    else
        return 1 + piped;
}
  
int main()
{
    char inputString[MAXCOM], *parsedArgs[MAXLIST];
    char* parsedArgsPiped[MAXLIST];
    int execFlag = 0;
    init_shell();
  
    while (1) {
        // print shell line
        printDir();
        // take input
        if (takeInput(inputString))
            continue;
        // process
        execFlag = processString(inputString,
        parsedArgs, parsedArgsPiped);
        // execflag returns zero if there is no command
        // or it is a builtin command,
        // 1 if it is a simple command
        // 2 if it is including a pipe.
  
        // execute
        if (execFlag == 1)
            execArgs(parsedArgs);
  
        if (execFlag == 2)
            execArgsPiped(parsedArgs, parsedArgsPiped);
    }
    return 0;
}
To Run the code –

 gcc shell.c -lreadline
./a.out 
Output:



This article is contributed by Suprotik Dey. If you like GeeksforGeeks and would like to contribute, you can also write an article using contribute.geeksforgeeks.org or mail your article to contribute@geeksforgeeks.org. See your article appearing on the GeeksforGeeks main page and help other Geeks.

Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.


Last Updated : 07 Jun, 2020

62

Similar Reads
Similar read thumbnail
Shell Script to Show the Difference Between echo “$SHELL” and echo ‘$SHELL’
Similar read thumbnail
Shell Scripting - Difference between Korn Shell and Bash shell
Similar read thumbnail
Introduction to Linux Shell and Shell Scripting
Similar read thumbnail
Auto Logout in Linux Shell Using TMOUT Shell Variable
Similar read thumbnail
How to protect Linux shell file using noclobber in bash shell?
Similar read thumbnail
How to Build Your Own Commands in Linux?
Similar read thumbnail
How to Code Your Own Port Scanner Using BASH Script and netcat Tool in Linux?
Similar read thumbnail
Shell Scripting - Decision Making
Similar read thumbnail
Shell Scripting - Restricted Shell
Similar read thumbnail
Shell Script to Demonstrate the Use of Shell Function Library
Previous
Segmentation Fault in C/C++
Next
Rounding Floating Point Number To two Decimal Places in C and C++
Article Contributed By :
https://media.geeksforgeeks.org/auth/avatar.png
GeeksforGeeks
Vote for difficulty
Current difficulty : Medium
Easy
Normal
Medium
Hard
Expert
Improved By :
top_gunn
Article Tags :
system-programming
C Language
Linux-Unix
Improve Article
Report Issue

Join our Community
Recently Published
article-card
AVG Antivirus: Your Ultimate Defense Against Viruses and Malware
Read
article-card
Top 10 Django Projects For Beginners With Source Code
Read
article-card
Why to Choose Java For Backend Development?
Read
article-card
7 Best Java Courses and Certifications in 2023
Read
article-card
Chinese Company Tencent is About to Launch ChatGPT-Like AI Chatbot
Read
article-card
Best Way to Master Java Spring Boot Microservices – A Complete Roadmap
Read
article-card
Top Engineering Colleges in Bangalore 2023
Read
article-card
Best Internet Security Suites to Protect your Devices
Read
article-card
Top 10 Heroku Alternatives That You Can Try
Read



geeksforgeeks-footer-logo
A-143, 9th Floor, Sovereign Corporate Tower, Sector-136, Noida, Uttar Pradesh - 201305
feedback@geeksforgeeks.org
GFG App on Play Store
GFG App on App Store
Company
About Us
Legal
Careers
In Media
Contact Us
Advertise with us
Campus Training Program
Explore
Job-A-Thon Hiring Challenge
Hack-A-Thon
GfG Weekly Contest
Offline Classes (Delhi/NCR)
DSA in JAVA/C++
Master System Design
Master CP
Languages
Python
Java
C++
PHP
GoLang
SQL
R Language
Android Tutorial
DSA Concepts
Data Structures
Arrays
Strings
Linked List
Algorithms
Searching
Sorting
Mathematical
Dynamic Programming
DSA Roadmaps
DSA for Beginners
Basic DSA Coding Problems
DSA Roadmap by Sandeep Jain
DSA with JavaScript
Top 100 DSA Interview Problems
All Cheat Sheets
Web Development
HTML
CSS
JavaScript
Bootstrap
ReactJS
AngularJS
NodeJS
Express.js
Lodash
Computer Science
GATE CS Notes
Operating Systems
Computer Network
Database Management System
Software Engineering
Digital Logic Design
Engineering Maths
Python
Python Programming Examples
Django Tutorial
Python Projects
Python Tkinter
OpenCV Python Tutorial
Python Interview Question
Data Science & ML
Data Science With Python
Data Science For Beginner
Machine Learning Tutorial
Maths For Machine Learning
Pandas Tutorial
NumPy Tutorial
NLP Tutorial
Deep Learning Tutorial
DevOps
Git
AWS
Docker
Kubernetes
Azure
GCP
Competitive Programming
Top DSA for CP
Top 50 Tree Problems
Top 50 Graph Problems
Top 50 Array Problems
Top 50 String Problems
Top 50 DP Problems
Top 15 Websites for CP
System Design
What is System Design
Monolithic and Distributed SD
Scalability in SD
Databases in SD
High Level Design or HLD
Low Level Design or LLD
Top SD Interview Questions
Interview Corner
Company Wise Preparation
Preparation for SDE
Experienced Interviews
Internship Interviews
Competitive Programming
Aptitude Preparation
GfG School
CBSE Notes for Class 8
CBSE Notes for Class 9
CBSE Notes for Class 10
CBSE Notes for Class 11
CBSE Notes for Class 12
English Grammar
Commerce
Accountancy
Business Studies
Economics
Management
Income Tax
Finance
Statistics for Economics
UPSC
Polity Notes
Geography Notes
History Notes
Science and Technology Notes
Economics Notes
Important Topics in Ethics
UPSC Previous Year Papers
SSC/ BANKING
SSC CGL Syllabus
SBI PO Syllabus
SBI Clerk Syllabus
IBPS PO Syllabus
IBPS Clerk Syllabus
Aptitude Questions
SSC CGL Practice Papers
Write & Earn
Write an Article
Improve an Article
Pick Topics to Write
Write Interview Experience
Internships
@GeeksforGeeks, Sanchhaya Education Private Limited, All rights reserved
Lightbox
