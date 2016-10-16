//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdint.h>

//Includes Locais
#include <debug.h>
#include <Led.h>
#include <Timer.h>
#include <Time.h>
#include "../../../git/FreeRtos9CMSIS/FreeRtos9CMSIS/include/Serial.h"

Led led(GPIOC, GPIO_Pin_13, State::LOW);
Timer timer;
Serial serial;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-declarations"

int main(void) {
	logMessage("Inicializando\n");
	led.init();
	const char* texto = "AT+GMR";
	// Hiberna e espera por evento
	while (1) {
		if (time.millis() % 5000 == 0) {
			serial.printf("%s\r\n", texto);
			while(!serial.available())
				;
			logMessage(serial.read());
		}
		__WFI();
	}
}

#pragma GCC diagnostic pop
// ----------------------------------------------------------------------------
