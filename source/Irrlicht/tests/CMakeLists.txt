find_package(doctest)

add_executable(test
	test.cpp
)

target_link_libraries(test
	PRIVATE
		doctest::doctest
		IrrlichtMt::IrrlichtMt
)
