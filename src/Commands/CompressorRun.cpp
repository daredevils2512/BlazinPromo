#include "CompressorRun.h"

CompressorRun::CompressorRun()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CompressorRun::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CompressorRun::Execute()
{
	if(!Robot::compressor->Pressurized()) {
		Robot::compressor->On();
	}else{
		Robot::compressor->Off();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CompressorRun::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CompressorRun::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorRun::Interrupted()
{

}
