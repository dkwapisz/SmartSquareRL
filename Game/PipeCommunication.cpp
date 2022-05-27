#include "PipeCommunication.h"

PipeCommunication::PipeCommunication() {
    createPipe();
}

void PipeCommunication::createPipe() {
    using std::wcout, std::endl;

    pipe = CreateNamedPipe(
            reinterpret_cast<LPCSTR>(R"(\\.\pipe\MainPipe)"),
            PIPE_ACCESS_DUPLEX,
            PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
            1,
            65536,
            65536,
            0,
            NULL
    );

    wcout << "Creating an instance of a named pipe..." << endl;

    if (pipe == NULL || pipe == INVALID_HANDLE_VALUE) {
        wcout << "Failed to create outbound pipe instance.";
        return;
    }

    wcout << "Waiting for a client to connect to the pipe..." << endl;

    BOOL result = ConnectNamedPipe(pipe, NULL);
    if (!result) {
        wcout << "Failed to make connection on named pipe." << endl;
        CloseHandle(pipe);
        return;
    }

}

void PipeCommunication::sendData(const wchar_t *data) {
    using std::wcout, std::endl;

    wcout << "Sending data to pipe..." << endl;

    // This call blocks until a client process reads all the data
    DWORD numBytesWritten = 0;
    BOOL result = WriteFile(
            pipe,
            data,
            wcslen(data) * sizeof(wchar_t),
            &numBytesWritten,
            NULL
    );

    if (result) {
        wcout << "Number of bytes sent: " << numBytesWritten << endl;
    } else {
        wcout << "Failed to send data." << endl;

    }

    wcout << "Done." << endl;
}
