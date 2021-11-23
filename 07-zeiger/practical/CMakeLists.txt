project(gip-07-practical)

add_executable(encrypt
	common/common.c
	common/common.h
	vigenere/vigenere.c
	vigenere/vigenere.h
	encrypt.c)
