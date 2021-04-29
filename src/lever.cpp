#include "lever.h"
//#include "EB_Device.h"
//#include "../src/EB_Device.cpp"

using namespace std;


/*
    some components' features are fixed --> shaft width, towtruck height, platform height 
*/
    const double std_shaftWidth = 20;
    const double std_towtruckHeight = 40;
    const double std_platformHeight = 20;

    const double std_Ycir=120;
    const double std_radius=10;
    const double std_YtowTruck=100;
/*
    centro di istantanea rotazione --> punto attorno al quale l'asta ruota, corrisponde al
    centro della coppia rotoidale che unisce asta e carrello --> Ycir è fissa, Xcir varia in
    funzione dello spostamento del carrello lungo x
*/

int my_set(double ShaftLength, double SquareSide1, double SquarePos1, double SquareSide2, double SquarePos2){
    
    if (ShaftLength==0 || SquareSide1==0 || SquareSide2==0 || SquarePos1==0 || SquarePos2==0){
        cout<<"\n Dimensions have to be different than 0!!!"<<endl;
        return 1;
    }

    if (ShaftLength<0 || SquareSide1<0 || SquareSide2<0 || SquarePos1<0 || SquarePos2<0){
        cout<<"\n Dimensions have to be POSITIVE (>0)!!!"<<endl;
        return 1;
    }
    
    if(ShaftLength>500){
        cout<<"\n Dimension of the shaft have to be SMALLER than 500!!!"<<endl;
        return 1;
    }

    if(SquarePos1>(ShaftLength/2) || SquarePos2>(ShaftLength/2)){
        cout<<"\n Position of the squares have to be SMALLER than HALF of the SHAFT's LENGTH"<<endl;
        return 1;
    }

    if(SquareSide1>(ShaftLength/2) || SquareSide2>(ShaftLength/2)){
        cout<<"\n Sides of the squares have to be SMALLER than HALF of the SHAFT's LENGTH"<<endl;
        return 1;
    }

    return 0;
}


Pol_shaft* shaft_init(float sLength){

    // Allocating a struct called "newshaft" like "Pol_shaft"
    Pol_shaft* newshaft = new Pol_shaft;

    // Size assignment
    newshaft->s_length = sLength;

    //Returning the object
    return newshaft;
}


Pol_squares* squares_init(float side1, float pos1, float side2, float pos2){

    // Allocating a struct called "newsquares" like "Pol_squares"
    Pol_squares* newsquares = new Pol_squares;

    // Size assignment
    newsquares->sq1_side = side1;
    newsquares->sq1_pos = pos1;
    newsquares->sq2_side = side2;
    newsquares->sq2_pos = pos2;

    //Returning the object
    return newsquares;
}


bool with_measures(){
    char choice;
    int forbool;
    int end=1;
    do{
        cout<<"Do you want to include in the measures in the svg file? y/n: ";
        cin>>choice;
        switch (choice)
        {
        case 'y':
            end=2;
            forbool=1;
            break;

        case 'n':
            end=2;
            forbool=0;
            break;
        
        default:
            cout<< "Wrong choice. Try again"<<endl;
            end=1;
            break;
        }
        
        
    }while(end==1);
    
    return forbool;
}


