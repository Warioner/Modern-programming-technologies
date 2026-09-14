// Playlist.cpp — частичная реализация
#include "Playlist.h"
#include <iomanip>
#include <sstream>

Playlist::Playlist(int capacity) {
  if (capacity <= 0)
    throw PlaylistException("недопустимое значение вместимости = " +
                            std::to_string(capacity));
  this->capacity = capacity;
  this->count = 0;
  this->tracks = new Track[capacity];
}

Playlist::Playlist(const Playlist &other) {
  capacity = other.capacity;
  count = other.count;
  tracks = new Track[capacity];
  for (int i = 0; i < count; i++)
    tracks[i] = other.tracks[i];
}

Playlist &Playlist::operator=(const Playlist &other) {
  if (this == &other)
    return *this;
  delete[] tracks;
  capacity = other.capacity;
  count = other.count;
  tracks = new Track[capacity];
  for (int i = 0; i < count; i++)
    tracks[i] = other.tracks[i];
  return *this;
}

Playlist::~Playlist() { delete[] tracks; }

const Track &Playlist::operator[](int i) const {
  if (i < 0 || i > count - 1)
    throw PlaylistException("неверное значение индекса i = " +
                            std::to_string(i));
  return tracks[i];
}

Track &Playlist::operator[](int i) {
  if (i < 0 || i > count - 1)
    throw PlaylistException("неверное значение индекса i = " +
                            std::to_string(i));
  return tracks[i];
}

bool Playlist::operator==(const Playlist &other) const {
  if (count != other.count)
    return false;
  for (int i = 0; i < count; i++) {
    if (tracks[i] != other.tracks[i])
      return false;
  }
  return true;
}

bool Playlist::Contains(const Track &track) const {
  for (int i = 0; i < count; i++) {
    if (tracks[i] == track)
      return true;
  }
  return false;
}

void Playlist::Add(const Track &track) {
  if (count >= capacity)
    throw PlaylistException("плейлист заполнен, вместимость = " +
                            std::to_string(capacity));
  if (Contains(track))
    throw PlaylistException("трек уже есть в плейлисте: " + track.artist +
                            " - " + track.title);
  tracks[count] = track;
  count++;
}

int Playlist::TotalDuration() const {
  int total = 0;
  for (int i = 0; i < count; i++)
    total += tracks[i].durationSec;
  return total;
}

std::string Playlist::ToString() const {
  std::ostringstream out;
  for (int i = 0; i < count; i++) {
    int m = tracks[i].durationSec / 60;
    int s = tracks[i].durationSec % 60;
    out << tracks[i].artist << " - " << tracks[i].title << " (" << m << ":"
        << std::setw(2) << std::setfill('0') << s << ")\n";
  }
  return out.str();
}

int Playlist::FindByArtist(const std::string &artist) const {
  for (int i = 0; i < count; i++) {
    if (tracks[i].artist == artist) {
      return i;
    }
  }
  throw PlaylistException("Трек по автору " + artist + " не найден!");
  return -1;
}

void Playlist::Merge(const Playlist &other) {
  for (int i = 0; i < other.Count(); i++) {
    if (!Contains(other[i])) {
      Add(other[i]);
    }
  }
}

void Playlist::RemoveTracksOf(const Playlist &other) {
  bool flag = false;
  for (int i = 0; i < other.Count(); i++) {
    for (int j = 0; j < count; j++) {
      if (other[i] == (*this)[j]) {
        flag = true;
        for (int g = j; j < count - 1; j++) {
          (*this)[j] = (*this)[j + 1];
        }
        Track emt;
        (*this)[j] = emt;
        count--;
      }
    }
  }
  if (!flag) {
    throw PlaylistException("Треков для удаления не найдено!");
  }
}