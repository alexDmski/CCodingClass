#pragma once
#include "IWeaponInfo.h"
#include <iostream>

class SetFaust : public IWeaponInfo
{
public:

    void Attack() override
    {
        std::wcout << "Ich schlage mit einem Faust zu\n";
    }
};