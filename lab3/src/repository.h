#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

template <class T> class Repository {
private:
  std::vector<T> items;

public:
  void Add(T item);
  void Remove(int index);
  void Update(int index, T item);
  int Size();
  std::vector<T> GetAll();
  void Clear();
};

template <class T> void Repository<T>::Add(T item) { items.push_back(item); }
template <class T> void Repository<T>::Update(int index, T item) {
  items[index] = item;
}
template <class T> void Repository<T>::Remove(int index) {
  items.erase(items.begin() + index);
}

template <class T> int Repository<T>::Size() { return items.size(); }
template <class T> std::vector<T> Repository<T>::GetAll() { return items; }
template <class T> void Repository<T>::Clear() { items.clear(); }

#endif
