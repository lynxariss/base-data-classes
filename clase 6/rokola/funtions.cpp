#include "funtions.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

void loadCatalog(Jukebox& jukebox) {
    string artistList[ARTIST_COUNT] = {
        "Cavetown", "Stomach Book", "Set It Off", "Nirvana", "Linkin Park",
        "Los Retros", "Missa Sinfonia", "Ado", "Maretu", "Yukigloom"
    };

    string songList[ARTIST_COUNT][SONGS_PER_ARTIST] = {
        {"Lemon Boy", "Home", "Meteor Shower", "Devil Town", "Juliet", "Fool", "Talk to me", "Poison", "Hazel", "Best friend"},
        {"Casket kids", "Animals", "Bambi", "Fukouna Girl", "Tragedy", "Let you Down", "We all fall down", "SICK SICK SICK", "Paper dolls", "Anachy!!!"},
        {"I'd Rather Drown", "Plastic Promises", "Why Worry", "Partners in Crime", "Rotten", "Evil people", "horrible kids", "Wolf in sheep's clothing", "No control", "Nigthmare"},
        {"Smells Like Teen Spirit", "The Man Who Sold the World", "Dumb", "Lake of Fire", "Rape Me", "About at girl", "Sappy", "In Bloom", "Silver", "Drain You"},
        {"Numb", "Faint", "In the End", "The Emptiness Machine", "Lost", "Crawling", "Burn it down", "Heavy", "Bleed it out", "Talking to myself"},
        {"Someone to Spend Time With", "Amtrak", "Looking Back", "Friends", "Last Day on Earth", "Sweet Honey", "Room Gloom", "Purple Nights", "Likewise", "Lonely"},
        {"Vulnerables", "No es verdad", "Privilegios", "Tarde para el plan B", "Piratas", "Desconexion Emocional", "El tiempo", "Aqui estoy", "Fantasma enamorado", "Nuestros limites"},
        {"Ussewa", "untravel", "RuLe", "Episode X", "Rockstar", "Monstruo", "KIRA", "AIAIA", "Vivarium", "MAGIC"},
        {"magical doctor", "wating to wake up", "mind brand", "stuck in up", "Darling", "brain revolution girl", "MARETU | EVEN THOUGH I LOVED YOU", "SIU", "New Darling", "White Happy"},
        {"Stupid homura kinnie", "Cyberia", "a Fallen angel's thesis", "Insomniac.jpeg (feat. wulf boi)", "crinial nerve exam (GONE WRONG)", "if i was a vampire", "nostalgia (con Peachumari)", "TOOL ASSISTED ABSTRACTION", "SMOKE AND MIRRORS (YUKIGLOOM COVER)", "flawless EXEcution!"}
    };

    for (int artist = 0; artist < ARTIST_COUNT; artist++) {
        jukebox.artists[artist] = artistList[artist];
        for (int song = 0; song < SONGS_PER_ARTIST; song++) {
            jukebox.songs[artist][song] = songList[artist][song];
        }
    }
}

//funtion aproved
void initializeJukebox(Jukebox& jukebox) {
    loadCatalog(jukebox);
    clearPlaylist(jukebox);
}

//funtion aproved
bool isValidSelection(int artistIndex, int songIndex) {
    return artistIndex >= 0 && artistIndex < ARTIST_COUNT &&
           songIndex >= 0 && songIndex < SONGS_PER_ARTIST;
}

//funtion aproved
bool addSong(Jukebox& jukebox, int artistIndex, int songIndex) {
    if (!isValidSelection(artistIndex, songIndex)) {
        return false;
    }

    jukebox.playlist.push({artistIndex, songIndex});

    if (jukebox.playlist.size() == 1) {
        jukebox.currentPosition = 0;
        jukebox.paused = false;
    }

    return true;
}

//funtion aproved
bool getSongAt(queue<SongSelection> playlist, int position, SongSelection& selection) {
    if (position < 0 || position >= static_cast<int>(playlist.size())) {
        return false;
    }

    for (int i = 0; i < position; i++) {
        playlist.pop();
    }

    selection = playlist.front();
    return true;
}

//funtion aproved
bool getCurrentSong(const Jukebox& jukebox, SongSelection& selection) {
    return getSongAt(jukebox.playlist, jukebox.currentPosition, selection);
}

//funtion aproved
bool playSong(Jukebox& jukebox) {
    if (jukebox.playlist.empty()) {
        return false;
    }

    jukebox.paused = false;
    return true;
}

//funtion aproved
bool pauseSong(Jukebox& jukebox) {
    if (jukebox.playlist.empty()) {
        return false;
    }

    jukebox.paused = !jukebox.paused;
    return true;
}

//funtion aproved
bool nextSong(Jukebox& jukebox) {
    if (jukebox.playlist.empty() || jukebox.currentPosition >= static_cast<int>(jukebox.playlist.size()) - 1) {
        return false;
    }

    jukebox.currentPosition++;
    jukebox.paused = false;
    return true;
}

//funtion aproved
bool previousSong(Jukebox& jukebox) {
    if (jukebox.playlist.empty() || jukebox.currentPosition == 0) {
        return false;
    }

    jukebox.currentPosition--;
    jukebox.paused = false;
    return true;
}

