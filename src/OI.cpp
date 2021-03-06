#include "OI.h"
#include "Commands/AutoGearScoreSub.h"
#include "Commands/SetDrivetrainClosedLoop.h"
#include "Commands/Auto/SetIntake.h"
#include "Constants.h"


#include <WPILib.h>

OI *OI::m_instance = 0;

OI::OI() {

	std::cout << "info: creating operator interface." << std::endl;

	drvStick = new Joystick(0);
	m_drvButton1 = new JoystickButton(drvStick, 1);
	m_drvButton2 = new JoystickButton(drvStick, 2);
	m_drvButton3 = new JoystickButton(drvStick, 3);
	m_drvButton4 = new JoystickButton(drvStick, 4);
	m_drvButton5 = new JoystickButton(drvStick, 5);
	m_drvButton6 = new JoystickButton(drvStick, 6);
	m_drvButton7 = new JoystickButton(drvStick, 7);
	m_drvButton8 = new JoystickButton(drvStick, 8);


	opStick = new Joystick(1);
	m_opButton1 = new JoystickButton(opStick, 1);
	m_opButton2 = new JoystickButton(opStick, 2);
	m_opButton3 = new JoystickButton(opStick, 3);
	m_opButton4 = new JoystickButton(opStick, 4);
	m_opButton5 = new JoystickButton(opStick, 5);
	m_opButton6 = new JoystickButton(opStick, 6);

	//DSI Controls
	dsiBrickA = new Joystick(2);
	dsiBrickB = new Joystick(3);

	m_brickAselect1 = new JoystickButton(dsiBrickA, 1);
	m_brickAselect2 = new JoystickButton(dsiBrickA, 2);
	m_brickAselect3 = new JoystickButton(dsiBrickA, 3);
	m_brickAselect4 = new JoystickButton(dsiBrickA, 4);
	m_brickAselect5 = new JoystickButton(dsiBrickA, 5);
	m_brickAselect6 = new JoystickButton(dsiBrickA, 6);
	m_brickAselect7 = new JoystickButton(dsiBrickA, 7);
	m_brickAselect8 = new JoystickButton(dsiBrickA, 8);

	m_brickBselect1 = new JoystickButton(dsiBrickB, 1);
	m_brickBselect2 = new JoystickButton(dsiBrickB, 2);
	m_brickBselect3 = new JoystickButton(dsiBrickB, 3);
	m_brickBselect4 = new JoystickButton(dsiBrickB, 4);
	m_brickBselect5 = new JoystickButton(dsiBrickB, 5);
	m_brickBselect6 = new JoystickButton(dsiBrickB, 6);
	m_brickBselect7 = new JoystickButton(dsiBrickB, 7);
	m_brickBselect8 = new JoystickButton(dsiBrickB, 8);

	m_dsiSw1 = new JoystickButton(dsiBrickB, 9);
	m_dsiSw2 = new JoystickButton(dsiBrickB, 10);
	m_dsiSw3 = new JoystickButton(dsiBrickA, 9);
	m_dsiSw4 = new JoystickButton(dsiBrickA, 10);
	m_dsiSw5 = new JoystickButton(dsiBrickA, 11);

	m_drvButton6->WhenPressed(new AutoGearScoreSub());
	m_drvButton6->WhenReleased(new SetDrivetrainClosedLoop(false));
	m_drvButton6->WhenReleased(new SetIntake(INTAKE_ARM_POSITION_UP));


	//-----------------DRIVER CONTROLS---------------------

	//m_drvButton3->WhileHeld(new )

	//-----------------OPERATOR CONTROLS---------------------


}

OI* OI::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating OperatorInterface Class" << std::endl;
		m_instance = new OI();
	}
	return m_instance;
}


int OI::GetSelectorA() {
	if(m_brickAselect1->Get())
		return 0;
	if(m_brickAselect2->Get())
		return 1;
	if(m_brickAselect3->Get())
		return 2;
	if(m_brickAselect4->Get())
		return 3;
	if(m_brickAselect5->Get())
		return 4;
	if(m_brickAselect6->Get())
		return 5;
	if(m_brickAselect7->Get())
		return 6;
	if(m_brickAselect8->Get())
		return 7;

	return 0;
}


int OI::GetSelectorB() {
	if(m_brickBselect1->Get())
		return 1;
	if(m_brickBselect2->Get())
		return 2;
	if(m_brickBselect3->Get())
		return 3;
	if(m_brickBselect4->Get())
		return 4;
	if(m_brickBselect5->Get())
		return 5;
	if(m_brickBselect6->Get())
		return 6;
	if(m_brickBselect7->Get())
		return 7;
	if(m_brickBselect8->Get())
		return 8;

	return 0;
}


int OI::GetDSSwitches() {
	int switches = 0;
	int sw1 = m_dsiSw1->Get();
	switches = sw1;
	int sw2 = m_dsiSw2->Get();
	switches = switches + (sw2 << 1);
	int sw3 = m_dsiSw3->Get();
	switches = switches + (sw3 << 2);
	int sw4 = m_dsiSw4->Get();
	switches = switches + (sw4 << 3);
	int sw5 = m_dsiSw5->Get();
	switches = switches + (sw5 << 4);

	return switches;
}


bool OI::GetSw1() {
	return m_dsiSw1->Get();
}


bool OI::GetSw2() {
	return m_dsiSw2->Get();
}


bool OI::GetSw3() {
	return m_dsiSw3->Get();
}


bool OI::GetSw4() {
	return m_dsiSw4->Get();
}


bool OI::GetSw5() {
	return m_dsiSw5->Get();
}
