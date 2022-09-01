#include "hello.hpp"

#include <stdio.h>
#include <cstdlib>
#include <dlfcn.h>

namespace Engine {
    void Hello();
}

int main(){
    void * engine;

    engine = dlopen("./run/libengine.so", RTLD_LAZY);

    if (!engine) { 
        printf("dlopen failed: %s\n", dlerror()); 
        exit(EXIT_FAILURE);
    }

    Engine::Hello();

    int eret = dlclose(engine);
}