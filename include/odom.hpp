/// @file odom.hpp
/// @brief Hardware and software odometry.
#pragma once

#include "datatypes.hpp"

class Odom2WheelIMU {
public:
        /// @brief Struct for managing odom-related hardware.
        struct odom_hardware_struct {
                std::unique_ptr<pros::Rotation> x_wheel;
                std::unique_ptr<pros::Rotation> y_wheel;
                std::unique_ptr<pros::IMU>      imu;
        };

        Odom2WheelIMU() = delete;

        /// @brief Get the current position of the robot.
        /// @return The current x and y position of the robot in cm, relative
        /// to the starting position.
        static fvector2 get_position(void);

        /// @brief Get the current heading of the robot.
        /// @return The current heading of the robot in radians, relative to 
        /// the starting position.
        static fvector2 get_heading(void);

        /// @brief Initialise the odometry system. 
        static void init_odom(void);

        /// @brief Get a pointer to the odom hardware.
        /// @return A pointer to the hardware struct, or nullptr if not
        /// initialised.
        static odom_hardware_struct* get_hardware_ptr(void);
private:
        const static int odom_x_port = 1;
        const static int odom_y_port = 2;
        const static int imu_port = 3;

        static inline bool initialised = false;

        static inline struct odom_hardware_struct hardware;

        static void get_sensor_data(void);
        static void calc_pos(void);
};
