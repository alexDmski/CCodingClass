#pragma once
#include "IWeaponInfo.h"
#include <iostream>

class SetZweihandAxt : public IWeaponInfo
{
public:

    void Attack() override
    {
        std::wcout << "Ich schlage mit einem Zweihandaxt zu\n";
    }
};