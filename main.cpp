#include "lever.h"
#include "myMachine.h"
//#include "../src/EB_Device.cpp"

#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>

using namespace std;

    void Pol_Machine(int n);
    void Pol_Device();
    //Objects that are checked. 
    Pol_shaft* myshaft = new Pol_shaft;
    Pol_squares* mysquares= new Pol_squares;


    //Objects that have to be checked. Object not checked
    Pol_shaft* tryshaft= new Pol_shaft;
    Pol_squares* trysquares= new Pol_squares;

    //Default parameters of my device
    float ShaftLength=300 ;
    float SquareSide1=20 ;
    float SquarePos1=80 ;
    float SquareSide2=50 ;
    float SquarePos2=50;

    //Name of the svg file that you want to create
    string svgfilename_to;

    //Name of the file to get the data from
    string svgfilename_from;

    //String that will contain the file svg readed
    string svg_readed;

    //Create a new string in order to create the new svg file with parameters selected, and this string is shown in terminal
    string svg_created;


    //-----------------imported from EB v3.0.1

    //Default sizes I created/chose for the imported device
    //-----------------imported from EB v3.0.1
    EbDevice* MyDevice = new EbDevice;
    double length_shaft=300;
    double width_towtruck=150;
    double width_platform=350;
    double rotation=-25;
    double sliding=150;
    string errormsg="ERROR 404: mechanical constraints exceeded";
    //-----------end imported





    //-----------end imported
/**
    A function which print the 5 parameters of a device 
**/
void eb_printParameters(EbDevice* device){
    cout<<"5 fondamental parameters are: "<<endl;
    cout<<"Length shaft: "<<device -> length_shaft<<endl;
    cout<<"Width_towtruck: "<<device -> width_towtruck<<endl;
    cout<<"Width_platform: "<<device -> width_platform<<endl;
    cout<<"Angle of rotation: "<<device -> rotation<<endl;
    cout<<"Sliding: "<<device -> sliding<<endl;
}

int main() {    
    int fine=2;
    int choice;
    do{
        cout<<"\n Welcome! What you want to do? Type a number :"<<endl;
        cout<<"1 - Build only my device - A Lever"<<endl;
        cout<<"2 - Build a machine - A trolley crane with a lever"<<endl;
        cout<<"9 - To quit/end the program"<<endl;
        cout<<"\n Insert your option here: ";

        /**I found online this formula that checks if the input is correct.. 
         * example, it will fail if the input is a letter or not an integer (float, double..)
        */
        while(!(cin>> choice)){
            cout<<"\n ERROR: an integer must be entered:";
            cin.clear();
            cin.ignore(132, '\n');
        }
        cout<<endl;
        cout<<"DEBUG:" << choice << "\n" << endl;
        switch (choice)
        {
        case 1:
            Pol_Device();
            fine=2;
            break;
        case 2:
            int n;
            cout<<"How many machine do you want?: ";
            while(!(cin>> n)){
            cout<<"\n ERROR: an integer must be entered:";
            cin.clear();
            cin.ignore(132, '\n');
            }
            Pol_Machine(n);
            fine=2;
            break;
        case 9:
            fine=0;
            return EXIT_SUCCESS;
        default:
            cout<<"\n Please, enter a correct option!\n";
            fine=1;
            break;
        }

    }while(fine==1);

    
    return EXIT_SUCCESS;
}


