#include<iostream>
#include<functional>
#include "Polynomial.h"

using namespace std;

int main (){

    int choice,termsCount1,termsCount2 , coeff , expo;
    while(true){
        cout<<"\n\n----------------***_______MENU______***------------------\n|\t\t\t\t\t\t\t|\n";
        cout<<"|\t\t1  : ADD TWO POLYNOMIAL\t\t\t|\n";
        cout<<"|\t\t2  : SUBTRACT TWO POLYNOMIAL\t\t|\n";
        cout<<"|\t\t3  : MULTIPLY TWO POLYNOMIAL\t\t|\n";
        cout<<"|\t\t4  : DIVIDE TWO POLYNOMIAL\t\t|\n";
        cout<<"|\t\t99 : EXIT FROM THE APPLICATION\t\t|\n\n";
        cout<<"---------------***___________________***-----------------\n\n";

        cout<<"\t\tENTER YOUR CHOICE : ";
        cin>>choice;
        Polynomial P ,P1 , P2;
        if ( choice > 0 && choice < 5){
            cout<<"\n\n---------------***___________________***-----------------\n\n";
            cout<<"|\t\tEXAMPLE : 2x^2 + 4x + 5\t\t\t|\n";
            cout<<"|\t\tNumber of Terms : 3\t\t\t|\n|\t\tPaired coefficient & exponents are :\t|\n|\t\t(2,2),(4,1),(5,0)\t\t\t|\n"; 
            cout<<"|\n---------------***___________________***-----------------\n";
            cout<<"\n=====================***INPUT***========================\n\n";
            cout<<"\t\tEnter number of terms in P1 : ";
            cin>>termsCount1;
            
            cout<<"\n";
            for (int i = 0 ; i< termsCount1 ; i++){
                cout<<"\t\tEnter Pair of coeff & exponent :";
                cin>>coeff>>expo;
                Terms T(coeff , expo);
                Node<Terms> N(T);
                P1.insert(&N);
            }
            cout<<"\n-------------------------------------------------------\n\n";
            cout<<"\t\tEnter number of terms in P2 : ";
            cin>>termsCount2;
            cout<<"\n";
            for (int i = 0 ; i< termsCount2 ; i++){
                cout<<"\t\tEnter Pair of coeff & exponent :";
                cin>>coeff>>expo;
                Terms T(coeff , expo);
                Node<Terms> N(T);
                P2.insert(&N);
            }
            cout<<"\n===================*************========================\n";
        }
        switch(choice){

            case 1 : 
                
                P = P1 + P2;

                cout<<"\n=====================***OUTPUT***=======================\n\n";
                cout<<"\t\tP1      :: "<<P1<<endl;
                cout<<"\t\tP2      :: "<<P2<<endl;
                cout<<"\t\tP1 + P2 :: "<<P<<endl;
                cout<<"\n===================*************========================\n\n";
                
                break;
            
            case 2:

                P = P1 - P2;
                cout<<"\n=====================***OUTPUT***=======================\n\n";
                cout<<"\t\tP1      :: "<<P1<<endl;
                cout<<"\t\tP2      :: "<<P2<<endl;
                cout<<"\t\tP1 - P2 :: "<<P<<endl;
                cout<<"\n===================*************========================\n\n";
                break;
            
            case 3:

                P = P1 * P2;
                cout<<"\n=====================***OUTPUT***=======================\n\n";
                cout<<"\t\tP1      :: "<<P1<<endl;
                cout<<"\t\tP2      :: "<<P2<<endl;
                cout<<"\t\tP1 * P2 :: "<<P<<endl;
                cout<<"\n===================*************========================\n\n";
                break;
                
            case 4:
                cout<<"\n\t\tSORRY! Implementation Need To Be Done\n";
                break;
                
            case 99:
                exit(0);

            default:
                cout<<"\n\t\tPLEASE, Enter Correct Choice\n";
                break;
        }


    }

    return 0;
}