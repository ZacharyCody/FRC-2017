#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <iostream>
#include "Constants.h"
#include "CANTalon.h"
#include "WPILib.h"

class Shooter : public Subsystem {
private:
	CANTalon* m_Motor1;
	CANTalon* m_Motor2;
	Solenoid* m_flashlight;
	Solenoid* m_ringlight;
	Solenoid* m_gearlight;


	Shooter();
	static Shooter* m_instance;
	int m_rpm = 0;
	bool m_isClosedLoop=false;
public:

	static Shooter* GetInstance();
	void InitDefaultCommand();
	void ConfigureClosedLoop();
	void ConfigureOpenLoop();
	void SetOpenLoop(float value);
	void SetVoltageRamp(float value);
	void SetRPM(int rpm);
	int GetRPM();
	float GetCurrent();
	float GetVoltage();


	void SetFlashlightOn(bool on);
	void SetRingLightOn(bool on);
	void SetGearLight(bool on);

};

#endif  // Shooter_H
