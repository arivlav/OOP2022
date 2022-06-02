#pragma once
#include <array>
#include <climits>
#include <map>

enum class EngineStatus :bool
{
	On = true,
	Off = false
};

enum class Gear :int
{
	Reverse = -1,
	Neutral = 0,
	First,
	Second,
	Third,
	Fourth,
	Fifth
};

enum class Direction :int
{
	Back = -1,
	Parking = 0,
	Forward
};

typedef std::map<Gear, std::array<int, 2>> GearRanges;

class CCar
{
public:
	CCar();
	~CCar();
	EngineStatus IsTurnedOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	Gear GetGear() const;
	EngineStatus TurnOnEngine();
	EngineStatus TurnOffEngine();
	bool SetGear(Gear gear);
	bool SetSpeed(int speed);

private:
	EngineStatus m_engineStatus = EngineStatus::Off;
	int m_speed = 0;
	Gear m_gear = Gear::Neutral;
	Direction m_direction = Direction::Parking;
	GearRanges m_gearRanges = {
		{ Gear::Reverse, { 0, 20 } },
		{ Gear::Neutral, { 0, INT_MAX } },
		{ Gear::First, { 0, 30 } },
		{ Gear::Second, { 20, 50 } },
		{ Gear::Third, { 30, 60 } },
		{ Gear::Fourth, { 40, 90 } },
		{ Gear::Fifth, { 50, 150 } }
	};

};
