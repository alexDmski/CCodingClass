#pragma once
#include "IWeaponInfo.h"
#include <iostream>

class SetAxt : public IWeaponInfo
{
public:

    void Attack() override
    {
        std::wcout << "Ich schlage mit einem Axt zu\n";
    }
};