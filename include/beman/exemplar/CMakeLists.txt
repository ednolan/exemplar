# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

target_sources(
    beman.exemplar
    PUBLIC
        FILE_SET beman_exemplar_headers
            TYPE HEADERS
            FILES
                identity.hpp
)
