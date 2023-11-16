#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Max numer of users the programme can have
#define NAME "other_users1.txt"

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
    float distance[MAX]; // used to store the distance between the user and the other person.
    int user;
    distance[user] = 700000000;
    float latitudeDif, longitudeDif, altitudeDif; // will be used to return the other person that is closest to the user.
    for (int k = 1; k <= people; k++)             // will cycle through the people.
    {
        printf("hello");
        latitudeDif = (userPosition[0].userlatitude - userPosition[k].userlatitude) * (userPosition[0].userlatitude - userPosition[k].userlatitude);
        longitudeDif = (userPosition[0].userlongitude - userPosition[k].userlongitude) * (userPosition[0].userlongitude - userPosition[k].userlatitude);
        altitudeDif = (userPosition[0].useraltitude - userPosition[k].useraltitude) * (userPosition[0].useraltitude - userPosition[k].userlatitude);
        // will house the if statement and the equation.
        distance[k] = sqrt(latitudeDif + longitudeDif + altitudeDif);
        printf("This is the distance: %lf\n", 12);
        if (distance[k] < distance[user])
        {
            user = k;
        }
    }

    return user;
}

USERSTATS getOtherUserLocation(USERSTATS *userStats1, int people)
{
    USERSTATS location;
    FILE *fileRead = fopen(NAME, "r"); // open the file for reading
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

        fclose(fileRead); // close the file
        // store the location in the global array
        userStats1[m].useraltitude = alt;
        userStats1[m].userlatitude = lat;
        userStats1[m].userlongitude = lon;
        userStats1[m].userTime = time;
        userStats1[people].userName[m] = name[m];
        printf("%lf\n", alt);
    }
}

int main()
{
    FILE *fileRead = fopen(NAME, "r"); // open the file for reading
    USERSTATS userStats1[MAX] = {};

    userStats1[0].useraltitude = 100.00;
    userStats1[0].userlatitude = 100.00;
    userStats1[0].userlongitude = 100.00;
    // userStats1[0].userName = "Me";

    int numPeople;
    printf("Please enter the number of users: ");
    scanf("%d", &numPeople);
    // fread(&numPeople, 2, 1, fileRead);

    printf("Hello: %d\n", numPeople);

    float latitude[MAX], longitude[MAX], altitude[MAX];

    printf("Hello\n");
    getOtherUserLocation(&userStats1, numPeople);
    int closestUser = userDistance(&userStats1, numPeople);

    // there will be a print statement after this to help with the layout.

    printf("The closest user to you is user %d with a position of %f, %f, %f.", closestUser, longitude[closestUser], latitude[closestUser], altitude[closestUser]);
}