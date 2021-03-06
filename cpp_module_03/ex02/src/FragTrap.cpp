/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:28:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string const	FragTrap::__constructorVoiceLines[] =
{
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

std::string const	FragTrap::__destructorVoiceLines[] =
{
	"I'll stop talking when I'm dead!",
	"I'll die the way I lived: annoying!",
	"Come back here! I'll gnaw your legs off!",
	"This could've gone better!",
	"Good thing I don't have a soul!",
	"You can't kill me!",
	"I'm too pretty to die!",
	"Robot down!",
	"No, nononono NO!",
	"I'll never go back to the bad place!",
	"I have many regrets!"
};

std::string const	FragTrap::__rangedAttackVoiceLines[] =
{
	"Step right up, to the Bulletnator 9000!",
	"I am a tornado of death and bullets!",
	"Stop me before I kill again, except don't!",
	"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
	"Ha ha ha! Fall before your robot overlord!",
	"Can't touch this!",
	"Ha! Keep 'em coming!",
	"There is no way this ends badly!",
	"This is why I was built!"
};

std::string const	FragTrap::__meleeAttackVoiceLines[] =
{
	"Hyah!",
	"Heyyah!",
	"Take that!",
	"Bop!"
};

std::string const	FragTrap::__takeDamageVoiceLines[] =
{
	"My assets... frozen!",
	"I can't feel my fingers! Gah! I don't have any fingers!",
	"Too cold... can't move!",
	"I am a robot popsicle!",
	"Brrh... So cold... brrh...",
	"Metal gears... frozen solid!",
	"Why do I even feel pain?!",
	"Why did they build me out of galvanized flesh?!",
	"Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!",
	"Yikes! Ohhoho!",
	"Woah! Oh! Jeez!",
	"If only my chassis... weren't made of recycled human body parts! Wahahaha!"
};

std::string const	FragTrap::__beRepairedVoiceLines[] =
{
	"Can I just say... yeehaw.",
	"You are ace high!",
	"You're the wub to my dub!",
	"Sweet life juice!",
	"Healsies!"
};

std::string const	FragTrap::__vaulthunterVoiceLines[] =
{
	"Place your bets!",
	"Defragmenting!",
	"Running the sequencer!",
	"It's happening... it's happening!",
	"It's about to get magical!",
	"I'm pulling tricks outta my hat!",
	"You can't just program this level of excitement!",
	"What will he do next?",
	"Things are about to get awesome!",
	"Push this button, flip this dongle, voila! Help me!",
	"Square the I, carry the 1... YES!",
	"Resequencing combat protocols!",
	"Look out everybody, things are about to get awesome!",
	"I have an IDEA!",
	"Round and around and around she goes!",
	"It's like a box of chocolates...",
	"Step right up to the sequence of Trapping!",
	"Loading combat packages!",
	"F to the R to the 4 to the G to the WHAAT!"
};

int					FragTrap::vaulthunter_dot_exe(std::string const &rTarget)
{
	std::string const	vhunter_atk_pool[][3] =
	{
		{"Shhhhh...trap", "I'm a robot ninja...", "0"},
		{"Funzerker", "I'm a sexy dinosaur! Rawr!", "0"},
		{"Rubber Ducky", "I am rubber, and you are so dead!", "0"},
		{"Pirate Ship Mode", "Avast ye scurvy dogs!", "0"},
		{"Meat Unicycle", "It's the only way to stop the voices!", "180"}
	};
	std::string			msg;
	size_t				n_voices = sizeof(__vaulthunterVoiceLines) / sizeof(std::string);
	size_t				n_atks = sizeof(vhunter_atk_pool) / sizeof(std::string[3]);
	int					idx;

	if (_hitPoints <= 0 || rTarget.empty())
		return (-1);
	if (_energyPoints < 25)
	{
		_printInfoMessage("Not enough energy points to execute VaultHunter.EXE");
		return (-1);
	}
	_printVoiceMessage(__vaulthunterVoiceLines[std::rand() % n_voices]);
	if ((_energyPoints -= 25) < 0)
		_energyPoints = 0;
	idx = std::rand() % n_atks;
	msg = typeid(*this).name();
	msg += " " + _name + " executes VaultHunter.EXE <" + vhunter_atk_pool[idx][0] + \
		"> on " + rTarget + " dealing " + vhunter_atk_pool[idx][2] + " points of damage! Wow!";
	_printInfoMessage(msg);
	_printVoiceMessage(vhunter_atk_pool[idx][1]);
	return (std::stoi(vhunter_atk_pool[idx][2]));
}

					FragTrap::FragTrap(std::string const &rName) :
					ClapTrap(rName)
{
	size_t			n_voices = sizeof(__constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_msgColor = "\033[0;33m";
	_meleeAtkDamage = 30;
	_rangedAtkDamage = 20;
	_armorDamageReduction = 5;
	_rangedAttackVoiceLines = __rangedAttackVoiceLines;
	_meleeAttackVoiceLines = __meleeAttackVoiceLines;
	_takeDamageVoiceLines = __takeDamageVoiceLines;
	_beRepairedVoiceLines = __beRepairedVoiceLines;
	_rangedAttackNumVoices = sizeof(__rangedAttackVoiceLines) / sizeof(std::string);
	_meleeAttackNumVoices = sizeof(__meleeAttackVoiceLines) / sizeof(std::string);
	_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	_printDebugMessage(dmsg);
	_printVoiceMessage(__constructorVoiceLines[std::rand() % n_voices]);
}

					FragTrap::FragTrap(FragTrap const &rSrc)
{
	*this = rSrc;
	_rangedAttackVoiceLines = __rangedAttackVoiceLines;
	_meleeAttackVoiceLines = __meleeAttackVoiceLines;
	_takeDamageVoiceLines = __takeDamageVoiceLines;
	_beRepairedVoiceLines = __beRepairedVoiceLines;
	_rangedAttackNumVoices = sizeof(__rangedAttackVoiceLines) / sizeof(std::string);
	_meleeAttackNumVoices = sizeof(__meleeAttackVoiceLines) / sizeof(std::string);
	_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);
}

					FragTrap::~FragTrap(void)
{
	size_t			n_voices = sizeof(__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	_printDebugMessage(dmsg);
}

FragTrap			&FragTrap::operator=(FragTrap const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_msgColor = rRhs.getMsgColor();
		_level = rRhs.getLevel();
		_hitPoints = rRhs.getHitPoints();
		_maxHitPoints = rRhs.getMaxHitPoints();
		_energyPoints = rRhs.getEnergyPoints();
		_maxEnergyPoints = rRhs.getMaxEnergyPoints();
		_meleeAtkDamage = rRhs.getMeleeAtkDamage();
		_rangedAtkDamage = rRhs.getRangedAtkDamage();
		_armorDamageReduction = rRhs.getArmorDamageReduction();
	}
	return (*this);
}

					FragTrap::FragTrap(void)
{
}
