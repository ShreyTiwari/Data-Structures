a.out: bst_client.o bst_impl.o
	gcc bst_client.o bst_impl.o

bst_client.o: bst_client.c bst.h
		gcc -c bst_client.c

bst_impl.o: bst_impl.c bst.h
		gcc -c bst_impl.c
