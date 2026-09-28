#ifndef FUNTIONS_H
#define FUNTIONS_H

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int ARTIST_COUNT = 10;
const int SONGS_PER_ARTIST = 10;

struct SongSelection {
    int artistIndex;
    int songIndex;
};

struct Jukebox {
    string artists[ARTIST_COUNT];
    string songs[ARTIST_COUNT][SONGS_PER_ARTIST];
    queue<SongSelection> playlist;
    int currentPosition;
    bool paused;
};

void loadCatalog(Jukebox& jukebox);
void initializeJukebox(Jukebox& jukebox);
bool isValidSelection(int artistIndex, int songIndex);
bool addSong(Jukebox& jukebox, int artistIndex, int songIndex);
bool getSongAt(queue<SongSelection> playlist, int position, SongSelection& selection);
bool getCurrentSong(const Jukebox& jukebox, SongSelection& selection);
bool playSong(Jukebox& jukebox);
bool pauseSong(Jukebox& jukebox);
bool nextSong(Jukebox& jukebox);
bool previousSong(Jukebox& jukebox);
bool removeSong(Jukebox& jukebox, int position);
void clearPlaylist(Jukebox& jukebox);
bool updateSong(Jukebox& jukebox, int artistIndex, int songIndex, const string& newTitle);
void showArtists(const Jukebox& jukebox);
void showSongs(const Jukebox& jukebox, int artistIndex);
void showPlaylist(const Jukebox& jukebox);
bool runTests();

//menu
void showShortMenu();
void showLongMenu(const Jukebox& jukebox);
void showDeleteMenu();

#endif
