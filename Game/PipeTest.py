import time

import win32file
import win32pipe


def named_pipe_client():
    print("pipe client")
    quit = False

    while not quit:
        handle = win32file.CreateFile(
            r'\\.\pipe\MainPipe',
            win32file.GENERIC_READ | win32file.GENERIC_WRITE,
            0,
            None,
            win32file.OPEN_EXISTING,
            0,
            None
        )
        res = win32pipe.SetNamedPipeHandleState(handle, win32pipe.PIPE_READMODE_MESSAGE, None, None)
        if res == 0:
            print(f"SetNamedPipeHandleState return code: {res}")
        while True:
            resp, data = win32file.ReadFile(handle, 64*1024)
            print(data.decode("UTF8"))

named_pipe_client()