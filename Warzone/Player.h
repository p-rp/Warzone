#pragma once
#include <string>
#include <vector>
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
#include "PlayerStrategy.h"
using namespace std;

class PlayerStrategy;

class Player {

	string name;
	vector<Territory*> territoriesCollection;
	Hand* hand;
	OrdersList* ordersList;
	

public:

	PlayerStrategy* ps;

	// Constructors
	Player();
	~Player();
	Player(const Player&);
	Player(string name, vector<Territory*> territories, Hand* hand, OrdersList* ordersList);

	// Methods
	Player& operator = (const Player&);		// Assignment Operator
	friend ostream& operator<< (ostream&, const Player&);		// Stream Extraction Operator
	vector<int> toDefend();			// Returns the list of territores player can defend
	vector<int> toAttack();			// Returns the list of territories player can attack
	void issueOrder();						//	Creates an order and adds it the list
	
	// Getters
	string getName();
	vector<Territory*> getTerritoriesCollection();
	Hand* getHand();
	OrdersList* getOrdersList();

	// Setters
	void setName(string name);
	void setTerritoriesCollection(vector <Territory*>);
	void setHand(Hand* hand);
	void setOrdersList(OrdersList* ordersList);
	void setPlayerStrategy(PlayerStrategy* ps);

};