/*
Lixie.h - Library for driving Lixie displays!
Created by Connor Nishijima, October 26th 2016.
Released under the GPLv3 license.
*/

#ifndef lixie_h
#define lixie_h

#include "Arduino.h"
#include "FastLED.h"

#ifndef LED_TYPE
  #define LED_TYPE WS2812B
#endif

#ifndef COLOR_ORDER
  #define COLOR_ORDER GRB
#endif

class Lixie{
	public:
		Lixie(const uint8_t pin, uint8_t nDigits);
		void begin();
   
		void clear(bool show_change = true);
		void show();
		
		void write(uint32_t input);
		void write(char* input);
		
		void write_flip(uint32_t input, uint16_t flip_time = 100);
		
		void sweep(CRGB col);
    
		void write_digit(byte input, byte index);
		void push_digit(byte number);
    
		void color(byte r, byte g, byte b);
		void color(CRGB c);
		void color(byte r, byte g, byte b, byte index);
		void color(CRGB c, byte index);

		void color_off(byte r, byte g, byte b);
		void color_off(CRGB c);
		void color_off(byte r, byte g, byte b, byte index);
		void color_off(CRGB c, byte index);
		
		void color_fade(CRGB col, uint16_t duration);
		void color_fade(CRGB col, uint16_t duration, byte index);
		
		void color_array_fade(CRGB *cols, uint16_t duration);

		void brightness(byte bright);
		void color_balance(CRGB c_adj);

		void max_power(byte volts, uint16_t milliamps);
	
		uint8_t get_numdigits() const;
		bool maxed_out(uint32_t input) const;

		CRGB* get_leds() const;

		// Debug Functions
		void print_binary() const;
		void print_current() const;

	private:
		static constexpr byte Addresses[10] = {3, 4, 2, 0, 8, 6, 5, 7, 9, 1};
		const static uint8_t LEDsPerDigit = 20;
		const uint8_t NumDigits;
		const uint16_t NumLEDs;
		CRGB *leds;
		CRGB *colors;
		CRGB *colors_off;
		byte *led_states;
		CLEDController *controller;
		byte bright = 255;
		byte sweep_dir = 0;
		void setBit(uint16_t pos, byte val);
		byte getBit(uint16_t pos) const;
		byte get_size(uint32_t input) const;
		byte char_to_number(char input) const;
		bool char_is_number(char input) const;
		void build_controller(uint8_t DataPin);
};

#endif
