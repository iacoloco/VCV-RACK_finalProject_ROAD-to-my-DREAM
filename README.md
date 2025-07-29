# VCV Rack Practice Plugin (C++ Simulation)

This project is my **C++ OOP practice environment** for learning how VCV Rack plugins work.  
It simulates the **Plugin / Model system** that VCV Rack uses under the hood.

---

## 🧱 What This Project Does
- Defines a `Model` class for representing modules (e.g., `"Oscillator"`, `"VCA"`).
- Defines a `Plugin` class that:
  - Stores a list of models using `vector<Model*>`.
  - Can **add, list, rename, and remove models** dynamically.
- Uses a global `pluginInstance` pointer to simulate how VCV Rack loads plugins.
- Implements `init(Plugin* p)` to set up the plugin with modules.

---

## 🧠 What I Learned
- How to use **C++ classes, constructors, and methods**.
- How pointers (`*`, `->`) work and why they’re used for efficiency.
- Difference between dot `.` and arrow `->` when accessing class members.
- How to dynamically allocate objects with `new`.
- Using `vector` to manage dynamic lists of pointers.
- Writing and calling custom functions for **adding, counting, renaming, and removing items**.
- Git + GitHub for **version control and portfolio building**.

---

## 🔧 Features (Functions I Built)
1. **`addModel(Model* model)`**  
   - Adds a module (model) to the plugin.  
   - Prints confirmation:
     ```cpp
     Model* osc = new Model("Oscillator");
     plugin.addModel(osc); // "Model added: Oscillator"
     ```

2. **`showModels()`**  
   - Prints a list of all registered models.

3. **`countModels()`**  
   - Displays the total number of models currently in the plugin.

4. **`removeModel(string name)`**  
   - Removes a model by name (if found).
   - If not found, prints an error.

5. **`renameModel(string oldName, string newName)`**  
   - Finds a model by name and changes its name.
   - Prints confirmation or an error if not found.

---

## ▶️ Example Flow

```cpp
Plugin myPlugin;
init(&myPlugin);

pluginInstance->showModels();         // Shows all models
pluginInstance->countModels();        // Counts models
pluginInstance->removeModel("VCA");   // Deletes VCA
pluginInstance->renameModel("Oscillator", "SuperOscillator");
pluginInstance->showModels();         // Shows updated models
pluginInstance->countModels();        // Shows updated count
