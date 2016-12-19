#ifndef ASSOC_H_
    #define ASSOC_H_
    #include <iostream>
    #include <cstdlib>
    #include <string.h>
    #include <string>
    #include <cctype>
    using namespace std;

	class AssocTabR{
    public:
		AssocTabR();
		AssocTabR(const AssocTabR &);
		virtual ~AssocTabR();

		AssocTabR& operator= (const AssocTabR&);
		int& operator[](const char*);
	    
    protected:
		struct node;
        node *head;

	   	void clear();
		void swap(AssocTabR &);
        virtual bool porownaj(const char*, const char*)const;
        void insert (const char *, int);
        node* find (const char *) const;
	};

	struct AssocTabR::node{
	    node *next;
	    char *key;
	    int val;

	    node(const char *k): next(NULL){
		key = new char[strlen(k)+1];
		strcpy(key, k);
	    }
	    
	    node (const node &x): next(NULL){
		if(x.key == NULL)
			key = NULL;
		else{
			key = new char[strlen(x.key) + 1];
			strcpy(key, x.key);
		}
		val = x.val;
	    } 
	    ~node(){delete [] key;}
	    
            private:
		node &operator=(const node &);
	};

	class AssocTabN :public AssocTabR{
		private:
            virtual bool porownaj(const char*, const char*)const;
	};
#endif
