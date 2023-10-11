// Tetris_Byjavidx9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <Windows.h>

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
int nScreenWidth = 80;                  // Console Screen Size X (columns)
int nScreenHeight = 30;                 // Console Screen Size Y (rows)
unsigned char* pField = nullptr;

int Rotate(int px, int py, int r) {
    switch (r % 4) {
    case 0: return py * 4 + px; // 0 degrees
    case 1: return 12 + py - (px * 4);  // 90 degrees
    case 2: return 15 - (py * 4) - px;  // 180 degrees
    case 3: return 3 - py + (px * 4);   // 270 degrees
    }

    return 0;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY) {
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++) {
            // Get index into piece
            int pi = Rotate(px, py, nRotation);

            // Get index intp field
            int fi = (nPosY + py) * nFieldWidth + (nPosX + px);
            if (nPosX + px >= 0 && nPosX + px < nFieldWidth)
            {
                if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
                {
                    if (tetromino[nTetromino][pi] == L 'X' && pField[fi] != 0)
                        return false; //fail on first hit
                }
            }
        }

    return true;
}

int main()
{
    // Create assets
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    pField = new unsigned char[nFieldWidth * nFieldHeight]; // Create play field buffer
    for (int x = 0; x < nFieldWidth; x++) { // Board Boundary
        for (int y = 0; y < nFieldHeight; y++) {
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
        }
    }


    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;


    bool bGameOver = false;

    int nCurrentPiece = 0;
    int nCurrentRotation = 0;
    int nCurrentX = nFieldWidth / 2;
    int NcurrentY = 0;

    bool bKey[4];
    bool bRotateHold = false;

    int nSpeed = 20;
    int nSpeedCounter = 0;
    bool bForceDown = false;

    while (!bGameOver)
    {
        // GAME TIMING ===============================================================

        this_thread::sleep_for(50ms); //game tick
        nSpeedCounter++;
        nSpeedCounter++;
        bForceDown = (nSpeedCounter == nSpeed);


        // INPUT =====================================================================
        for (int k = 0; k < 4; k++)                                //R   L   D  Z
            bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;

        // GAME LOGIC ================================================================
        nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, NcurrentY)) ? 1 : 0;
        nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, NcurrentY)) ? 1 : 0;
        nCurrentX += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, NcurrentY + 1)) ? 1 : 0;

        if (bKey[3])
        {
            nCurrentRotation += (!bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, NcurrentY)) ? 1 : 0;
            bRotateHold = true;
        }
        else
            bRotateHold = false;

        /*
        if (bForceDown) {
            if DoesPieceFit(nCurrentPiece)
        }
        */


        // RENDER OUTPUT =============================================================







        // Draw Field
        for (int x = 0; x < nFieldWidth; x++) {
            for (int y = 0; y < nFieldHeight; y++) {
                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
            }
        }
        //Draw current piece
        for (int px = 0; px < 4; px++)
            for (int py = 0; py < 4; py++)
                if (tetromino[nCurrentPiece][Rotate(px.py, nCurrentRoation)] == L 'X')
                    screen[nCurrentY + py + 2] * nScreenWidth + (nCurrentX + px + 2) = nCurrentPiece + 65;



        // Display Frame
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);

    }


    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
