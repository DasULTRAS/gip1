project(gip-06-assignment)

add_library(my_math
	my_math/my_math.c)
add_library(my_string
	my_string/my_string.c)

add_executable(main
	main.c)

target_link_libraries(main
  	my_math
	my_string)
