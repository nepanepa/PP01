#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Player.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {} 

		void Run()
		{
			_isGameRunning = true;
			lnitialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{
				chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
				Input();
				Update();
				Render();
				chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			}

			Release();
		}

		void Stop()
		{
			_isGameRunning = false;
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
				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnPressed();
			}

		}
		void Update()
		{
			
		}
		void Render()
		{
			
			cRenderer.Clear();

			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");

			cRenderer.DrawString(10, 20);
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS: " + to_string(1.0/renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::microseconds(20));
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