#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Song
{
    int id;
    string title;
    string artist;
};

const int TOTAL_ARTISTS = 10;
const int SONGS_PER_ARTIST = 10;

void loadArtists(string artists[TOTAL_ARTISTS][2]);

void loadSongs(queue<Song>& songs);

void showMenu();

void showArtists(string artists[TOTAL_ARTISTS][2]);

void showAllSongs(const queue<Song>& songs);

void showSongsByArtist(
    const queue<Song>& songs,
    const string& artist
);

int selectArtist(string artists[TOTAL_ARTISTS][2]);

string getArtistName(
    string artists[TOTAL_ARTISTS][2],
    int artistIndex
);

void loadArtistQueue(
    const queue<Song>& songs,
    queue<int>& playbackQueue,
    const string& artist
);

void clearQueue(queue<int>& playbackQueue);

void showQueue(
    queue<int> playbackQueue,
    const queue<Song>& songs
);

void playCurrentSong(
    const queue<int>& playbackQueue,
    const queue<Song>& songs
);

void nextSong(
    queue<int>& playbackQueue,
    queue<int>& history
);

void previousSong(
    queue<int>& playbackQueue,
    queue<int>& history
);

void addSong(queue<Song>& songs);

void deleteSong(queue<Song>& songs, int songId);

void updateSong(queue<Song>& songs, int songId);

int findSongById(
    const queue<Song>& songs,
    int id
);

void showSong(const Song& song);

int countSongsByArtist(
    const queue<Song>& songs,
    const string& artist
);

bool isQueueEmpty(
    const queue<int>& playbackQueue
);

void pauseProgram();

void clearScreen();

#endif