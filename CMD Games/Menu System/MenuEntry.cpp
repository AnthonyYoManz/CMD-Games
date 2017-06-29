//Author: Anthony Arian

#include "MenuEntry.h"

MenuEntry::MenuEntry(std::string _name, std::string _link)
{
	name = _name;
	link = _link;
}

std::string MenuEntry::getName()
{
	return name;
}

std::string MenuEntry::activate()
{
	return link;
}