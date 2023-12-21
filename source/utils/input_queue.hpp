#ifndef INPUT_QUEUE_HPP
#define INPUT_QUEUE_HPP

#include <queue>

namespace godot {
    enum InputType {
        FORWARDS,
        BACKWARDS,
        STRAFE_LEFT,
        STRAFE_RIGHT,
    };

    struct InputQueueElement {
        public:
            InputType type;
            float strength;
    };

    class InputQueue {
        private:
            std::queue<InputQueueElement> input_queue;

        public:
            InputQueue();
            ~InputQueue();

            void add(InputQueueElement new_element);
    };
} // namespace godot

#endif
