cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
project(rtcpcl)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
include(${PROJECT_SOURCE_DIR}/cmake/rtcpcl_utils.cmake)

# Set version and OS-specific settings
set(RTC_VERSION 1.0.0 CACHE STRING "RTC:PCL version")
DISSECT_VERSION()
SET_DEST_DIRS()

# Add an "uninstall" target
CONFIGURE_FILE ("${PROJECT_SOURCE_DIR}/cmake/uninstall_target.cmake.in"
    "${PROJECT_BINARY_DIR}/uninstall_target.cmake" IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET (uninstall "${CMAKE_COMMAND}" -P
    "${PROJECT_BINARY_DIR}/uninstall_target.cmake")

# Get necessary dependency information
find_package(OpenRTM HINTS /usr/lib64/openrtm-1.1/cmake)
if(${OpenRTM_FOUND})
  MESSAGE(STATUS "OpenRTM configuration Found")
else(${OpenRTM_FOUND})
  message(STATUS "Use cmake/Modules/FindOpenRTM.cmake in the project")
  list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
  find_package(OpenRTM REQUIRED)
endif(${OpenRTM_FOUND})
find_package(PCL 1 REQUIRED)
find_package(Boost 1.42.0 REQUIRED regex)
find_package(wxWidgets)

# Compilation options
#option(CORBA_SUPPORT "Include support for CORBA-based ports" TRUE)
set(CORBA_SUPPORT TRUE)
option(DDS_SUPPORT "Include support for DDS-based ports" FALSE)
if(DDS_SUPPORT)
    find_package(DDS 4.5 REQUIRED)
    find_package(RTMDDS 1 REQUIRED)
endif(DDS_SUPPORT)

# Component selection
option(BUILD_RTCPCDBENCHMARK "Build the RTCPCDBenchmark component" TRUE)
option(BUILD_RTCPCLCUBOID "Build the RTCPCLCuboid component" TRUE)
option(BUILD_RTCPCDLOAD "Build the RTCPCDLoad component" TRUE)
option(BUILD_RTCPCDSAVE "Build the RTCPCDSave component" TRUE)
option(BUILD_RTCPCLNORMALS "Build the RTCPCLNormals component" TRUE)
option(BUILD_RTCPCLOPENNI
    "Build the RTCPCLOpenNI component (PCL must have OpenNI support included)"
    FALSE)
option(BUILD_RTCPCLPASSTHROUGH "Build the RTCPCLPassthrough component" TRUE)
option(BUILD_RTCPCLPLANESEGMENTATION
    "Build the RTCPCLPlaneSegmentation component" TRUE)
option(BUILD_RTCPCLRAINBOWTUBE "Build the RTCPCLRainbowTube component" TRUE)
option(BUILD_RTCPCLVOXELFILTER "Build the RTCPCLVoxelFilter component" TRUE)
option(BUILD_RTCPCLVIEWER "Build the RTCPCLViewer component" TRUE)
option(BUILD_RTCRIVIEWER "Build the RTCRIViewer component" TRUE)

add_definitions(${OPENRTM_CFLAGS})
add_definitions(${OMNIORB_CFLAGS})
add_definitions(-DNOMINMAX)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR}/include)

set(DEPS_INCLUDE_DIRS ${OPENRTM_INCLUDE_DIRS}
    ${OMNIORB_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS}
    ${DDS_INCLUDE_DIRS} ${RTMDDS_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
set(DEPS_LIBRARIES ${OPENRTM_LIBRARIES} ${PCL_LIBRARIES} ${DDS_LIBRARIES}
    ${RTMDDS_LIBRARIES} ${Boost_LIBRARIES})
set(DEPS_LIBRARY_DIRS ${OPENRTM_LIBRARY_DIRS}
    ${OMNIORB_LIBRARY_DIRS} ${PCL_LIBRARY_DIRS} ${DDS_LIBRARY_DIRS}
    ${RTMDDS_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

# Subdirectories
add_subdirectory(cmake)
add_subdirectory(doc)
add_subdirectory(examples)
add_subdirectory(pc_type)
add_subdirectory(include)
add_subdirectory(rtcpclbase)
if(BUILD_RTCPCDBENCHMARK)
    add_subdirectory(rtcpcdbenchmark)
endif(BUILD_RTCPCDBENCHMARK)
if(BUILD_RTCPCLCUBOID)
    add_subdirectory(rtcpclcuboid)
endif(BUILD_RTCPCLCUBOID)
if(BUILD_RTCPCDLOAD)
    add_subdirectory(rtcpcdload)
endif(BUILD_RTCPCDLOAD)
if(BUILD_RTCPCDSAVE)
    add_subdirectory(rtcpcdsave)
endif(BUILD_RTCPCDSAVE)
if(BUILD_RTCPCLNORMALS)
    add_subdirectory(rtcpclnormals)
endif(BUILD_RTCPCLNORMALS)
if(BUILD_RTCPCLOPENNI)
    add_subdirectory(rtcpclopenni)
endif(BUILD_RTCPCLOPENNI)
if(BUILD_RTCPCLPASSTHROUGH)
    add_subdirectory(rtcpclpassthrough)
endif(BUILD_RTCPCLPASSTHROUGH)
if(BUILD_RTCPCLPLANESEGMENTATION)
    add_subdirectory(rtcpclplanesegmentation)
endif(BUILD_RTCPCLPLANESEGMENTATION)
if(BUILD_RTCPCLRAINBOWTUBE)
    add_subdirectory(rtcpclrainbowtube)
endif(BUILD_RTCPCLRAINBOWTUBE)
if(BUILD_RTCPCLVOXELFILTER)
    add_subdirectory(rtcpclvoxelfilter)
endif(BUILD_RTCPCLVOXELFILTER)
if(BUILD_RTCPCLVIEWER)
    add_subdirectory(rtcpclviewer)
endif(BUILD_RTCPCLVIEWER)
if(BUILD_RTCRIVIEWER)
    if (wxWidgets_FOUND)
        add_subdirectory(rtcriviewer)
    else (wxWidgets_FOUND)
        message(STATUS "wxWidgets was not found - cannot build RTCRIViewer")
    endif (wxWidgets_FOUND)
endif(BUILD_RTCRIVIEWER)

# Package creation
include(InstallRequiredSystemLibraries)
set(RTC_DESCRIPTION "RT-Components for PCL.")
set(RTC_VENDOR "Geoffrey Biggs, AIST")
configure_file("${PROJECT_SOURCE_DIR}/cmake/cpack_options.cmake.in"
    "${PROJECT_BINARY_DIR}/cpack_options.cmake" @ONLY)
set(CPACK_PROJECT_CONFIG_FILE "${PROJECT_BINARY_DIR}/cpack_options.cmake")
include(CPack)

