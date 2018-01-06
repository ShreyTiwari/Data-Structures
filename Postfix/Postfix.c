#include <stdio.h>
#include <stdlib.h>

typedef struct list s_list;
typedef struct node node;

struct list {
	node *head;
	int number_of_nodes;
};

/* initializes a linked list */
void list_initialize(s_list* list); 

void list_insert_front(s_list* list, int data);

/* Inserts data at specified position 0 <= position < length(list). 
 * Returns position if insertion is successful, else -1
 */
int list_insert_at(s_list* list, int data, int position); 

void list_delete_front(s_list *list);

/* Returns pointer to the node at specified index, if 0 <= index < length(list).
 * Returns NULL otherwise
 */
node* list_get(s_list *list, int index);

/* Returns the element that (*node_ptr) contains */
const int node_get_data(node* node_ptr);

/* Removes the last node of the linked list */
void list_delete_rear(s_list* list); 

void list_reverse(s_list* list);
void list_print(s_list* list); 

/* deallocates resources held by the list */
void list_destroy(s_list* list); 

typedef struct {
	s_list *ptr_list;	
} stack;

void stack_initialize(stack* ptr_stack);
void stack_push(stack* ptr_stack, int data);
void stack_pop(stack* ptr_stack);
int stack_is_empty(stack* ptr_stack);
const int stack_peek(stack* ptr_stack);
void stack_destroy(stack* ptr_stack);

/* The implementations for the above function declarations have been supplied to you, below main() */

void convert_infix_to_postfix(const char * source_infix, char * target_postfix);

/* Provide suitable implementation for converting an infix expression to postfix expression */

int main() {
	char source_infix[2000];
	char target_postfix[2000];
	int number_of_inputs = 0;
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) {
		scanf("%s", source_infix);
		convert_infix_to_postfix(source_infix, target_postfix);
		printf("%s\n", target_postfix);
	}
	return 0;
}

struct node {
	int data;
	node *link;
};

static node* create_node(int data, node* link) {
	node* temp =  (node*)malloc(sizeof(node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void list_initialize(s_list* ptr_list) {
	ptr_list -> head = NULL;
	ptr_list -> number_of_nodes = 0;
}

void list_insert_front(s_list* ptr_list, int data) {
	node *new_node = create_node(data, ptr_list -> head);
	ptr_list -> head = new_node;
	++ ptr_list -> number_of_nodes;
}

int list_insert_at(s_list* ptr_list, int data, int position) {		
	if(ptr_list -> number_of_nodes == 0 || position < 0 || position > (ptr_list -> number_of_nodes -1))
		return -1;
	
	node *new_node = NULL;	
	node *previous_node = NULL;
	node *current_node = ptr_list -> head;
	
	for(int counter = 0; counter < position; ++counter) {
		previous_node = current_node;
		current_node = current_node -> link;
	}
	
	new_node = create_node(data, current_node);
	if(previous_node != NULL)
		previous_node -> link = new_node;
	++ ptr_list -> number_of_nodes;	
	
	return position;
}

node* list_get(s_list *ptr_list, int index) {
	if(ptr_list -> number_of_nodes == 0 || index < 0 || index > (ptr_list -> number_of_nodes -1))
		return NULL;
	node *node_ptr = ptr_list -> head;
	for(int counter = 0; counter < index; ++ counter)
		node_ptr = node_ptr -> link;
	return node_ptr; 
}

const int node_get_data(node *node_ptr) {
	return node_ptr -> data;
}

void list_delete_front(s_list* ptr_list) {
	if(ptr_list -> number_of_nodes == 0) 
		return;
	node *node_ptr = ptr_list -> head;
	ptr_list -> head = node_ptr -> link;
	free(node_ptr);
	-- ptr_list -> number_of_nodes;
}

void list_delete_rear(s_list* ptr_list) {
	if(ptr_list -> number_of_nodes == 0) 
		return;
	node *node_ptr = (node*)malloc(sizeof(node));
	node_ptr -> link = ptr_list -> head;	
	
	for(int counter = 0; counter < (ptr_list -> number_of_nodes - 1); ++counter)
		node_ptr = node_ptr -> link;
	
	free(node_ptr -> link);
	node_ptr -> link = NULL;
	-- ptr_list -> number_of_nodes;
	if(ptr_list -> number_of_nodes == 0)
		ptr_list -> head = NULL;
}

void list_reverse(s_list* ptr_list) {
	node* prev = NULL;
	node* pres = ptr_list -> head;
	node* temp = NULL;
	while(pres != NULL) {
		temp = pres -> link;
		pres -> link = prev;
		prev = pres;
		pres = temp;
	}
	ptr_list -> head = prev;	
}

void list_print(s_list* ptr_list) {
	node* temp = ptr_list -> head;
	while(temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> link;
	}
}

void list_destroy(s_list* ptr_list) {
	while(ptr_list -> head != NULL) {
		node* temp = ptr_list -> head;
		ptr_list -> head = temp -> link;
		free(temp);
	}
	ptr_list -> number_of_nodes = 0;
}

void stack_initialize(stack *ptr_stack) {
	ptr_stack -> ptr_list = (s_list*)malloc(sizeof(s_list));
	list_initialize(ptr_stack -> ptr_list);
}

void stack_push(stack *ptr_stack, int key) {
	list_insert_front(ptr_stack -> ptr_list, key);
}

void stack_pop(stack *ptr_stack) {
	list_delete_front(ptr_stack -> ptr_list);
}

int stack_is_empty(stack *ptr_stack) {
	return ptr_stack-> ptr_list -> number_of_nodes == 0;
}

const int stack_peek(stack *ptr_stack) {
	return node_get_data(list_get(ptr_stack -> ptr_list, 0));
}

void stack_destroy(stack *ptr_stack) {
	list_destroy(ptr_stack -> ptr_list);
	free(ptr_stack -> ptr_list);
}

int precedence(char a)
{
	if(a=='*' || a=='/')
		return 3;
	else if(a=='+' || a=='-')
		return 2;
	else
		return 1;
}


void convert_infix_to_postfix(const char *source_infix, char *target_postfix)
{
	char *s = source_infix;
	stack a,b;
	stack_initialize(&a);
	stack_initialize(&b);
	for(int i=0; i<strlen(source_infix); ++i)
	{
		if(s[i] == '(')
			stack_push(&b, s[i]);
		else if(( s[i]>= 'a' && s[i]<= 'z' ) || ( s[i]>= 'A' && s[i]<= 'Z' ))
			stack_push(&a, s[i]);
		else if(s[i] == ')')
		{
			while(stack_peek(&b)!='(')
			{
				stack_push(&a, stack_peek(&b));
				stack_pop(&b);
			}
			stack_pop(&b);
		}
		else
		{
			if(stack_is_empty(&b))
				stack_push(&b, s[i]);
			
			else if(precedence(stack_peek(&b)) >= precedence(s[i]))
			{
				stack_push(&a, stack_peek(&b));
				stack_pop(&b);
				stack_push(&b, s[i]);
			}
			
			else
				stack_push(&b, s[i]);
		}
		
	}
	
	
	while(!stack_is_empty(&b))
	{
		stack_push(&a, stack_peek(&b));
		stack_pop(&b);
	}
	stack_destroy(&b);
	stack_initialize(&b);
	while(!stack_is_empty(&a))
	{
		stack_push(&b, stack_peek(&a));
		stack_pop(&a);
	}
	
	int i =0;
	while(!stack_is_empty(&b))
	{
		target_postfix[i] = stack_peek(&b);
		stack_pop(&b);
		i++;
	}
}

