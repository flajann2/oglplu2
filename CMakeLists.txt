# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5)
if(POLICY CMP0054)
	cmake_policy(SET CMP0054 NEW)
endif()

if(POLICY CMP0056)
	cmake_policy(SET CMP0056 NEW)
endif()

if(POLICY CMP0066)
	cmake_policy(SET CMP0066 NEW)
endif()

if(POLICY CMP0067)
	cmake_policy(SET CMP0067 NEW)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX d)

project(OGLplus)

file(READ VERSION OGLPLUS_VERSION)

include(config/Defaults.cmake)

if(NOT ${CONFIG_INFO_ONLY})
	include(config/BuildType.cmake)
	include(config/StaticAnalysis.cmake)
	include(config/Compiler.cmake)
	include(config/CppFeature.cmake)
	include(config/LowProfile.cmake)
	include(config/Jobs.cmake)
endif()

include(config/Tools.cmake)

include(FindPkgConfig)
include(config/CommonFindMod.cmake)

# GL-libraries
include(config/FindGL.cmake)
include(config/FindGLES3.cmake)
include(config/FindGLEW.cmake)
include(config/FindGL3W.cmake)

include(config/FindGLX.cmake)
include(config/FindGLFW.cmake)
include(config/FindGLFW3.cmake)
include(config/FindGLUT.cmake)
include(config/FindSDL.cmake)
include(config/FindWXGL.cmake)

include(config/FindGLM.cmake)

# PNG
include(config/FindPNG.cmake)

# EGL
include(config/FindEGL.cmake)

# OpenAL
include(config/FindAL.cmake)

# setting up executable requirements
include(config/ExeRequirements.cmake)

# configure GL API and Context-init libraries
include(config/ConfigGL.cmake)

# if we only want the configuration info
if(${CONFIG_INFO_ONLY})
	add_subdirectory("config")
	return()
endif()

# now create the site-configuration headers
include(config/SiteConfig.cmake)

include_directories("${PROJECT_BINARY_DIR}/include")
include_directories("include")
include_directories("implement")
include_directories("third_party/include")
include_directories("third_party/GSL/include")

# common functions for GL version and extension detection
include(config/GLVerFeat.cmake)
# GL version detection
include(config/GLVer.cmake)
# GL feature detection
include(config/GLFeat.cmake)

# re-create the site-configuration header
include(config/SiteConfig.cmake)

# tools, textures, etc.
if(NOT ${NO_EXAMPLES})
	add_subdirectory("source")
endif()

# examples
if(NOT ${NO_EXAMPLES})
	add_subdirectory("example")
endif()

# tests
if(NOT ${NO_TESTS})
	add_subdirectory("test")
endif()

# installation
include(config/Installation.cmake)
