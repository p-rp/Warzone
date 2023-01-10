#pragma once
#include "Player.h"
#include <string>
#include <vector>
using namespace std;

class Territory
{
private:
	string territoryName;
	int army;

	Continent* continent;
	Player* owner;

	vector<Territory*> adjTerritories;

public:

	
	Territory();									// Default constructor
	Territory(const Territory*);					// Copy construtor 
	Territory(string territoryName, int army);		// Param constructor
	Territory& operator = (const Territory&);		// Assignment operator
	~Territory();									// Descturctor

	// Methods
	void displayBorders();

	// Getters
	string getTerritoryName();
	int getArmy();
	Continent* getContiennt();
	Player* getOwner();
	vector<Territory*> getAdjTerritories();

	// Setters
	void setTerritoryName(string territoryName);
	void setArmy(int army);
	void setContiennt(Continent* continent);
	void setOwner(Player* owner);
	void setAdjTerritories(vector<Territory*> adjterritories);
};

class Continent
{
private:
	string continentName;
	vector<Territory*> territoriesIncontinent;


public:

	// Constructors

	// Methods

	// Getters

	// Setters

};
