a.out : stack_impl.o stack_client.o
		gcc stack_impl.o stack_client.o

stack_impl.o : stack_impl.c stack.h
		gcc -c stack_impl.c

stack_client.o : stack_client.c stack.h
		gcc -c stack_client.c
