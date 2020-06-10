/*  
    LICENCE
    Provided with an MIT Licence and Licenced as Share-Alike CC 6/5/2020

    NAME
    Keyboard Math '75

    DEPENDENCIES
    You must add constant.h to your project

    DESCRIPTION
    This file is used for testing linear algebraic algorithms, and describing the 
    most fundamental aspects of computing bidimentional arrays. This simple application
    program is intended as starting point for more complex algorithms involving arrays
    and linear algebra. This application performs only the fundamentals and computes
    under the standard practice of functional programming. 

    ASSIGNMENT
    Assignment Type: Final Project
    Course: Programming Logic
    Date: 6/4/2020

    RUN
    gcc main.c -o main

    MODIFIED
    * Created       5 Jun 2020      Michaus M. , &. Romero M.A.;
*/

/***********************************************************/
/***********************************************************/
/***********************************************************/

/*
Declaration of Include files 
*/

#include <stdio.h>     // access terminal
#include <stdlib.h>    // access system
#include <stdbool.h>   // boolean variables
#include <string.h>    // string functions
#include "constants.h" // constants

float res[21][21];                       // (global) ANS as matrix
float sys[10];                           // (global) ANS as system
float matrix_a[2][2] = {{1, 2}, {3, 4}}; // (global) matrix A
float matrix_b[10][10];                  // (global) matriz B

int mn = 0;              // (global) current size of matrix
bool is_valid_a = false; // (global) matrix is usable
bool is_valid_b = false; // (global) matrix is usable

int printTitle()
{
    printf("\n");
    printf("\n");
    printf("\t     ::.----.`    `.---..:////:-.       \n");
    printf("\t     ymh-:::::-  -:::::-dmmmmmmmmds:    \n");
    printf("\t     ymm:::::::  `````` .-::::/+ohmmd:  \n");
    printf("\t     ymm:::::::       `   `-:::::-/hmmo \n");
    printf("\t     ymm:::::::      .:-    .::::::-hmm/\n");
    printf("\t     ymm:::::::     -:::-o-  .:::::::mmy\n");
    printf("\t     ymm:::::::   `-:::-syy-  :::::::mmy\n");
    printf("\t     ymm:::::::  `:::::yyyy.  :::::::mmy\n");
    printf("\t     ymm:::::::  .::-/yyyy-   :::::::mmy\n");
    printf("\t     ymm:::::::`  --/yyys.    :::::::mmy\n");
    printf("\t     omms-::::::`   :yyo`     :::::::mmy\n");
    printf("\t     `hmmo-::::::.   .+`      :::::::mmy\n");
    printf("\t      `smmdo/--:::-.`         :::::::mmy\n");
    printf("\t        -sdmmdhyyyyyy-::::::  ::::::-dmy\n");
    printf("\t          `-+osyyyys/-::::-`   .-:::-:oo\n");
    printf("\n");
    printf("\t :::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t ::            KEYBOARD MATH '75            ::\n");
    printf("\t :::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n");
    printf("\n");
    system("pause");
    return 0;
}

int main()
{
    printTitle();
    arrayTranspose();
}

int arrayTranspose()
{
    for (int i = 0; i < mn; ++i)
        for (int j = 0; j < mn; ++j)
            res[j][i] = matrix_a[i][j];

    //1 2    1 3
    //3 4    2 4

    //print array
    for (int i = 0; i < mn; ++i)
        for (int j = 0; j < mn; ++j)
            printf("%.2f", res[j][i]);
    return 0;
}
