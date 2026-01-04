# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

target_sources(
    beman.{{cookiecutter.project_name}}
    PUBLIC
        FILE_SET beman_{{cookiecutter.project_name}}_headers
            TYPE HEADERS
            FILES
                identity.hpp
)
