#include "CommandProcessing.h"

// Command Class

// Constructors
Command::Command()
{
	this->command = "Unknown_Command";
	this->effect = "Unknown_Effect";
}

Command::Command(const Command& cmd)
{
	this->command = cmd.command;
	this->effect = cmd.effect;
}

Command::~Command()
{

}

Command::Command(string command, string effect)
{
	this->command = command;
	this->effect = effect;
}


// Methods

//Save Effect Method
void Command::saveEffect(string effect)
{
	this->effect = effect;
}

// Assigment Operator
Command& Command::operator=(const Command& cmd)
{
	command = cmd.command;
	effect = cmd.effect;
	return *this;
}

// Stream Extraction Opearator
std::ostream& operator<<(std::ostream& out, const Command& cmd)
{
	out <<  cmd.command << " Effect: " << cmd.effect;
	return out;
}

// Stream Insertion Opearator
std::istream& operator>>(std::istream& in, Command& cmd)
{
	return in;
}


// CommandProcessor Class

// Constructors
CommandProcessor::CommandProcessor()
{
	commands;
}

CommandProcessor::CommandProcessor(const CommandProcessor& cmdP)
{
	commands = cmdP.commands;
}

CommandProcessor::~CommandProcessor()
{
	for (auto x : commands)
	{
		delete x;
	}
	commands.clear();

}

// Methods

string CommandProcessor::readCommand()
{
	string line;
	std:getline(std::cin, line);
	return line;
}

void CommandProcessor::saveCommand(string toSave)
{
	Command* command = new Command(toSave, "Unknown_Effect");
	commands.push_back(command);
}

string CommandProcessor::getCommand(int state)
{
	string enteredCommand = readCommand();
	if (validate(state, enteredCommand))
	{
		saveCommand(enteredCommand);
		return enteredCommand;
	}
	else
		cout << "Invalid command at this state.\n";
	return "Invalid Command";

};

bool CommandProcessor::validate(int state, string command)
{
	
	if (command.find("loadmap", 0) == 0 && (state == 0 || state == 1))
	{
		return true;
	}
	if (command == "validatemap" && state == 1)
	{
		return true;
	}
	if (command.find("addplayer", 0) == 0 && (state == 2 || state == 3))
		return true;
	if (command == "gamestart" && state == 3)
		return true;
	if (command == "replay" && state == 7)
		return true;
	if (command == "quit" && state == 7)
		return true;
	return false;
}

// Assignment Operator
CommandProcessor& CommandProcessor::operator=(const CommandProcessor& cmd)
{
	commands = cmd.commands;
	return *this;
}

// Stream Extraction Opearator
std::ostream& operator<<(std::ostream& out, const CommandProcessor& cmd)
{
	
	for (int i = 0; i < cmd.commands.size(); i++)
	{
	out << cmd.commands.at(i)->command + ": " + cmd.commands.at(i)->effect + "\n";
	}

	return out;
}


// Stream Insertion Operator
std::istream& operator>>(std::istream& in, CommandProcessor& t)
{
	return in;
}
