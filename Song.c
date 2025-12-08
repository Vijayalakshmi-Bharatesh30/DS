#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song *next;
} Song;

typedef struct Playlist {
    char name;
    Song *head;
    struct Playlist *next;
} Playlist;

// Function to add song in circular linked list
void addSong(Playlist *pl, char songName[]) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    strcpy(newSong->name, songName);
    newSong->next = NULL;

    if (pl->head == NULL) {
        pl->head = newSong;
        newSong->next = newSong; // circular
        return;
    }

    Song *temp = pl->head;
    while (temp->next != pl->head)
        temp = temp->next;

    temp->next = newSong;
    newSong->next = pl->head;
}

// Function to display circular songs in playlist
void playSongs(Playlist *pl, int count) {
    if (pl->head == NULL) {
        printf("Playlist %c is empty.\n", pl->name);
        return;
    }
    printf("\nPlaying songs in Playlist %c:\n", pl->name);

    Song *temp = pl->head;
    for (int i = 0; i < count; i++) {
        printf("→ %s\n", temp->name);
        temp = temp->next;
    }
}

// Delete a song by name in playlist
void deleteSong(Playlist *pl, char songName[]) {
    if (pl->head == NULL) return;

    Song *curr = pl->head, *prev = NULL;

    // Find last node
    Song *last = pl->head;
    while (last->next != pl->head)
        last = last->next;

    do {
        if (strcmp(curr->name, songName) == 0) {
            if (curr == pl->head) {          // deleting head
                if (curr->next == curr) {    // only one song
                    pl->head = NULL;
                } else {
                    pl->head = curr->next;
                    last->next = pl->head;
                }
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("\nDeleted song '%s' from playlist %c\n", songName, pl->name);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != pl->head);

    printf("\nSong '%s' not found in Playlist %c\n", songName, pl->name);
}

// Delete a whole playlist
void deletePlaylist(Playlist **head, char name) {
    Playlist *curr = *head, *prev = NULL;

    do {
        if (curr->name == name) {
            if (curr == *head) {               // deleting head playlist
                Playlist *last = *head;
                while (last->next != *head)
                    last = last->next;
                if (curr->next == curr)
                    *head = NULL;
                else {
                    *head = curr->next;
                    last->next = *head;
                }
            } else {
                prev->next = curr->next;
            }

            // delete all songs of this playlist
            Song *s = curr->head;
            if (s) {
                Song *t;
                do {
                    t = s->next;
                    free(s);
                    s = t;
                } while (s != curr->head);
            }

            printf("\nPlaylist %c deleted.\n", name);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
}

// Play playlists in circular manner
void playPlaylists(Playlist *head, int count) {
    printf("\nPlaying playlists in circular manner:\n");
    Playlist *temp = head;
    for (int i = 0; i < count; i++) {
        printf("→ Playlist %c\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    // Create playlists A, B, C
    Playlist *A = (Playlist *)malloc(sizeof(Playlist));
    Playlist *B = (Playlist *)malloc(sizeof(Playlist));
    Playlist *C = (Playlist *)malloc(sizeof(Playlist));

    A->name = 'A'; A->head = NULL;
    B->name = 'B'; B->head = NULL;
    C->name = 'C'; C->head = NULL;

    // circular linking
    A->next = B;
    B->next = C;
    C->next = A;

    Playlist *playlistHead = A;

    // Add songs
    addSong(A, "Motivation1");
    addSong(A, "Motivation2");

    addSong(B, "Romantic1");
    addSong(B, "Romantic2");

    addSong(C, "Sad1");
    addSong(C, "Sad2");

    // Simulate plays
    playPlaylists(playlistHead, 7);
    playSongs(A, 5);
    playSongs(B, 5);
    playSongs(C, 5);

    // Delete a song from B
    deleteSong(B, "Romantic1");
    playSongs(B, 5);

    // Delete Playlist C
    deletePlaylist(&playlistHead, 'C');
    playPlaylists(playlistHead, 5);

    return 0;
}
