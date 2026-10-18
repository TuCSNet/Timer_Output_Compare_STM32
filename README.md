# Timer_Output_Compare_STM32

## Overview

This project demonstrates how to use STM32 timer output compare mode to control an LED's blinking frequency. Users can enter their desired blinking frequency through a PC terminal via UART and connect an LED to the TIM3_CH1 output pin (PA6) to observe the blinking behavior.

## Hardware

- STM32 Nucleo-F446RE development board
- USB connection to PC

## Software and Tools

- STM32CubeIDE
- STM32CubeMX
- STM32 HAL
- C programming language

## Features

- TIM3 is configured in output compare toggle mode to control the LED's blinking frequency
- UART communication is used to receive the desired blinking frequency from the user via a PC terminal

## Project Structure

- `Core/Inc/` — application header files
- `Core/Src/` — application source files
- `Drivers/` — STM32 HAL and CMSIS dependencies
- `.ioc` — STM32CubeMX configuration file
