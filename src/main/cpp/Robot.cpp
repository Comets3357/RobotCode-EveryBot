#include "Robot.h"

void Robot::RobotInit()
{
    // timer.RobotInit(robotData.timerData);

    drivebase.RobotInit();
    arm.RobotInit();
    intake.RobotInit();
}

void Robot::RobotPeriodic()
{

    if (IsEnabled())
    {
        otherComponents.RobotPeriodic(robotData.otherComponentsData);

        drivebase.RobotPeriodic(robotData, robotData.drivebaseData);
        arm.RobotPeriodic(robotData, robotData.armData);
        intake.RobotPeriodic(robotData,robotData.intakeData);
    }
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
    controller.TeleopPeriodic(robotData, robotData.controllerData, robotData.controlData);
}

void Robot::DisabledInit()
{
    // timer.DisabledInit();

    drivebase.DisabledInit();
    arm.DisabledInit();
    intake.DisabledInit();
}

void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif