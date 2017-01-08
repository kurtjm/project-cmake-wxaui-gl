cmake_minimum_required(VERSION 3.0)

set(APP_SRC
    Application.h
    Application.cpp
    Main_window.h
    Main_window.cpp
    Render_window.h
    Render_window.cpp
)

# platform-specific configuration...

if (MSVC)

    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)

    set(EXE_CONFIG
        ${PROJECT_NAME}
        WIN32
        ${APP_SRC}
        # platform-specific resources, like icons
    )

elseif (APPLE)

    set(EXE_CONFIG
        ${PROJECT_NAME}
        MACOSX_BUNDLE
        ${APP_SRC}
        # platform-specific resources, like icons
    )

else()

    set(EXE_CONFIG
        ${PROJECT_NAME}
        ${APP_SRC}
    )

endif()

add_executable(${EXE_CONFIG})

target_link_libraries(
    ${PROJECT_NAME}
    ${wxWidgets_LIBRARIES}
    ${SDL_LIBRARY}
    ${OPENGL_LIBRARIES}
)
