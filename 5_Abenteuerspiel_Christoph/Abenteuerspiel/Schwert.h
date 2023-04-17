#pragma once
#include "IWeaponInfo.h"
#include <iostream>

class SetSchwert : public IWeaponInfo
{
public:

    void Attack() override
    {
        std::wcout << "Ich schlage mit einem Schwert zu\n";
    }
};