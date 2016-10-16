//=================================================================================//
//	Arquivo : Time.h
//	Projeto : IntTeste
//	Autor : Maikeu Locatelli
//	Copyright : Locatelli Engenharia
//
//	Descricão: 
//=================================================================================//
//	This file is part of IntTeste
//	IntTeste is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//==================================================================================//
//	Includes
//==================================================================================//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32f10x_conf.h>

#ifndef TIME_H_
#define TIME_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" void SysTick_Handler(void);

#pragma GCC diagnostic pop

class Time {
public:
	friend void SysTick_Handler(void);
	Time();
	virtual ~Time();
	uint32_t millis();
	void delay(uint32_t ms);
protected:
	uint32_t _ms;
};

extern Time time;

#endif /* TIME_H_ */