void Pol_Machine(int n){


    cout<<"\n Doing a machine"<<endl;
    //-----------------imported from EB v3.0.1
    MyDevice=eb_init(length_shaft, width_towtruck, width_platform, rotation, sliding);
    if(MyDevice==NULL){
        cout<<errormsg<<endl;
        exit(1);
    }
    eb_printParameters(MyDevice);

    


//     struct MyDevice {
//    int i;
// };
 
// MyDevice* my_init_device(int i){
//    cout << "Sto inizializzando " << i << endl;
//    MyDevice* ret = new MyDevice;
//    ret->i = i;
//    return ret;
// }
 
// int main() {
 
//    // SOLUZIONE CON ARRAY DINAMICO DI PUNTATORI A STRUCT
  
//    MyDevice** arr;    // notare doppio asterisco
 
//    int n = 2;
//    arr = new MyDevice* [n];  // notare asterisco dopo MyDevice
 
//    MyDevice* d1 = my_init_device(1);
//    MyDevice* d2 = my_init_device(2);
 
//    arr[0] = d1;
//    arr[1] = d2;
 
//    // ...
 
//    // elimino un device alla volta
//    delete arr[0];  // oppure my_destroy_device(arr[0])  se è definita
//    delete arr[1];  // oppure my_destroy_device(arr[1])  se è definita
//    // ....
 
//    // poi elimino tutto l'array
//    delete[] arr;
    int c;
    int fine=2;
    do {
        cout<<"\n Choose a command. Do you want change the default sizes? Type a number :"<<endl;
        cout<< "1 - No" <<endl;
        cout<< "2 - Yes" <<endl;
        cout<< "3 - Read sizes from an already existing file and storing them" << endl;
        cout<< "9 - to quit/end the program"<<endl;
        cout<< "\n Insert the option here: ";
        
        /**I found online this formula that checks if the input is correct.. 
         * example, it will fail if the input is a letter or not an integer (float, double..)
        */
        while(!(cin>> c)){
            cout<<"\n ERROR: an integer must be entered:";
            cin.clear();
            cin.ignore(132, '\n');
        }
        cout<<endl;
        cout<<"DEBUG:" << c << "\n" << endl;
        
        switch (c) 
        {
            case 1:
                //Parameters are sets to default
                ShaftLength=300 ; cout<<"Default shaft length is: "<<ShaftLength<<endl;
                SquareSide1=20 ; cout<<"Default Side of Square 1 is: "<<SquareSide1<<endl;
                SquarePos1=80 ; cout<<"Default Position of Square 1 is: "<<SquarePos1<<endl;
                SquareSide2=50 ; cout<<"Default Side of Square 2 is: "<<SquareSide2<<endl;
                SquarePos2=50; cout<<"Default Position of Square2 is: "<<SquarePos2<<endl;

                //Parameters decided to be default for the EBdevice:
                length_shaft=300;
                width_towtruck=150;
                width_platform=350;
                rotation=-25;
                sliding=150;

                //Inizialization of EbDevice
                MyDevice=eb_init(length_shaft, width_towtruck, width_platform, rotation, sliding);
                
                //Checking dimensions
                if(my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2)==0 && MyDevice!=NULL){
                    fine=0;
                }else{
                    cout<<"Error occured in side assignment. Check sizes!"<<endl;
                    fine=1;
                    }

                if (fine==0){
                    cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;
                    //The dimensions checked are now associated to the objects, creating objects
                    myshaft= shaft_init(ShaftLength);
                    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);
                }
                break;

            case 2:
                cout << "Inizialize a lever" << endl;
                cout << "A Shaft with the following size: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN 500!!)" << endl;
                cout << "- Length: "<< endl;
                cin >> ShaftLength;
                cout << "The FIRST square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquareSide1;
                cout << "The FIRST square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos1;
                cout << "The SECOND square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquareSide2;
                cout << "The SECOND square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos2;
                

                //Changing EBdevice
                cout<<"Now You are going to 'build' the Eb Device"<<endl<<"You must insert 5 fondamental parameters..."<<endl;
                cout<<"Length shaft: ";
                cin>>length_shaft;
                cout<<endl<<"Width towtruck: ";
                cin>>width_towtruck;
                cout<<endl<<"Width_platform: ";
                cin>>width_platform;
                cout<<endl<<"Rotation: ";
                cin>>rotation;
                cout<<endl<<"Sliding: ";
                cin>>sliding;
                cout<<endl;

                //Inizialization of EbDevice
                MyDevice=eb_init(length_shaft, width_towtruck, width_platform, rotation, sliding);
                
                //Checking dimensions
                if(my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2)==0 && MyDevice!=NULL){
                    fine=0;
                }else{
                    cout<<"Error occured in side assignment. Check sizes!"<<endl;
                    fine=1;
                    }
                    
                eb_printParameters(MyDevice);

                //Dimensions are checked
                //fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                if (fine==0){
                    cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;
                    //The dimensions checked are now associated to the objects, creating objects
                    myshaft= shaft_init(ShaftLength);
                    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);
                }
                break;

            case 3:
                cout<<"Tell me the name of the file to get the data from (without extension): ";
                cin>>svgfilename_from;
                svgfilename_from+=".svg";
                svg_readed=read_svg (svgfilename_from);
                if (svg_readed=="no"){
                    cout<<"something goes wrong"<<endl;
                    fine=1;
                    break;                    
                }else{
                    cout<<"The svg file readed is:"<<endl;
                    cout<<svg_readed<<endl;
                    
                    //New objects, NOT checked, that are created from the file readed
                    tryshaft= my_parse_shaft(svg_readed);
                    trysquares= my_parse_squares(svg_readed);

                    //Check of variables readed
                    fine=my_set(tryshaft->s_length, trysquares->sq1_side, trysquares->sq1_pos, trysquares->sq2_side, trysquares->sq2_pos);
                    if(fine==0){ 
                        cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;           
                        //New objects, checked, that are created from the file readed
                        myshaft=tryshaft;
                        mysquares=trysquares;
                    }
                    
                    break;
                }
            case 9:
                fine=0;
                return exit(1);
            default:
                cout<<"\n Please, enter a correct option!\n";
                fine=1;
                break;
        }
      
    }while(fine==1);


    //Is now created a string for a svg file with the dimesions that are given    
    svg_created = to_svg_Machine(MyDevice,myshaft, mysquares);
    cout << "\n The new svg code created is:" << endl;
    cout << svg_created;


    //Prints the svg string to a file called as specified in the variable svgfilename
    cout<<"\n Name of the file to save the data to (without extension): ";
    cin>>svgfilename_to;
    svgfilename_to+=".svg";
    cout<<"\nThe new svg string with the parameters selected is created and is now saved into a file in ../bin\n"<<endl;
    svg_to_file(svgfilename_to,svg_created);
    
    
    //Destroy the objects
    destroyer(myshaft, mysquares);
    eb_destroy_device(MyDevice);
    
}

