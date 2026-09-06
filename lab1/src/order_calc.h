#pragma once
#include <cmath>
#include <string>
#include <vector>

double applyDiscount(double total, bool isPremium);
double calcShipping(double total);
double finalPrice(double total, double discount, double shipping);
int countExpensiveItems(const std::vector<double> &prices, double threshold);

// Катерина

double maxPriceOddValueOddIndex(const std::vector<int> &prices);
double productOddIndexSum(const std::vector<std::vector<double>> &A);

// Антон

double productOddIndices(const std::vector<double> &prices);
int sumOddBelowMainDiagonal(const std::vector<std::vector<int>> &A);