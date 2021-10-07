INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_ATTACK attack)

FIND_PATH(
    ATTACK_INCLUDE_DIRS
    NAMES attack/api.h
    HINTS $ENV{ATTACK_DIR}/include
        ${PC_ATTACK_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    ATTACK_LIBRARIES
    NAMES gnuradio-attack
    HINTS $ENV{ATTACK_DIR}/lib
        ${PC_ATTACK_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/attackTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ATTACK DEFAULT_MSG ATTACK_LIBRARIES ATTACK_INCLUDE_DIRS)
MARK_AS_ADVANCED(ATTACK_LIBRARIES ATTACK_INCLUDE_DIRS)