string to_svg(EbDevice* eb_device, Pol_shaft* myshaft, Pol_squares * mysquares){

   string svg;

    /*----copied from Elia B. v2.0.1 */
    /*parametri device*/
    double sliding=eb_device->sliding;
    double length=eb_device->length_shaft;
    double angle=eb_device->rotation; 
    double widthPla=eb_device->width_platform;
    double widthTt=eb_device->width_towtruck;
    /*variabili utili*/
    double Xcir=eb_Xcir(eb_device);
    double Xplatform=eb_Xplatform(eb_device);
    double Yplatform=eb_Yplatform(eb_device);
    string code;



    //250 is the position of the vertex of the triangle
    double xline1= Xplatform + widthPla/2 - (myshaft->s_length)/2;
    double xline2= Xplatform + widthPla/2 + (myshaft->s_length)/2;
    double position1x= Xplatform + widthPla/2 - (mysquares->sq1_pos );
    double position2x= Xplatform + widthPla/2 + (mysquares->sq2_pos);
    double position1y= Yplatform-50 - mysquares->sq1_side;
    double position2y= Yplatform-50 - mysquares->sq2_side;
    
    
    bool store_choice=with_measures();
    
    
    if (store_choice==0){
     
        code+="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
        code+="<svg xmlns=\"http://www.w3.org/2000/svg\" style=\"background-color:white\" width=\"1500\" height=\"1000\">\n\n";
    
        /*
            carrello gru con spostamento orizzontale
        */
        code+="<g>\n";
        code+="<rect x = \""+to_string(sliding)+"\" y = \"100\" width = \"" + to_string(widthTt) +"\" height = \"40\" stroke = \"black\" stroke-width = \"3\" fill = \"yellow\"/>\n";
        code+="</g>\n\n";

        /*
            asta rotante, 
            angolo positivo --> asta ruota in senso orario(verso sx)
            angolo negativo --> asta ruota in senso antiorario(verso dx)
        */
        code+="<g transform  = \"rotate("+to_string(angle)+","+to_string(Xcir)+",120)\">\n";
        code+="<rect x = \""+to_string(Xcir-std_radius)+"\" y = \"120\" width = \"20\" height = \"" + to_string(length) + "\" stroke = \"black\" stroke-width = \"3\" fill = \"orange\" />\n";
        code+="<circle cx = \""+to_string(Xcir)+"\" cy = \"120\" r = \"10\" stroke = \"black\" stroke-width = \"3\" fill = \"white\"/>\n";
        code+="</g>\n\n";

        /*
            piattaforma
        */
        code+="<g>\n";
        code+="<rect x = \""+to_string(Xplatform)+"\" y = \""+to_string(Yplatform)+"\" width = \""+to_string(widthPla)+"\" height = \"20\"  stroke = \"black\" stroke-width = \"3\" fill = \"black\" />\n";
        code+="</g>\n\n";
        
        svg=code;

        svg+= "<polygon points='"+to_string(Xplatform + widthPla/2 -50)+","+to_string(Yplatform)+" "+to_string(Xplatform + widthPla/2)+","+to_string(Yplatform-50)+" "+to_string(Xplatform + widthPla/2+50)+","+to_string(Yplatform)+"' style='fill:lime;stroke:purple;stroke-width:1' />\n";  
        svg+= "<!-- Shaft -->\n";
        svg+= "<line x1='"+ to_string(xline1) + "'" + " y1='"+to_string(Yplatform-50)+"' x2='" + to_string(xline2)+ "' y2='"+to_string(Yplatform-50)+"' style='stroke:rgb(255,0,0);stroke-width:2' />\n";
        svg+= "<!-- Square1 -->\n";
        svg+= "<rect x='"+ to_string(position1x) +"' y='"+ to_string(position1y) +"' width='"+ to_string(mysquares->sq1_side) +"' height='"+ to_string(mysquares->sq1_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
        svg+= "<!-- Square2 -->\n";
        svg+= "<rect x='"+ to_string(position2x) +"' y='"+ to_string(position2y) +"' width='"+ to_string(mysquares->sq2_side) +"' height='"+ to_string(mysquares->sq2_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
        svg+= "</svg> \n";
    }

    if(store_choice==1){
        svg= "<?xml version='1.0' encoding='UTF-8' standalone='no'?> \n";
        svg+= "<svg xmlns='http://www.w3.org/2000/svg' height='300' width='500'> \n" ;
        svg+= "<polygon points='200,300 250,250 300,300' style='fill:lime;stroke:purple;stroke-width:1' />\n";  
        svg+= "<!-- Shaft -->\n";
        svg+= "<line x1='"+ to_string(xline1) + "'" + " y1='250' x2='" + to_string(xline2)+ "' y2='250' style='stroke:rgb(255,0,0);stroke-width:2' />\n";
        svg+= "<line x1= '"+ to_string(xline1) +"' y1='260' x2='" + to_string(xline2)+ "' y2='260'  stroke='black' stroke-width='1'/>\n";
        svg+= "<text x='"+ to_string(xline1) +"' y='280' fill='black'>"+ to_string(myshaft->s_length) +"</text>\n";
        svg+= "<!-- Square1 -->\n";
        svg+= "<rect x='"+ to_string(position1x) +"' y='"+ to_string(position1y) +"' width='"+ to_string(mysquares->sq1_side) +"' height='"+ to_string(mysquares->sq1_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
        svg+= "<line x1= '"+ to_string(position1x) +"' y1= '"+ to_string(position1y -10) +"' x2= '250' y2 = '"+ to_string(position1y -10) +"'  stroke='black' stroke-width= '1'/>\n";
        svg+= "<text x='"+ to_string(position1x) +"' y='"+ to_string(position1y -12) +"' fill='black'>"+ to_string(mysquares->sq1_pos ) +"</text>\n";
        svg+= "<line x1 = '"+ to_string(position1x-10) +"' y1= '"+ to_string(position1y) +"' x2= '"+ to_string(position1x-10) +"' y2= '"+ to_string(position1y + mysquares->sq1_side) +"'  stroke='black' stroke-width='1'/>\n";
        svg+= "<text x='"+ to_string(position1x-13) +"' y='"+ to_string(position1y + mysquares->sq1_side/2) +"' transform='rotate(-90 "+ to_string(position1x-13) + ","+ to_string(position1y + mysquares->sq1_side/2) +")' fill='black'>"+ to_string(mysquares->sq1_side) +"</text>\n";
        svg+= "<!-- Square2 -->\n";
        svg+= "<rect x='"+ to_string(position2x) +"' y='"+ to_string(position2y) +"' width='"+ to_string(mysquares->sq2_side) +"' height='"+ to_string(mysquares->sq2_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
        svg+= "<line x1= '"+ to_string(position2x) +"' y1= '"+ to_string(position2y -10) +"' x2= '250' y2 = '"+ to_string(position2y -10) +"'  stroke= 'black' stroke-width= '1'/>\n";
        svg+= "<text x='"+ to_string(250) +"' y='"+ to_string(position2y -12) +"' fill='black'>"+ to_string(mysquares->sq2_pos ) +"</text>\n";
        svg+= "<line x1= '"+ to_string(position2x + mysquares->sq2_side+10) +"' y1= '"+ to_string(position2y) +"' x2= '"+ to_string(position2x + mysquares->sq2_side+10) +"' y2= '"+ to_string(position2y + mysquares->sq2_side) +"'  stroke= 'black' stroke-width= '1'/>\n";
        svg+= "<text x='"+ to_string(position2x + mysquares->sq2_side+13) +"' y='"+ to_string(position2y) +"' transform='rotate(90 "+ to_string(position2x + mysquares->sq2_side+13) +","+ to_string(position2y) +")'  fill='black'>"+ to_string(mysquares->sq2_side) +"</text>\n";
        svg+= "</svg> \n";
        
    }
    return svg;
}


void svg_to_file(string filename, string str_svg){

    // Create and open a text file, writing to the file the string of the svg, closing the file
    ofstream MyFile(filename);
    MyFile << str_svg;
    MyFile.close();
}


string read_svg (string filename){

    // Read from the text file
    ifstream MyReadFile(filename);
    stringstream buffer;
    //Create a text string, which is used to output the text file
    string myText;

    if (MyReadFile.is_open()){
        buffer << MyReadFile.rdbuf();
        // Create a text string, which is used to output the text file
        myText = buffer.str();
    }else{
        cout << "\n Unable to open file, maybe the file's name is wrong!"<<endl;
        return "no";
    }
    MyReadFile.close();

    return myText; 
}


float Finder(string str, string start, string end, string typeofelement){
  
  size_t found_typeofelement = str.find(typeofelement);
  float elementFound;

  if (found_typeofelement!=string::npos){
    size_t found = str.find(start,found_typeofelement);
    if (found!=string::npos){        
      size_t find1 = found + start.size();
      size_t find2= str.find(end, find1);
      string element = str.substr(find1, find2-find1);
      cout<< "DEBUG: Parameter readed is: "<< element<<endl;
      elementFound=stof(element); //Convert a string into a float
    }else{
        cout<<"not found!"<<endl;
        return -1;
    }
  }else{
    cout<<"Comment of the device name not found!"<<endl;
    return -1;
  }
 

  return elementFound;
}


Pol_shaft * my_parse_shaft(string str){
    // Allocating a struct called "newshaft" like "Pol_shaft"
    Pol_shaft* newshaftreaded = new Pol_shaft;
    float checking1,checking2;

    checking1=Finder(str, "x2='", "'", "Shaft");
    checking2=Finder(str, "x1='", "'", "Shaft");

    if (checking1!=-1 && checking2!=-1){
        newshaftreaded->s_length= checking1 - checking2;
        cout<< "DEBUG: Shaft length calculated from the file read is: "<<newshaftreaded->s_length<<"\n"<<endl;
    }
    return newshaftreaded;
}


Pol_squares * my_parse_squares(string str){
    // Allocating a struct called "newsquares" like "Pol_shaft"
    Pol_squares* newsquaresreaded = new Pol_squares;
    float checking;

    //250 is the position of the vertex of the triangle
    // float xline1= 250 - (myshaft->s_length)/2;
    // float xline2= 250 + (myshaft->s_length)/2;
    // float position1x= 250 - (mysquares->sq1_pos );
    // float position2x= 250 + (mysquares->sq2_pos);
    // float position1y= 250 - mysquares->sq1_side;
    // float position2y= 250 - mysquares->sq2_side;
    // bool store_choice=with_measures();

    checking=Finder(str, "x='",  "'", "Square1");
    if(checking!=-1){
        newsquaresreaded->sq1_pos = (250-checking);
        cout<<"DEBUG: sq1 pos calculated from the file read: "<<newsquaresreaded->sq1_pos <<"\n"<<endl;
    }
    
    checking=Finder(str, "width='",  "'", "Square1");
    if(checking!=-1){
        newsquaresreaded->sq1_side = checking;
    cout<<"DEBUG: sq1 side calculated from the file read: "<<newsquaresreaded->sq1_side <<"\n"<<endl;
    }
    
    checking=Finder(str, "x='",  "'", "Square2");
    if(checking!=-1){
        newsquaresreaded->sq2_pos = (checking-250);
        cout<<"DEBUG: sq2 pos calculated from the file read: "<<newsquaresreaded->sq2_pos <<"\n"<<endl;
    }

    checking=Finder(str, "width='",  "'", "Square2");
    if(checking!=-1){    
        newsquaresreaded->sq2_side = checking;
        cout<<"DEBUG: sq2 side calculated from the file read: "<<newsquaresreaded->sq2_side <<endl;
    }

    return newsquaresreaded;

}


void destroyer(Pol_shaft * myshaft, Pol_squares * mysquares){
    if (myshaft != NULL){
        delete myshaft;
    }

    if (mysquares != NULL){
        delete mysquares;
    }

}

