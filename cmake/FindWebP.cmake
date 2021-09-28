# Script to locate WebP library if installed.
#
# Sets the following variables
#
#     WebP_FOUND
#     WebP_INCLUDE_DIR
#     WebP_LIBRARY
#
# and the following imported targets
#
#     WebP::WebP.
#
# Authors: Josiah VanderZee - josiah_vanderzee@mediacombb.net

# When looking for WebP library, static library is preferred.
find_library(WebP_LIBRARY
	NAMES libwebp.a libwebp.dll libwebp.so
)

# Attempt to avoid finding the wrong encode.h, but
# we have to append /webp to the path
find_path(WebP_INCLUDE_DIR_PREFIX
	NAMES webp/encode.h
	PATH_SUFFIXES webp
)
if(WebP_INCLUDE_DIR_PREFIX)
	set(WebP_INCLUDE_DIR "${WebP_INCLUDE_DIR_PREFIX}/webp")
endif()
unset(WebP_INCLUDE_DIR_PREFIX)

# TODO Figure out a way to determine WebP version.

mark_as_advanced(WebP_FOUND WebP_LIBRARY WebP_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WebP
	REQUIRED_VARS WebP_LIBRARY WebP_INCLUDE_DIR
)

if(WebP_FOUND AND NOT TARGET WebP::WebP)
	add_library(WebP::WebP INTERFACE IMPORTED)
	# CMake 3.5 does not allow calling target_include_directories
	# to set interface properties on imported targets.
	set_target_properties(WebP::WebP PROPERTIES
		INTERFACE_LINK_LIBRARIES "${WebP_LIBRARY}"
		INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}"
	)
endif()
