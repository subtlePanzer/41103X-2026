/// @file
/// @brief Various data-processing filters.
#include "filters.hpp"

HighPass::HighPass(float alpha) : alpha(alpha) {}

float HighPass::filter(float raw) {
        float tmp = this->buffer_filtered.peek_last() + raw - buffer_raw.peek_last();
        float filtered = alpha * tmp;

        buffer_raw.push(raw);
        buffer_filtered.push(filtered);

        return filtered;
}
