
using namespace std;

Polynomial::Polynomial(int numOfTerm){
	start = nullptr;
	this->numOfTerms = numOfTerm;
    Node<Terms> *p , *temp;
    int i =  0;
    while(i< numOfTerms){
        temp = new Node<Terms>;
        if(start == nullptr){
            start = p = temp;
            i = i+1;
            continue;
        }
        p->setNext(temp);
        p = p->getNext();
        i = i+1;
    }
}


Polynomial::Polynomial(Polynomial& other){
	start = nullptr;
	numOfTerms = other.numOfTerms;
    Node<Terms> *copy , *current ;
    current = other.start;
    int i = 0 ;
    while(i < other.numOfTerms){
        copy = new Node<Terms>;
        if (start == nullptr){
            copy->setData(current->getData());
            copy->setNext(current->getNext());
            start = current ;
            current = current->getNext();
            i = i+1;
            continue;
        }
        copy->setData(current->getData());
        copy->setNext(current->getNext());
        current = current->getNext();
        
        i = i+1;
    }
}


Polynomial::Polynomial(Polynomial&& other){
	start = other.start;
	numOfTerms = other.numOfTerms;
	other.start = nullptr;
	other.numOfTerms = 0;
}
 

Polynomial& Polynomial :: operator = (Polynomial& other){
    //cout << "Inside =&"<<endl;
    //cout<<other.start->getData()<<" : B"<<endl;
    //cout << other <<endl;
    Node <Terms> *t = start;
    // while (start != nullptr){
    //     start = start->getNext();
    //     delete t;
    //     t = start;

    // }
	start = nullptr;
	numOfTerms = other.numOfTerms;
    // cout<< other.numOfTerms <<" : NO "<< endl;
    Node<Terms> *copy = nullptr , *current = nullptr ;
    current = other.start;

    //cout<<other.start->getData()<<" : C"<<endl;
    //cout<<other<<endl;
    int i = 0 ;
    while(i < other.numOfTerms){
        //cout << "Inside W"<<endl;
        //cout << current->getData() <<endl; 
        copy = new Node<Terms>;
        if (start == nullptr){
            copy->setData(current->getData());
            copy->setNext(current->getNext());
            start = current ;
            current = current->getNext();
            i = i+1;
            continue;
        }
        copy->setData(current->getData());
        copy->setNext(current->getNext());
        current = current->getNext();
        i = i+1;
    }
    //cout <<"Exiting =&"<<endl;
	return *this; 
}


Polynomial& Polynomial:: operator = (Polynomial&& other){
    //cout << "Exiting =&&"<<endl;
    if (start != nullptr)
        delete start;
	start = other.start;
	numOfTerms = other.numOfTerms;
	other.start = nullptr;
	other.numOfTerms = 0;
    //cout <<"Exiting =&&"<<endl;
	return *this; 
}

Polynomial& Polynomial:: operator + (Polynomial& other){
    Polynomial *P = new Polynomial();
    P->add(*this , other);
    return(*P);
}

Polynomial& Polynomial:: operator - (Polynomial& other){
    Polynomial *P = new Polynomial();
    P->subtract(*this , other);
    return(*P);
}

Polynomial& Polynomial:: operator * (Polynomial& other){
    Polynomial *P = new Polynomial();
    P->multiply(*this , other);
    return(*P);
}

int Polynomial :: length(){
    return numOfTerms;
}

void Polynomial:: updateNode(Node<Terms> T){
    auto add= [](int a , int b){return a+b;};
    auto mul= [](int a , int b){return a*b;};
}


void Polynomial :: append(Node<Terms>* node ){
    Node<Terms>* t;
    t = start;
    if(t != nullptr){
        
        while(t->getNext() != nullptr){
            t= t->getNext();
        }
        t->setNext(node);
    }else{
        start = node;
    }
    numOfTerms++;
}

void Polynomial :: insert(Node<Terms>* n ){
    Node<Terms>* t , *pre;
    t = start;
    pre = nullptr;
    Node<Terms> *node = new Node<Terms>;
    node->setData(n->getData());
    node->setNext(n->getNext());
    if(t != nullptr ){
        
        while(t != nullptr && t->getData().getExponent() > node->getData().getExponent()){
            pre= t;
            t= t->getNext();
        }
        if (t == nullptr){
            pre->setNext(node);
        }
        else{
            if (pre != nullptr){
                node->setNext(pre->getNext());
                pre->setNext(node);
            }
            else{
                node->setNext(t);
                start = node;
            }
        }
    }else{
        start = node;
    }
    numOfTerms++;
}


void Polynomial:: showPolynomial(){
    Node<Terms>* t ;
    t = start;
    int i = 0;
    cout<<"Start";
    while(t){

        cout<<i++<<" ---> ";
        cout << t->getData();
        t = t->getNext();
        
    }
}

Node<Terms>& Polynomial:: operator[](int i){
    Node<Terms>* t ;
    t = start;
    int j = 0 ;
    while(t && j< i){
        t = t->getNext(); 
        j++;
    }
    return *t;
}

