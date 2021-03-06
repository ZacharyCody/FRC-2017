#ifndef SetRingLight_H
#define SetRingLight_H

#include "../../CommandBase.h"

class SetRingLight : public CommandBase {
public:
	SetRingLight(bool on);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_on;
	bool m_isFinished=false;
};

#endif  // SetRingLight_H
