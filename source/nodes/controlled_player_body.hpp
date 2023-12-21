#ifndef CONTROLLED_PLAYER_BODY_HPP
#define CONTROLLED_PLAYER_BODY_HPP

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/ref.hpp>

namespace godot {
    class ControlledPlayerBody : public CharacterBody3D {
            GDCLASS(ControlledPlayerBody, CharacterBody3D)

        private:
            double speed;
            double acceleration_time;

        protected:
            static void _bind_methods();

        public:
            ControlledPlayerBody();
            ~ControlledPlayerBody() override;

            double get_speed() const;
            void set_speed(double new_speed);
            double get_acceleration_time() const;
            void set_acceleration_time(double new_acceleration_time);

            void _unhandled_input(const Ref<InputEvent> &event) override;
            void _physics_process(double delta) override;
    };
} // namespace godot

#endif
