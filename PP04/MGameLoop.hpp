#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool isGameRunning;
		MConsoleRenderer cRenderer;

	public:
		MGameLoop()
		{
			isGameRunning = false;
		}
		~MGameLoop() {} 

		void Run()
		{
			isGameRunning = true;

			lnitialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}

			Release();
		}

		void Stop()
		{
			isGameRunning = false;
		}

	private:

		int playerCoordX, playerCoordY;
		bool isKeyPressed;

		void Initialize()
		{
			SetCursorState(false);
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{
				
			}
			else
			{
				
			}

		}
		void Update()
		{
			
		}
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);
			cRenderer.DrawString("test");

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			string fps = "FPS(millisconds):" + to_string(renderDuration.count());
			cRenderer.DrawString(fps);

			//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
			//if (remainingFrameTime > 0)
				//this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		}

		void Release() {}

	private: //게임 사용 함수

		void MoveCursor(short x, short y)
		{
			COORD position = { x , y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}

		void SetCursorState(bool visible)
		{
			CONSOLE_CURSOR_INFO consoleCursor;
			consoleCursor.bVisible = visible;
			consoleCursor.dwSize = 1;
			SetConsoleCursorinfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorinfo);
		}
	}; 
}