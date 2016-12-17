#include "assoc.h"

AssocTab::AssocTab (){
	head = NULL;
}

AssocTab::AssocTab(const AssocTab &x){
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

AssocTab::~AssocTab(){
	clear();
}

void AssocTab::clear(){
	while(head){
		node *temp = head->next;
		delete head;
		head = temp;
	}
}

void AssocTab::insert(const char *key, int value){
	node *n = new node(key);
	n->next = head; 
	head = n;
	head->val = value;
}

void AssocTab::swap (AssocTab &x){
	node *temp = head;
	head = x.head;
	x.head = temp;
}

AssocTab& AssocTab::operator= (const AssocTab &x){
	if(&x == this)
		return *this;
	
	AssocTab temp (x);
	swap (temp);
	
	return *this;
}

int& AssocTab::operator[] (const char *key){
	node *x = find (key);
	if(!x){
		insert(key, 0);
		x = head;
	}
	
	return x->val;
}

AssocTab::node* AssocTab::find(const char *key) const{
	node *x = head;
	
	while(x){
		if(!strcmp(x->key, key))
			return x;
		x = x->next;
	};
	
	return NULL;
}
