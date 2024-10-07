#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
using namespace std;

class CommandProcessor;

class Command
{

public:
	// Constructors
	Command();
	Command(const Command&);
	~Command();
	Command(string command, string effect);

	// Methods
	void saveEffect(string effect);

	Command& operator = (const Command& t);		// Assignment Operator
	friend std::istream& operator>>(std::istream& in, Command& t);		// Stream Insertion Operator
	friend std::ostream& operator<<(std::ostream& out, const Command& t);	// Stream Extractin Operator

	string command;
	string effect;
};


class CommandProcessor: public Command
{
	virtual string readCommand();
	void saveCommand(string command);

public:
	// Constructors
	CommandProcessor();
	CommandProcessor(const CommandProcessor&);
	~CommandProcessor();

	// Methods
	virtual string getCommand(int state);
	bool validate(int state, string command);

	CommandProcessor& operator = (const CommandProcessor&);		// Assignment Operator
	friend std::ostream& operator<<(std::ostream& out, const CommandProcessor&);	// Stream Extraction Operator
	friend std::istream& operator>>(std::istream& in, CommandProcessor&);	// Stream Insertion Operator

	vector<Command*> commands;
};

class FileLineReader
{

public:
	// Constructors
	FileLineReader();
	FileLineReader(const FileLineReader&);
	~FileLineReader();

	// Methods
	string readLine(ifstream* file);
	
	FileLineReader& operator = (const FileLineReader&);		// Assignment Operators
	friend std::ostream& operator<<(std::ostream& out, const FileLineReader&);	// Stream Extraction Operator
	friend std::istream& operator>>(std::istream& in, FileLineReader&);		// Stream Insertion Operator
};

class FileCommandProcessorAdapter :public CommandProcessor, public FileLineReader
{
	CommandProcessor* commandProcessor;
	FileLineReader* fileLineReader;

public:
	// Constructors
	FileCommandProcessorAdapter();
	FileCommandProcessorAdapter(const FileCommandProcessorAdapter&);
	~FileCommandProcessorAdapter();

	// Methods 
	string getCommand(int state);
	string getCommand(int state, ifstream* file);
	string readCOmmand();
	string readCommand(ifstream* file);

	FileCommandProcessorAdapter& operator = (const FileCommandProcessorAdapter&);	// Assignment Operator
	friend std::ostream& operator<<(std::ostream& out, const FileCommandProcessorAdapter&);		// Stream Extraction Opearator
	friend std::istream& operator>>(std::istream& in, FileCommandProcessorAdapter&);	// Strema Insertion Operator

	
};