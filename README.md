# 🎓 Final Project – VCV Rack Module Development  
## Phase 1: C++ Architecture Simulation

This is the first phase of my final project: building and understanding the C++ architecture behind VCV Rack plugins by simulating how modules are registered using classes, pointers, and dynamic memory.

---

## 🧱 What This Project Does

- Defines a `Model` class for module names like "Oscillator" or "VCA"
- Defines a `Plugin` class that holds a list of `Model` pointers
- Uses a global pointer `pluginInstance` to simulate how VCV Rack loads a plugin
- Registers multiple modules using `init(Plugin* p)`
- Prints the list of registered modules to the console

---

## 🧠 What I Learned in This Phase

- ✅ C++ classes, constructors, and methods
- ✅ How to use pointers (`*`, `->`)
- ✅ The difference between dot `.` and arrow `->`
- ✅ How `new` creates objects on the heap
- ✅ How to build vectors of pointers (`vector<Model*>`)
- ✅ Function design, passing pointers, and memory management
- ✅ Git + GitHub for version control and project tracking

---

## 🔧 How It Works (Flow of the Code)

1. **Create a `Plugin` object** in `main()`  
   This represents your plugin toolbox — where all your modules (models) will go.

   ```cpp
   Plugin myPlugin;
   ```

2. **Call the `init()` function**, passing the address of your plugin  
   This simulates how VCV Rack gives your plugin a "box" to fill.

   ```cpp
   init(&myPlugin);
   ```

3. **Inside `init()`**, store the plugin address in a global pointer `pluginInstance`  
   This lets your code access the plugin from anywhere.

   ```cpp
   pluginInstance = p;
   ```

4. **Create new modules** dynamically using `new` and the `Model` class constructor  
   This simulates defining modules like "Oscillator", "VCA", etc.

   ```cpp
   Model* osc = new Model("Oscillator");
   Model* vca = new Model("VCA");
   ```

5. **Register those modules** by passing them to `addModel()` on the plugin pointer  
   These go into a `vector<Model*>` inside the `Plugin` class.

   ```cpp
   p->addModel(osc);
   p->addModel(vca);
   ```

6. **Back in `main()`**, call `pluginInstance->showModels()`  
   This loops through all stored module pointers and prints their names.

   ```cpp
   pluginInstance->showModels();
   ```

---

## ✅ Current Code Flow

```cpp
int main() {
    Plugin myPlugin;
    init(&myPlugin);
    pluginInstance->showModels();
}
```

---

## 🚀 Next Phase (VCV Rack SDK + Real Module)

In the next stage of this project, I will:

---UNKNOW
---

## 💼 Final Project Goal

To create a fully working, open-source VCV Rack plugin  
→ **designed, coded, tested, and version-controlled from scratch**

This current simulation lays the foundation in modern C++ and plugin architecture before working with the real SDK.


