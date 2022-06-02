#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

std::string GetStringFromInputStream();

std::vector<float> GetFloatVectorFromString(const std::string str);
//Каждый элемент массива должен быть умножен на минимальный элемент исходного массива
//функция должна принимать значение по ссылке
void TransformVectorWithVariant2(std::vector<float> &currentVector);

void SortVector(std::vector<float>& vector);
void PrintVector(const std::vector<float>& vector);
