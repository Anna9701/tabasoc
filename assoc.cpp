#include "assoc.h"

AssocTabR::AssocTabR (){
	head = NULL;
}

AssocTabR::AssocTabR(const AssocTabR &x){
	node *src, **dst;
	head = NULL;
	src = x.head;
	dst = &head;
	
	try{
		while(src){
			*dst = new node(*src);
			src = src->next;
			dst = &((*dst)->next);
		}
	}catch(...){
		clear ();
		throw;
	}
}

AssocTabR::~AssocTabR(){
	clear();
}

void AssocTabR::clear(){
	while(head){
		node *temp = head->next;
		delete head;
		head = temp;
	}
}

void AssocTabR::insert(const char *key, int value){
	node *n = new node(key);
	n->next = head; 
	head = n;
	head->val = value;
}

void AssocTabR::swap (AssocTabR &x){
	node *temp = head;
	head = x.head;
	x.head = temp;
}

AssocTabR& AssocTabR::operator= (const AssocTabR &x){
	if(&x == this)
		return *this;
	
	AssocTabR temp (x);
	swap (temp);
	
	return *this;
}

int& AssocTabR::operator[] (const char *key){
	node *x = find (key);
	if(!x){
		insert(key, 0);
		x = head;
	}
	
	return x->val;
}

AssocTabR::node* AssocTabR::find(const char *key) const{
	node *x = head;
	
	while(x){
		if(!strcmp(x->key, key))
			return x;
		x = x->next;
	};
	
	return NULL;
}

char* AssocTabN::konwert(const char *key) const {
	int i=0;
	char *newkey = new char [strlen(key)+1];
 
	while(key[i] != '\0'){
		newkey[i] = toupper(key[i]);
		++i;
	}
	newkey[i] = '\0';
	
	return newkey;
}
		
void AssocTabN::insert(const char *key, int value){
	char *newkey = konwert(key);
	AssocTabR::insert(newkey, value);

	delete [] newkey;
}

AssocTabR::node* AssocTabN::find(const char *key)const{
	char *newkey = konwert(key); 
	
	node *x = AssocTabR::find(newkey);
	delete []newkey; 
	
	return x; 
}

int& AssocTabN::operator[](const char *key){
	node *x = find(key);
	if(!x){
		insert(key, 0);
		x = head;
	}
	return x->val;
}

