cmake_minimum_required( VERSION 3.19 )
project( plato )

# Qt cmake (jiaheng 2021.07.15)
set( CMAKE_PREFIX_PATH D:/dev/Qt/6.1.2/mingw81_64/lib/cmake )

# vulkan (jiaheng 2021.07.16)
set( VULKAN_HOME D:/dev/VulkanSDK/1.2.182.0 )

set( Vulkan_INCLUDE_DIR ${VULKAN_HOME}/Include )
set( Vulkan_LIBRARY ${VULKAN_HOME}/Lib )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )
set( CMAKE_AUTOUIC ON )

set( QT_VERSION 6 )
set( REQUIRED_LIBS Core Gui Widgets )
set( REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/bin )

add_executable( ${PROJECT_NAME} main.cpp )

if ( NOT CMAKE_PREFIX_PATH )
    message( WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)" )
endif ()

find_package( Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED )
target_link_libraries( ${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} )
if ( WIN32 )
    set( DEBUG_SUFFIX )
    #    if ( CMAKE_BUILD_TYPE MATCHES "Debug" )
    #        set( DEBUG_SUFFIX "d" )
    #    endif ()
    set( QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}" )
    if ( NOT EXISTS "${QT_INSTALL_PATH}/bin" )
        set( QT_INSTALL_PATH "${QT_INSTALL_PATH}/.." )
        if ( NOT EXISTS "${QT_INSTALL_PATH}/bin" )
            set( QT_INSTALL_PATH "${QT_INSTALL_PATH}/.." )
        endif ()
    endif ()
    if ( EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll" )
        add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/" )
        add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/" )
    endif ()
    foreach ( QT_LIB ${REQUIRED_LIBS} )
        add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>" )
    endforeach ( QT_LIB )
endif ()

include_directories(
        include
)

function( gtest_folder name main )
    aux_source_directory( ${name} DIR_${name} )
    add_executable( ${name} ${main} ${DIR_${name}} )

    set( INDEX 2 )
    while ( INDEX LESS ${ARGC} )
        target_link_libraries( ${name} ${ARGV${INDEX}} )
        math( EXPR INDEX "${INDEX} + 1" )
    endwhile ()
endfunction()

add_subdirectory( test )
