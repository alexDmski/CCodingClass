/*
Author: Domanski Alexander
Name:   using of std::vector

Task:  This program implements class MyVector. class has the following functionality: add number - addNumber(int& arg),
search element in vector(first matching elem. - searchElem(int& arg), print vector - printVector(), delete element/-s - deleteElement(int& arg),
replace value - replaceValue(int& arg1, int& arg2)

Date: 22.03.2023
*/

#include <iostream>
#include <vector>

class MyVector
{
private:
    std::vector<int> numVector;
public:
    void addNumber(int& num);//this function uses push_back() to add a new element
    int searchElem(int& num);//this function uses iterator to iterate in vector 
    void printVector();//this function uses short form of iterrator to iterate through vector
    void deleteElement(int& num);//this function uses iterator to iterate in vector (iterator here like a pointer)
    void replaceValue(int& currentVal, int& newVal);//this function raplace found value by searchElem() with a new value
};

int main()
{
    MyVector newVector;

    //Input of Numbers in Vector
    int inputNum = 0;//The numbers that the user wants to write in the vector
    int ifInterrupt = 0;//ifInterrupt != 0, then unterrupt input
    do
    {
        std::cout << "Gebe ein neues Element ein (Ein Integer Wert)... /(Gib -1 ein, um Eingabe zu beenden)" << std::endl;
        std::cin >> inputNum;
     
        if (inputNum == -1)
        {
            std::cout << "Unterbrechen (put in int != 0) oder (put in 0) -1  in den Vektor hinzufugen?" << std::endl;
            std::cin >> ifInterrupt;
            if (!ifInterrupt)
            {
                newVector.addNumber(inputNum);
            }
        }
        else
        {
            newVector.addNumber(inputNum);
        }

    } while (inputNum != -1 || ifInterrupt == false);

    //Search of elem in Verctor
    int searchedNumber;//number to look for 

    std::cout << "Gib eine Zahl ein, die du suchen mochtest..." << std::endl;
    std::cin >> searchedNumber;
    int result = newVector.searchElem(searchedNumber);//find the first matching element

    if (result != -111111)// if not -111111 is returned from searchElem()
    {
        std::cout << "Die Zahl " << result << " wurde in Vector gefunden. \n\n";
        std::cout << "Mochtest du diesen Wert verandern? (nein - 0, andere Zahl - ja) \n";
        int choice = 0;
        std::cin >> choice;
        if (choice != 0)
        {
            std::cout << "Gib neuen Wert ein... \n";
            int newValue;
            std::cin >> newValue;
            newVector.replaceValue(result, newValue);
        }
    }
    else
    {
        std::cout << "Diese Zahl wurde im Vektor nicht gefunden.\n\n";
    }

    //print of all elements
    newVector.printVector();

    //delete of some element 
    int delNumber;//number you want to delete
    std::cout << "Gib eine Zahl ein, die du loschen mochtest..." << std::endl;
    std::cin >> delNumber;
    newVector.deleteElement(delNumber);

    //print of all elements
    newVector.printVector();
}


void MyVector::addNumber(int& num)
{
    numVector.push_back(num);
}

//this function uses iterator to iterate in vector (iterator here like a pointer). 
int MyVector::searchElem(int& num)
{
    for (std::vector<int>::iterator it = numVector.begin(); it != numVector.end(); it++)
    {
        if (*it == num)
        {
            return *it;
        }
    }

    return -111111;
}

void MyVector::printVector()
{
    std::cout << "\Vector is: ";
    for (auto elem : numVector)
    {
        std::cout << elem << " ";
    }

    std::cout << "\n";
}

void MyVector::deleteElement(int& num)
{
    bool found = false;//if elem was not found in vector false
    for (std::vector<int>::iterator it = numVector.begin(); it != numVector.end();)
    {
        if (*it == num)
        {
            it = numVector.erase(it);// erase() invalidates the iterator, use returned iterator
            std::cout << "Das Element wurde geloscht!\n\n";
        }
        else
        {
            ++it;
        }
    }
    if (!found)
    {
        std::cout << "Das Element wurde nicht gefunden!\n\n";
    }
}

void MyVector::replaceValue(int& currentVal, int& newVal)
{
    for (std::vector<int>::iterator it = numVector.begin(); it != numVector.end(); ++it)
    {
        if (*it == currentVal)
        {
            *it = newVal;
            std::cout << "Der Wert wurde verandert!\n\n";
        }
    }
}
