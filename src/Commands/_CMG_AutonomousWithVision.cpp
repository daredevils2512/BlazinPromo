#include "_CMG_AutonomousWithVision.h"
#include "Commands/IntakeActuate.h"
#include "Commands/AutonDrive.h"
#include "Commands/_CMG_ShooterCharge.h"
#include "Commands/_CMG_ShootBall.h"
#include "Commands/AutonVisionTurning.h"
#include "Commands/PauseCommand.h"

_CMG_AutonomousWithVision::_CMG_AutonomousWithVision(bool shooting)
{
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
	AddSequential(new IntakeActuate(false));
    AddSequential(new AutonDrive(1.5, -0.8, 0.0, false));
    AddSequential(new AutonDrive(7.0, -0.4, 0.0, false));
    AddSequential(new AutonDrive(6.3, -0.8, 0.0, true));
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonDrive(2.5, 0.0, 0.8, true));
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonDrive(1.0, 0.6, 0.0, true));
    //vision tracking
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    //end of vision tracking
    AddSequential(new AutonDrive(4.5, 0.8, 0.0, true));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    AddSequential(new AutonVisionTurning());
    AddSequential(new PauseCommand(0.2));
    if(shooting) {
		AddParallel(new _CMG_ShooterCharge());
		AddSequential(new PauseCommand(4.0));
		AddSequential(new _CMG_ShootBall());
    }
}
