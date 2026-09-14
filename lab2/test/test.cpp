#include "Playlist.h"
#include <gtest/gtest.h>

TEST(PlaylistTests, Constructor_Expected_Exception_OnZeroCapacity) {
  EXPECT_THROW(Playlist p(0), PlaylistException);
}

TEST(PlaylistTests, Indexer_Expected_Exception_OnOutOfRange) {
  Playlist p(2);
  p.Add({"Song A", "Artist A", 200});
  EXPECT_THROW(p[5], PlaylistException);
}

TEST(PlaylistTests, Add_Expected_Exception_OnDuplicate) {
  Playlist p(2);
  p.Add({"Song A", "Artist A", 200});
  EXPECT_THROW(p.Add({"Song A", "Artist A", 250}), PlaylistException);
}

TEST(PlaylistTests, Add_Expected_Exception_OnOverflow) {
  Playlist p(1);
  p.Add({"Song A", "Artist A", 200});
  EXPECT_THROW(p.Add({"Song B", "Artist B", 180}), PlaylistException);
}

TEST(PlaylistTests, Equal_SamePlaylists_ReturnsTrue) {
  Playlist a(2);
  a.Add({"Song A", "Artist A", 200});
  Playlist b(2);
  b.Add({"Song A", "Artist A", 200});
  EXPECT_TRUE(a == b);
}

TEST(PlaylistTests, Equal_SamePlaylists_ReturnsFalse1) {
  Playlist a(2);
  a.Add({"Song A", "Artist A", 200});
  Playlist b(2);
  b.Add({"Song B", "Artist A", 200});
  EXPECT_FALSE(a == b);
}

TEST(PlaylistTests, Equal_SamePlaylists_ReturnsFalse2) {
  Playlist a(2);
  a.Add({"Song A", "Artist A", 200});
  Playlist b(2);
  b.Add({"Song A", "Artist B", 200});
  EXPECT_FALSE(a == b);
}

TEST(PlaylistTests, TotalDuration_ReturnsSumOfTracks) {
  Playlist p(2);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});
  EXPECT_EQ(p.TotalDuration(), 300);
}

TEST(FindByArtist, Test1) {
  Playlist p(4);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});
  p.Add({"Song C", "Artist C", 300});
  p.Add({"Song D", "Artist D", 500});
  EXPECT_EQ(p.FindByArtist("Artist C"), 2);
}

TEST(FindByArtist, Test2) {
  Playlist p(4);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});
  p.Add({"Song C", "Artist C", 300});
  p.Add({"Song D", "Artist D", 500});
  EXPECT_THROW(p.FindByArtist("Artist E"), PlaylistException);
}

TEST(Merge, Test1) {
  Playlist p(6);
  Playlist g(4);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});

  g.Add({"GSong A", "GArtist A", 200});
  g.Add({"GSong B", "GArtist B", 100});
  g.Add({"GSong C", "GArtist C", 300});
  g.Add({"GSong D", "GArtist D", 500});

  p.Merge(g);

  bool flag = true;
  if (p[0].title != "Song A")
    flag = false;
  if (p[1].title != "Song B")
    flag = false;
  if (p[2].title != "GSong A")
    flag = false;
  if (p[3].title != "GSong B")
    flag = false;
  if (p[4].title != "GSong C")
    flag = false;
  if (p[5].title != "GSong D")
    flag = false;

  EXPECT_TRUE(flag);
}

TEST(Merge, Test2) {
  Playlist p(2);
  Playlist g(4);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});

  g.Add({"GSong A", "GArtist A", 200});
  g.Add({"GSong B", "GArtist B", 100});
  g.Add({"GSong C", "GArtist C", 300});
  g.Add({"GSong D", "GArtist D", 500});

  EXPECT_THROW(p.Merge(g), PlaylistException);
}

TEST(Merge, Test3) {
  Playlist p(2);
  Playlist g(1);
  p.Add({"GSong A", "GArtist A", 200});

  g.Add({"GSong A", "GArtist A", 200});

  p.Merge(g);

  bool flag = true;
  if (p[0].title != "GSong A" || p.Count() != 1)
    flag = false;

  EXPECT_TRUE(flag);
}

TEST(RemoveTracksOf, Test1) {
  Playlist p(4);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});
  p.Add({"Song C", "Artist C", 300});
  p.Add({"Song D", "Artist D", 500});

  Playlist g(2);
  g.Add({"Song A", "Artist A", 200});
  g.Add({"Song E", "Artist E", 100});

  p.RemoveTracksOf(g);

  bool flag = true;
  if (p[0].title != "Song B")
    flag = false;
  if (p[1].title != "Song C")
    flag = false;
  if (p[2].title != "Song D")
    flag = false;
  if (p.Count() != 3)
    flag = false;
  EXPECT_TRUE(flag);
}

TEST(RemoveTracksOf, Test2) {
  Playlist p(4);
  p.Add({"Song A", "Artist A", 200});
  p.Add({"Song B", "Artist B", 100});
  p.Add({"Song C", "Artist C", 300});
  p.Add({"Song D", "Artist D", 500});

  Playlist g(2);
  g.Add({"Song AR", "Artist AR", 200});
  g.Add({"Song E", "Artist E", 100});

  EXPECT_THROW(p.RemoveTracksOf(g), PlaylistException);
}

TEST(Operator, Test1) {
  Playlist p(1);
  p.Add({"Song A", "Artist A", 200});

  Playlist g(1);
  g.Add({"Song AR", "Artist AR", 200});
  p[0] = g[0];

  EXPECT_TRUE(p[0].artist == g[0].artist && p[0].title == g[0].title);
}

TEST(Operator, Test2) {
  Playlist p(1);
  p.Add({"Song A", "Artist A", 200});

  Playlist g(1);
  g.Add({"Song A", "Artist A", 200});
  p[0] = g[0];

  EXPECT_TRUE(p[0].artist == g[0].artist && p[0].title == g[0].title);
}