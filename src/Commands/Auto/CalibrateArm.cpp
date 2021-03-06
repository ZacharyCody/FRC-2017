#include "CalibrateArm.h"

CalibrateArm::CalibrateArm(bool leaveArmDown) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::GetInstance());
	m_armDown = leaveArmDown;
}

// Called just before this Command runs the first time
void CalibrateArm::Initialize() {
	//SetTimeout(2.0);
	m_isFinished = false;
	m_switchdelaycount = 0;
	//if(Intake::GetInstance()->IsClosedLoop())
	//	Intake::GetInstance()->ConfigureOpenLoop();
	//Intake::GetInstance()->SetCalibrating(1);
}

// Called repeatedly when this Command is scheduled to run
void CalibrateArm::Execute() {
	if(Intake::GetInstance()->isSensorPluggedIn() == 1) Intake::GetInstance()->ConfigureClosedLoop();
	Intake::GetInstance()->ConfigureOpenLoop();
	m_isFinished = true;

//	Intake::GetInstance()->SetArm(-0.3);
//	if(Intake::GetInstance()->IsIntakeDown())
//	{
//		m_switchdelaycount++;
//		Intake::GetInstance()->SetArm(-0.15);
//		if(m_switchdelaycount >= m_switchdelay)
//		{
//			Intake::GetInstance()->ConfigureClosedLoop();
//			Intake::GetInstance()->SetArm(INTAKE_ARM_POSITION_DOWN);
//			m_isFinished = true;
//		}
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool CalibrateArm::IsFinished() {

	return m_isFinished;
}

// Called once after isFinished returns true
void CalibrateArm::End() {
	if(!Intake::GetInstance()->IsClosedLoop()) {
		std::cout << "error: could not calibrate arm" << std::endl;
//		Intake::GetInstance()->SetArm(0); //Stop Arm
	}
//	else
//		if(m_armDown == false)
//		{
//			Intake::GetInstance()->SetArmAngle(INTAKE_ARM_POSITION_UP);
//		}
//		else
//		{
//			Intake::GetInstance()->SetArmAngle(INTAKE_ARM_POSITION_DOWN);
//
//		}
//	Intake::GetInstance()->SetCalibrating(false);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CalibrateArm::Interrupted() {

}
