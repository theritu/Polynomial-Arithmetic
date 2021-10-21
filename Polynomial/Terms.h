#include<iostream>
#include<functional>

using namespace std ;

class Terms{
    int coefficient ;
    int exponent;
    public:
        //Terms() : coefficient(0) , exponent(0) {};
        Terms(int coef=0 , int expo=0) : coefficient(coef) ,exponent(expo) {};
        // Terms(Terms const& other) :coefficient(other.coefficient) , exponent(other.exponent) {};
        // Terms(Terms const&& other) :coefficient(other.coefficient) , exponent(other.exponent) {};
        friend ostream& operator<< (ostream& out, Terms& other){
            out << "(" <<other.coefficient <<","<<other.exponent<<")";
            return out;
        }

        int getCoefficient(){
            return coefficient;
        }

        int getExponent(){
            return exponent;
        }

        void setCoefficient(int coefficient){
            this->coefficient = coefficient;
        }

        void setExponent(int exponent){
            this->exponent = exponent;
        }

};