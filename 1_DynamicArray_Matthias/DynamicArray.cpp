/*
Author: Domanski Alexander
Name:   Dynamic Array(Final Version)

Task:   It belongs to implement a class DynamicItemArray that reserves array for pointers type Item.
        This class has the mathod Add() - add object, GetItemAtPosition(i) - return pointer on one element.

Date: 17.03.2023
*/

#include <iostream>

class Item final
{
    std::uint32_t m_value;
public:
    Item() = default;

    /*The explicit function specifier controls unwanted implicit type conversions.
    It can only be used in declarations of constructors within a class declaration. */
    explicit Item(std::uint32_t value)
        : m_value(value)
    {

    }
    ~Item() = default;

    std::uint32_t GetValue() const
    {
        return m_value;
    }
};

class DynamicItemArray final
{
private:
    Item* arr;
    std::uint32_t size;//number of elements
    std::uint32_t capacity;//allocated memory

public:
    DynamicItemArray() 
    {
        arr = new Item[1];
        capacity = 1;
    };

    void addMemory()
    {
        capacity *= 2;//capacity will be doubled
        Item* tempArr = arr;//current array will be saved
        arr = new Item[capacity];//new allocation
        for (std::uint32_t i = 0; i < size; ++i)//deep copy    
        {
            arr[i] = tempArr[i];
        }
        delete[] tempArr;
    }

    //like push_back
    void Add(Item item)
    {
        if (size >= capacity)
        {
            addMemory();//allocates more mamory if needed
        }
        arr[size++] = item;
    }

    Item& GetItemAtPosition(std::uint32_t index)
    {
        return arr[index];
    }

    ~DynamicItemArray()
    {
        delete[]arr;
        std::cout << "Destructed arr on address " << arr << std::endl;
        arr = nullptr;
    }

};

void function(std::uint32_t count)
{
    DynamicItemArray dynamicArray;
    for (std::uint32_t i = 0; i < count; i++)
    {
        dynamicArray.Add(Item(20 % (i + 1) + i));
    }

    for (std::uint32_t i = 0; i < count; i++)
    {
        const Item& item = dynamicArray.GetItemAtPosition(i);
        std::cout << "Value of the item at position " << i + 1 <<
            " is " << item.GetValue() << std::endl;
    }
}

int main()
{
    function(10);
    return 0;
}
