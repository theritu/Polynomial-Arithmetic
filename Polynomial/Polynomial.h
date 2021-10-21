#include "Terms.h"
#include "Node.h"

class Polynomial {
private:
	Node<Terms>* start;
	int numOfTerms;
    int degreeOfPolynomial;
public:
    Polynomial(){
        start = nullptr;
        numOfTerms = 0;
    };
	Polynomial(int);
    Polynomial(Terms *T , int numOfTerms){
        start = nullptr;
        this->numOfTerms = 0;
        for (int i =  0 ; i < numOfTerms ; i++){
            Node<Terms> *t = new Node<Terms>;
            t->setData(T[i]);
            t->setNext(nullptr);
            insert(t);
        }
    }
	Polynomial(Polynomial&);
	Polynomial(Polynomial&&);
	Polynomial& operator =(Polynomial&);
	Polynomial& operator =(Polynomial&&);
    Polynomial& operator +(Polynomial&);
    Polynomial& operator -(Polynomial&);
    Polynomial& operator *(Polynomial&);
    Node<Terms>& operator [](int i);
    friend ostream& operator<< (ostream& out, Polynomial& other){
        Node<Terms>* t ;
        t = other.start;
        int i = 0;
        while(t){
            
            if (t->getData().getExponent()){
                if ( t->getData().getCoefficient() > 0 && t != other.start)
                    cout <<" + "<<t->getData().getCoefficient()<<"x^"<<t->getData().getExponent();
                else{
                    cout <<t->getData().getCoefficient()<<"x^"<<t->getData().getExponent();
                }
            }
            else {
                if (t->getData().getCoefficient() > 0 && t != other.start)
                    cout <<" + "<<t->getData().getCoefficient();
                else{
                    cout <<t->getData().getCoefficient();
                }
            }
            t = t->getNext();
        
        }
        return out;
    }
	int length();
	void append(Node<Terms>*);
    void insert(Node<Terms>*);
    void showPolynomial();
    void updateNode(Node<Terms>);
    Polynomial& updatePolynomial(function<int(int,int)> ,function<int(int,int)>, Node<Terms> , Polynomial&);
    void add(Polynomial&,Polynomial&);
    void subtract(Polynomial&,Polynomial&);
    void multiply(Polynomial&,Polynomial&);
	~Polynomial();
};

#include "Polynomial.tcc"