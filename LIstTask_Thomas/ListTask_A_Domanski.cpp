/*
Author: Domanski Alexander
Name:   using of std::list

Task:  This program implements class MyVector. class has the following functionality: add word - addNumber(string& arg),
search word in list(first matching word - searchElem(string& arg), print list - printVector(), delete words/-s - deleteElement(string& arg),
replace value - replaceValue(string& arg1, string& arg2)

Date: 24.03.2023
*/

#include <iostream>
#include <list>
#include <string>


class MyList
{
private:
    std::list<std::string> myList;
public:
    void addWord(std::string& str);//this function uses push_back() to add a new element
    std::string searchElem(std::string& str);//this function searches the first matching word in the list
    void deleteElement(std::string& str);//this function deletes word/-s using erase() and iterator 
    void replaceValue(std::string& currentVal, std::string& newVal);//this function raplace found value by searchElem() with a new value
    void printList();//prints all current elements of list using iterator
};


int main()
{
    MyList newList;

    //Input of Strings in List
    std::string inputStr;//The strings that the user wants to write in the List
    int ifInterrupt = 0;//ifInterrupt != 0, then unterrupt input
    do
    {
        std::cout << "Gebe ein neues Element ein (Ein Wort ohne Lehrzeihen)... /(Gib \"exit\" ein, um Eingabe zu beenden)" << std::endl;
        std::cin >> inputStr;

        if (inputStr == "exit")
        {
            std::cout << "Unterbrechen (put in int != 0) oder (put in 0) Wort \"exit\"  in den List hinzufugen ? " << std::endl;
            std::cin >> ifInterrupt;
            if (!ifInterrupt)
            {
                newList.addWord(inputStr);
            }
        }
        else
        {
            newList.addWord(inputStr);
        }

    } while (inputStr != "exit" || ifInterrupt == 0);

    //Search of elem in List
    std::string searchedString;//number to look for 

    std::cout << "Gib ein Wort ein, die du suchen mochtest..." << std::endl;
    std::cin >> searchedString;
    std::string result = newList.searchElem(searchedString);//find the first matching element

    if (result != "missing")// if not "missing" is returned from searchElem()
    {
        std::cout << "Das Wort " << result << " wurde in Vector gefunden. \n\n";
        std::cout << "Mochtest du diesen Wert verandern? (nein - 0, andere Zahl - ja) \n";
        int choice = 0;
        std::cin >> choice;
        if (choice != 0)
        {
            std::cout << "Gib neues Wort ein... \n";
            std::string newValue;
            std::cin >> newValue;
            newList.replaceValue(result, newValue);
        }
    }
    else
    {
        std::cout << "Dieses Wort wurde im List nicht gefunden.\n\n";
    }

    //print of all elements
    newList.printList();

    //deleting of some element 
    std::string delString;//word you want to delete
    std::cout << "Gib ein Wort ein, die du loschen mochtest..." << std::endl;
    std::cin >> delString;
    newList.deleteElement(delString);

    //print of all elements
    newList.printList();
}

//this function uses push_back() to add a new element
void MyList::addWord(std::string& str)
{
    myList.push_back(str);
}

//this function searches the first matching word in the list
std::string MyList::searchElem(std::string& str) 
{
    for (std::list<std::string>::iterator it = myList.begin(); it != myList.end(); it++)
    {
        if (*it == str)
        {
            return *it;
        }
    }
    return "missing";
}

//this function deletes word/-s using erase() and iterator 
void MyList::deleteElement(std::string& num)
{
    bool found = false;//if elem was not found in list, then false
    for (std::list<std::string>::iterator it = myList.begin(); it != myList.end();)
    {
        if (*it == num)
        {
            it = myList.erase(it);// erase() invalidates the iterator, use returned iterator
            std::cout << "Das Element wurde geloscht!\n\n";
            found = true;
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

//this function raplace found value by searchElem() with a new value
void MyList::replaceValue(std::string& currentVal, std::string& newVal)
{
    for (std::list<std::string>::iterator it = myList.begin(); it != myList.end(); ++it)
    {
        if (*it == currentVal)
        {
            *it = newVal;
            std::cout << "Der Wert wurde verandert!\n\n";
        }
    }
}

//prints all current elements of list using iterator
void MyList::printList()
{
    std::cout << "List is: ";
    for (auto i = myList.cbegin(); i != myList.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n\n";
}
