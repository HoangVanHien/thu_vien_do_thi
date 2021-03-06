# Install script for directory: /home/kawasemi/ALL/cgraph/ctc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bkc/ctc" TYPE FILE FILES
    "/home/kawasemi/ALL/cgraph/ctc/array.h"
    "/home/kawasemi/ALL/cgraph/ctc/common.h"
    "/home/kawasemi/ALL/cgraph/ctc/deque.h"
    "/home/kawasemi/ALL/cgraph/ctc/hashset.h"
    "/home/kawasemi/ALL/cgraph/ctc/hashtable.h"
    "/home/kawasemi/ALL/cgraph/ctc/list.h"
    "/home/kawasemi/ALL/cgraph/ctc/pqueue.h"
    "/home/kawasemi/ALL/cgraph/ctc/queue.h"
    "/home/kawasemi/ALL/cgraph/ctc/ring_buffer.h"
    "/home/kawasemi/ALL/cgraph/ctc/slist.h"
    "/home/kawasemi/ALL/cgraph/ctc/stack.h"
    "/home/kawasemi/ALL/cgraph/ctc/treeset.h"
    "/home/kawasemi/ALL/cgraph/ctc/treetable.h"
    "/home/kawasemi/ALL/cgraph/ctc/tsttable.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bkc/ctc/my" TYPE FILE FILES "/home/kawasemi/ALL/cgraph/ctc/my/hsi.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/kawasemi/ALL/Run/cgraph/ctc/libcollectc.a")
endif()

