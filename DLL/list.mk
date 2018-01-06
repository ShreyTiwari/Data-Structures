a.out : list_client.o list_impl.o
		gcc list_client.o list_impl.o

list_client.o : list_client.c list.h
		gcc -c list_client.c

list_impl.o : list_impl.c list.h
		gcc -c list_impl.c
