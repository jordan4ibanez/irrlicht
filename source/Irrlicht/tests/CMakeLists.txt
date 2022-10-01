find_package(doctest)

add_executable(test
	inMemoryFile.cpp inMemoryFile.h
	testCOBJMeshFileLoader.cpp
)

target_link_libraries(test
	PRIVATE
		doctest::doctest
		IrrlichtMt::IrrlichtMt
)

target_compile_options(test
	PRIVATE
	"$<$<CXX_COMPILER_ID:GNU>:-Wall;-Wextra;-Wnon-virtual-dtor;-pedantic>"
)
