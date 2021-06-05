/*~*~*
CIS 22C
Project: Stack ADT

Written by: Shun Furuya
IDE: Xcode
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "StackADT.h"

void printInfo();
void readData(string filename, Stack<int> &s); // read data from txt file
void showData(Stack<int> &s); //show and reset the stack

int main()
{
    string filenames[] = {"numbers1.txt", "numbers2.txt", "numbers3.txt", ""};
    Stack<int> s;
    
    
    printInfo();
    for (int i = 0; filenames[i] != ""; i++)
    {
           // call a function to process the input file using a stack
        readData(filenames[i], s);
        showData(s);
    }
    
    return 0;
}

/*~*~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}


/*~*~*~*~*~*~
This function reads data from the input files and store into the stack.
Each time read 0, display the number of elements in the stack.
Each time read 1, display the element at the top of the stack.
Each time read a negative number, pop and print as many values from the stack as the absolute value of the negative number.
If there are fewer numbers in the stack, print a message and nothing else.
*~*/
void readData(string filename, Stack<int> &s){
    
    ifstream inFile;
    inFile.open(filename);

    if(inFile.fail())
    {
      cout << "Input file: " << filename << " not found!" << endl;
      exit(EXIT_FAILURE);
    }
    
    cout << endl << "Input File: " << filename << endl;
    
    int item;
    
    while(inFile >> item){
        //cout << "Read: " << item;
        
        if(item > 1) //For positive numbers except 1, store into the stack
        {
            s.push(item);
        }
        
        
        else if(item == 1){ //For 1, show the top of the stack
            cout << "Top: ";
            
            if(s.getLength() == 0)
                cout << "Empty" << endl;
            
            else
                cout << s.peek() << endl;
        }
        
        
        else if(item == 0) //For 0, show the length of the stack
            cout << "Count: " << s.getLength() << endl;
        
        
        else //For negative numbers, show and eliminate the values
        {
            if(abs(item) > s.getLength())
                cout << "Error" << endl;
            
            else{
                cout << "Stack: ";
                
                for(int i = 0; i < abs(item); i++)
                {
                    cout << s.pop() << " ";
                }
                cout << endl;
            }
        }
    }
    
    inFile.close();
}

/*
This function shows the rest of the stack data and reset it.
*/
void showData(Stack<int> &s){
    
    cout << "Stack: ";
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    cout << endl;
}
/*~*~*~*~*~*~ Save the output below

 ~*~ Project: Stack ADT ~*~

 Input File: numbers1.txt
 Top: 30
 Count: 4
 Stack: 50 40
 Stack: 25 15 30
 Stack: 70 60 20 10

 Input File: numbers2.txt
 Top: Empty
 Count: 0
 Error
 Top: 40
 Count: 3
 Stack: 50 90 40 10 40 30
 Stack: 20

 Input File: numbers3.txt
 Count: 4
 Top: 45
 Count: 4
 Top: 65
 Count: 7
 Top: 75
 Count: 7
 Error
 Count: 7
 Top: 75
 Count: 7
 Stack: 75 65 55 45 35
 Count: 9
 Top: 90
 Count: 9
 Stack: 90 80 70
 Stack: 54 43 33 23 13
 Count: 6
 Top: 60
 Count: 6
 Count: 24
 Top: 99
 Stack: 99 89 79 69 59 49
 Count: 18
 Top: 39
 Count: 22
 Error
 Count: 24
 Stack: 64 54 44 34 24 14 39 29 19 97 87 77 67 57 47 7 27 17 60 50 40 10 25 15

*~*/
