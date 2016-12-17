#ifndef ASSOC_H_
    #define ASSOC_H_
    #include <iostream>
    #include <cstdlib>
    #include <string.h>
    #include <string>
    #include <cctype>
    using namespace std;

	class AssocTab{
	    public:
		AssocTab();
		AssocTab(const AssocTab &);
		~AssocTab();

		AssocTab& operator= (const AssocTab&);
		int& operator[](const char*);
	    private:
		struct node;
                node *head;
		
		void insert (const char *, int);
		void clear ();
		node* find (const char *) const;
		void swap (AssocTab &);
	};

	struct AssocTab::node{
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


#endif
