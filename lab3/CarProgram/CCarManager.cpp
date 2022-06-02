#include "CCarManager.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

CCarManager::CCarManager(CCar& car) :m_car(car)
{
}

CCarManager::~CCarManager()
{
}

void GetInfo(const CCar& car)
{
    cout << "Engine status: " << ((car.IsEngineTurnOn()) ? ("turned on") : ("turned off")) << endl;
    cout << "Direction: " << DirectionToString(car.GetDirection()).c_str() << endl;
    cout << "Gear: " << GearToString(car.GetGear()).c_str() << endl;
	cout << "Speed: " << car.GetSpeed() << endl;
}

bool CCar::TurnOnEngine()
{
    auto result = m_car.TurnOnEngine();
	if (result)
	{
		cout << "the engine is turned on" << endl;
	}
	else
	{
		cout << "engine is already enabled" << endl;
	}
	return result;
}
	
bool CCar::TurnOffEngine() 
{
    auto result = m_car.TurnOffEngine();
	if (result)
	{
		cout << "the engine is turned off" << endl;
	}
	else
	{
		cout << "can not turn off the engine" << endl;
	}
	return result;
}

bool CCar::SetGear(const std::string& gear)
{
    try
	{
		auto carGear = IntToGear(gear);
		auto result = m_car.SetGear(carGear);
		if (result)
		{
			cout << "selected gear " << gear << endl;
		}
		else
		{
			cout << "gear didn't change" << endl;
		}
		return result;
	}
	catch (exception & exception)
	{
		cout << "gear didn't change" << endl;
		cerr << exception.what() << endl;
		return false;
	}
}

bool CCar::SetSpeed(const std::string& speed)
{
    auto result = m_car.SetSpeed(speed);
	if (result)
	{
		cout << "selected speed " << speed << endl;
	}
	else
	{
		cout << "speed didn't changed" << endl;
	}
	return result;
}

void CCar::DoInstruction(string& instruction)
{
    to_lower(instruction);
	vector<string> instructionParts;
	split(instructionParts, instruction, is_any_of(" "));
    switch(instructionParts.size()) 
    {
        case 1:
            string command = instructionParts[0];
            switch (command)
            {
                case Info:
                    GetInfo();
                    break;
                case EngineOn:
                    TurnOnEngine();
                    break;
                case EngineOff:
                    TurnOffEngine();
                    break;
                default:
                    cout << "Unknown command" << endl;
                    break;
            }
            break;
        case 2:
            string command = instructionParts[0];
            string param = instructionParts[1];
            switch (command)
            {
                case Info:
                    SetGear(param);
                    break;
                case SetSpeed:
                    SetSpeed(param);
                    break;
                default:
                    cout << "Unknown command" << endl;
                    break;
            } 
            break;
        default:
            cout << "Unknown command" << endl;
            break;        
    }
}