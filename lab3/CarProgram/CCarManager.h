#pragma once
#include "CCar.h"
#include <sstream>
#include <iostream>
#include <string>

enum class Commands
{
	Info,
	EngineOn,
	EngineOff,
	SetGear,
	SetSpeed
};

typedef std::map<std::string, Commands> CommandType;

class CCarManager
{
public:
	CCarManager(CCar& car);
	~CCarManager();

	void GetInfo() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const std::string& gear);
	bool SetSpeed(const std::string& speed);
	void DoInstruction(std::string& instruction);

private:
	CCar& m_car;
	const CommandType m_commands = {
		{ "info", Info },
		{ "engineon", EngineOn },
		{ "engineoff", EngineOff },
		{ "setgear", SetGear },
		{ "setspeed", SetSpeed },
	}
};
