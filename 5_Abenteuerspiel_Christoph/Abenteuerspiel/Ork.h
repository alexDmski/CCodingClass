#pragma once
#include "Character.h"
#include "IWeaponInfo.h"

class Ork : public Character
{
public:
  Ork(const std::wstring& name)
	: Character(name)
  {
  }

};