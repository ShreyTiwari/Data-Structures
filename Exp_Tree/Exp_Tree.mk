a.out : exp_tree_client.o exp_tree_impl.o
		gcc exp_tree_client.o exp_tree_impl.o

exp_tree_client.o : exp_tree_client.c exp_tree.h
		gcc -c exp_tree_client.c

exp_tree_impl.o : exp_tree_impl.c exp_tree.h
		gcc -c exp_tree_impl.c