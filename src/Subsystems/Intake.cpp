#include "Intake.h"
#include "../RobotMap.h"

Intake *Intake::m_instance = 0;

Intake::Intake() : Subsystem("Intake") {

	m_ArmMotor = new CANTalon(INTAKE_ARM_MOTOR);
	m_GearMotor = new CANTalon(INTAKE_GEAR_MOTOR);
	m_BallMotor_1 = new CANTalon(INTAKE_BALL_MOTOR_1);
	m_BallMotor_2 = new CANTalon(INTAKE_BALL_MOTOR_2);

	m_ArmMotor->SetSafetyEnabled(false);
	m_GearMotor->SetSafetyEnabled(false);
	m_BallMotor_1->SetSafetyEnabled(false);
	m_BallMotor_2->SetSafetyEnabled(false);
}


Intake* Intake::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Intake Class" << std::endl;
		m_instance = new Intake();
	}
	return m_instance;
}


void Intake::InitDefaultCommand() {

}


void Intake::SetArm(float val) {
	m_ArmMotor->Set(val);
}


void Intake::SetGear(float val) {
	m_GearMotor->Set(val);
}


void Intake::SetBall(float val) {
	m_BallMotor_1->Set(val);
	m_BallMotor_2->Set(-val);
}