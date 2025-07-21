//
//  main.cpp
//  VCV Practise01
//
//  Created by Armando Iachini on 16/07/2025.
#include <iostream>
#include <vector>
using namespace std;

// -------- Task 1: Create the Model Class --------
class Model {
public:
    string name;

    // Constructor: runs when we create a model
    Model(string modulename) {
        name = modulename;
    }
};

// -------- Task 2: Create the Plugin Class --------
class Plugin {
public:
    vector<Model*> models;

    void addModel(Model* modelname) {
        models.push_back(modelname);
        cout << "Model added: " << modelname->name << endl;
    }

    void showModels() {
        cout << "\nRegistered models:\n";
        for (Model* m : models) {
            cout << "- " << m->name << endl;
        }
    }

    // Remove a model by name
    void removeModel(string modelName) {
        for (int i = 0; i < models.size(); i++) {
            if (models[i]->name == modelName) {
                models.erase(models.begin() + i);
                cout << modelName << " Deleted!!!" << endl;
                return;  // stop once deleted
            }
        }
        cout << "MODEL NOT FOUND" << endl;
    }

    // Count models
    void countModels() {
        cout << "You got " << models.size() << " Models in your Plugin" << endl;
    }

    // Rename a model by name
    void renameModel(string nameModel, string newName) {
        for (int i = 0; i < models.size(); i++) {
            if (models[i]->name == nameModel) {
                models[i]->name = newName;
                cout << nameModel << " Changed name to: " << newName << endl;
                return;
            }
        }
        cout << "Not Model Found, Could not change the name" << endl;
    }
};

// -------- Task 3: Init Function --------
Plugin* pluginInstance;

void init(Plugin* p) {
    pluginInstance = p;

    // Create models (instances of Model)
    Model* osc = new Model("Oscillator");
    Model* vca = new Model("VCA");
    Model* filter = new Model("Filter");

    // Add them to the plugin
    p->addModel(osc);
    p->addModel(vca);
    p->addModel(filter);
}

// -------- Main --------
int main(int argc, const char* argv[]) {
    Plugin myPlugin;

    init(&myPlugin);

    pluginInstance->showModels();
    pluginInstance->removeModel("VCA");
    pluginInstance->countModels();
    pluginInstance->renameModel("Oscillator", "NewOscillator");
    pluginInstance->showModels();

    return 0;
}
