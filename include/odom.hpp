/// @file
/// @brief Hardware and software odometry.
#pragma once

#include <atomic>
#include <filters.hpp>
#include <memory>

#include "api.h"

#include "vector2.hpp"

/// @brief Odometry using 2 tracking wheels and an IMU
class Odom2WheelIMU {
public:
        /// @brief Struct for managing odom-related hardware.
        typedef struct odom_hardware_struct {
                std::unique_ptr<pros::Rotation> x_wheel;
                std::unique_ptr<pros::Rotation> y_wheel;
                std::unique_ptr<pros::IMU>      imu;
        } odom_hardware_struct;

        Odom2WheelIMU() = delete;

        /// @brief Get the current position of the robot.
        /// @return The current x and y position of the robot in cm, relative
        /// to the starting position.
        static fvector2 get_position(void);

        /// @brief Get the current heading of the robot.
        /// @return The current heading of the robot in radians, relative to 
        /// the starting position.
        static float get_heading(void);

        /// @brief Initialise the odometry system. 
        static void init_odom(void);

        /// @brief Get a pointer to the odom hardware.
        /// @return A pointer to the hardware struct, or nullptr if not
        /// initialised.
        static odom_hardware_struct* get_hardware_ptr(void);
private:
        static constexpr int odom_x_port = 1;
        static constexpr int odom_y_port = 2;
        static constexpr int imu_port = 3;

        static inline std::atomic<float> position_global_x_cm{0.0f};
        static inline std::atomic<float> position_global_y_cm{0.0f};
        static inline std::atomic<float> heading_global_rads{0.0f};

        static inline std::atomic<float> x_wheel_angle_cdeg{0.0f};
        static inline std::atomic<float> y_wheel_angle_cdeg{0.0f};
        static inline std::atomic<float> imu_heading_rate{0.0f};
        static inline std::atomic<float> filtered_imu_heading_deg{0.0f};

        static inline Filter imu_filter{HighPass(0.95)}; // TODO: tune filter

        /// @internal Used to avoid returning bad data if the calculation 
        /// thread has not been run yet.
        static inline bool initialised = false;

        /// @brief The odometry hardware.
        static inline odom_hardware_struct hardware;

        /// @brief Thread for reading sensor data.
        static void get_sensor_data(void);

        /// @brief Thread for updating position in real time based on odometry 
        /// readings.
        static void calc_pos(void);
};
