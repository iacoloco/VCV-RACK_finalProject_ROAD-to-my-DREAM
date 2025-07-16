//
//  main.cpp
//  VCV Practise
//
//  Created by Armando Iachini on 15/07/2025.
//

#include <iostream>

#include <iostream>


using namespace std;

string* pluginInstance;

void init(string* p){
    
    pluginInstance = p;
    cout<< pluginInstance<< endl;
}



int main(int argc, const char * argv[]) {
    
    string myplugin = "My first Plugin";
    
    init (&myplugin);
    
    cout<< &myplugin<<endl;
    
   
    

         }
 
