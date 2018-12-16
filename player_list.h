#pragma once
#include "image.h"
#include "common.h"
#include <netinet/in.h>
#include "vehicle.h"

typedef struct Position {
    float x;
    float y;
    float theta;
} Position;

typedef struct Player {
    int id;
    int last_packet_timestamp;
    char new[MAX_PLAYERS];
    Position position;
    Image * texture;
    struct sockaddr_in client_addr_udp;
    struct Player * next;
    Vehicle* vehicle;
    int in_game;
} Player;

typedef struct {
    Player * first;
    int n;
} PlayersList;

PlayersList * players_list_new();
Player * player_list_insert(PlayersList * p, int id, Image * i, Vehicle* vehicle);
Player * player_list_find(PlayersList * p, int id);
void player_list_delete(PlayersList * p, int id);
void player_list_print(PlayersList * p);
void player_list_free(PlayersList * p);
