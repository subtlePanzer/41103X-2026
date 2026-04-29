/// @file
/// @brief Hardware and software odometry.
#include "odom.hpp"

#include <cmath>

#include "api.h"

fvector2 Odom2WheelIMU::get_position(void) {
        if (!initialised) throw; // TODO: do actual exception handling
        return fvector2(
                position_global_x_cm.load(),
                position_global_y_cm.load()
        );
}

float Odom2WheelIMU::get_heading(void) {
        return heading_global_rads.load();
}

void Odom2WheelIMU::init_odom(void) {
        hardware.x_wheel = std::make_unique<pros::Rotation>(odom_x_port);
        hardware.y_wheel = std::make_unique<pros::Rotation>(odom_y_port);
        hardware.imu = std::make_unique<pros::IMU>(imu_port);
        pros::Task odom_sensor_task(get_sensor_data, "ODOM SNSR");
        pros::Task odom_pos_calc_task(calc_pos, "ODOM CALC POS");

        initialised = true;
}

Odom2WheelIMU::odom_hardware_struct* Odom2WheelIMU::get_hardware_ptr(void) {
        if (initialised) return &hardware;
        else return nullptr;
}

void Odom2WheelIMU::get_sensor_data(void) {
        int dt = 10; // 100 Hz, approx refresh rate of the sensor
        do {
                x_wheel_angle_cdeg = hardware.x_wheel->get_position();
                y_wheel_angle_cdeg = hardware.y_wheel->get_position();
                imu_heading_rate = (float)hardware.imu->get_gyro_rate().z;
                filtered_imu_heading_deg += // account for initial pos ie. calibrate
                        imu_filter.filter(imu_heading_rate) * (1000 / dt);

                pros::delay(dt);
        } while (true);
}

void Odom2WheelIMU::calc_pos(void) {
        do {
                // TODO
                pros::delay(10);
        } while (true);
}
