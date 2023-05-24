#*******************************************************************************
# Copyright (c) 2011 - 2018 AIT, ACIN, Profactor GmbH, fortiss GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#
#
# *******************************************************************************/

#forte_add_module(ROS "Function Blocks to communicate with ROS (publish/subscribe)")


forte_add_module(ALPHABOT ON "Function Blocks to communicat Alphabot FBs")

if (FORTE_MODULE_ALPHABOT)


#############################################################################
# FORTE UTILITY FBs
#############################################################################

if(NOT "${FORTE_ARCHITECTURE}" STREQUAL "VxWorks") #the compiler used to test vxworks doesn't support ++11
  if(CYGWIN)
    forte_add_definition("-std=gnu++11") 
  else(CYGWIN)
    forte_add_definition("-std=c++11")
  endif(CYGWIN)

#  forte_add_sourcefile_hcpp(E_STOPWATCH)
endif(NOT "${FORTE_ARCHITECTURE}" STREQUAL "VxWorks")



include_directories(include)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

forte_add_sourcefile_hcpp(AB_BACKWORD AB_CMDPARSER AB_FORWARD AB_LEFT AB_RIGHT AB_STOP gpioutils)

endif(FORTE_MODULE_ALPHABOT)

