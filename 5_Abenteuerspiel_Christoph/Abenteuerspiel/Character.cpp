#include "Character.h"
#include <iostream>
#include "StandLaufanimation.h"
#include "Faust.h"

Character::Character(const std::wstring& name)
  : m_name(name)
  , m_laufAnimation(std::make_unique<StandLaufanimation>())
  , m_weaponInfo(std::make_unique<SetFaust>())
{}

Character::~Character() = default;

void Character::Walk() const
{
  if (m_laufAnimation)
  {
    m_laufAnimation->Walk();
  }
}

void Character::Attack() const
{
    if (m_weaponInfo)
    {
        m_weaponInfo->Attack();
    }
}

void Character::SayOurName() const
{
  std::wcout << "Mein Name ist: " << m_name << "\n";
}

void Character::SetWeapon(std::unique_ptr<IWeaponInfo>&& newWeapon)
{
    m_weaponInfo.reset(newWeapon.release());
}

void Character::SetLaufAnimation(std::unique_ptr<ILaufanimation>&& newLauf)
{
  m_laufAnimation.reset(newLauf.release());
}
