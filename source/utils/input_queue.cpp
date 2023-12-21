#include "input_queue.hpp"

namespace godot {
    InputQueue::InputQueue() {
        this->input_queue = std::queue<InputQueueElement>();
    }

    InputQueue::~InputQueue() = default;

    void InputQueue::add(const InputQueueElement new_element) {
        if (auto &[type, strength] = this->input_queue.back(); new_element.type == type) {
            strength = new_element.strength;
            return;
        }

        this->input_queue.push(new_element);
    }
} // namespace godot
