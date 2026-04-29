#include "odom.hpp"

#include "api.h"

fvector2 Odom2WheelIMU::get_position(void) {

}

void Odom2WheelIMU::init_odom(void) {
        hardware.x_wheel = std::make_unique<pros::Rotation>(odom_x_port);

        pros::Task odom_sensor_task(get_sensor_data, "ODOM SNSR");
        pros::Task odom_pos_calc_task(calc_pos, "ODOM CALC POS");

        initialised = true;
}

Odom2WheelIMU::odom_hardware_struct* Odom2WheelIMU::get_hardware_ptr(void) {
        if (initialised) return &hardware;
        else return nullptr;
}
