#include "DrawRanger.h"
#include <iostream>

DrawRanger::DrawRanger(const std::string& name,
    const int           maxMana,
    const int           baseManaRegenRate)
    : Hero(name, maxMana, baseManaRegenRate)
{
    generateSpells();
}

void DrawRanger::castSpell(const SpellType spell)
{
    const Spell& selectedSpell = _spells[spell];

    if (_currMana >= selectedSpell.manaCost) {
        _currMana -= selectedSpell.manaCost;
        std::cout << _name << " casted " << selectedSpell.name << " for " << selectedSpell.manaCost << " mana" << std::endl;

        if (spell == SpellType::BASIC) {
            std::cout << _name << " casted " << _spells[SpellType::BASIC].name << " for 0 mana" << std::endl;
        }
    }
    else {
        std::cout << _name << " - not enough mana to cast " << selectedSpell.name << std::endl;
    }
}

void DrawRanger::regenerateMana()
{
    _currMana += _manaRegenRate;
    if (_currMana > _maxMana) {
        _currMana = _maxMana;
    }
}