cmake_minimum_required(VERSION 3.0.0)
project(MCUConfig C CXX)

# Compiler Variables ###########################################################

# Set Cpp Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable In-Source Builds
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

# Makefile Settings
set(CMAKE_VERBOSE_MAKEFILE OF)
set(CMAKE_COLOR_MAKEFILE   OFF)

# Find Sources #################################################################

file(GLOB_RECURSE SRC_FILES	"src/*.h"        "src/*.cpp")
file(GLOB IMGUI_SRC_FILES   "Deps/ImGui/*.cpp" "Deps/ImGui/*.h")

set(GLAD_INCLUDE_DIR   "${PROJECT_SOURCE_DIR}/Deps/glad/include")
set(GLAD_SRC           "${PROJECT_SOURCE_DIR}/Deps/glad/src/glad.c")
set(GLM_INCLUDE_DIR    "${PROJECT_SOURCE_DIR}/Deps/glm/")
set(IMGUI_INCLUDE_DIR  "${PROJECT_SOURCE_DIR}/Deps/ImGui")

# Find Dependencies ############################################################

find_package(Freetype REQUIRED)
find_package(glfw3    REQUIRED)
find_package(OpenGL   REQUIRED)
find_package(spdlog   REQUIRED)

# Targets ######################################################################

add_executable(
	${PROJECT_NAME}
	${SRC_FILES}
	${IMGUI_SRC_FILES}
	${GLAD_SRC}
)

include_directories(
	${Freetype_INCLUDE_DIRS}
	${glfw3_INCLUDE_DIR}
	${OpenGL_INCLUDE_DIR}
	# In /Deps
	${GLAD_INCLUDE_DIR}
	${GLM_INCLUDE_DIR}
	${IMGUI_INCLUDE_DIR}
)


if (WIN32)
    target_link_libraries(
		${PROJECT_NAME}
		${GLFW3_LIBRARY}
		${Freetype_LIBRARY}
	)
# Linux
elseif (UNIX AND NOT APPLE)
    target_link_libraries(
		${PROJECT_NAME}
		-lpthread
		-ldl
		glfw
		${Freetype_LIBRARY}
		${OPENGL_LIBRARIES}
	)
elseif (APPLE)
	    target_link_libraries(
		${PROJECT_NAME}
		-lpthread
		-ldl
		"-framework IOKit"
		"-framework AppKit"
		"-framework OpenGL"
		"-framework CoreFoundation"
		"-framework Carbon"
		glfw
		${Freetype_LIBRARY}
	)
endif()

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Resources"
    "${CMAKE_CURRENT_BINARY_DIR}"
)
