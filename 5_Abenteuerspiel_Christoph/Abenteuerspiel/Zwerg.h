#pragma once
#include "Character.h"

class Zwerg : public Character
{
public:
  Zwerg(const std::wstring& name)
    : Character(name)
  {
  }
};