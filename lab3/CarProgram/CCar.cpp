#include "CCar.h"

CCar::CCar() = default;

CCar::~CCar()
{
}

EngineStatus CCar::IsTurnedOn() const
{
	return m_engineStatus;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

Gear CCar::GetGear() const
{
	return m_gear;
}

EngineStatus CCar::TurnOnEngine() 
{
	if (m_engineStatus == EngineStatus::Off)
	{
		m_engineStatus = EngineStatus::On;
	}
	return m_engineStatus;
}

EngineStatus CCar::TurnOffEngine() 
{
	if (m_engineStatus == EngineStatus::On && m_gear == Gear::Neutral && m_speed == 0)
		m_engineStatus = EngineStatus::Off;
	return m_engineStatus;
}

bool CCar::SetGear(Gear gear) 
{
	if (m_gearRanges.find(gear) == m_gearRanges.end())
	{
		return false;
	}

	if (m_engineStatus == EngineStatus::Off)
	{
		m_gear = gear;
		return true;
	}

	if (gear >= Gear::First && m_direction == Direction::Back)
	{
		return false;
	}

	if (gear == Gear::Reverse && m_direction == Direction::Forward)
	{
		return false;
	}

	if (m_speed >= m_gearRanges[gear][0] && m_speed <= m_gearRanges[gear][1])
	{
		m_gear = gear;
		return true;
	}

	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (m_engineStatus == EngineStatus::Off || (m_gear == Gear::Neutral && speed > m_speed) || speed < 0)
	{
		return false;
	}

	if (m_speed >= m_gearRanges[m_gear][0] && m_speed <= m_gearRanges[m_gear][1])
	{
		if (speed == 0)
		{
			m_direction = Direction::Parking;
		}
		else
		{
			if (m_gear > Gear::Neutral)
			{
				m_direction = Direction::Forward;
			}
			else
			{
				m_direction = Direction::Back;
			}
		}

		m_speed = speed;

		return true;
	}
	return false;
}