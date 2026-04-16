#include "Archmage.h"
#include <iostream>

Archmage::Archmage(const std::string& name,
    const int           maxMana,
    const int           baseManaRegenRate,
    const int           manaRegenModifier)
    : Hero(name, maxMana, baseManaRegenRate)
    , _manaRegenModifier(manaRegenModifier)
{
    generateSpells();
}

void Archmage::castSpell(const SpellType spell)
{
    const Spell& selectedSpell = _spells[spell];

    if (_currMana >= selectedSpell.manaCost) {
        _currMana -= selectedSpell.manaCost;
        std::cout << _name << " casted " << selectedSpell.name << " for " << selectedSpell.manaCost << " mana" << std::endl;

        if (spell == SpellType::ULTIMATE) {
            regenerateMana();
        }
    }
    else {
        std::cout << _name << " - not enough mana to cast " << selectedSpell.name << std::endl;
    }
}

void Archmage::regenerateMana()
{
    int manaToRegen = _manaRegenRate * _manaRegenModifier;
    _currMana += manaToRegen;
    if (_currMana > _maxMana) {
        _currMana = _maxMana;
    }
}