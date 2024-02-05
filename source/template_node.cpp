#include "template_node.hpp"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace gdext {
    void TemplateNode::_bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("get_message"), &TemplateNode::get_message);
        godot::ClassDB::bind_method(godot::D_METHOD("set_message", "new_message"), &TemplateNode::set_message);
        godot::ClassDB::add_property("TemplateNode", godot::PropertyInfo(godot::Variant::STRING, "message"), "set_message", "get_message");
        ADD_SIGNAL(godot::MethodInfo("message_displayed", godot::PropertyInfo(godot::Variant::STRING, "message")));
    }

    TemplateNode::TemplateNode() {
        if (godot::Engine::get_singleton()->is_editor_hint()) {
            set_process_mode(PROCESS_MODE_DISABLED);
        }
    }

    TemplateNode::~TemplateNode() = default;

    void TemplateNode::set_message(godot::String new_message) {
        _message = new_message;
        godot::UtilityFunctions::print("Set message to \"", _message, "\"!");
    }

    godot::String TemplateNode::get_message() const {
        return _message;
    }

    void TemplateNode::_ready() {
        godot::UtilityFunctions::print("TemplateNode ready!");
    }

    void TemplateNode::_input(const godot::Ref<godot::InputEvent> &event) {
        if (event->is_action_pressed("ui_accept")) {
            godot::UtilityFunctions::print(get_message());
            emit_signal("message_displayed", get_message());
        }
    }

}
