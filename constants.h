
extern const char EXIT_TEXT[] = "Closing App";                                                      // (editable) closing
extern const int MAX_MATRIX_SIZE = 10;                                                              // (editable 85, 86, 87) max size of square matrix
extern const int MIN_MATRIX_SIZE = 2;                                                               // (readonly) min size of square matrix
extern const char EDIT_MATRIX_TEXT[] = "Editing Matrix";                                            // (editable) before scanning matrix
extern const char PRINT_MATRIX_TEXT[] = "Matrix: ";                                                 // (editable) before scanning matrix
extern const char PRINT_RES_TEXT[] = "Resultado: ";                                                 // (editable) before scanning matrix
extern const char DOT_MATRIX_TEXT[] = "Dot Product of A and B: ";                                   // (editable) before dot matrix
extern const char SUM_MATRIX_TEXT[] = "Sum of A and B: ";                                           // (editable) before sum matrix
extern const char GAUSSIAN_MATRIX_TEXT[] = "Performing Gaussian Elimination on Matrix A";           // (editable) before gaussian matrix
extern const char CRAMER_MATRIX_TEXT[] = "Solving Matrix A with Cramer's Rule";                     // (editable) before gaussian matrix
extern const char MATRIX_INFINITE[] = "Detected infinitely many solutions.";                        // (editable) system with too many answers
extern const char MATRIX_INCONSISTANT[] = "Invalid, system is inconsistant.";                       // (editable) system with no answers
extern const char RESET_MATRIX_WARNING[] = "This will reset A and B";                               // (editable) before scanning matrix again
extern const char INPUT_MATRIX_SIZE[] = "Squared Matrix, enter size: ";                             // (editable) before scanning int matrix size
extern const char ERROR_MATRIX_SIZE[] = "Invalid, min is 2, max is ";                               // (editable) error on maxout
extern const char ERROR_TEXT[] = "Error...";                                                        // (editable) closing with error
extern const char ERROR_MATRIX_SARRUS[] = "Matrix size needs to be smaller or equal than 3";        // (editable) error on maxout
extern const char DISABLED_WARNING[] = "Now this is Epic, But As I said, you can't do this yet..."; // (editable) option warning
extern const char SELECT_TEXT[] = "Choose an option: ";                                             // (editable) before scanning option input
extern const char SELECT_INVALID_TEXT[] = "Invalid Input, try again";                               // (editable) input is not valid
extern const char SELECT_INVALID = '@';                                                             // (editable) invalid char to return <<must be symbol>>
extern const int MENU_SIZE = 11;                                                                    // (readonly) size of main menu {X_MENU_LIST}
extern const char *A_MENU_LIST[11]                                                                  // (editable 49, 63) main menu <<do not change status or order, word choice allowed>>
    = {
        "a) A.exe          | Edits the components of A",
        "b) B.exe          | Edits the components of B",
        "c) [disabled]     | Prints A",
        "d) [disabled]     | Prints B",
        "e) [disabled]     | Solves A by Gaussian Elimination",
        "f) [disabled]     | Solves A with the Crammer Method",
        "g) [disabled]     | Computes the Determinant of A",
        "h) [disabled]     | Computes A Transposed",
        "i) [disabled]     | Calculates the Dot Product of A and B",
        "j) [disabled]     | Calculates the Sum of A and B",
        "k) Exit           | Exit this app",
};
extern const char *B_MENU_LIST[11] // (editable 35, 63) main menu <<do not change status or order, word choice allowed>>
    = {
        "a) A.exe          | Edits the components of A",
        "b) B.exe          | Edits the components of B",
        "c) PrintA.exe     | Prints A",
        "d) [disabled]     | Prints B",
        "e) GaussA.exe     | Solves A by Gaussian Elimination",
        "f) CrammerA.exe   | Solves A with the Crammer Method",
        "g) SarrussA.exe   | Computes the Determinant of A",
        "h) TransposeA.exe | Computes A Transposed",
        "i) [disabled]     | Calculates the Dot Product of A and B",
        "j) [disabled]     | Calculates the Sum of A and B",
        "k) Exit           | Exit this app",
};
extern const char *MENU_LIST[11] //   (editable 35, 49) main menu <<do not change status or order, word choice allowed>>
    = {
        "a) A.exe          | Edits the components of A",
        "b) B.exe          | Edits the components of B",
        "c) PrintA.exe     | Prints A",
        "d) PrintB.exe     | Prints B",
        "e) GaussA.exe     | Solves A by Gaussian Elimination",
        "f) CrammerA.exe   | Solves A with the Crammer Method",
        "g) SarrussA.exe   | Computes the Determinant of A",
        "h) TransposeA.exe | Computes A Transposed",
        "i) DotAB.exe      | Calculates the Dot Product of A and B",
        "j) SumAB          | Calculates the Sum of A and B",
        "k) Exit           | Exit this app",
};
extern const int CONTINUE_SIZE = 2; // (readonly) size of continue menu {CONTINUE_LIST}
extern const char *CONTINUE_LIST[2] // continue menu <<do not change order, word choice allowed>>
    = {
        "a) Continue",
        "b) Exit",
};
