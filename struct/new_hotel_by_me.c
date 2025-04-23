#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int room_number;
    char name[80];
    int companions;
    char category;
    int days;
} Guest;

typedef struct
{
    int room_number;
    char category;
    char status;
} Room;

#define SINGLE_PRICE 85
#define FAMILY_PRICE 65
#define ROOMS_SIZE 15

void register_rooms(Room *rooms, int size)
{
    for (int i = 0; i < size; i++, rooms++)
    {
        rooms->room_number = i + 1;
        rooms->status = 'L';
        if (i < 5)
            rooms->category = 'S';
        else
            rooms->category = 'F';
    }
}

void register_guest(Guest *guests, Room *rooms, int size) {}

void show_rooms(Room *rooms, int size)
{
    for (int i = 0; i < size; i++, rooms++)
    {
        printf("Room %d: %c\n", rooms->room_number, rooms->category);
        printf("Status: %c\n\n", rooms->status);
    }
}

void allocate_room(Room **rooms, int size)
{
    *rooms = (Room *)realloc(*rooms, size * sizeof(Room));
    if (*rooms == NULL)
    {
        printf("Fail to allocate memory");
        exit(1);
    }
}

void allocate_guest(Guest **guests, int size)
{
    *guests = (Guest *)realloc(*guests, size * sizeof(Guest));
    if (*guests == NULL)
    {
        printf("Fail to allocate memory");
        exit(1);
    }
}

int main()
{
    Room *rooms = NULL;
    int option;
    allocate_room(&rooms, ROOMS_SIZE);
    register_rooms(rooms, ROOMS_SIZE);

    do
    {
        printf("\n[1]Show rooms\n[2]Check-in\n[3]Check-out\n[4]End\n");
        printf("Option: ");
        scanf("%d", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            show_rooms(rooms, ROOMS_SIZE);
            break;
        }
    } while (option != 4);

    return 0;
}