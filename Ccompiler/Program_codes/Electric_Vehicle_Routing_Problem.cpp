//
//  Electric_Vehicle_Routing_Problem.cpp
//  
//
//  Created by Shohre Sadeghsa on 13/12/2018.
//
#include "Electric_Vehicle_Routing_Problem.hpp"
#include <iostream>
#include <string>
#include<list>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <tinyxml.h>
#include<cmath>
#include <algorithm>
using namespace std;
//**************************************Function DEFINTION****************************








//**************************************Main****************************
int main()
{
    int input[100];
    int id_input=0;
    
    ifstream inputfile;
    inputfile.open ("//Users//shiva//Documents//Cxcode//Ccompiler//Ccompiler//Input_files//Input.txt");
    if (inputfile.fail())
    {
        cout << "Input file is not work"<< endl;
    }
    else {
        
        
        while (!inputfile.eof())
        {
            inputfile>> input[id_input];
            cout << input[id_input] << endl;
        }
        inputfile.close();
        inputfile.clear();
        
    }// END INPUT FILE
    
    
    ofstream output_file;
    output_file.open ("//Users//shiva//Documents//Cxcode//Ccompiler//Ccompiler//Output_files// output.txt");
    output_file << "Writing this to an output file.\n";
    output_file.close();
    
    return 0;
}

