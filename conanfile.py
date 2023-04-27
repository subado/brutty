from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps


class App(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    requires = ["fmt/9.1.0", "libzip/1.9.2"]
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    def generate(self):
        tc = CMakeToolchain(self)
        # Export compile_commands.json for lsp server
        tc.cache_variables["CMAKE_EXPORT_COMPILE_COMMANDS"] = True
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
