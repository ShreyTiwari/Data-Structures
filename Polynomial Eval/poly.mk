a.out: poly_client.o poly_impl.o
		gcc poly_client.o poly_impl.o

poly_client.o: poly_client.c poly.h
		gcc -c poly_client.c

poly_impl.o: poly_impl.c poly.h
		gcc -c poly_impl.c