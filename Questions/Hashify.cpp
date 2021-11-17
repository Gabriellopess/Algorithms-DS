#include <iostream>
#include <string.h>

using namespace std;

struct Song{
    string name;
    int time = 0, position = 0, timePlayed = 0, asciiValue;
};

int ascii(string name){
    int asciiSum = 0;

    for(int i = 0; i < name.length(); i++){
        asciiSum += ((int)name[i] * i);
    }

    return asciiSum;
}

void asciiStruct(Song *music){
    int asciiSum = 0;

    for(int i = 0; i < music->name.length(); i++){
        asciiSum += ((int)music->name[i] * i);
    }
    music->asciiValue = asciiSum;
}

int hashing(string name, int size){
    int asciiSum = 0, initPos = 0;
    asciiSum = ascii(name);
    initPos = asciiSum % size;
    return initPos;
}

bool verifyCapacity(int occupCounter, int size){
    if(size%2 == 0){
        if(occupCounter >= size/2){
            return true;
        }
        else return false;
    }
    else{
        if(occupCounter > size/2){
            return true;
        }
        else return false;
    }
    
}

Song addSong(Song music, Song *playlist, int size, int *occupCounter){
    int position = hashing(music.name, size);
    int attempt = 0;
    bool isAdded = false;
    int i = position % size;

    asciiStruct(&music);
    while(isAdded == false){
        if(playlist[i].name.length() == 0){
            playlist[i] = music;
            playlist[i].position = i;
            isAdded = true;
            (*occupCounter)++;
        }   
        else{
            while(playlist[i].name.length() != 0){
                attempt++;
                i = (position + attempt) % size;
                if(i >= size){
                    i = 0;
                    attempt = 0;
                }
            }
        }
    }

    return playlist[i];
}

Song insertSong(Song music, Song *playlist, int size, int *occupCounter){
    int position = music.asciiValue % size;
    int attempt = 0;
    bool isAdded = false;
    int i = position % size;

    while(isAdded == false){
        if(playlist[i].name.length() == 0){
            playlist[i] = music;
            playlist[i].position = i;
            isAdded = true;
            (*occupCounter)++;
        }   
        else{
            while(playlist[i].name.length() != 0){
                attempt++;
                i = (position + attempt) % size;
                if(i >= size){
                    i = 0;
                    attempt = 0;
                }
            }
        }
    }

    return playlist[i];
}

Song *rehashing(int *size, Song *oldPlaylist, int *occupCounter){
    int oldSize = *size;
    *size = ((*size)*2) + 1;

    Song *newPlaylist;
    newPlaylist = (Song *) calloc(*size, sizeof(Song));
    *occupCounter = 0;

    for(int i = 0; i < oldSize; i++){
        if(oldPlaylist[i].name.length() != 0){
            insertSong(oldPlaylist[i], newPlaylist, *size, occupCounter);
        }
    }

    free(oldPlaylist);

    return newPlaylist;
}

Song *searchSong(string name, Song *playlist, int size){
    int possiblePos = hashing(name, size);
    Song *music;
    for(int i = 0; i < size; i++){
        if(playlist[possiblePos].name == name){
            music = &playlist[possiblePos];
            i = size;
        }
        else{
            possiblePos++;
            if(possiblePos >= size){
                possiblePos = 0;
            }
        }
    }

    return music;
}

Song *play(Song *music){
    music->timePlayed += music->time;

    return music;
}

int main(){
    int tableSize, occupCounter = 0;
    Song music;
    string status;

    cin >> tableSize;

    Song *playlist;
    playlist = (Song *) calloc(tableSize, sizeof(Song));

    do{
        cin >> status;

        if(status == "ADD"){
            cin >> music.name;
            cin >> music.time;
            Song musicAdded;
            
            musicAdded = addSong(music, playlist, tableSize, &occupCounter);

            if(verifyCapacity(occupCounter, tableSize)){
                playlist = rehashing(&tableSize, playlist, &occupCounter);
                // cout << "---------------------------------" << endl;
                // cout << "REHASHING: " << endl << "Nova playlist | size: " << tableSize << endl;
                // cout << "---------------------------------" << endl;
            }

            cout << "---------------------------------" << endl;
            cout << "Music Added: " << musicAdded.name << " Position: " << musicAdded.position << endl;
            cout << "Taxa de ocupacao: " << occupCounter << endl;
            cout << "---------------------------------" << endl;
        }
        else if(status == "PLAY"){
            cin >> music.name;
            Song *musicPlayed;
            musicPlayed = play(searchSong(music.name, playlist, tableSize));
            cout << "---------------------------------" << endl;
            cout << "Musica encontrada: " << endl << "Nome: " << musicPlayed->name << " | Tempo: " << musicPlayed->time << endl;
            cout << "Tempo tocado: " << musicPlayed->timePlayed << endl;
            cout << "---------------------------------" << endl;
        }
        else if(status == "TIME"){
            cin >> music.name;
            Song *musicTime;
            musicTime = searchSong(music.name, playlist, tableSize);
            cout << "---------------------------------" << endl;
            cout << "Musica encontrada: " << endl << "Nome: " << musicTime->name << " | Tempo tocado: " << musicTime->timePlayed << endl;
            cout << "---------------------------------" << endl; 

        }
    } while(status != "END");

    return 0;
}