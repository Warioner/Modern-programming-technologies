#include "order_calc.h"

// 1. Расчёт скидки
// Описание: возвращает сумму со скидкой в зависимости от стоимости заказа и
// статуса клиента.
// - Если total < 0, возвращает -1.0 (ошибка).
// - Если total >= 10000: скидка 20% для премиум-клиентов, 15% для обычных.
// - Если total >= 5000: скидка 10% для премиум-клиентов, 5% для обычных.
// - В остальных случаях скидка 0%.
double applyDiscount(double total, bool isPremium) {
  if (total < 0)
    return -1.0;
  if (total >= 10000) {
    if (isPremium) {
      return total * 0.80;
    } else {
      return total * 0.85;
    }
  } else if (total >= 5000) {
    if (isPremium) {
      return total * 0.90;
    } else {
      return total * 0.95;
    }
  }
  return total;
}

// 2. Расчёт стоимости доставки
// Описание: возвращает стоимость доставки в зависимости от суммы заказа.
// - Если total < 0, возвращает -1.0 (ошибка).
// - Если total >= 5000, доставка бесплатная (0.0).
// - Иначе доставка стоит 300.0.
double calcShipping(double total) {
  if (total < 0)
    return -1.0;
  if (total >= 5000)
    return 0.0;
  return 300.0;
}

// 3. Итоговая цена
// Описание: вычисляет финальную стоимость заказа с учётом скидки и доставки.
// - Если любой аргумент отрицательный, возвращает -1.0 (ошибка).
// - Если итоговая цена получается отрицательной, она обнуляется (0.0).
// - Результат округляется до двух знаков после запятой.
double finalPrice(double total, double discount, double shipping) {
  if (total < 0 || discount < 0 || shipping < 0)
    return -1.0;
  double result = total - discount + shipping;
  if (result < 0)
    result = 0.0;
  return std::round(result * 100) / 100;
}

// 4. Подсчёт количества дорогих товаров в корзине
// Описание: возвращает количество товаров, цена которых превышает заданный
// порог.
// - Если вектор пустой, возвращает 0.
// - В противном случае подсчитывает количество элементов > threshold.
int countExpensiveItems(const std::vector<double> &prices, double threshold) {
  int count = 0;
  for (size_t i = 0; i < prices.size(); ++i) {
    if (prices[i] > threshold) {
      count++;
    }
  }
  return count;
}

// 5. Нахождение максимальной цены среди товаров,
// у которых значение цены нечётное (целая часть) и индекс тоже нечётный.
// Если таких товаров нет, возвращать 0.0.
double maxPriceOddValueOddIndex(const std::vector<int> &prices) {
  size_t size_prices = prices.size();
  int max_price = 0;
  for (size_t i = 1; i < size_prices; i += 2) {
    if ((prices[i] & 1) == 1 && max_price < prices[i]) {
      max_price = prices[i];
    }
  }
  return max_price;
}

// 5. Вычисление произведения элементов двумерного массива (матрицы цен),
// у которых сумма индексов (строка + столбец) является нечётной.
// Если таких элементов нет, возвращать 1.0.
double productOddIndexSum(const std::vector<std::vector<double>> &A) {
  size_t a_size_x = A.size();
  size_t a_size_y = 0;
  if (a_size_x > 0)
    a_size_y = A[0].size();
  else
    return 1.0;

  double output = 1.0;
  for (size_t i = 0; i < a_size_x; ++i) {
    for (size_t j = 0; j < a_size_y; ++j) {
      if (((i + j) & 1) == 1)
        output *= A[i][j];
    }
  }
  return output;
}

// 1. Вычисление произведение цен товаров, стоящих на нечётных индексах корзины.
// Если корзина пуста или нет нечётных индексов, функция должна возвращать 1.0.
double productOddIndices(const std::vector<double> &prices) {
  size_t size_prices = prices.size();
  double output = 1.0;
  for (size_t i = 1; i < size_prices; i += 2) {
    output *= prices[i];
  }
  return output;
}

// 2. Вычисление суммы нечётных элементов двумерного массива (матрицы цен),
// расположенных ниже главной диагонали (индекс строки > индекс столбца).
// Если таких элементов нет, возвращать 0.
int sumOddBelowMainDiagonal(const std::vector<std::vector<int>> &A) {
  size_t a_size_x = A.size();
  size_t a_size_y = 0;
  if (a_size_x > 0)
    a_size_y = A[0].size();
  else
    return 0;

  int output = 0;
  for (size_t i = 0; i < a_size_x; ++i) {
    for (size_t j = 0; j < i; ++j) {
      if ((A[i][j] & 1) == 1) {
        output += A[i][j];
      }
    }
  }
  return output;
}