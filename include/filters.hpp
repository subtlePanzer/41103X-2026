/// @file
/// @brief Various data-processing filters.
#pragma once

#include "ring_buffer.hpp"

/// @brief Pure virtual class for different types of data filters.
class Filter {
public:
        Filter(void) = default;

        /// @brief Filter the data.
        /// @param raw The unfiltered data.
        /// @return The filtered data.
        virtual float filter(float raw);

protected:
        ring_buffer<128> buffer_raw;
        ring_buffer<128> buffer_filtered;
};

/// @brief Simple high-pass filter that removes low-band signals.
class HighPass : public Filter {
public:
        /// @brief Constructor.
        /// @param alpha Time factor, 0.0-1.0. An alpha closer to 1.0 will let 
        /// more data through, while alpha closer to 0 will eliminate more 
        /// low-frequency data.
        HighPass(float alpha);

        /// @brief Filter the data using a high-pass filter.
        /// @param raw The unfiltered data.
        /// @return The filtered data.
        float filter(float raw) override;
private:
        float alpha;
};
