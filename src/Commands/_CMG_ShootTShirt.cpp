#include "_CMG_ShootTShirt.h"
#include "Robot.h"
#include "PauseCommand.h"
#include "ShooterTShirtActuateSolenoid1.h"
#include "ShooterTShirtActuateSolenoid2.h"
#include "ShooterTShirtFireValve.h"

_CMG_ShootTShirt::_CMG_ShootTShirt() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential (new ShooterTShirtActuateSolenoid1(false));
	AddSequential (new PauseCommand(1.0));
	AddSequential (new ShooterTShirtActuateSolenoid1(true));
	AddSequential (new PauseCommand(0.5));
	AddSequential (new ShooterTShirtFireValve(true));
	AddSequential (new PauseCommand(0.25));
	AddSequential (new ShooterTShirtFireValve(false));
	AddSequential (new ShooterTShirtActuateSolenoid2(true));
	AddSequential (new PauseCommand(0.5));
	AddSequential (new ShooterTShirtActuateSolenoid1(false));
}
