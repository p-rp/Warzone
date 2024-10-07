#pragma once
#include "Player.h"
#include "Map.h"

#include <vector>
using namespace std;

class Player;

class PlayerStrategy
{

public:
	Player* player;
	
	// Constructors
	PlayerStrategy();
	PlayerStrategy(const PlayerStrategy&);
	virtual ~PlayerStrategy();

	// Operators
	PlayerStrategy& operator = (const PlayerStrategy& playerStrategy);
	friend ostream& operator << (ostream& out, const PlayerStrategy& playerStrategy);

	// Methods
	virtual void issueOrder() = 0;
	virtual vector<int> toAttack() = 0;
	virtual vector<int> toDefend() = 0;
	void setPlayer(Player* player);

};

class HumanPlayerStrategy : public PlayerStrategy
{

public:
	// Constructors
	HumanPlayerStrategy();
	HumanPlayerStrategy(const HumanPlayerStrategy&);
	~HumanPlayerStrategy();

	// Operators
	HumanPlayerStrategy& operator = (const HumanPlayerStrategy&);
	friend ostream& operator << (ostream& out, const HumanPlayerStrategy& playerStrategy);

	// Methods
	void issueOrder();
	vector<int> toAttack();
	vector<int> toDefend();

};



class AggressivePlayerStrategy : public PlayerStrategy
{

public:
	// Constructors
	AggressivePlayerStrategy();
	AggressivePlayerStrategy(const AggressivePlayerStrategy&);
	~AggressivePlayerStrategy();

	// Operators
	AggressivePlayerStrategy& operator = (const AggressivePlayerStrategy& playerStrategy);
	friend ostream& operator << (ostream& out, const AggressivePlayerStrategy& playerStrategy);

	// Methods
	void issueOrder();
	vector<int> toAttack();
	vector<int> toDefend();

};



class BenevolentPlayerStrategy : public PlayerStrategy
{

public:
	// Constructors
	BenevolentPlayerStrategy();
	BenevolentPlayerStrategy(const BenevolentPlayerStrategy&);
	~BenevolentPlayerStrategy();

	// Operators
	BenevolentPlayerStrategy& operator = (const BenevolentPlayerStrategy& playerStrategy);
	friend ostream& operator << (ostream& out, const BenevolentPlayerStrategy& playerStrategy);

	// Methods
	void issueOrder();
	vector<int> toAttack();
	vector<int> toDefend();

};

class NeutralPlayerStrategy : public PlayerStrategy
{

public:
	// Constructors
	NeutralPlayerStrategy();
	NeutralPlayerStrategy(const NeutralPlayerStrategy&);
	~NeutralPlayerStrategy();

	// Operators
	NeutralPlayerStrategy& operator = (const NeutralPlayerStrategy& playerStrategy);
	friend ostream& operator << (ostream& out, const NeutralPlayerStrategy& playerStrategy);

	// Methods
	void issueOrder();
	vector<int> toAttack();
	vector<int> toDefend();

};


class CheaterPlayerStrategy : public PlayerStrategy
{

public:
	// Constructors
	CheaterPlayerStrategy();
	CheaterPlayerStrategy(const CheaterPlayerStrategy&);
	~CheaterPlayerStrategy();

	// Operators
	CheaterPlayerStrategy& operator = (const CheaterPlayerStrategy& playerStrategy);
	friend ostream& operator << (ostream& out, const CheaterPlayerStrategy& playerStrategy);

	// Methods
	void issueOrder();
	vector<int> toAttack();
	vector<int> toDefend();

};