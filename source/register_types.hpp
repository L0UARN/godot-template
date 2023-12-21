#ifndef REGISTER_TYPES_HEADER
#define REGISTER_TYPES_HEADER

#include <godot_cpp/godot.hpp>

namespace godot {
    void initialize_modules(ModuleInitializationLevel p_level);
    void uninitialize_modules(ModuleInitializationLevel p_level);
} // namespace godot

#endif
