/// @file
/// @brief Custom ring-buffer datatype for high speed fixed-length queues.

#include <iostream>
#include <array>

/// @brief A optimised FIFO queue implemented using a ring-buffer.
/// @tparam size The size of the buffer, must be a power of 2.
template<typename T, size_t size = 128>
struct ring_buffer {
        static_assert((size & (size - 1)) == 0, "Size must be a power of 2.");
public:
        std::array<T, size> buffer;
        size_t head = 0;
        size_t tail = 0;
        const size_t mask = size - 1;

        /// @brief Push to the buffer.
        /// @param value The value to push to the buffer.
        /// @internal Uses a trick that requires an array size of base-2.
        void push(T value) {
                buffer[head] = value;
                head = (head + 1) & mask; // this trick is faster but only works
                // with powers of 2

                if (head == tail) tail = (tail + 1) & mask;
        }

        /// @brief View the top item on the buffer.
        /// @return Zero if the array is empty, otherwise the most recent item
        /// on the buffer.
        T peek_last(void) {
                if (is_empty()) return T();
                return buffer[head];
        }

        /// @brief Pop the oldest value added to the buffer.
        /// @return Zero if the array is empty, otherwise the oldest item in the
        /// array.
        T pop(void) {
                if (is_empty()) return T(); // TODO: Proper error handling

                float value = buffer[tail];
                tail = (tail + 1) & mask;

                return value;
        }

        /// @brief 4th wall breaking joke here.
        /// @return True if the array is empty, otherwise false.
        bool is_empty() const {
                return head == tail;
        }
};
