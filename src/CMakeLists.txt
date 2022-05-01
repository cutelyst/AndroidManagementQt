# SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
# SPDX-License-Identifier: MIT

set(android_management_SRC
    androidmanagement.cpp
    androidmanagementpolicy.cpp
    googlecloudoauth2.cpp
)

set(android_management_HEADERS
    androidmanagementexports.h
    androidmanagement.h
    androidmanagementpolicy.h
    googlecloudoauth2.h
)

set(android_management_HEADERS_PRIVATE
#     common.h
)

add_library(AndroidManagementQt${QT_VERSION_MAJOR}
    ${android_management_SRC}
    ${android_management_HEADERS}
    ${android_management_HEADERS_PRIVATE}
)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(AndroidManagementQt${QT_VERSION_MAJOR}::Core ALIAS AndroidManagementQt${QT_VERSION_MAJOR})

if (CMAKE_GENERATOR MATCHES "Visual Studio")
  set_property(TARGET AndroidManagementQt${QT_VERSION_MAJOR} PROPERTY DEBUG_POSTFIX "d")
endif()

target_compile_definitions(AndroidManagementQt${QT_VERSION_MAJOR}
  PRIVATE
    PLUGINS_PREFER_DEBUG_POSTFIX=$<CONFIG:Debug>
)

target_include_directories(AndroidManagementQt${QT_VERSION_MAJOR} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/android-management-qt${QT_VERSION_MAJOR}/AndroidManagementQt>
)

set_target_properties(AndroidManagementQt${QT_VERSION_MAJOR} PROPERTIES
    EXPORT_NAME Core
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
)

target_link_libraries(AndroidManagementQt${QT_VERSION_MAJOR}
    PUBLIC
        Qt${QT_VERSION_MAJOR}::Network
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        jwt-cpp::jwt-cpp
)

set_property(TARGET AndroidManagementQt${QT_VERSION_MAJOR} PROPERTY PUBLIC_HEADER ${android_management_HEADERS})
install(TARGETS AndroidManagementQt${QT_VERSION_MAJOR}
    EXPORT AndroidManagementTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION bin COMPONENT runtime
    ARCHIVE DESTINATION lib COMPONENT devel
    PUBLIC_HEADER DESTINATION include/android-management-qt${QT_VERSION_MAJOR}/AndroidManagementQt COMPONENT devel
)
