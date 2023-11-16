#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Max numer of users the programme can have
#define FILE_NAME "other_users1.txt"

typedef struct userStats // this is the format of the structure I found online, feel free to update as needed.
{
    char userName[MAX];
    double userlatitude;
    double userlongitude;
    double useraltitude;
    double userTime;
} USERSTATS;
USERSTATS userStats1[MAX];

int userDistance(USERSTATS userPosition[MAX], int people)
{
    double distance[MAX]; // used to store the distance between the user and the other person.
    int user = 0;
    distance[user] = 9999999999999;
    double latitudeDif, longitudeDif, altitudeDif; // will be used to return the other person that is closest to the user.
    for (int k = 1; k <= people; k++)              // will cycle through the people.
    {
        latitudeDif = (userPosition[0].userlatitude - userPosition[k].userlatitude) * (userPosition[0].userlatitude - userPosition[k].userlatitude);
        longitudeDif = (userPosition[0].userlongitude - userPosition[k].userlongitude) * (userPosition[0].userlongitude - userPosition[k].userlatitude);
        altitudeDif = (userPosition[0].useraltitude - userPosition[k].useraltitude) * (userPosition[0].useraltitude - userPosition[k].userlatitude);
        // will house the if statement and the equation.
        distance[k] = sqrt((latitudeDif + longitudeDif + altitudeDif));

        // printf("This is the distance: %lf\n", distance);
        if (distance[k] < distance[user])
        {
            user = k;
        }
    }

    return user;
}

USERSTATS getOtherUserLocation(USERSTATS *userStats1, int people)
{
    USERSTATS *location;
    FILE *fileRead = fopen(FILE_NAME, "r"); // open the file for reading
    if (fileRead == NULL)
    {
        printf("Error: cannot open file\n");
        exit(1); // terminate the program with an error code
    }
    // scan the file for the location
    int id;
    double lat, lon, alt, time;
    char name[MAX];
    for (int m = 1; m <= people; m++)
    {
        fscanf(fileRead, "%lf\n%lf\n%lf\n%lf\n%s", &lat, &lon, &alt, &time, &name);

        // store the location in the global array
        userStats1[m].useraltitude = alt;
        userStats1[m].userlatitude = lat;
        userStats1[m].userlongitude = lon;
        userStats1[m].userTime = time;
        for (int t = 0; t < strlen(name); t++)
            userStats1[m].userName[t] = name[t];
    }
}

int main()
{
    FILE *fileRead = fopen(FILE_NAME, "r"); // open the file for reading

    userStats1[0].useraltitude = 5000.00;
    userStats1[0].userlatitude = 5000.00;
    userStats1[0].userlongitude = 5000.00;
    userStats1[0].userTime = 5000.00;

    int numPeople = 10;
    char name[MAX];

    getOtherUserLocation(&userStats1, numPeople);
    int closestUser = userDistance(&userStats1, numPeople);

    // there will be a print statement after this to help with the layout.

    printf("Reference user: \nUser Me: \nLatitude: \t%.2lf\nLongitude: \t%.2lf\nAltitude: \t%.2lf\n\n", userStats1[0].userlatitude, userStats1[0].userlongitude, userStats1[0].useraltitude);

    printf("The closest user to you is user %d, ", closestUser);
    for (int j = 0; j <= strlen(userStats1[closestUser].userName); j++)
    {
        name[j] = userStats1[closestUser].userName[j];
    }
    printf("%s", name);
    printf(" , with a position of %.2lf, %.2lf, %.2lf.", userStats1[closestUser].userlatitude, userStats1[closestUser].userlongitude, userStats1[closestUser].useraltitude);
}