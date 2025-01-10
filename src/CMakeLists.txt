cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(AUTO_LOAD_VULKAN ON)

message("CMAKE_CURRENT_DIR:${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/glfw3/include)

# ##################################
# 查找Vulkan位置并设置
# ##################################
set(VULKAN_PATH "")
set(VULKAN_INCLUDE "")
set(VULKAN_LIBS "vulkan.1")

if (AUTO_LOAD_VULKAN MATCHES ON)
    MESSAGE(STATUS "start find package of vulkan...")
    # 查询vulkan包
    find_package(Vulkan)
    # 检查是否查询到Vulkan库了
    if (NOT ${Vulkan_INCLUDE_DIRS} STREQUAL "")
        set(VULKAN_PATH ${Vulkan_INCLUDE_DIRS})
        message(STATUS "vulkan path=======>${Vulkan_INCLUDE_DIRS}")
        set(VULKAN_INCLUDE ${Vulkan_INCLUDE_DIRS})
        # 将路径中的/include替换掉，得到VulkanSDK根目录
        #STRING(REGEX REPLACE "/Include" "" VULKAN_PATH ${VULKAN_PATH})
        # 打印vulkan目录结构信息
        MESSAGE(STATUS "Set VulkanSDK location and libs path: ")
        MESSAGE(STATUS "    VulkanSDK Path: ${VULKAN_PATH}")
        MESSAGE(STATUS "    VulkanSDK Include: ${VULKAN_INCLUDE}")
    else()
        # 没找到VulkanSDK
        MESSAGE(STATUS "Cannot found VulkanSDK folder, please make sure your installed VulkanSDK and try again...")
        return()
    endif()
endif()
message(STATUS "vulkan path:${VULKAN_PATH}")
message(STATUS "vulkan lib path:${VULKAN_LIBS}")
# 设置头文件
include_directories(${VULKAN_INCLUDE})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/glfw3/lib-universal;${VULKAN_PATH}/../Lib)

add_library(comp_shader SHARED graph/comp_shader.cpp)  # 这里应该列出构成库的所有源文件
# 链接 comp_shader 库到 testshader 可执行文件
target_link_libraries(comp_shader glfw.3 ${VULKAN_LIBS} )