//funtion aproved
bool removeSong(Jukebox& jukebox, int position) {
    if (position < 0 || position >= static_cast<int>(jukebox.playlist.size())) {
        return false;
    }

    queue<SongSelection> remaining;
    int index = 0;

    while (!jukebox.playlist.empty()) {
        if (index != position) {
            remaining.push(jukebox.playlist.front());
        }
        jukebox.playlist.pop();
        index++;
    }

    jukebox.playlist = remaining;

    if (jukebox.playlist.empty()) {
        jukebox.currentPosition = 0;
        jukebox.paused = false;
    } else if (position < jukebox.currentPosition) {
        jukebox.currentPosition--;
    } else if (jukebox.currentPosition >= static_cast<int>(jukebox.playlist.size())) {
        jukebox.currentPosition = static_cast<int>(jukebox.playlist.size()) - 1;
    }

    return true;
}

//funtion aproved
void clearPlaylist(Jukebox& jukebox) {
    while (!jukebox.playlist.empty()) {
        jukebox.playlist.pop();
    }

    jukebox.currentPosition = 0;
    jukebox.paused = false;
}

//funtion aproved
bool updateSong(Jukebox& jukebox, int artistIndex, int songIndex, const string& newTitle) {
    if (!isValidSelection(artistIndex, songIndex) || newTitle.empty()) {
        return false;
    }

    jukebox.songs[artistIndex][songIndex] = newTitle;
    return true;
}

//funtion aproved
void showArtists(const Jukebox& jukebox) {
    cout << "┌─── ELIGE UN ARTISTA ───┐\n";
    for (int i = 0; i < ARTIST_COUNT; i++) {
        cout << "│ " << i + 1 << ". " << jukebox.artists[i] <<"│"<< '\n';
    }
    cout << "└────────────────────────┘\n";
    cout << "Artista: ";
}

void showSongs(const Jukebox& jukebox, int artistIndex) {
    if (artistIndex < 0 || artistIndex >= ARTIST_COUNT) {
        return;
    }

    cout << "┌─────── " << jukebox.artists[artistIndex] << " ──────┐\n";
    for (int i = 0; i < SONGS_PER_ARTIST; i++) {
        cout << "│ " << i + 1 << ". " << jukebox.songs[artistIndex][i]<< "│" << '\n';
    }
    cout << "└───────────────────────┘\n";
    cout << "Cancion: ";
}

void showPlaylist(const Jukebox& jukebox) {
    queue<SongSelection> copy = jukebox.playlist;
    int position = 0;

    while (!copy.empty()) {
        SongSelection selection = copy.front();
        cout << position + 1 << ". "
             << jukebox.artists[selection.artistIndex] << " - "
             << jukebox.songs[selection.artistIndex][selection.songIndex];

        if (position == jukebox.currentPosition) {
            cout << (jukebox.paused ? " [PAUSED]" : " [PLAYING]");
        }

        cout << '\n';
        copy.pop();
        position++;
    }
}

bool runTests() {
    Jukebox jukebox;
    initializeJukebox(jukebox);

    bool passed = true;

    passed = passed && jukebox.playlist.empty();
    passed = passed && addSong(jukebox, 0, 0);
    passed = passed && addSong(jukebox, 4, 0);
    passed = passed && jukebox.playlist.size() == 2;
    passed = passed && jukebox.playlist.front().artistIndex == 0;
    passed = passed && jukebox.playlist.back().artistIndex == 4;
    passed = passed && nextSong(jukebox);
    passed = passed && jukebox.currentPosition == 1;
    passed = passed && previousSong(jukebox);
    passed = passed && jukebox.currentPosition == 0;
    passed = passed && pauseSong(jukebox);
    passed = passed && jukebox.paused;
    passed = passed && playSong(jukebox);
    passed = passed && !jukebox.paused;
    passed = passed && updateSong(jukebox, 0, 0, "Updated Song");
    passed = passed && jukebox.songs[0][0] == "Updated Song";
    passed = passed && removeSong(jukebox, 0);
    passed = passed && jukebox.playlist.size() == 1;

    clearPlaylist(jukebox);
    passed = passed && jukebox.playlist.empty();

    cout << (passed ? "All tests passed.\n" : "A test failed.\n");
    return passed;
}

//menu
void showShortMenu() {
    cout << "┌──────────────────────────────┐\n";
    cout << "│           ROCKOLA            │\n";
    cout << "├──────────────────────────────┤\n";
    cout << "│  1. Agregar cancion a la cola│\n";
    cout << "│  2. Salir                    │\n";
    cout << "└──────────────────────────────┘\n";
    cout << "Opcion: ";
}


void showLongMenu(const Jukebox& jukebox) {
    cout << "┌──────────────────────────────┐\n";
    cout << "│           ROCKOLA            │\n";
    cout << "├──────────────────────────────┤\n";
    cout << "│  1. Agregar cancion          │\n";
    cout << "│  2. Pausar / Reanudar        │\n";
    cout << "│  3. Siguiente                │\n";
    cout << "│  4. Eliminar                 │\n";
    cout << "│  5. Anterior                 │\n";
    cout << "│  6. Salir                    │\n";
    cout << "└──────────────────────────────┘\n";

    SongSelection current;
    if (getCurrentSong(jukebox, current)) {
        cout << (jukebox.paused ? "En pausa: " : "Reproduciendo: ")
             << jukebox.songs[current.artistIndex][current.songIndex]
             << " de " << jukebox.artists[current.artistIndex] << "\n";
    }

    cout << "\nCola:\n";
    showPlaylist(jukebox);

    cout << "Opcion: ";
}



void showDeleteMenu() {
    cout << "┌──────────────────────────────┐\n";
    cout << "│           ELIMINAR           │\n";
    cout << "├──────────────────────────────┤\n";
    cout << "│  1. Eliminar una cancion     │\n";
    cout << "│  2. Eliminar todas           │\n";
    cout << "│  3. Cancelar                 │\n";
    cout << "└──────────────────────────────┘\n";
    cout << "Opcion: ";
}