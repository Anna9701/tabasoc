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
        if(porownaj(x->key, key))
			return x;
		x = x->next;
	};
	
	return NULL;
}

bool AssocTabR::porownaj(const char *key1, const char *key2)const{
    if(!strcmp(key1, key2))
        return true;
    else
        return false;
}

bool AssocTabN::porownaj(const char *key1, const char *key2) const {
	int i=0;

    /*if(strlen(key1) != strlen(key2))
        return false;*/

    while(key1[i] != '\0'){
        if(toupper(key1[i]) != toupper(key2[i]))
            return false;
		++i;
	}
	
    return true;
}
		