Polynomial& Polynomial:: updatePolynomial(function<int(int,int)> add ,function<int(int,int)> mul, Node<Terms> T, Polynomial& P1){
    Polynomial *P = new Polynomial();
    *P = P1;
    Node<Terms>* t ;
    t = P->start;
    int i = 0;
    cout <<"p1 : "<< *P <<endl;
    while(t){
        //cout << t->getData() << "  : t"<<endl;
        t->getData().setCoefficient(mul(T.getData().getCoefficient() , t->getData().getCoefficient()));
        t->getData().setExponent(add(T.getData().getExponent() , t->getData().getExponent()));
        cout << t->getData() << "  : t"<<endl;
        t = t->getNext();
        i++;
    }
    cout << *P <<endl;
    cout << P1 <<endl;
    cout << "Exiting from update" <<endl;
    return *P;
}

void Polynomial::multiply(Polynomial& P1 , Polynomial& P2){
    cout << "\nEntry P1 :"<<P1 <<endl;
    cout << "\nEntry P2 :"<<P2 <<endl;
    auto add= [](int a , int b){return a+b;};
    auto mul= [](int a , int b){return a*b;};

    Polynomial P, result;
    Node<Terms>* t ;
    t = P1.start;
    int i = 0;
    while(t!= nullptr){
        cout<< t->getData()<<endl;
        P = updatePolynomial(add , mul, t->getData(),P2);
        cout << "\nAfter Update:"<<P2 <<endl;
        cout << P << endl;
        cout<<"before this"<<endl;
        *this = *this + P;
        cout<< *this <<endl;
        cout<<"After this"<<endl;
        t = t->getNext();
        i++;
    }

    cout << "\nExit P1 :"<<P1 <<endl;
    cout << "\nExit P2 :"<<P2 <<endl;

}
void Polynomial::add(Polynomial& P1,Polynomial& P2){
    
    start = nullptr ;
    Node<Terms> *p = P1.start,*q = P2.start;
    while(p != nullptr && q != nullptr)
    {
        Node<Terms> *t = new Node<Terms>;
        
        if (p->getData().getExponent() == q->getData().getExponent()){
            if (p->getData().getCoefficient()+q->getData().getCoefficient() != 0){
                t->setData(Terms(p->getData().getCoefficient()+q->getData().getCoefficient(),p->getData().getExponent()));
                t->setNext(nullptr);
                append(t);
            }
            p=p->getNext();
            q=q->getNext();
        }
        else if (p->getData().getExponent() > q->getData().getExponent()){
            t->setData(Terms(p->getData().getCoefficient(),p->getData().getExponent()));
            t->setNext(nullptr);
            append(t);
            p=p->getNext();
        }
        else{
            t->setData(Terms(q->getData().getCoefficient(),q->getData().getExponent()));
            t->setNext(nullptr);
            append(t);
            q=q->getNext();
        }
    }
    while (p != nullptr)
    {
        Node<Terms> *t = new Node<Terms>;
        t->setData(Terms(p->getData().getCoefficient(),p->getData().getExponent()));
        t->setNext(nullptr);
        append(t);
        p=p->getNext();
    }
    while ( q!= nullptr)
    {
        Node<Terms> *t = new Node<Terms>;
        t->setData(Terms(q->getData().getCoefficient(),q->getData().getExponent()));
        t->setNext(nullptr);
        append(t);
        q=q->getNext();
    }
    
}

void Polynomial::subtract(Polynomial& P1,Polynomial& P2){
    
    start = nullptr ;
    Node<Terms> *p = P1.start,*q = P2.start;
    while(p != nullptr && q != nullptr)
    {
        Node<Terms> *t = new Node<Terms>;
        
        if (p->getData().getExponent() == q->getData().getExponent()){
            if (p->getData().getCoefficient()-q->getData().getCoefficient() != 0){
                t->setData(Terms(p->getData().getCoefficient()-q->getData().getCoefficient(),p->getData().getExponent()));
                t->setNext(nullptr);
                append(t);
            }
            p=p->getNext();
            q=q->getNext();
        }
        else if (p->getData().getExponent() > q->getData().getExponent()){
            t->setData(Terms(p->getData().getCoefficient(),p->getData().getExponent()));
            t->setNext(nullptr);
            append(t);
            p=p->getNext();
        }
        else{
            t->setData(Terms(q->getData().getCoefficient(),q->getData().getExponent()));
            t->setNext(nullptr);
            append(t);
            q=q->getNext();
        }
    }
    while (p != nullptr)
    {
        Node<Terms> *t = new Node<Terms>;
        t->setData(Terms(p->getData().getCoefficient(),p->getData().getExponent()));
        t->setNext(nullptr);
        append(t);
        p=p->getNext();
    }
    while ( q!= nullptr)
    {
        Node<Terms> *t = new Node<Terms>;
        t->setData(Terms(q->getData().getCoefficient(),q->getData().getExponent()));
        t->setNext(nullptr);
        append(t);
        q=q->getNext();
    }
    
}

Polynomial:: ~Polynomial(){
    Node<Terms>* t ;
    t = start;
    while(t){
        Node<Terms>* temp ;
        temp = t ;
        t = t->getNext();
        //delete temp;
        temp = nullptr;
        
    }
    start = nullptr;
}