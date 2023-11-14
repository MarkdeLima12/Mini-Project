#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100 // Max numer of users the programme can have

int userDistance(struct userStats userPosition[MAX], int people)
{
    float distance[MAX]; // used to store the distance between the user and the other person.
    int user;
    float latitudeDif, longitudeDif, altitudeDif; // will be used to return the other person that is closest to the user.
    for (int k = 1; k <= people; k++)             // will cycle through the people.
    {
        latitudeDif = (userPosition.userlatitude[0] - userPosition.userlatitude[k]) * (userPosition.userlatitude[0] - userPosition.userlatitude[k]);
        longitudeDif = (userPosition.userlongitude[0] - userPosition.userlongitude[k]) * (userPosition.userlongitude[0] - userPosition.userlatitude[k]);
        altitudeDif = (userPosition.useraltitude[0] - userPosition.useraltitude[k]) * (userPosition.useraltitude[0] - userPosition.userlatitude[k]);
        // will house the if statement and the equation.
        distance[k] = sqrt(latitudeDif + longitudeDif + altitudeDif);
        if (distance[k] < distance[user])
        {
            user = k;
        }
    }

    return user;
}

struct userStats // this is the format of the structure I found online, feel free to update as needed.
{
    char userName[MAX];
    float userlatitude;
    float userlongitude;
    float useraltitude;
};
struct userStats userStats1[MAX];

struct userStats getOtherUserLocation(int people)
{

    struct userStats location;
    FILE *fileRead = fopen("other_users1.txt", "r"); // open the file for reading
    if (fileRead == NULL)
    {
        printf("Error: cannot open file\n");
        exit(1); // terminate the program with an error code
    }
    // scan the file for the location
    int id;
    double lat, lon, alt;
    fscanf(fileRead, "%d\n%lf\n%lf\n%lf", &id, &lat, &lon, &alt);

    fclose(fileRead); // close the file
    // store the location in the global array
    userStats1[people] = location;
    // return the location
    return location;
}

int main()
{
    struct userStats userStats1[MAX] = {};
    int numPeople;

    float latitude[MAX], longitude[MAX], altitude[MAX];

    for (int i = 0; i < numPeople; i++)
    {
        userStats1[i] = getOtherUserLocation(i);
    }
    int closestUser = userDistance(userStats1, numPeople);

    // there will be a print statement after this to help with the layout.

    printf("The closest user to you is user %d with a position of %f, %f, %f.", closestUser, longitude[closestUser], latitude[closestUser], altitude[closestUser]);
}