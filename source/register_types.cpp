#include "register_types.hpp"
#include "nodes/controlled_player_body.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>

namespace godot {
    void initialize_modules(const ModuleInitializationLevel p_level) {
        if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
        }

        // Register classes here
        ClassDB::register_class<ControlledPlayerBody>();
    }

    void uninitialize_modules(const ModuleInitializationLevel p_level) {
        if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
        }

        // Uninitialize stuff here if needed
    }
} // namespace godot

extern "C" {
    GDExtensionBool GDE_EXPORT modules_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initatization) {
        const godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initatization);
        init_obj.register_initializer(godot::initialize_modules);
        init_obj.register_terminator(godot::initialize_modules);
        init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
