#include<iostream>
#include<functional>

using namespace std ;


template <class Y>
Node<Y> :: Node(){
	Y S;
	data = S;
	next = nullptr;
}

template <class Y>
Node<Y> :: Node(Y y){
	data = y;
	next = nullptr;
}

template <class Y>
Node<Y> :: Node(Node& other){
		data = other.data;
		next = other.next;
}
template<class Y>
Node<Y> :: Node(Node&& other){
	data = other.data;
	next = other.next;
	other.next = nullptr;
}

template<class Y>
Node<Y>&Node<Y> :: operator =(Node& other){
	data = other.data;
	next = other.next;
}

template<class Y>
Node<Y>&Node<Y> :: operator =(Node&& other){
	data = other.data;
	next = other.next;
	other.next = nullptr;
}

template<class Y>
void Node<Y> :: setData(Y y){
	data = y;
}

template<class Y>
Y& Node<Y> :: getData(){
	return data;
}

template<class Y>
void Node<Y> ::setNext(Node* N){
	next = N;
}

template<class Y>
Node<Y>* Node<Y> ::getNext(){
	return next;
}

template<class Y>
Node<Y> :: ~Node() {
	next = nullptr;
}
