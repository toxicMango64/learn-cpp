// Copyright [2025] <myousaf>
#pragma once

#include <iostream>
#include <string>

typedef std::string str;

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(const T& var));

template<typename T>
void	printValue(const T val);
