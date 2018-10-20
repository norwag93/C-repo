            /* This program takes input from the user in the form of
             *varA, varB, varC and calculates roots of quadric equation
             *Ax^2 + Bx + C = 0
             *It detects automatically whatever input is indeed quadric equation. 
			  *
			  *Pawel Gawron 20.10.2018 */


// C LIBRARIES *************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



// GLOBAL VARIABLES *************************************************************************************

double numA, numB, numC; // variables for a, b, c function parameters
double inputNumber;      // this value is used for user input before it's assigned to some other variables
double delta;            // variable for delta parameter
double x1, x2;           // variables for a solution
char Y[1];               // variable for yes
char valueY[2] = "yY";   // string for yes comparision



// FUNCTIONS SECTION *************************************************************************************

            /* Function scanfCheck takes input from a keyboard and
             * allows the user to pass only numeric values such as
             * integers and float point numbers. It restricts the user
             * from entering any other characters from the ASCII table.
             * It's not-essential but nice to have feature :) */

double scanfCheck(void){
    char inputString[18];
    char * end;

    char wrongInputList[] = "`=qwertyuiop[]asdfghjkl;'zxcvbnm,/~!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:|ZXCVBNM<>?";
    char *pWrongInputCheck;

    char dot[] = ".";
    char *pToDot = 0;
    char *pToSecondDot = 0;
    char *pTopSecondDot = 0;

    char minus[] = "-";
    char *pToMinus = 0;
    char *pToSecondMinus = 0;
    char *pTopSecondMinus = 0;



    scanf("%18s", inputString);

    pWrongInputCheck = strpbrk(inputString, wrongInputList);

    pToDot = strpbrk(inputString, dot);
    if(pToDot != 0)
    {
        pTopSecondDot = pToSecondDot;
        pToSecondDot = strpbrk((pToDot + 1), dot);
    }

    pToMinus = strpbrk(inputString, minus);
    if(pToMinus != 0)
    {
        pTopSecondMinus = pToSecondMinus;
        pToSecondMinus = strpbrk((pToMinus + 1), minus);

    }
    /* WHILE WITH GOTO LOOP INSIDE */
    while(pWrongInputCheck != 0)
    /* WHILE WITH GOTO LOOP INSIDE */
    {

        loop:   /* GOTO LOOP INSIDE THIS FUNCTION */

        while(getchar() != '\n');
        printf("\nWrong input, variable must be a number!!!\nPlease try again: ");
        scanf("%18s", inputString);
        pWrongInputCheck = strpbrk(inputString, wrongInputList);
        pToDot = strpbrk(inputString, dot);
        pToMinus = strpbrk(inputString, minus);
        if(pToDot != 0)
        {
            pToSecondDot = strpbrk((pToDot + 1), dot);
        }
        if(pToMinus != 0)
        {
            pToSecondMinus = strpbrk((pToMinus + 1), minus);
        }


    }

    if(pToDot != 0 && inputString[0] == dot[0]){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;   /* THIS GOTO LOOP GO TO MARKED WHILE STATEMENT */
    }

    if(pToSecondDot != 0){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;   /* THIS GOTO LOOP GO TO MARKED WHILE STATEMENT */
    }

    if(pToMinus != 0 && inputString[0] != minus[0]){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;   /* THIS GOTO LOOP GO TO MARKED WHILE STATEMENT */
    }

    if(pToSecondMinus != 0){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;   /* THIS GOTO LOOP GO TO MARKED WHILE STATEMENT */
    }

    if(pToMinus != 0 && inputString[0] == minus[0] && inputString[1] == dot[0]){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;   /* THIS GOTO LOOP GO TO MARKED WHILE STATEMENT */
    }

    if(pToMinus != 0 && inputString[0] == minus[0] && inputString[1] == dot[0] && inputString[2] != NULL){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;
    }

    if(inputString[0] == minus[0] && inputString[1] == NULL){
        pToDot = 0;
        pToSecondDot = 0;
        pTopSecondDot = 0;
        pToMinus = 0;
        pToSecondMinus = 0;
        pTopSecondMinus = 0;

        goto loop;
    }

    inputNumber = strtod(inputString, & end);

    pToDot = 0;
    pToSecondDot = 0;
    pTopSecondDot = 0;
    pToMinus = 0;
    pToSecondMinus = 0;
    pTopSecondMinus = 0;

    return 0;
}


            /* Function deltaCalculator takes three variables A B C
             * from quadric equation, and calculate the
             * delta value for further use. */

