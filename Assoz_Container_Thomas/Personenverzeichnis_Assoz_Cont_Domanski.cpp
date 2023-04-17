/*
Author: Domanski Alexander
Name:   using of std::unordered_map

Task:  This program implements class myPerson, that has following functionality: creates unordered_map and has functions like: 
addPerson(); deletePerson(); printAllPersons(); searchPersByID(), searchPersByName(), showPerson() - print one person, showOptions() - print options for 
one person(delete or modify), modifyPers() - modify name of a person, isUnique() - check if ID allready exists


Date: 30.03.2023
*/

#include <iostream>
#include <unordered_map>
#include <string>


class MyMap
{
private:
    std::unordered_map<int, std::string> myMap;
    std::unordered_map<std::string, int> myReverseMap;
public:
    void addPerson(std::pair<int, std::string>& newEntry, std::pair<std::string, int>& newEntryRev);//this function uses insert() to add a new element
    void printAllPersons();//prints all current elements of map using iterator
    int searchPersByName(std::string& str);//this function searches elem in map by name an returns ID
    std::string searchPersByID(int& ID);//returns string of entry or empty string, pair doesn't exists
    void deletePerson(int& ID);//this function deletes pair 
    bool isUnique(int& id);//check if ID allready exists
    void showOptions(int& ID);//show options: delete or modify a person
    void showPerson(int& ID);// show one entry as kay - value
    void modifyPerson(int& ID);//modify name of a person
};


int main()
{
    MyMap newMap;

    //Input of Data Pairs in map
    int persID = 0;
    std::string name;//The strings that the user wants to write in the List

    while (true)
    {
        std::pair<int, std::string> newPerson;//<key, value>
        std::pair<std::string, int> newPersonRev;//<value, key> - reverse pair to look for entry by name

        std::cout << "Gib ein neues PersonID (int) ein ... /(Gib \"-1\" ein, um Eingabe zu beenden)" << std::endl;
        std::cin >> persID;

        if (persID == -1)
        {
            break;
        }
        else
        {
            if (persID > 0 && newMap.isUnique(persID))
            {
                std::cout << "Gib den Namen des Persons mit ID " << persID << " ein..." << std::endl;
                std::cin >> name;
                newPerson.first = persID;
                newPerson.second = name;

                newPersonRev.first = name;
                newPersonRev.second = persID;
                newMap.addPerson(newPerson, newPersonRev);//adding of pairs in a normal map and reverse map at the same time

            }
            else
            {
                std::cout << "ID muss eine orinale postive Ganzzahl sein..." << std::endl;
            }
        } 
    }

    std::cout << "Die Personen sind: " << std::endl;
    newMap.printAllPersons();

    while (true)
    {
        int choice;
        std::cout << "Eine Person nach ID suchen 1, nach Name 2, zum Abbruch -1: " << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Gib ID von der Person ein..." << std::endl;
            std::cin >> persID;
            name = newMap.searchPersByID(persID);
            if (name != "")
            {
                std::cout << "Person gefunden! \n";
                newMap.showPerson(persID);
                newMap.showOptions(persID);
            }
            else
            {
                std::cout << "Person wurde nicht gefunden! \n";
            }
        }
        else if (choice == 2)
        {
            std::cout << "Gib Name von der Person ein..." << std::endl;
            std::cin >> name;
            int persID  =  newMap.searchPersByName(name);
            if (persID != 0)
            {
                std::cout << "Person gefunden! \n";
                newMap.showPerson(persID);
                newMap.showOptions(persID);
            }
            else
            {
                std::cout << "Person wurde nicht gefunden! \n";
            }
        }
        else if (choice == -1)
        {
            break;
        }
        else
        {
            std::cout << "Falsche Zahl eingegeben..." << std::endl;
            continue;
        }
    }
}
    
void MyMap::addPerson(std::pair<int, std::string>& newEntry, std::pair<std::string, int>& newEntryRev)
{
    myMap.insert(newEntry);
    myReverseMap.insert(newEntryRev);
}

void MyMap::printAllPersons()
{
    for (const auto& person : myMap)
    {
        std::cout << "ID: " << person.first << " Name: " << person.second << std::endl;
    }
}


std::string MyMap::searchPersByID(int& ID)
{
    const auto& iter = myMap.find(ID);
    if (iter != myMap.end())
    {
        return iter->second;
    }
    return "";
}

int MyMap::searchPersByName(std::string& str)
{
    const auto& iter = myReverseMap.find(str);
    if (iter != myReverseMap.end())
    {
        return iter ->second;
    }
    return 0;
}

bool MyMap::isUnique(int& id)
{
    const auto& iter = myMap.find(id);
    if (iter != myMap.end())
    {
        return false;
    }
    return true;
}

void MyMap::showOptions(int& ID)
{
    int choice = 0;
    std::cout << "Person loschen 1, Person modifizieren 2" << std::endl;

    std::cin >> choice;
    if (choice == 1)
    {
        deletePerson(ID);
    }
    else if (choice == 2)
    {
        modifyPerson(ID);
    }
}

void MyMap::showPerson(int& ID)
{
    const auto& iter = myMap.find(ID);
    if (iter != myMap.end())
    {
        std::cout << "Die Person mit der ID " << iter->first << ", hat den Namen: " << iter->second << std::endl; 
    }
}

void MyMap::deletePerson(int& ID)
{
    std::string value = myMap[ID];//we need to store value of myMap, because in myReverseMap this value is a key of pair
    myMap.erase(ID);
    myReverseMap.erase(value);
    std::cout << "Person wurde geloscht! " << std::endl;
    printAllPersons();
}

void MyMap::modifyPerson(int& ID)
{
    std::string newName;
    std::string currentValue = myMap[ID];

    std::cout << "Geben Sie neuen Namen ein, ID bleibt gleich: " << std::endl;
    std::cin >> newName;
    myMap[ID] = newName;
    myReverseMap.erase(currentValue);//deleting of reverse pair
    myReverseMap[newName] = ID;//creating of new pair with modified value
    std::cout << "Eintrag wurde verandert!" << std::endl;
    printAllPersons();
}