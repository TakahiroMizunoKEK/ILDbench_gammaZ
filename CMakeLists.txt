########################################################
# cmake file for building ILDbench_tautau analysis package
# @author Ete Remi, DESY
CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
########################################################

# project name
PROJECT( zhllx )

# project version
SET( ${PROJECT_NAME}_VERSION_MAJOR 1 )
SET( ${PROJECT_NAME}_VERSION_MINOR 0 )
SET( ${PROJECT_NAME}_VERSION_PATCH 0 )

### DEPENDENCIES ############################################################


FIND_PACKAGE( ILCUTIL REQUIRED COMPONENTS ILCSOFT_CMAKE_MODULES )
FIND_PACKAGE( ROOT REQUIRED COMPONENTS TMVA )

INCLUDE_DIRECTORIES( ${ROOT_INCLUDE_DIRS} )
LINK_LIBRARIES( ${ROOT_LIBRARIES} )
ADD_DEFINITIONS( ${ROOT_DEFINITIONS} )

# load default settings from ILCSOFT_CMAKE_MODULES
INCLUDE( ilcsoft_default_settings )


FIND_PACKAGE( Marlin 1.0 REQUIRED ) # minimum required Marlin version
INCLUDE_DIRECTORIES( ${Marlin_INCLUDE_DIRS} )
LINK_LIBRARIES( ${Marlin_LIBRARIES} )
LINK_LIBRARIES( ${ROOT_TMVA_LIBRARY} )
ADD_DEFINITIONS( ${Marlin_DEFINITIONS} )

#INCLUDE_DIRECTORIES( ${ROOT_INCLUDE_DIRS} )

#INCLUDE_DIRECTORIES( /home/ilc/tianjp/analysis/PostDBD/physsim-svn/Physsim/trunk/include )
INCLUDE_DIRECTORIES( /home/ilc/tianjp/analysis/PostDBD/MEM-develop/include )

# Compile you project
ADD_SUBDIRECTORY( source )

# display some variables and write them to cache
DISPLAY_STD_VARIABLES()
