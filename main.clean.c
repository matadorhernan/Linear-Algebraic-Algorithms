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
    gcc main.clean.c -o mk75

    MODIFIED
    * Created       5 Jun 2020      Michaus M. , &. Romero M.A.;
*/

/***********************************************************/
/***********************************************************/
/***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "constants.h"
float res[11][11];
float sys[11][11];
float matrix_a[11][11];
float matrix_b[11][11];
int mn = 0;
bool is_valid_a = false;
bool is_valid_b = false;
int KM75_printTitle(bool skip);
char KM75_scanSelect(const char *text, const int size);
float KM75_scanNumber(const char *text, bool int_only);
char KM75_listSelect(const char *texts[], const int size);
void KM75_exitApp(const char *text);
int KM75_arraySizer(bool edit_mn);
int KM75_arrayEditor(bool zero_only, float argv[11][11]);
int KM75_arrayMenu(bool is_a);
int KM75_arrayPrinter(bool is_sys, float argv_mat[11][11]);
int KM75_arrayDot(float argv_a[11][11], float argv_b[11][11]);
int KM75_arraySum(float argv_a[11][11], float argv_b[11][11]);
int KM75_arrayMemcpy(float argv_des[11][11], float argv_srs[11][11]);
int KM75_scanConstants(float argv_des[11][11], float argv_src[11][11]);
int KM75_arraySwapRow(float argv_des[11][11], int r1, int r2);
int KM75_arraySwapCol(float argv_des[11][11], int c1, int c2);
int KM75_arrayBkwdSubs(float argv_des[11][11], float argv_src[11][11]);
int KM75_arrayGaussian(float argv_des[11][11], float argv_src[11][11]);
float KM75_diagonalProduct(float argv_src[11][11]);
int KM75_arrayCramer(float argv_des[11][11], float argv_src[11][11]);
int KM75_arraySarrus(float argv_src[11][11]);
int KM75_arrayTranspose(float argv_des[11][11], float argv_src[11][11]);
bool KM75_appBootstrapper(bool by_passing, char option);
int KM75_printTitle(bool skip)
{
    if (!skip)
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
    }
    return 0;
}
char KM75_scanSelect(const char *text, const int size)
{
    char scanned[1];
    printf("\n%s", text);
    fgets(scanned, 2, stdin);
    char selected = (char)scanned[0];
    selected = ((int)selected >= 97 && (int)selected < 97 + size) || ((int)selected >= 65 && ((int)selected < 65 + size)) ? selected : SELECT_INVALID;
    if (selected == SELECT_INVALID)
    {
        printf("%s \n", SELECT_INVALID_TEXT);
    }
    fflush(stdin);
    return selected;
}
float KM75_scanNumber(const char *text, bool int_only)
{
    char scanned[10000];
    printf("\n%s", text);
    fgets(scanned, 10001, stdin);
    float selected = int_only ? (float)atoi(scanned) : atof(scanned);
    fflush(stdin);
    return selected;
}
char KM75_listSelect(const char *texts[], const int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%s \n", texts[i]);
    char selected = SELECT_INVALID;
    while (selected == SELECT_INVALID)
        selected = KM75_scanSelect(SELECT_TEXT, MENU_SIZE);
    return selected;
}
void KM75_exitApp(const char *text)
{
    printf("\n%s,", text);
    system("pause");
    exit(0);
}
int KM75_arraySizer(bool edit_mn)
{
    bool mn_invalid = true;
    int mn = MAX_MATRIX_SIZE;
    while (mn_invalid)
    {
        if (edit_mn)
        {
            mn = (int)KM75_scanNumber(INPUT_MATRIX_SIZE, true);
            if (mn <= MAX_MATRIX_SIZE && mn >= MIN_MATRIX_SIZE)
                mn_invalid = false;
            else
                printf("\n%s%i", ERROR_MATRIX_SIZE, MAX_MATRIX_SIZE);
        }
        else
            mn_invalid = false;
    }
    return mn;
}
int KM75_arrayEditor(bool zero_only, float argv[11][11])
{
    if (!zero_only)
        printf("\n%s \n", EDIT_MATRIX_TEXT);
    int aux_mn = mn;
    mn = mn == 0 ? KM75_arraySizer(!zero_only) : mn;
    for (int i = 0; i < mn; i++)
        for (int j = 0; j < mn; j++)
        {
            char text[255];
            snprintf(text, sizeof(text), "[%i,%i]: ", i, j);
            argv[i][j] = zero_only ? 0 : KM75_scanNumber(text, false);
        }
    if (zero_only)
        mn = !is_valid_a && !is_valid_b ? 0 : aux_mn;
    return 0;
}
int KM75_arrayMenu(bool is_a)
{
    bool wants_to_continue = true;
    if ((is_valid_a && is_a) || (is_valid_b && !is_a))
    {
        printf("\n%s \n", RESET_MATRIX_WARNING);
        char selected_continue = KM75_listSelect(CONTINUE_LIST, CONTINUE_SIZE);
        wants_to_continue = selected_continue == 'a' || selected_continue == 'A';
    }
    if (wants_to_continue)
    {
        if ((is_valid_a && is_a) || (is_valid_b && !is_a))
        {
            is_valid_a = false;
            is_valid_b = false;
            mn = 0;
            KM75_arrayEditor(true, matrix_a);
            KM75_arrayEditor(true, matrix_b);
        }
        KM75_arrayEditor(true, is_a ? matrix_a : matrix_b);
        KM75_arrayEditor(false, is_a ? matrix_a : matrix_b);
        if (is_a)
            is_valid_a = true;
        else
            is_valid_b = true;
    }
    return 0;
}
int KM75_arrayPrinter(bool is_sys, float argv_mat[11][11])
{
    printf("\n%s\n", is_sys ? PRINT_RES_TEXT : PRINT_MATRIX_TEXT);
    printf("\n");
    for (int i = 0; i < mn; i++)
    {
        char var = (char)(97 + i);
        if (is_sys)
            printf("%c:%.2f", var, argv_mat[i][0]);
        for (int j = 0; j < mn; j++)
            if (!is_sys)
                printf("%.2f ", argv_mat[i][j]);
        printf("\n");
    }
    return 0;
}
int KM75_arrayDot(float argv_a[11][11], float argv_b[11][11])
{
    float argv_res[11][11];
    printf("\n%s\n", DOT_MATRIX_TEXT);
    float aux;
    KM75_arrayEditor(true, argv_res);
    for (int i = 0; i < mn; i++)
        for (int j = 0; j < mn; j++)
        {
            aux = 0;
            for (int k = 0; k < mn; ++k)
                aux += argv_a[i][k] * argv_b[k][j];
            argv_res[i][j] = aux;
        }
    KM75_arrayPrinter(false, argv_res);
    return 0;
}
int KM75_arraySum(float argv_a[11][11], float argv_b[11][11])
{
    float argv_res[11][11];
    printf("\n%s\n", SUM_MATRIX_TEXT);
    KM75_arrayEditor(true, argv_res);
    for (int i = 0; i < mn; i++)
        for (int j = 0; j < mn; j++)
            argv_res[i][j] = argv_a[i][j] + argv_b[i][j];
    KM75_arrayPrinter(false, argv_res);
    return 0;
}
int KM75_arrayMemcpy(float argv_des[11][11], float argv_srs[11][11])
{
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            argv_des[i][j] = argv_srs[i][j];
    return 0;
}
int KM75_scanConstants(float argv_des[11][11], float argv_src[11][11])
{
    KM75_arrayMemcpy(argv_des, argv_src);
    for (int i = 0; i < mn; i++)
    {
        char text[255] = "";
        for (int j = 0; j < mn; j++)
        {
            char var = (char)(97 + j);
            char partial[20];
            if (j == 0)
                snprintf(partial, sizeof(partial), "(%.2f%c)", argv_des[i][j], var);
            else if (j == (mn - 1))
            {
                snprintf(partial, sizeof(partial), "%c(%.2f%c)%c ", '+', argv_des[i][j], var, '=');
            }
            else
                snprintf(partial, sizeof(partial), "%c(%.2f%c)", '+', argv_des[i][j], var);
            strcat(text, partial);
        }
        argv_des[i][mn] = KM75_scanNumber(text, false);
    }
    return 0;
}
int KM75_arraySwapRow(float argv_des[11][11], int r1, int r2)
{
    float aux;
    for (int i = 0; i <= mn; i++)
    {
        aux = argv_des[r2][i];
        argv_des[r2][i] = argv_des[r1][i];
        argv_des[r1][i] = aux;
    }
    return 0;
}
int KM75_arraySwapCol(float argv_des[11][11], int c1, int c2)
{
    float aux;
    for (int i = 0; i <= mn; i++)
    {
        aux = argv_des[i][c2];
        argv_des[i][c2] = argv_des[i][c1];
        argv_des[i][c1] = aux;
    }
    return 0;
}
int KM75_arrayTraingular(float argv_des[11][11])
{
    for (int i = 0; i < mn; i++)
    {
        int max_pivot_index = i;
        int max_pivot_value = argv_des[max_pivot_index][i];
        for (int j = i + 1; j < mn; j++)
            if (abs(argv_des[j][i]) > max_pivot_value)
                max_pivot_value = argv_des[j][i], max_pivot_index = j;
        if (!argv_des[i][max_pivot_index])
            return i;
        if (max_pivot_index != i)
            KM75_arraySwapRow(argv_des, i, max_pivot_index);
        for (int j = i + 1; j < mn; j++)
        {
            float elem = argv_des[j][i] / argv_des[i][i];
            for (int k = i + 1; k <= mn; k++)
                argv_des[j][k] -= argv_des[i][k] * elem;
            argv_des[j][i] = 0;
        }
    }
    return -1;
}
int KM75_arrayBkwdSubs(float argv_des[11][11], float argv_src[11][11])
{
    for (int i = mn - 1; i >= 0; i--)
    {
        argv_des[i][0] = argv_src[i][mn];
        for (int j = i + 1; j < mn; j++)
            argv_des[i][0] -= argv_src[i][j] * argv_des[j][0];
        argv_des[i][0] = argv_des[i][0] / argv_src[i][i];
    }
    return 0;
}
int KM75_arrayGaussian(float argv_des[11][11], float argv_src[11][11])
{
    float mem[11][11];
    KM75_arrayEditor(true, mem);
    printf("\n%s\n", GAUSSIAN_MATRIX_TEXT);
    KM75_scanConstants(mem, argv_src);
    int principal_index_zeroed = KM75_arrayTraingular(mem);
    if (principal_index_zeroed != -1)
    {
        if (mem[principal_index_zeroed][mn])
            printf("\n%s\n", MATRIX_INCONSISTANT);
        else
            printf("\n%s\n", MATRIX_INFINITE);
        return 0;
    }
    KM75_arrayBkwdSubs(argv_des, mem);
    KM75_arrayPrinter(true, argv_des);
    return 0;
}
int KM75_arraySarrus(float argv_src[11][11])
{
    float argv_des[11][11];
    KM75_arrayMemcpy(argv_des, argv_src);
    if (mn > 3)
    {
        printf("\n%s\n", ERROR_MATRIX_SARRUS);
        return 0;
    }
    float d1 = 0, d2 = 0, d = 0;
    if (mn == 3)
        for (int i = 0; i < 3; i++)
        {
            d1 = d1 + argv_des[0][i] * argv_des[1][(i + 1) % 3] * argv_des[2][(i + 2) % 3];
            d2 = d2 + argv_des[2][i] * argv_des[1][(i + 1) % 3] * argv_des[0][(i + 2) % 3];
        }
    d = d1 - d2;
    if (mn == 2)
        d = (argv_des[0][0] * argv_des[1][1]) - (argv_des[1][0] * argv_des[0][1]);
    printf("\n%s%.2f\n", PRINT_RES_TEXT, d);
    return d;
}
int KM75_arrayTranspose(float argv_des[11][11], float argv_src[11][11])
{
    for (int i = 0; i < mn; ++i)
        for (int j = 0; j < mn; ++j)
            argv_des[j][i] = argv_src[i][j];
    KM75_arrayPrinter(false, argv_des);
    return 0;
}
float KM75_diagonalProduct(float argv_src[11][11])
{
    float det = 1;
    for (int i = 0; i < mn; i++)
        det *= argv_src[i][i];
    return det;
}
int KM75_arrayCramer(float argv_des[11][11], float argv_src[11][11])
{
    float res[11][11];
    float ds = 0;
    printf("\n%s\n", CRAMER_MATRIX_TEXT);
    KM75_arrayEditor(true, res);
    KM75_scanConstants(res, argv_src);
    for (int i = 0; i <= mn; i++)
    {
        float aux[11][11];
        KM75_arrayMemcpy(aux, res);
        if (i != 0)
            KM75_arraySwapCol(aux, i - 1, mn);
        int principal_index_zeroed = KM75_arrayTraingular(aux);
        if (principal_index_zeroed != -1)
        {
            if (aux[principal_index_zeroed][mn])
                printf("\n%s\n", MATRIX_INCONSISTANT);
            else
                printf("\n%s\n", MATRIX_INFINITE);
            return 0;
        }
        argv_des[i == 0 ? mn : i - 1][0] = KM75_diagonalProduct(aux);
    }
    for (int i = 0; i < mn; i++)
        argv_des[i][0] /= argv_des[mn][0];
    KM75_arrayPrinter(true, argv_des);
}
bool KM75_appBootstrapper(bool by_passing, char option)
{
    char selected_menu = option;
    if (!by_passing)
    {
        selected_menu = KM75_listSelect(!is_valid_a ? A_MENU_LIST : !is_valid_b ? B_MENU_LIST : MENU_LIST, MENU_SIZE);
    }
    system("cls");
    switch (selected_menu)
    {
    case 'a':
    case 'A':
        KM75_arrayMenu(true);
        break;
    case 'b':
    case 'B':
        KM75_arrayMenu(false);
        break;
    case 'c':
    case 'C':
        if (!is_valid_a)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arrayPrinter(false, matrix_a);
        break;
    case 'd':
    case 'D':
        if (!is_valid_b)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arrayPrinter(false, matrix_b);
        break;
    case 'e':
    case 'E':
        if (!is_valid_a)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arrayGaussian(sys, matrix_a);
        break;
    case 'f':
    case 'F':
        if (!is_valid_a)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arrayCramer(sys, matrix_a);
        break;
    case 'g':
    case 'G':
        if (!is_valid_a)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arraySarrus(matrix_a);
        break;
    case 'h':
    case 'H':
        if (!is_valid_a)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arrayTranspose(res, matrix_a);
        break;
    case 'i':
    case 'I':
        if (!is_valid_a || !is_valid_b)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arrayDot(matrix_a, matrix_b);
        break;
    case 'j':
    case 'J':
        if (!is_valid_a || !is_valid_b)
        {
            printf("\n%s \n", DISABLED_WARNING);
            return true;
        }
        KM75_arraySum(matrix_a, matrix_b);
        break;
    case 'k':
    case 'K':
        KM75_exitApp(EXIT_TEXT);
        return false;
        break;
    default:
        printf("%s,%s", ERROR_TEXT, EXIT_TEXT);
        return false;
        break;
    }
    char selected_continue = KM75_listSelect(CONTINUE_LIST, CONTINUE_SIZE);
    bool wants_to_continue = selected_continue == 'a' || selected_continue == 'A';
    if (!wants_to_continue)
        KM75_exitApp(EXIT_TEXT);
    system("cls");
    return wants_to_continue;
}
int main()
{
    KM75_printTitle(false);
    bool can_repeat = true;
    while (can_repeat)
    {
        can_repeat = KM75_appBootstrapper(false, SELECT_INVALID);
    }
    return 0;
}