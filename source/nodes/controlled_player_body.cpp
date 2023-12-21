#include "controlled_player_body.hpp"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {
    void ControlledPlayerBody::_bind_methods() {
        ClassDB::bind_method(D_METHOD("get_speed"), &ControlledPlayerBody::get_speed);
        ClassDB::bind_method(D_METHOD("set_speed", "new_speed"), &ControlledPlayerBody::set_speed);
        ClassDB::add_property("ControlledPlayerBody", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

        ClassDB::bind_method(D_METHOD("get_acceleration_time"), &ControlledPlayerBody::get_acceleration_time);
        ClassDB::bind_method(D_METHOD("set_acceleration_time", "new_acceleration_time"), &ControlledPlayerBody::set_acceleration_time);
        ClassDB::add_property("ControlledPlayerBody", PropertyInfo(Variant::FLOAT, "acceleration_time"), "set_acceleration_time", "get_acceleration_time");
    }

    ControlledPlayerBody::ControlledPlayerBody() {
        if (Engine::get_singleton()->is_editor_hint()) {
            set_process_mode(PROCESS_MODE_DISABLED);
        }

        this->speed = 1.0;
        this->acceleration_time = 0.5;
    }

    ControlledPlayerBody::~ControlledPlayerBody() = default;

    double ControlledPlayerBody::get_speed() const {
        return this->speed;
    }

    void ControlledPlayerBody::set_speed(const double new_speed) {
        this->speed = new_speed;
    }

    double ControlledPlayerBody::get_acceleration_time() const {
        return this->acceleration_time;
    }

    void ControlledPlayerBody::set_acceleration_time(const double new_acceleration_time) {
        this->acceleration_time = new_acceleration_time;
    }

    void ControlledPlayerBody::_unhandled_input(const Ref<InputEvent> &event) {
        if (event->is_action_pressed("Forwards")) {
            UtilityFunctions::print("Forwards");
        }
    }

    void ControlledPlayerBody::_physics_process(const double delta) {
        UtilityFunctions::print("Physics process ", delta);
    }
} // namespace godot
