#ifndef PIPECOMMUNICATION_H
#define PIPECOMMUNICATION_H
#include <windows.h>
#include <iostream>

class PipeCommunication {
public:
    HANDLE pipe;

    PipeCommunication();
    void createPipe();
    void sendData(const wchar_t *data);
};


#endif //PIPECOMMUNICATION_H
