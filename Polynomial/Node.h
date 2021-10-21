
template <class Y>
class Node {
private:
	Y data;
	Node* next;
public:
	Node();
	Node(Y);
	Node(Node&);
	Node(Node&&);
	Node& operator =(Node&);
	Node& operator =(Node&&);
	void setData(Y);
	Y& getData();
	void setNext(Node*);
	Node* getNext();
    friend ostream& operator<< (ostream& out, Node& other){
        out << other.data ;
        return out;
    }
	~Node();
};

#include "Node.tcc"