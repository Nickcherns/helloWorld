#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// calculator
// ask user for type of operation
// ask user to input 2 numbers
// print solution

// struct to allow two numbers to be returned from a function
struct Numbers 
{
    int firstNumber;
    int secondNumber;
};

// function declarations for compiler
string selectOperation();
Numbers selectNumbers();
void restartCalculator();
float solveEquation(int num1, int num2, string selectedOperator);

int main()
{

    Numbers userNumbers;
    float equationSolution;

    // select operator
    string currentOperator = selectOperation();
    cout << "Your chosen operator is: " << currentOperator << "\n";
    // allow user to input two numbers
    userNumbers = selectNumbers();
    
    // relay user provided information and solve
    cout << "Your equation is...\n\n" << userNumbers.firstNumber << " " << currentOperator << " " << userNumbers.secondNumber << "\n";
    equationSolution = solveEquation(userNumbers.firstNumber, userNumbers.secondNumber, currentOperator);
    // provide solution
    cout << "Your Solution is... " << equationSolution << "\n\n";

    // allow option to start over
    restartCalculator();
}

// function to solve equation based on provided numbers and operator
float solveEquation(int num1, int num2, string selectedOperator)
{
    float solution;
    if (selectedOperator == "+") {
        solution = (float)num1 + (float)num2;
    } 
    else if (selectedOperator == "-")
    {
        solution = (float)num1 - (float)num2;
    }
    else if (selectedOperator == "*")
    {
        solution = (float)num1 * (float)num2;
    }
    else if (selectedOperator == "/")
    {
        solution = (float)num1 / (float)num2;
    }
    return solution;
};

// function to convert user input to an operator and return it
string selectOperation() 
{
    string currentOperator;
    int userSelectedOperator;

    cout << "Welcome to The Calculator\n" << "Which operation would you like to you use?\n" <<
        "1. Addition\n" << "2. Subtraction\n" << "3. Multiplication\n" << "4. Division\n";
    cin >> userSelectedOperator;

    if (userSelectedOperator == 1) {
        currentOperator = "+";
    } 
    else if (userSelectedOperator == 2)
    {
        currentOperator = "-";
    }
    else if (userSelectedOperator == 3)
    {
        currentOperator = "*";
    }
    else if (userSelectedOperator == 4)
    {
        currentOperator = "/";
    }
    else
    {
        cout << "\nInvalid Selection... Please try again...\n\n";
        selectOperation();
    }
    return currentOperator;
}

// function to allow two inputs for numbers then return struct that holds both inputs
Numbers selectNumbers() 
{
    Numbers userNumbers;
  
    cout << "Enter two numbers to be used with your selected Operator: \n";
    cin >> userNumbers.firstNumber >> userNumbers.secondNumber;

    return userNumbers;
}

// function to restart calculator after solution is given
void restartCalculator() 
{
    const char* yesPossibilities[] = {"yes", "yeah", "ye"};
    char yesCharacter = 'y';
    string userAnswer;

    cout << "Would you like to input another equation?\n";
    cin >> userAnswer;

    // transform string to lowercase, regardless of input
    std::transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

    // search through possible 'yes' inputs, if yes restart program, if no end
    const char** possibleInputCheck = find(yesPossibilities, yesPossibilities+3, userAnswer);
    if (possibleInputCheck != yesPossibilities+3) 
    {
        main();
    }
    else 
    {
        cout << "Good Bye!";
    }

}
