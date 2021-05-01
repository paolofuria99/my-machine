#include "myMachine.h"

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

string to_svg_Machine(EbDevice* eb_device, Pol_shaft* myshaft, Pol_squares * mysquares){

   string svg;

    /*----copied from Elia B. v3.0.1 */
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
        /*
            disegno con misure
        */
        code+="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
        code+="<svg xmlns=\"http://www.w3.org/2000/svg\" style=\"background-color:white\" width=\"1500\" height=\"1000\">\n\n";
        
        /*
            carrello gru con spostamento orizzontale
        */
        code+="<g>\n";
        code+="<rect x = \""+to_string(sliding)+"\" y = \"100\" width = \"" + to_string(widthTt) +"\" height = \"40\" stroke = \"black\" stroke-width = \"3\" fill = \"yellow\"/>\n";
        code+="<text x = \""+to_string(sliding)+"\" y = \"65\" fill = \"black\"> width_towtruck = "+to_string((int)sliding)+" </text>\n";
        code+="<line x1 = \""+to_string(sliding)+"\" y1 = \"75\" x2 = \""+to_string(sliding+widthTt)+"\" y2 = \"75\"  stroke = \"black\" stroke-width  = \"2\"/>\n";

        code+="</g>\n\n";

        /*
            asta rotante, 
            angolo positivo --> asta ruota in senso orario(verso sx)
            angolo negativo --> asta ruota in senso antiorario(verso dx)
        */
        code+="<g transform  = \"rotate("+to_string(angle)+","+to_string(Xcir)+",120)\">\n";
        code+="<rect x = \""+to_string(Xcir-std_radius)+"\" y = \"120\" width = \"20\" height = \"" + to_string(length) + "\" stroke = \"black\" stroke-width = \"3\" fill = \"orange\" />\n";
        code+="<text x = \""+to_string(Xcir+(widthTt/2)+40)+"\" y = \""+to_string(std_Ycir+(length/2))+"\" fill = \"black\"> length_shaft = "+to_string((int)length)+" </text>\n";
        code+="<line x1 = \""+to_string(Xcir+(widthTt/2)+30)+"\" y1 = \"120\" x2 = \""+to_string((Xcir+(widthTt/2)+30))+"\" y2 = \""+to_string((120+length))+"\"  stroke = \"black\" stroke-width  = \"2\"/>\n";
        code+="<text x = \""+to_string(Xcir-std_radius-80)+"\" y = \""+to_string(std_Ycir-10+(length/2))+"\" fill = \"black\"> angle="+to_string((int)angle)+" </text>\n";
        code+="<line x1 = \""+to_string(Xcir-std_radius-70)+"\" y1 = \""+to_string(std_Ycir+(length/2))+"\" x2 = \""+to_string(Xcir-std_radius)+"\" y2 = \""+to_string(std_Ycir+(length/2))+"\"  stroke = \"black\" stroke-width  = \"2\"/>\n";
        code+="<circle cx = \""+to_string(Xcir)+"\" cy = \"120\" r = \"10\" stroke = \"black\" stroke-width = \"3\" fill = \"white\"/>\n";
        code+="</g>\n\n";

        /*
            piattaforma
        */
        code+="<g>\n";
        code+="<rect x = \""+to_string(Xplatform)+"\" y = \""+to_string(Yplatform)+"\" width = \""+to_string(widthPla)+"\" height = \"20\"  stroke = \"black\" stroke-width = \"3\" fill = \"black\" />\n";
        code+="<text x = \""+to_string(Xplatform+(widthPla/4))+"\" y = \""+to_string(Yplatform+std_platformHeight+40)+"\" fill = \"black\"> width_platform = "+to_string((int)widthPla)+" </text>\n";
        code+="<line x1 = \""+to_string(Xplatform)+"\" y1 = \""+to_string(Yplatform+std_platformHeight+20)+"\" x2 = \""+to_string(Xplatform+widthPla)+"\" y2 = \""+to_string(Yplatform+std_platformHeight+20)+"\"  stroke = \"black\" stroke-width  = \"2\"/>\n";
        code+="</g>\n\n";

        /*
            quota spostamento carrello
        */    
        code+="<g>\n";
        if(sliding>100){
            code+="<text x = \""+to_string(sliding-100)+"\" y = \"110\" fill = \"black\"> sliding = "+to_string((int)sliding)+" </text>\n";
            code+="<line x1 = \""+to_string(sliding-80)+"\" y1 = \"120\" x2 = \""+to_string(sliding)+"\" y2 = \"120\"  stroke = \"black\" stroke-width  = \"2\"/>\n";
        }
        else{
            code+="<text x = \"10\" y = \"20\" fill = \"black\"> sliding = "+to_string((int)sliding)+" </text>\n";
            code+="<line x1 = \"2\" y1 = \"30\" x2 = \""+to_string(sliding+20)+"\" y2 = \"30\"  stroke = \"black\" stroke-width  = \"2\"/>\n";
        }
        code+="</g>\n";

        svg=code;
        //svg= "<?xml version='1.0' encoding='UTF-8' standalone='no'?> \n";
        //svg+= "<svg xmlns='http://www.w3.org/2000/svg' height='300' width='500'> \n" ;
        svg+= "<polygon points='"+to_string(Xplatform + widthPla/2 -50)+","+to_string(Yplatform)+" "+to_string(Xplatform + widthPla/2)+","+to_string(Yplatform-50)+" "+to_string(Xplatform + widthPla/2+50)+","+to_string(Yplatform)+"' style='fill:lime;stroke:purple;stroke-width:1' />\n";  
        svg+= "<!-- Shaft -->\n";
        svg+= "<line x1='"+ to_string(xline1) + "'" + " y1='"+to_string(Yplatform-50)+"' x2='" + to_string(xline2)+ "' y2='"+to_string(Yplatform-50)+"' style='stroke:rgb(255,0,0);stroke-width:2' />\n";
        svg+= "<line x1= '"+ to_string(xline1) +"' y1='"+to_string(Yplatform-40)+"' x2='" + to_string(xline2)+ "' y2='"+to_string(Yplatform-40)+"'  stroke='black' stroke-width='1'/>\n";
        svg+= "<text x='"+ to_string(xline1) +"' y='"+to_string(Yplatform-20)+"' fill='black'>"+ to_string((int)myshaft->s_length) +"</text>\n";
        svg+= "<!-- Square1 -->\n";
        svg+= "<rect x='"+ to_string(position1x) +"' y='"+ to_string(position1y) +"' width='"+ to_string(mysquares->sq1_side) +"' height='"+ to_string(mysquares->sq1_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
        svg+= "<line x1= '"+ to_string(position1x) +"' y1= '"+ to_string(position1y -10) +"' x2= '"+to_string(Xplatform + widthPla/2)+"' y2 = '"+ to_string(position1y -10) +"'  stroke='black' stroke-width= '1'/>\n";
        svg+= "<text x='"+ to_string(position1x) +"' y='"+ to_string(position1y -12) +"' fill='black'>"+ to_string((int)mysquares->sq1_pos ) +"</text>\n";
        svg+= "<line x1 = '"+ to_string(position1x-10) +"' y1= '"+ to_string(position1y) +"' x2= '"+ to_string(position1x-10) +"' y2= '"+ to_string(position1y + mysquares->sq1_side) +"'  stroke='black' stroke-width='1'/>\n";
        svg+= "<text x='"+ to_string(position1x-13) +"' y='"+ to_string(position1y + mysquares->sq1_side/2) +"' transform='rotate(-90 "+ to_string(position1x-13) + ","+ to_string(position1y + mysquares->sq1_side/2) +")' fill='black'>"+ to_string((int)mysquares->sq1_side) +"</text>\n";
        svg+= "<!-- Square2 -->\n";
        svg+= "<rect x='"+ to_string(position2x) +"' y='"+ to_string(position2y) +"' width='"+ to_string(mysquares->sq2_side) +"' height='"+ to_string(mysquares->sq2_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
        svg+= "<line x1= '"+ to_string(position2x) +"' y1= '"+ to_string(position2y -10) +"' x2= '"+to_string(Xplatform + widthPla/2)+"' y2 = '"+ to_string(position2y -10) +"'  stroke= 'black' stroke-width= '1'/>\n";
        svg+= "<text x='"+to_string(Xplatform + widthPla/2)+"' y='"+ to_string(position2y -12) +"' fill='black'>"+ to_string((int)mysquares->sq2_pos ) +"</text>\n";
        svg+= "<line x1= '"+ to_string(position2x + mysquares->sq2_side+10) +"' y1= '"+ to_string(position2y) +"' x2= '"+ to_string(position2x + mysquares->sq2_side+10) +"' y2= '"+ to_string(position2y + mysquares->sq2_side) +"'  stroke= 'black' stroke-width= '1'/>\n";
        svg+= "<text x='"+ to_string(position2x + mysquares->sq2_side+13) +"' y='"+ to_string(position2y) +"' transform='rotate(90 "+ to_string(position2x + mysquares->sq2_side+13) +","+ to_string(position2y) +")'  fill='black'>"+ to_string((int)mysquares->sq2_side) +"</text>\n";
        svg+= "</svg> \n";
        
    }
    return svg;
}
