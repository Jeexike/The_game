#include "include/main.hpp"
#include "include/TApplication.hpp"

int main(int argc, char *argv[]){
    Lessons::TApplication Application;
    Application.Init();
    Application.Run();
    Application.End();
    
    return 0;
}
