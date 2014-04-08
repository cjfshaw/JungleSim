#include "Champfactory.h"

Champ * Champfactory::CreateNunu()
{
        Champ * new_champ = new Champ();
        
        new_champ->setName("Nunu");
		new_champ->setMaxHealth( 5000 );
		new_champ->setCurrentHealth( 5000 );
		new_champ->setHealthRegeneration(50);
        new_champ->setMaxMana(1000);
        new_champ->setCurrentMana(1000);
        new_champ->setManaRegeneration(10);
        new_champ->setMana5(50);
        new_champ->setAttackSpeedBonus(0);
        new_champ->setModifiedAttackSpeed(0.625);//( new_champ->getBaseAttackSpeed() ( ( new_champ->getBaseAttackSpeedPerLevel * (new_champ->getLevel()-1) ) + new_champ->getAttackSpeedBonus() ) - new_champ->getBaseAttackSpeed() );
        new_champ->setCriticalBonus(200);
        new_champ->setMovespeed(300);
        new_champ->setExperience(0);
        new_champ->setLevel(1);
        new_champ->setRange(100);
        new_champ->setDamage(7300);//73
        new_champ->setBaseAttackSpeed(0.625);
        new_champ->setArmor(100);
        new_champ->setMagicResist(100);
        new_champ->setCounter(1);
        new_champ->setCriticalChance(0);

        new_champ->setHealthRegenerationPerLevel(100);
        new_champ->setHealth5PerLevel(5);
        new_champ->setManaPerLevel(50);
        new_champ->setManaRegenerationPerLevel(5);
        new_champ->setDamagePerLevel(3.45);
        new_champ->setBaseAttackSpeedPerLevel(1.0225);
        new_champ->setArmorPerLevel(30);
        new_champ->setMagicResistPerLevel(30);

        return new_champ;
}