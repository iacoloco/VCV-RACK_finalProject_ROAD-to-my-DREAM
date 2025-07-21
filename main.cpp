//
//  main.cpp
//  VCV Practise01
//
//  Created by Armando Iachini on 16/07/2025.
#include <iostream>
#include <vector>
using namespace std;






// Firts task created a Class Model

class Model{
    // inside the design of the object
public:
    string name;
    
    //constructor: runs when we create a model
    Model ( string modulename){
        name = modulename;
    }
};


//Second task Create a Plugin Class
class Plugin {
    
public:
    
    vector<Model*> models;
    
    void addModel(Model* modelname) {
        
        models.push_back(modelname);
        
        cout<<"Model added: " << modelname->name << endl;
    };
    
    void showModels(){
        cout<< "\nRegistered models:\n";
        for ( Model* m : models){
            cout << "-" << m->name<< endl;
        }
    };
    //4 task add remove model and Count Models
    
    void removeModel(string modelName){
        for (int i=0 ; i < models.size() ; i++){
            if (models[i]->name == modelName){
                models.erase(models.begin() + i);
                cout<<modelName<<" Delated!!!"<< endl;
                return; // Function ends here if model is found
            }
        }
        cout<<"MOD~EL NOT FOUND$$$$$$$$$"<<endl;
    };
    
    void countModels(){
        cout<<"You got "<< models.size()<<" Models in your Plugin"<< endl;
        
    };
    
    void renameModel(string nameModel , string newName){
        for ( int i=0 ; i < models.size() ; i++){
            if (models[i]->name == nameModel){
                models[i]->name = newName;
                cout<<nameModel << " Changed name to: "<< newName<< endl;
                return;
            }

        }
        cout<< "Not Model Found, Could not change the name"<<endl;
    }
    
};//end plugin class

    
    
    


//Third Task Init() Function.
Plugin* pluginInstance;

void init(Plugin* p){
    
    pluginInstance = p;
    
    //Create models (instances of Model)
    Model* osc = new Model("oscillator");
    Model* vca = new Model("VCA");
    Model* filter = new Model("Filter");
    
    //Add them to the plugIn
    p->addModel(osc);
    p->addModel(vca);
    p->addModel(filter);
    
};


int main(int argc, const char * argv[]) {
    
    Plugin myPlugin;
    
    init(&myPlugin);
    
    pluginInstance->showModels();
    pluginInstance->removeModel("vcv");
    pluginInstance->countModels();
    pluginInstance->renameModel("oscillator","NewOscillator ");
    pluginInstance->showModels();
    
    
    
};
