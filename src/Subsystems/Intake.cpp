#include "Intake.h"
#include "../RobotMap.h"

Intake *Intake::m_instance = 0;

Intake::Intake() : Subsystem("Intake") {

	m_ArmMotor = new CANTalon(INTAKE_ARM_MOTOR);
	m_GearMotor = new CANTalon(INTAKE_GEAR_MOTOR);
	m_BallMotor_1 = new CANTalon(INTAKE_BALL_MOTOR_1);

	m_ArmMotor->SetSafetyEnabled(false);
	m_GearMotor->SetSafetyEnabled(false);
	m_BallMotor_1->SetSafetyEnabled(false);

	//m_ArmMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);

	m_UpLimit = new frc::DigitalInput(INTAKE_ARM_UP_LIMIT);
	m_DownLimit = new frc::DigitalInput(INTAKE_ARM_DOWN_LIMIT);
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
	//if(IsIntakeDown())
	//	m_ArmMotor->Set(0);
	//else
		m_ArmMotor->Set(val);
}

void Intake::SetGear(float val) {
	m_GearMotor->Set(val);
}

void Intake::SetBall(float val) {
	m_BallMotor_1->Set(val);
}

void Intake::ConfigureOpenLoop() {
	m_ArmMotor->SetControlMode(frc::CANSpeedController::ControlMode::kPercentVbus);
	m_ArmMotor->Set(0.0);
}

void Intake::ConfigureClosedLoop() {
	m_ArmMotor->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);
	m_ArmMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	m_ArmMotor->SetSensorDirection(false);
	m_ArmMotor->SetClosedLoopOutputDirection(false);
	m_ArmMotor->SetAllowableClosedLoopErr(0);
	m_ArmMotor->SelectProfileSlot(0);
	m_ArmMotor->ConfigPeakOutputVoltage(11,INTAKE_ARM_DOWN_VOLTAGE);  //Forward is Up
	m_ArmMotor->SetF(0.0);
	m_ArmMotor->SetP(INTAKE_ARM_POSITION_P);
	m_ArmMotor->SetI(INTAKE_ARM_POSITION_I);
	m_ArmMotor->SetD(0.0);
	ResetArm();
	m_isClosedLoop = 1;
}

bool Intake::IsClosedLoop() {
	return m_isClosedLoop;
}

bool Intake::IsIntakeUp() {

	if(m_UpLimit)
		return true;
	else
		return false;
}


bool Intake::IsIntakeDown() {
	return !m_DownLimit->Get();
}


void Intake::ResetArm() {
	m_ArmMotor->SetPosition(-1.1);
}

void Intake::SetArmAngle(float angle) {
	if(m_isClosedLoop)
		m_ArmMotor->Set(angle);
	std::cout << angle*INTAKE_ARM_ROTATIONS_PER_DEGREE << std::endl;
}

float Intake::GetArmAngle() {

	return m_ArmMotor->GetPosition();
}

