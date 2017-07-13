//
// Created by Mike on 7/7/17.
//
#include "controller.hpp"
#include <pthread.h>

int mycallback (void* messageTypeStruct)
{
    receivedSensorMessage = *(static_cast<CLIENT_DATA*>(messageTypeStruct));
    switch (receivedSensorMessage.updatedSensor)
    {
        case MessageType::VEHICLE:
            //  cout << "Vehicle velocity: " << VehicleController::getInstance().getVelocity(Unit::Velocity_Unit_KPH).velocity() <<endl;
            break;
        case MessageType::STEERING:
            //  cout << "Steering position: " << VehicleController::getInstance().Steering()->getHandWheelAngle().angle()  << endl;
            break;
        case MessageType::GEAR:
            //  cout << "Vehicle Gear position: " << VehicleController::getInstance().Gears()->getGearPosition().position() << endl;
            break;
        case MessageType::BRAKING:
            //  cout << "Vehicle brake position: " << VehicleController::getInstance().Brakes()->getPedalForce().percent() << " %" << endl;
            break;
        case MessageType::THROTTLE:
            //  cout << "Vehicle Throttle position: " << VehicleController::getInstance().Throttle()->getPedalPosition().percent() << " %" << endl;
            break;
        case MessageType::BENCH:
            // cout << "Bench Throttle position: " << VehicleController::getInstance().Bench()->getPedalPosition().percent() << " %" << endl;
            break;
        default:
            break;
    }
    return 0;
}

struct message{
    int cmd;
};
std::queue<message> q;

p.push(msg);

msg = q.top();
q.pop();


void *threadLoop(void *context)
{
    msg = context->messg;
    while (1) {

    }
    pthread_exit(NULL);
}

th = pthread_create(&do_somthing);

pthread_kill()
//pthread_self(&th);

PlexusController::PlexusController() : Controller() {
    vctrl = &(VehicleController::getInstance());
    vctrl->registerCallback(mycallback);
    vctrl.waitSeconds(1);
}

context;

PlexusController::~PlexusController() {
    turnOFF();
}

void PlexusController::steering(int angle) {
    if (vctrl->isMoving()) {
//    Direction direction;
//            direction.set_direction(Direction::CW);
        vctrl->Steering()->setAngle(angle, direction);
    }
    std::cout << "Steering " << angle << std::endl;
}

int PlexusController::turnON() {
    if (VehicleController::getInstance().turnON() == ClientMessages::Fault::ERROR)
    {
        std::cout << "Error setting VehicleController ON state " << std::endl;
        return -1;
    }
    std::cout << "turning on" << std::endl;
    pthread_t threadID;
    pthread_create(&threadID, NULL, threadLoop, (void *)context);
    return 0;
}

int setVelocity(int velocity) {
    this->PID(velocity);
}

void PlexusController::turnOFF() {
    vctrl->turnOFF();
    std::cout << "Turning everying off complete" << std::endl;
    vctrl->waitSeconds(1);

    context->exit_flag = 1;
    rc = pthread_join(threads[i], &status);

    if (rc){
        cout << "Error:unable to join," << rc << endl;
        exit(-1);
    }

    cout << "Main: completed thread id :" << i ;
    cout << "  exiting with status :" << status << endl;
    pthread_exit(NULL);
}