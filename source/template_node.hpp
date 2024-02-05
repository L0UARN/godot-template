#ifndef TEMPLATE_NODE_HPP
#define TEMPLATE_NODE_HPP

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/input_event.hpp>

namespace gdext {
    class TemplateNode : public godot::Node3D {
        GDCLASS(TemplateNode, godot::Node3D)

        public:
            TemplateNode();
            ~TemplateNode() override;

            void set_message(godot::String new_message);
            godot::String get_message() const;

            void _ready() override;
            void _input(const godot::Ref<godot::InputEvent> &event) override;

        protected:
            static void _bind_methods();

        private:
            godot::String _message;
    };
}

#endif //TEMPLATE_NODE_HPP
