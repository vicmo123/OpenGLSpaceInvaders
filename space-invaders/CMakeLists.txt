cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)
# ici on declare des variables avec set
set(
        PROJECT_NAME_VALUE
        space-invaders)
# declarer le projet
project(${PROJECT_NAME_VALUE})
# ajouter tous les fichiers qui sont dans le repertoire src
file(
        GLOB_RECURSE
        source_files
        src/*
)
#si besoin de repertoire assets
#attention le repertoire doit exister
file(
        COPY
        assets
        DESTINATION
       ${CMAKE_BINARY_DIR}
)
#permet de faire l executable
add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files}
)
# ajouter les linker des librairie, different en fonction de windows ou linux
if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_ttf
            -lSDL2_image
            -lSDL2_mixer
    )
endif ()

if (UNIX)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lSDL2main
            -lSDL2
            -lSDL2_ttf
            -lSDL2_image
            -lSDL2_mixer
    )
endif ()