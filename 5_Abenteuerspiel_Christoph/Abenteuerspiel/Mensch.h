#pragma once
#include "Character.h"

class Mensch : public Character
{
public:
  Mensch(const std::wstring& name) 
  : Character(name){ }

};