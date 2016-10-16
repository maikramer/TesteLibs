//=================================================================================//
//	Arquivo : Time.cpp
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
#include "Time.h"

Time::Time() : _ms(0) {
	/* Configura SysTick para 1ms de interrup��o  */
	SysTick_Config(SystemCoreClock / 1000);

	/* Configura prioridade do SysTick para M�xima */
	NVIC_SetPriority(SysTick_IRQn, 0x0);
}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

uint32_t Time::millis() {
	return (_ms);
}

void Time::delay(uint32_t ms) {
	uint32_t start = millis();

	while (millis() - start < ms)
		;
}

Time time;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-declarations"

extern "C" void SysTick_Handler(void) {
	time._ms++;
}

#pragma GCC diagnostic pop
