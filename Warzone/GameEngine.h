#pragma once
#include "Player.h"
#include "CommandProcessing.h"
#include <string>
#include <vector>
using namespace std;

struct StateNode {
public:
	//Constuctors
	StateNode();
	StateNode(string, StateNode*);
	StateNode(const StateNode&); //copy constructor

	//Getter methods
	string getName();
	StateNode* getNextState1();
	StateNode* getNextState2();

	//Setter methods
	void setName(string);
	void setNextState1(StateNode*);
	void setNextState2(StateNode*);

	//Assignment operators
	StateNode& operator=(const StateNode&);

	//Stream insertion operator
	friend std::ostream& operator<<(std::ostream&, const StateNode&);

	//Functions
	StateNode* initiliazeStates(); //Initliaze multi-linked list of StateNodes
	void playGame(StateNode*); //Driver method that takes input and determines appropriate transition 
	StateNode* transition(string, StateNode*); //Validate transition 
	void deleteStates(StateNode*);
	void startupPhase();
	
	CommandProcessor processor;
	MapLoader loader;
	string mapFileName;
	int playerCount;

private:
	//Node data values
	string name;
	StateNode* nextState1;
	StateNode* nextState2;
};