double deltaCalculator(double varA, double varB, double varC){

    delta = varB * varB + (-4) * varA * varC;
    return 0;
}


            /* Function functionRootCalculator takes three input values
             * Var A is A parameter from quadric equation
             * Var B is B parameter from quadric equation
             * Var Delta is delta parameter from the function deltaCalculator
             * This function produces three outputs,
             * Case1 varDelta > 0    x1 and x2 roots
             * Case2 varDelta == 0  x1 == x2 root
             * Case3 varDelta < 0    x1 and x2 as a complex roots. */

double functionRootCalclulator(double varA, double varB, double varDelta) {

    double functionDelta;
    double complexSquareRoot;
    double A, B;


    if (varDelta > 0) {
        x1 = (((-1) * varB + (-1) * sqrt(varDelta)) / (2 * varA));
        x2 = (((-1) * varB + sqrt(varDelta)) / (2 * varA));

        printf("\nx1 = %G\nx2 = %G\n", x1, x2);
    } else if (varDelta == 0) {
        x1 = (((-1) * varB)/(2*varA));

        printf("\nx1 = x2 = %G\n", x1);
    } else if (varDelta < 0) {
        functionDelta = (-1) * varDelta;
        complexSquareRoot = sqrt(functionDelta);
        complexSquareRoot = complexSquareRoot/(2*varA);
        A = 2*varA;
        B = (-1)*varB;
        B = B/A;
        printf("\nConplex root x1 = %G-%Gi\n", B, complexSquareRoot);
        printf("Conplex root x2 = %G+%Gi\n", B, complexSquareRoot);

    }

    return 0;
}

            /* Function linearFunctionRoot is used when
            *  the user enters 0 as A variable. It changes the quadric equation
            *  into a linear equation with only one root.
            *  This function calculates that root. */

double linearFunctionRoot(double varB, double varC){

    x1 = ((-1)*varC)/varB;
    printf("\nLinear equation root x1 = %G\n", x1);
    return 0;
}


// MAIN SECTION *************************************************************************************

int main(void){
    begin: /* GOTO LOOP STARTS HERE */

    // this section is for reading user input and displaying it for him

    printf("Ax^2 + Bx + C = y\n\nPlease enter variable A: ");
    scanfCheck();
    numA = inputNumber;

    printf("\n%Gx^2 + Bx + C = y\n\nPlease enter variable B: ", numA);
    scanfCheck();

    numB = inputNumber;
    printf("\n%Gx^2 + %Gx + C = y\n\nPlease enter variable C: ", numA, numB);
    scanfCheck();

    numC = inputNumber;
    printf("\n\n\nYour function is: %Gx^2 + %Gx + %G = y\n", numA, numB, numC);

    // this section determine whatever input is quadratic equation or not

    if(numA > 0 || numA < 0){
    deltaCalculator(numA, numB, numC);
    functionRootCalclulator(numA, numB, delta);
    } else {
        if(numB > 0 || numB < 0){
            linearFunctionRoot(numB, numC);
        } else {
            if(numC > 0 || numC < 0){
                printf("\nlinear equation without roots\n");
            } else {
                printf("\nevery x is a root of linear equation 0=0\n");
            }
        }

    }


    // this section takes y or Y as yes and repeats the whole program if user whish that

    printf("\n\nPlease enter y to start again, or enter any key to exit:  ");

    scanf("%1s", &Y[0]);

    if(Y[0] == valueY[0] || Y[0] == valueY[1]){
        goto begin; /* GOTO LOOP TO THE FIRST LINE OF MAIN FUNCTION */
    }

    return 0;
}

