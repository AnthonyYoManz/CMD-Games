//Class Name: Messenger
//Author: Anthony Arian
//Role: Allow allow communication between menus and engine components

#ifndef ANT_MESSENGER
#define ANT_MESSENGER

#include <vector>
#include <string>

//Message structure, used in the messenger class to store mail
struct Message
{
	std::string sender;
	std::string topic;
	std::string message;
	//others are self explanatory but this is for if you wish to pass down a pointer
	//requires the recipient to know or have a way of finding out the object that's being
	//pointed too's type. Use the topic and/or message to tell the recipient what's up
	void* ptrMessage;
};

class Messenger
{
private:
	//Collection of messages
	std::vector<Message> mailbox;
public:
	~Messenger();
	void addMessage(Message message);
	/*Returns true whenever a message is found at index 0 of the mailbox, 
	otherwise returns false. Deletes message if found after recording it 
	in the referenced argument*/
	bool pollMessage(Message& message);
};

#endif