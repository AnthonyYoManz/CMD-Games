//Author: Anthony Arian

#include "Messenger.h"

Messenger::~Messenger()
{
	mailbox.clear();
}

void Messenger::addMessage(Message _message)
{
	mailbox.push_back(_message);
	return void();
}

bool Messenger::pollMessage(Message& _message)
{
	if (mailbox.size() > 0)
	{
		_message = mailbox.at(0);
		mailbox.erase(mailbox.begin());
		return true;
	}
	return false;
}