void Pol_Device(){
    int c;
    int fine=2;
    do {
        cout<<"\n Choose a command. Do you want change the default sizes? Type a number :"<<endl;
        cout<< "1 - No" <<endl;
        cout<< "2 - Yes" <<endl;
        cout<< "3 - Read sizes from an already existing file and storing them" << endl;
        cout<< "9 - to quit/end the program"<<endl;
        cout<< "\n Insert the option here: ";
        
        /**I found online this formula that checks if the input is correct.. 
         * example, it will fail if the input is a letter or not an integer (float, double..)
        */
        while(!(cin>> c)){
            cout<<"\n ERROR: an integer must be entered:";
            cin.clear();
            cin.ignore(132, '\n');
        }
        cout<<endl;
        cout<<"DEBUG:" << c << "\n" << endl;
        
        switch (c) 
        {
            case 1:
                //Parameters are sets to default
                ShaftLength=300 ; cout<<"Default shaft length is: "<<ShaftLength<<endl;
                SquareSide1=20 ; cout<<"Default Side of Square 1 is: "<<SquareSide1<<endl;
                SquarePos1=80 ; cout<<"Default Position of Square 1 is: "<<SquarePos1<<endl;
                SquareSide2=50 ; cout<<"Default Side of Square 2 is: "<<SquareSide2<<endl;
                SquarePos2=50; cout<<"Default Position of Square2 is: "<<SquarePos2<<endl;

                //Checking dimensions
                fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                    
                if (fine==0){
                    cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;
                    //The dimensions checked are now associated to the objects, creating objects
                    myshaft= shaft_init(ShaftLength);
                    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);
                }
                break;

            case 2:
                cout << "Inizialize a lever" << endl;
                cout << "A Shaft with the following size: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN 500!!)" << endl;
                cout << "- Length: "<< endl;
                cin >> ShaftLength;
                cout << "The FIRST square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquareSide1;
                cout << "The FIRST square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos1;
                cout << "The SECOND square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquareSide2;
                cout << "The SECOND square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos2;
                
                //Dimensions are checked
                fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                if (fine==0){
                    cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;
                    //The dimensions checked are now associated to the objects, creating objects
                    myshaft= shaft_init(ShaftLength);
                    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);
                }
                break;

            case 3:
                cout<<"Tell me the name of the file to get the data from (without extension): ";
                cin>>svgfilename_from;
                svgfilename_from+=".svg";
                svg_readed=read_svg (svgfilename_from);
                if (svg_readed=="no"){
                    cout<<"something goes wrong"<<endl;
                    fine=1;
                    break;                    
                }else{
                    cout<<"The svg file readed is:"<<endl;
                    cout<<svg_readed<<endl;
                    
                    //New objects, NOT checked, that are created from the file readed
                    tryshaft= my_parse_shaft(svg_readed);
                    trysquares= my_parse_squares(svg_readed);

                    //Check of variables readed
                    fine=my_set(tryshaft->s_length, trysquares->sq1_side, trysquares->sq1_pos, trysquares->sq2_side, trysquares->sq2_pos);
                    if(fine==0){ 
                        cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;           
                        //New objects, checked, that are created from the file readed
                        myshaft=tryshaft;
                        mysquares=trysquares;
                    }
                    
                    break;
                }
            case 9:
                fine=0;
                return exit(1);
            default:
                cout<<"\n Please, enter a correct option!\n";
                fine=1;
                break;
        }
      
    }while(fine==1);


    //Is now created a string for a svg file with the dimesions that are given    
    svg_created = to_svg(myshaft, mysquares);
    cout << "\n The new svg code created is:" << endl;
    cout << svg_created;


    //Prints the svg string to a file called as specified in the variable svgfilename
    cout<<"\n Name of the file to save the data to (without extension): ";
    cin>>svgfilename_to;
    svgfilename_to+=".svg";
    cout<<"\nThe new svg string with the parameters selected is created and is now saved into a file in ../bin\n"<<endl;
    svg_to_file(svgfilename_to,svg_created);
    
    
    //Destroy the objects
    destroyer(myshaft, mysquares);
    
}