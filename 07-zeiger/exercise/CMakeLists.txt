project(gip-07-exercise)

add_executable(main
 	main.c)

add_library(my_string
	my_string/my_string.c)

target_link_libraries(main
	my_string)
