#pragma once
#include "CCar.h"
#include <sstream>
#include <iostream>
#include <string>

class CCarManager
{
public:
	CCarManager(CCar& car);
	~CCarManager();

	void GetInfo() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	void DoInstruction(std::string& instruction);

private:
	CCar& m_car;
};
